//发送心跳包给服务器
#ifndef HEARTBEATTHREAD_H
#define HEARTBEATTHREAD_H

#include <QThread>
#include "protocol.h"
#include "Thread/writethread.h"

class HeartBeatThread:public QThread
{
public:
    HeartBeatThread();
    void setIsStop(bool value);

protected:
    void run();
    bool isStop;//继续 停止
    HEAD head;
    WriteThread * wt;
    char data[1500];
};

#endif // HEARTBEATTHREAD_H
