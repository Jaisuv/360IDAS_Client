#include "heartbeatgetthread.h"

HeartBeatGetThread::HeartBeatGetThread()
{
    num=0;
    this->rt=ReadThread::getInstance();
    connect(this->rt,SIGNAL(hearBeatSingal()),this,SLOT(getHeartBeat()));
    this->isOver=false;
}

void HeartBeatGetThread::run()
{
    while(!isOver)
    {
        sleep(5);
        ++this->num;
        qDebug()<<"计次"<<this->num;
        if(num==3)
        {
            qDebug()<<"长时间没收到心跳";
            emit forceExit();
        }
    }
}

bool HeartBeatGetThread::getIsOver() const
{
    return isOver;
}

void HeartBeatGetThread::setIsOver(bool value)
{
    isOver = value;
}

void HeartBeatGetThread::getHeartBeat()
{
    this->num=0;
    qDebug()<<"收到心跳"<<this->num;
}



