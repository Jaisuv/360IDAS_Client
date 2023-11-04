#ifndef VIDEOPLAYERWIDGET_H
#define VIDEOPLAYERWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QString>
#include <QDebug>
#include "Thread/filesplitthread.h"
#include "Thread/videoplaythread.h"
#include "Thread/writethread.h"
#include "Thread/readthread.h"
#include <QDateTime>
#include <queue>
#include <QThreadPool>  //线程池
#include "sendimgtask.h"    //图片文件发送类
#include <unistd.h>
#include "socketconnect.h"
#include <QQueue>
#include <QMessageBox>
#include "crccheck.h"

using namespace std;

namespace Ui {
class VideoPlayerWidget;
}

class VideoPlayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerWidget(QWidget *parent = nullptr);
    ~VideoPlayerWidget();

    QString getVideoPath() const;
    void setVideoPath(const QString &value);

    void videoInitial(QString path);

    void openVideo(int frame);

    int userId;             //用户ＩＤ
    int equipmentId;        //设备ＩＤ

    void setVideoName(const QString &value);

    void addPath(QString path,int type);
    int getVideoWidth();
    int getVideoHeight();

    bool isEmpty();

    void endAllThread();
private slots:
    void on_playBtn_clicked();

    void ChangeData(int current,Mat frame);

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_captureBtn_clicked();//手动截图

    void imageUploadResult(IMAGEBACKT*);

    void on_exitBtn_clicked();

    void playEndSlot();

    void on_rationcomboBox_currentIndexChanged(int index);

private:
    Ui::VideoPlayerWidget *ui;
    QString videoPath;                      //视频路径
    FileSplitThread *spt;                   //文件拆分线程
    VideoPlayThread *videoPlayThread;       //视频播放线程
    WriteThread *wt;                        //写线程
    ReadThread *rt;                         //读线程
    QImage Img;
    SocketConnect *sc;
    QString videoName;
    //容器传过来的容器的大小
    int count;

    //imageOK准备
    IMAGEOKT imageOK;
    char img_name[30];                      //图片文件名
    QThreadPool sendpool;

    HEAD videoRecordhead;
    VIDEOT videoRecord;
    CRCcheck *crc;
    char buf[1500];
    bool videoEnd;

    //Mat capSave;
protected:
    void paintEvent(QPaintEvent *e);
signals:
    void toVideoList();

};

#endif // VIDEOPLAYERWIDGET_H
