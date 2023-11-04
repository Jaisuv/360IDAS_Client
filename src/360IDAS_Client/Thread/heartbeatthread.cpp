#include "heartbeatthread.h"

HeartBeatThread::HeartBeatThread()
{
    isStop=false;
    wt=WriteThread::getInstance();
    head.type=16;
    head.length=0;
    head.CRCnum=0;
    bzero(this->data,sizeof (data));
    memcpy(data,&head,sizeof(HEAD));
}

void HeartBeatThread::run()
{
    while(!isStop)
    {
        qDebug()<<"心跳中"<<endl;
        wt->setData(data,sizeof(HEAD));
        sleep(5);
    }
}

void HeartBeatThread::setIsStop(bool value)
{
    isStop = value;
}
