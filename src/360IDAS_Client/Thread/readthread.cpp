#include "readthread.h"

ReadThread* ReadThread::readThread_ins=nullptr;

ReadThread::ReadThread()
{

}

ReadThread *ReadThread::getInstance()
{
    if(ReadThread::readThread_ins==nullptr)
    {
        ReadThread::readThread_ins=new ReadThread;
    }
    return ReadThread::readThread_ins;
}

int ReadThread::getSocketfd() const
{
    return socketfd;
}

void ReadThread::setSocketfd(int value)
{
    socketfd = value;
}

void ReadThread::run()
{
    while (1)
    {
        //先读包头，再读包体
        read(this->socketfd,&head,sizeof (HEAD));
        qDebug()<<head.type;
        if(head.type == 1)//登录返回包
        {
            read(this->socketfd,&backInfo,head.length);
            qDebug()<<"登录请求的结果是:(0-成功　1-失败　2-CRC错误)"<<backInfo.flag;
            emit login_Request_Result(backInfo.flag,backInfo.name,backInfo.user_id);
        }
        else if (head.type==3)//注册返回包
        {
            read(this->socketfd,&backInfo,head.length);
            qDebug()<<"注册请求的结果是:(0-成功　1-失败　2-CRC错误)"<<backInfo.flag;
            emit regist_Request_Result(backInfo.flag);
        }
        else if (head.type==5)//录制返回
        {
            read(this->socketfd,&backInfo,head.length);
            qDebug()<<"录制信息上传结果是:(0-成功　1-失败　2-CRC错误)"<<backInfo.flag;
            emit videoRecordInfoRes(backInfo.flag);
        }
        else if (head.type==8)  //查询视频请求ＣＲＣ校验错误
        {

        }
        else if (head.type==9)  //视频查询返回
        {
            read(this->socketfd,&videoSearchRes,head.length);
            emit videoSearchResSign(&videoSearchRes);
        }
        else if (head.type==11) //图片信息上传完成ＣＲＣ校验错误
        {

        }
        else if (head.type==12)
        {
            read(this->socketfd,&imageBackInfo,head.length);
            qDebug()<<"手动截图上传的结果:(0-成功　１－数据包丢失)";
            emit image_Upload_Result(&imageBackInfo);
        }
        else if (head.type==13) //查询图片请求ＣＲＣ校验错误
        {

        }
        else if (head.type==14)
        {
            read(this->socketfd,&imageSearRes,head.length);
            emit imageSearchResSig(&imageSearRes);
        }
        else if (head.type==15)
        {
            read(this->socketfd,&backInfo,head.length);
            emit LogoutSignal(backInfo.flag);
        }
        else if (head.type==16)
        {
            read(this->socketfd,&backInfo,head.length);
            emit hearBeatSingal();
        }
    }
}
