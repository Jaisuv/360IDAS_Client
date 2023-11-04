//视频播放单例　－－　开机动画　视频列表点播
#ifndef VIDEOPLAYTHREAD_H
#define VIDEOPLAYTHREAD_H
#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <QString>
#include <QDebug>
#include <QDateTime>
using namespace std;
using namespace cv;

class VideoPlayThread:public QThread
{
    Q_OBJECT
public:
    static VideoPlayThread* videoPlayThread_ins; //静态视频播放线程实例
    static VideoPlayThread* getInstance();//获取实例

    //总帧数
    int getTotalPages() const;
    void setTotalPages(int value);

    //视频路径
    String getVideoPath() const;
    void setVideoPath(const String &value);

    //当前帧
    int getCurrentPage() const;
    void setCurrentPage(int value);

    //线程是否在播放视频
    bool getIsRun() const;
    void setIsRun(bool value);

    //是否在录制
    bool getIsRecord() const;
    void setIsRecord(bool value);

    void initVideo();

    void pauseThread();//暂停
    void resumeThread();//继续
    void overThread();//结束

    int getSleepMs() const;
    void setSleepMs(int value);

    void setIsOver(bool value);

private:
    VideoPlayThread();
    VideoCapture cap;//视频捕获对象
    VideoWriter writer;//写视频对象
    String videoPath;//视频路径
    Mat frame;//当前帧
    int totalPages;//视频总帧数
    int currentPage;//视频播放的当前帧数位置
    int recordNum;//录制的帧数
    int FPS;//帧率
    int frame_width;//帧宽
    int fram_height;//帧高
    bool isRun;//控制暂停
    bool isOver;//控制视频结束
    bool isRecord;//控制什么时候开始/结束录制
    int sleepMs;//播放时候的帧率
protected:
    void run();
signals:
    void send2UI(int current,Mat frame);
    void videoOver();
};

#endif // VIDEOPLAYTHREAD_H
