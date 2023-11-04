#include "filesplitthread.h"
#include "crccheck.h"
#include <QMessageBox>
FileSplitThread::FileSplitThread()
{
    qDebug()<<pathStr;
    this->isRun=false;
    this->isOver=false;
    pool.setMaxThreadCount(10);
    canContinue=true;
}

QString FileSplitThread::getFilePath() const
{
    return filePath;
}

void FileSplitThread::setFilePath(const QString &value)
{
    filePath = value;
    strcpy(this->pathStr,filePath.toStdString().c_str());
}

bool FileSplitThread::getIsRun() const
{
    return isRun;
}

void FileSplitThread::setIsRun(bool value)
{
    isRun = value;
}

bool FileSplitThread::getIsOver() const
{
    return isOver;
}

void FileSplitThread::setIsOver(bool value)
{
    isOver = value;
}

void FileSplitThread::setCanContinue(bool value)
{
    canContinue = value;
}

void FileSplitThread::imageBackDeal(int flag, QString img_path, QString img_nums, int user_id)
{

    qDebug()<<"数据包错误重新发送";
    qDebug()<<flag;
    qDebug()<<img_path;
    qDebug()<<img_nums;
    qDebug()<<user_id;
    int num=0;//具体下标
    QStringList list = img_nums.split("#");
    int rfd2=open(picPathQueue.front().toUtf8(),O_RDONLY);
    if(rfd2==-1)
    {
        qDebug()<<"文件都打不开"<<endl;
        return;
    }
    for (int i=0;i<list.size()-1;i++)
    {
        IMAGET imaget={0};
        num=list.at(i).toInt();
        int res2=lseek(rfd2,(num-1)*1000,SEEK_SET);//文件指针偏移
        bzero(this->data,sizeof(this->data));
        int res=read(rfd2,this->data,sizeof(this->data));
        memcpy(imaget.data,data,sizeof(this->data));
        imaget.img_num=num;
        imaget.img_length=res;
        imaget.user_id=this->userId;               //用户id
        imaget.equipment_id=this->equipmentId;
        imaget.img_type=this->Ftype;
        qDebug()<<"res="<<res<<" res2="<<res2;

        SendImgTask * task =new SendImgTask(imaget);
        task->setAutoDelete(true);
        pool.start(task);
        msleep(100);
        qDebug()<<"重发包"<<num;
    }
    if(pool.waitForDone())
    {
        qDebug()<<"重发完成协议";
    }
    head.type=11;
    head.length=sizeof(IMAGEOKT);

    head.CRCnum=CRCcheck::getInstance()->calculateCRC((char *)&imageOK,head.length);
    bzero(this->sendBuf,sizeof(this->sendBuf));
    memcpy(this->sendBuf,&this->head,sizeof(HEAD));
    memcpy(this->sendBuf+sizeof(HEAD),&this->imageOK,head.length);
    WriteThread::getInstance()->setData(this->sendBuf,sizeof(HEAD)+head.length);
    ::close(rfd2);
    msleep(100);
}

void FileSplitThread::enqueToQueue(QString path, int pictype)
{
    this->picPathQueue.enqueue(path);
    this->picTypeQueue.enqueue(pictype);
}

void FileSplitThread::dequeLastest()
{
    //QMutexLocker locker(&mylock);
    this->picTypeQueue.dequeue();
    this->picPathQueue.dequeue();
}

int FileSplitThread::getFirstType()
{

    int num=this->picTypeQueue.front();
    return num;
}

bool FileSplitThread::ifpicPathQueueEmpty()
{
    if(this->picPathQueue.isEmpty())
        return  true;
    else
        return  false;
}

void FileSplitThread::run()
{

    while (this->isOver==false)
    {
        msleep(1);
        if(this->picPathQueue.isEmpty())//是
        {
            continue;
        }
        else {
            this->filePath=this->picPathQueue.front();//队头的图片路径
            if(this->filePath.isEmpty()==false&&canContinue==true)
            {
                canContinue=false;
                int fd=0;
                int resbuf=0;
                char data[1000]={0};//数据内容载体
                int sequence=1; //图片序号
                umask(0);
                fd=open(filePath.toUtf8(),O_RDONLY,0777);
                if(fd<0)
                {
                    perror("open error");
                }
                else
                {
                    IMAGET imagePacket;//单个图片数据包
                    this->Ftype=this->picTypeQueue.front();
                    imagePacket.img_type=this->Ftype;//队头的图片路径
                    imagePacket.user_id=this->userId;               //用户id
                    imagePacket.equipment_id=this->equipmentId;     //设备id
                    //图片路径
                    QFileInfo fileInfo(this->filePath);
                    string imgdirectory=fileInfo.path().toStdString();
                    memcpy(imagePacket.img_path,imgdirectory.c_str(),sizeof (imagePacket.img_path));
                    //图片文件名
                    QStringList list=this->filePath.split("/");   //把路径名按照"/"拆分，尾部就是文件名
                    memcpy(imagePacket.img_name,list.last().toStdString().c_str(),sizeof (imagePacket.img_name));
                    memcpy(this->imgOK_name,imagePacket.img_name,sizeof (this->imgOK_name));//图片文件名
                    //计算文件总字节数
                    imagePacket.img_allBytes=lseek(fd,0,SEEK_END);
                    //零碎文件的总数
                    if(imagePacket.img_allBytes%sizeof (data)==0)
                    {
                      imagePacket.img_allNums=imagePacket.img_allBytes/sizeof (data);
                    }
                    else {
                      imagePacket.img_allNums=imagePacket.img_allBytes/sizeof (data)+1;
                    }

                    lseek(fd,0,SEEK_SET);     //回到文件开头
                    //开始循环读，拆分
                    while ((resbuf=read(fd,data,sizeof (data)))!=0)
                    {

                        qDebug()<<"*************************************";
                        imagePacket.img_num=sequence;   //图片序号
                        imagePacket.img_length=resbuf;//单个零碎文字数据的字节数
                        memcpy(imagePacket.data,data,resbuf);   //文件内容
                        qDebug()<<"当前零碎文件序号:"<<sequence;
                        sequence++;
                        if(imagePacket.img_length>0)
                        {
                            //this->imagePackets.push(imagePacket);
                            SendImgTask * task =new SendImgTask(imagePacket);
                            task->setAutoDelete(true);
                            pool.start(task);
                        }
                        bzero(data,sizeof (data));
                        msleep(100);
                    }
                    pool.waitForDone();
                    qDebug()<<"全发完了";
                    memset(&imageOK,0,sizeof (imageOK));
                    imageOK.user_id=this->userId;
                    imageOK.img_type=this->Ftype;
                    strcpy(imageOK.img_name,this->imgOK_name);
                    qDebug()<<imageOK.img_name;
                    HEAD OKhead;
                    memset(&OKhead,0,sizeof (OKhead));
                    OKhead.type=11;
                    OKhead.length=sizeof (IMAGEOKT);
                    OKhead.CRCnum=CRCcheck::getInstance()->calculateCRC((char*)(&imageOK),sizeof (imageOK));
                    char besend[1500];
                    memcpy(besend,&OKhead,sizeof (HEAD));
                    memcpy(besend+sizeof (HEAD),&(imageOK),sizeof (IMAGEOKT));
                    WriteThread::getInstance()->setData(besend,sizeof(HEAD)+sizeof (IMAGEOKT));
                    msleep(100);
                    this->filePath.clear();
                    ::close(fd);
                }
            }
        }
    }
}
