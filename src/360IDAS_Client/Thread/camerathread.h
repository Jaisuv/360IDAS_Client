//摄像头实时视频线程
#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H
#define CAMERA

#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <QString>
#include <QDebug>
#include <QDateTime>
#include "lightcheck.h"
#include <QMessageBox>
#include "protocol.h"
#include "Thread/writethread.h"
#include "crccheck.h"
using namespace std;
using namespace cv;

typedef struct data
{
    Mat img;
    vector<Point2f> points;
}DATA;

class CameraThread:public QThread
{
    Q_OBJECT
public:
    static CameraThread* getInstance();
    void detecCarDraw(Mat &frame,double scale);

    bool getIsRun() const;
    void setIsRun(bool value);

    bool getIsRecord() const;
    void setIsRecord(bool value);

    //添加个人签名的水印
    void addWaterMark(Mat &frame);
    void addWaterMark2(Mat &frame);

    int getModeType() const;
    void setModeType(int value);

    //倒车距离检测
    void obstacleRanging(Mat frame);

    //倒车辅助线
    void reverseLine(Mat frame);

    //鸟瞰透视变换
    void birdEyeView(Mat &currentFrame);

    void setUid(int value);

    void setIsOver(bool value);



private:
    CameraThread();
    static CameraThread* cameraThread_ins;  //线程实例
    int modeType;       //1-行车　2-倒车  3-鸟瞰
    VideoCapture cap;                       //播放视频
    VideoWriter writer;                     //录制视频
    CascadeClassifier carCas;               //车辆识别级联分类器件
    Mat frame;
    bool isRun;             //是否运行
    bool isRecord;          //是否录制

    int frame_width;        //帧宽
    int frame_height;       //帧高
    int frame_num;          //帧数
    int recordFPS;          //录制的帧率

    LightCheck *lightCheck; //红绿灯检测类

    Mat carBg;

    bool first;

    //录制请求
    HEAD head;
    VIDEOT videoInfo;

    //QImage videoCover;
    QString videoCoverName;

    WriteThread *wt;

    char data[1500];

    CRCcheck *crc;

    bool isOver;

    Mat CarsideMat;


protected:
    void run();

signals:
    void send2UI(Mat frame);
    void send2ReverPage(Mat frame);
    void send2BirdEye(Mat frame,Mat camera);//左边是实时的视频，右边的是３６０全景效果图
public slots:
    void CarSideScene(Mat sideMat);
};

#endif // CAMERATHREAD_H
