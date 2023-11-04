//登录界面
#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QWidget>
#include "protocol.h"
#include <QDebug>
#include <QIcon>
#include <QMessageBox>
#include <QRegExpValidator>
#include "socketconnect.h"
#include "Thread/readthread.h"
#include "Thread/writethread.h"
#include "registwin.h"
#include <iostream>
#include "tools.h"
#include "Window/systemmainwin.h"
#include <QString>
#include "crccheck.h"
#include "Control/verificationcode.h"
#include "Thread/heartbeatgetthread.h"
#include "Thread/heartbeatthread.h"
namespace Ui {
class LoginWin;
}

class LoginWin : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWin(QWidget *parent = nullptr);
    ~LoginWin();

    //设置密码可见性标志
    bool getPwdVisFlag() const;
    void setPwdVisFlag(bool value);

    //对密码进行MD5加密
    QString generateMD5(const QString &value);

    //清空界面所有的编辑框
    void Clear();

    QString getNameBeReturn() const;
    void setNameBeReturn(const QString &value);

private slots:
    //登录界面的取消按钮
    void on_cancel_pushButton_clicked();
    //登录界面的登录按钮
    void on_login_pushButton_clicked();
    //明秘文切换
    void on_eyeBtn_clicked();
    //返回包读取检测
    void isChecked(int flag,QString UserName,int uid);
    //注册界面返回，让登录界面重现
    void regWinBackThisReShow(QString);
    //注册按钮
    void on_regist_pushButton_clicked();
    //重置按钮
    void on_pushButton_clicked();
    //測試按鈕，自動填寫賬號密碼
    void on_pushButton_2_clicked();

    void logoutSlot();

    void heartBeatMissSlot();
private:
    Ui::LoginWin *ui;
    bool pwdVisFlag;//密码可见与否的标志
    SocketConnect *sc;
    ReadThread *rt;
    WriteThread *wt;
    HEAD head;
    LOGT loginInfo;
    char buf[1500];
    //注册界面
    RegistWin *regWin;
    //系统主界面
    SystemMainWin *sysMainWin;
    //CRC校验码生成类
    CRCcheck* CRC;
    //图形验证码
    VerificationCode *VerifyCode;
    //心跳发送
    HeartBeatThread *hbt;
    //心跳接受
    HeartBeatGetThread *hbgt;
protected:
    /********************************************/
    /*利用鼠标事件实现无边框窗口的移动*/
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    /*******************************************/
    bool m_Drag;
    QPoint m_DragPosition;

signals:
    void cancel_pushButton_clicked();
};

#endif // LOGINWIN_H
