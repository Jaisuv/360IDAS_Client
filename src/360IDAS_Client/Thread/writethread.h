//写线程单例类封装
#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QObject>
#include <QThread>
#include <unistd.h>
#include <QDebug>
#include "protocol.h"

class WriteThread:public QThread
{
    Q_OBJECT
public:
    static WriteThread* getInstance();

    int getSocketfd() const;
    void setSocketfd(int value);

    void setData(void *value,int size);

protected:
    void run();

private:
    WriteThread();
    static WriteThread* writeThread_ins;
    int socketfd;
    char data[1500];
    int  dataLength;
};

#endif // WRITETHREAD_H
