//心跳获取线程，从服务器获取心跳包
#ifndef HEARTBEATGETTHREAD_H
#define HEARTBEATGETTHREAD_H

#include <QThread>
#include <QObject>
#include "Thread/readthread.h"

class HeartBeatGetThread:public QThread
{
    Q_OBJECT
public:
    HeartBeatGetThread();
    void setIsOver(bool value);
    bool getIsOver() const;

protected:

    void run();
private:
    int num;
    ReadThread *rt;
    bool isOver;
private slots:
    void getHeartBeat();
signals:
    void forceExit();

};

#endif // HEARTBEATGETTHREAD_H
