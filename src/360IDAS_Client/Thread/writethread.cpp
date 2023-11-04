#include "writethread.h"

WriteThread* WriteThread::writeThread_ins=nullptr;

WriteThread::WriteThread()
{
    this->dataLength=0;
    memset(this->data,0,sizeof (this->data));
}

WriteThread *WriteThread::getInstance()
{
    if(WriteThread::writeThread_ins==nullptr)
    {
        WriteThread::writeThread_ins=new WriteThread;
    }
    return WriteThread::writeThread_ins;
}

int WriteThread::getSocketfd() const
{
    return socketfd;
}

void WriteThread::setSocketfd(int value)
{
    socketfd = value;
}

void WriteThread::setData(void *value, int size)
{
    this->dataLength=size;
    memcpy(this->data,value,this->dataLength);
}

void WriteThread::run()
{
    while(1)
    {
        //数据没准备好，写线程就不会自动发送数据出去，只有手动设置好数据，才会让写线程发送数据
        if(this->dataLength>0)
        {
            int res=write(this->socketfd,this->data,this->dataLength);
            qDebug()<<"写线程的文件描述符"<<this->socketfd;
            qDebug()<<"写线程发送的结果："<<res;
            bzero(this->data,sizeof (this->data));
            this->dataLength=0;
        }
    }
}

