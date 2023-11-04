#ifndef BIRDVIEWSIDETHREAD_H
#define BIRDVIEWSIDETHREAD_H

#include <QThread>
#include <QObject>
#include <opencv2/opencv.hpp>
#include <QString>
#include <QDebug>
using namespace std;
using namespace cv;

class BirdViewSideThread:public QThread
{
    Q_OBJECT
public:
    static BirdViewSideThread* getInstance();

    bool getIsRun() const;
    void setIsRun(bool value);

    bool getIsOver() const;
    void setIsOver(bool value);

    void setVideoInit(QString path);

    Mat CarSideScene(Mat frame);

    void restartThread();
private:
    BirdViewSideThread();
    static BirdViewSideThread* BirdViewSideThread_ins;
    VideoCapture cap;//视频捕获对象
    QString videoPath;
    bool isRun;
    bool isOver;
    int currentFrameNum;
    int totalFrameNum;
    double fps;
    Mat frame;
    Mat carBg;

protected:
    void run();

signals:
    void send2CarSide(Mat frame);
    void restart();

};

#endif // BIRDVIEWSIDETHREAD_H
