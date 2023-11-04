//读数据线程
#ifndef READTHREAD_H
#define READTHREAD_H

#include <QObject>
#include <QThread>
#include <unistd.h>
#include <QDebug>
#include "protocol.h"

class ReadThread: public QThread
{
    Q_OBJECT
public:
    static ReadThread* getInstance();

    int getSocketfd() const;
    void setSocketfd(int value);

protected:
    void run();

private:
    ReadThread();
    static ReadThread* readThread_ins;
    int socketfd;
    HEAD head;//包头
    LOGT loginValue;//登录信息
    REGT registValue;//注册信息
    BACKMSGT backInfo;//服务器返回的信息登录注册信息
    IMAGEBACKT imageBackInfo;//截图上传
    SEARCHT VideoSearchCrcErr;
    SEARCHREST videoSearchRes;
    IMAGESERCHREST imageSearRes;

signals:
    void login_Request_Result(int flag,QString UserName,int uid);
    void regist_Request_Result(int flag);
    void image_Upload_Result(IMAGEBACKT*);
    void videoRecordInfoRes(int flag);
    void videoSearchResSign(SEARCHREST* videosearInfo);
    void imageSearchResSig(IMAGESERCHREST* imageSearRes);
    void LogoutSignal(int flag);
    void hearBeatSingal();
};

#endif // READTHREAD_H
