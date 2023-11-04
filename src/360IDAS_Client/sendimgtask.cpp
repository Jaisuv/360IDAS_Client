#include "sendimgtask.h"

SendImgTask::SendImgTask(IMAGET pack,QObject *parent) : QObject(parent)
{
    memset(this->buf,0,sizeof (this->buf));
    memcpy(&this->imagePack,&pack,sizeof(IMAGET));
    memset(&this->head,0,sizeof (HEAD));
    this->crcGenerator=CRCcheck::getInstance();
    wt=WriteThread::getInstance();
    //通过网络连接类单例，得到服务器的socket
    sc=SocketConnect::getInstance();
    this->sockefd=sc->getSocketfd();
}

int SendImgTask::getSockefd() const
{
    return sockefd;
}

void SendImgTask::setSockefd(int value)
{
    sockefd = value;
}

void SendImgTask::run()
{
    if(this->imagePack.img_length>0)
    {
        QMutexLocker locker(&mutex);
        bzero(&this->head,sizeof(this->head));
        bzero(this->buf,sizeof (buf));
        //包头setSockefd
        this->head.type=10;
        this->head.length=sizeof (IMAGET);
        this->head.CRCnum=this->crcGenerator->calculateCRC((char*)(&imagePack),sizeof (IMAGET));
        //包头和包体加入发送缓冲
        memcpy(this->buf,&head,sizeof (HEAD));
        memcpy(this->buf+sizeof(HEAD),&imagePack,sizeof (IMAGET));
        qDebug()<<"线程池的发送socket"<<this->sockefd;
        int res=write(sockefd,buf,sizeof (HEAD)+sizeof (IMAGET));
        if(res<0)
        {
            perror("发送失败");
            qDebug()<<"该数据包的序号为"<<imagePack.img_num;
        }
    }
}
