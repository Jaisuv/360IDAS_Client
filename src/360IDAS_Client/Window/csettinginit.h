#ifndef CSETTINGINIT_H
#define CSETTINGINIT_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QMouseEvent>
#include <QPoint>
#include "Control/ipaddress.h"
#include <QDebug>
#include <QString>
#include <QSettings> //保存配置信息
#include "socketconnect.h"
#include <QMessageBox>
#include "loginwin.h"

namespace Ui {
class CSettingInit;
}

class CSettingInit : public QWidget
{
    Q_OBJECT

public:
    explicit CSettingInit(QWidget *parent = nullptr);
    ~CSettingInit();
    void saveSettings();
    void readSettings();

private:
    Ui::CSettingInit *ui;
    bool m_Drag;
    QPoint m_DragPosition;
    QGraphicsDropShadowEffect *effect;
    IPAddress *ipAddressInput;
    SocketConnect *sc;//网络连接类
    LoginWin *loginWin;

protected:
    /********************************************/
    /*利用鼠标事件实现无边框窗口的移动*/
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    /*******************************************/


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // CSETTINGINIT_H
