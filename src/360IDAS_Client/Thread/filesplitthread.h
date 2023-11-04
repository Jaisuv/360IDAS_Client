//文件拆分线程
#ifndef FILESPLITTHREAD_H
#define FILESPLITTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include "protocol.h"
#include <stdio.h>
#include <QString>
#include <QFile>
#include <QMutex>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <queue>            //队列存放图片数据包体
#include <QFileInfo>
#include "sendimgtask.h"    //图片文件发送类
#include <QThreadPool>
#include "writethread.h"
#include <QQueue>
#include "crccheck.h"
#include "Thread/writethread.h"
#include <QMutex>
#include <QMutexLocker>
using namespace std;

class FileSplitThread:public QThread
{
    Q_OBJECT
public:
    FileSplitThread();

    QString getFilePath() const;
    void setFilePath(const QString &value);

    bool getIsRun() const;
    void setIsRun(bool value);

    bool getIsOver() const;
    void setIsOver(bool value);

    int userId;             //用户ＩＤ
    int equipmentId;        //设备ＩＤ
    int Ftype;              //文件类型

    void setCanContinue(bool value);

    void imageBackDeal(int flag, QString img_path, QString img_nums, int user_id);//丢包处理

    void enqueToQueue(QString path,int pictype);
    void dequeLastest();
    int getFirstType();
    bool ifpicPathQueueEmpty();
private:
    char pathStr[50];                   //C语言字符串形式的文件路径
    QString filePath;                   //要被拆分的文件的路径

    QQueue<QString> picPathQueue;       //被拆分上传的图片的路径存入
    QQueue<int> picTypeQueue;           //同步于图片路径队列，保存图片类型(自动or手动)

    queue<IMAGET> imagePackets;         //队列，存放零碎图片包
    bool isRun;
    bool isOver;
    QThreadPool pool;

    char imgOK_name[30];                //给ＯＫ包成员赋值

    bool canContinue;                   //能否继续上传图片

    IMAGEOKT imageOK;                   //完整图片数据上传通知
    char data[1000];                    //收缓冲
    char sendBuf[1500];                 //发缓冲

    HEAD head;                          //包头

protected:
    void run();

};

#endif // FILESPLITTHREAD_H
