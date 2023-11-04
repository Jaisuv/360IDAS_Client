#ifndef REGISTWIN_H
#define REGISTWIN_H

#include <QWidget>
#include <QDebug>
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QRegExpValidator>
#include "Thread/readthread.h"
#include "Thread/writethread.h"
#include "socketconnect.h"
#include <QCryptographicHash>//生成密码散列，提供MD5加密
#include <QIcon>
#include "tools.h"
#include <QDesktopWidget>
#include "crccheck.h"
#include <QMouseEvent>
using namespace std;

namespace Ui {
class RegistWin;
}

class RegistWin : public QWidget
{
    Q_OBJECT

public:
    explicit RegistWin(QWidget *parent = nullptr);
    ~RegistWin();

    //清空界面所有的输入框
    void Clear();
private slots:
    void on_cancel_pushButton_clicked();

    void on_ok_pushButton_clicked();

    void on_eyeBtn_clicked();

    void on_eyeBtn_2_clicked();

    void on_pushButton_clicked();

    void isChecked(int flag);

private:
    Ui::RegistWin *ui;
    bool isVisible1,isVisible2;
    SocketConnect* sc;
    ReadThread *rt;
    WriteThread *wt;
    HEAD head;
    REGT registInfo;
    char buf[1500];
    //下一个窗口成员
    QString AccountBeReturned;
    CRCcheck* CRC;//校验码生成对象
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
    //返回登录界面
    void back2Login(QString AccountBeReturned);

};

#endif // REGISTWIN_H
