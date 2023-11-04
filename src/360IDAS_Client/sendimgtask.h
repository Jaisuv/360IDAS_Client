#ifndef SENDIMGTASK_H
#define SENDIMGTASK_H
#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QThread>
#include <queue>
#include <unistd.h>
#include <QMutex>
#include <QMutexLocker>
#include "Thread/writethread.h"
#include "protocol.h"
#include "crccheck.h"
#include "socketconnect.h"
using namespace std;

class SendImgTask : public QObject,public QRunnable
{
    Q_OBJECT
public:
    SendImgTask(IMAGET pack,QObject *parent = nullptr);

    int getSockefd() const;
    void setSockefd(int value);

private:
    HEAD head;
    IMAGET imagePack;
    int sockefd;
    //queue<IMAGET> imagePackets;
    char buf[1500];
    QMutex mutex;

    CRCcheck* crcGenerator;     //CRC校验码
    WriteThread * wt;
    SocketConnect *sc;
protected:
    void run();

signals:

public slots:
};

#endif // SENDIMGTASK_H
