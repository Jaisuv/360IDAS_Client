//系统主界面
#ifndef SYSTEMMAINWIN_H
#define SYSTEMMAINWIN_H

#include <QWidget>
#include <QDesktopWidget>
#include "videorecorditemwidget.h"
#include <QSize>
#include <QDebug>
#include <QRect>
#include <QString>
#include "Window/videoplayerwidget.h"
#include <QListWidgetItem>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include "Thread/camerathread.h"
#include "Thread/readthread.h"
#include "Thread/writethread.h"
#include <QWheelEvent>
#include <QScrollBar>
#include "crccheck.h"
#include "protocol.h"
#include <QMessageBox>
#include "videoscreenshotdelegate.h"
#include <QProcess>
#include <QMouseEvent>
#include "bigpicwidget.h"
#include "Thread/birdviewsidethread.h"
#include <QSettings>
#include "Control/ipaddress.h"
using namespace cv;

namespace Ui {
class SystemMainWin;
}

class SystemMainWin : public QWidget
{
    Q_OBJECT
public:
    explicit SystemMainWin(QWidget *parent = nullptr);
    ~SystemMainWin();

    QString getUsrName() const;
    void setUsrName(const QString &value);

    int getUser_id() const;
    void setUser_id(int value);

    CameraThread* cameThd;//摄像头线程

    void VideoSearch();//搜索视频

    void searchPicture();

    void setListMode(int value);

private slots:
    //视频列表查询
    void on_videoRecordtoolButton_clicked();
    void videoResearchSlot(SEARCHREST* videoResearchRes);

    void on_drivingModetoolButton_clicked();

    void on_reverseModetoolButton_clicked();

    void on_birdViewtoolButton_clicked();

    void on_featureRecordtoolButton_clicked();
    void imageResearchSlot(IMAGESERCHREST* imageSearRes);

    void on_systemSettingtoolButton_clicked();

    void playVideo(QString path,int frameNum,QString videoName);//视频列表点播

    /**********************************************/
    //行车模式
    void DrivingVideo(Mat frame);
    void autoCapture();//自动截图
    /**********************************************/
    //倒车模式
    void ReverseVideoShow(Mat frame);
    /********************************************/
    //鸟瞰模式
    void BirdEyeVideoRT(Mat effec,Mat camera);

    /********************************************/
    void return2VideoList();    //视频播放退出回到视频列表
    void return2PIcList();      //查看招牌后，退出回到照片列表
    void on_logoutBtn_clicked();
    void on_pic_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

public slots:
    void logoutSlot(int flag);
    void restartBirdT();
private:
    Ui::SystemMainWin *ui;
    QString usrName;
    int user_id;        //用户id,登录返回从服务器获取
    int equipmentID;    //设备ID
    VideoPlayerWidget *player;//场景重现，视频列表
    //实时视频的QImage
    QImage drivingImg;      //行车的QImage
    QImage reverserImg;     //倒车的QImage
    QImage birdImgLeft;     //鸟瞰360图
    QImage birdImgRight;    //鸟瞰摄像头图
    QTimer *timer1;  //定时器自动截取特征图片

    ReadThread *rt;         //读线程
    WriteThread *wt;        //写线程

    bool isLoading;
    QScrollBar *verticalScrollBar1;//视频列表滚轮
    QScrollBar *verticalScrollBar2;//图片列表滚轮

    HEAD head;
    SEARCHT videoListSearch;
    int videoListPage;//视频当前页
    int videoNum;//上一次视频查询的数量
    char buf[1500];

    CRCcheck *CRC;
    QListWidgetItem *filledItem;

    HEAD picHead;
    SEARCHT picListSearch;
    int picListPage;//图片列表单前页
    int picNum;
    char picbuf[1500];
    bool isPicLoading;

    int ListMode;//1-视频列表　2-图片列表

    Mat capframe;
    QImage capSaveImg;
    int capW,capH;

    HEAD logoutHead;
    BACKMSGT logoutRequst;

    BigPicWidget *bgPicWin;

    BirdViewSideThread *bvsThread;
    Mat CarsideMat;

    IPAddress *ipAddressInput;

protected:
    void wheelEvent(QWheelEvent *event);
    /********************************************/
    /*利用鼠标事件实现无边框窗口的移动*/
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    /*******************************************/
    bool m_Drag;
    QPoint m_DragPosition;

signals:
    void logoutSigal();

};

#endif // SYSTEMMAINWIN_H
