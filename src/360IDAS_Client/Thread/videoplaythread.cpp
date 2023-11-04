#include "videoplaythread.h"

VideoPlayThread* VideoPlayThread::videoPlayThread_ins=nullptr;

VideoPlayThread *VideoPlayThread::getInstance()
{
    if(VideoPlayThread::videoPlayThread_ins==nullptr)
    {
        VideoPlayThread::videoPlayThread_ins=new VideoPlayThread();
    }
    return VideoPlayThread::videoPlayThread_ins;
}

VideoPlayThread::VideoPlayThread():QThread ()
{
    //当前帧
    this->currentPage=0;
    //录制的帧
    this->recordNum=0;
    //运行
    this->isRun=false;
    //结束
    this->isOver=false;
    //录制
    this->isRecord=false;
}

void VideoPlayThread::setIsOver(bool value)
{
    isOver = value;
}

int VideoPlayThread::getSleepMs() const
{
    return sleepMs;
}

void VideoPlayThread::setSleepMs(int value)
{
    sleepMs = value;
}

int VideoPlayThread::getTotalPages() const
{
    return totalPages;
}

void VideoPlayThread::setTotalPages(int value)
{
    totalPages = value;
}

void VideoPlayThread::run()
{
    //判断播放线程是否已经结束
    while(this->isOver==false)
    {
        //视频是否在播放还是暂停
        if(this->isRun==true)
        {
            //读到一帧
            if(cap.read(frame))
            {
                this->currentPage++;//当前帧+1
                cvtColor(frame,frame,CV_BGR2RGB);
                emit send2UI(this->currentPage,frame);
                if(this->isRecord==true)
                {
                    cvtColor(frame,frame,CV_BGR2RGB);
                    //录制300帧
                    if(this->recordNum<300)
                    {
                        this->writer.write(frame);
                        this->recordNum++;
                        qDebug()<<"Record recordNum = "<<recordNum;
                    }
                    else //帧数足够
                    {
                        //录制保存
                        this->writer.release();
                        //释放置零
                        this->recordNum=0;
                        this->isRecord=false;
                    }
                }
                else {
                    this->writer.release();
                    this->recordNum=0;
                }
                if(this->currentPage==this->totalPages)
                {
                    qDebug()<<"视频播放结束";
                    this->setIsRun(false);
                    emit videoOver();
                }
                msleep(this->sleepMs);
            }
            else
            {

            }
        }
    }
    cap.release();
    qDebug()<<"thread over";
}

bool VideoPlayThread::getIsRecord() const
{
    return isRecord;
}

void VideoPlayThread::setIsRecord(bool value)
{
    isRecord = value;
    //开始录制
    if(this->isRecord==true)
    {
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString filename = "./video/";
        filename += current_date_time.toString("yyyy-MM-dd-hh-mm-ss");
        filename += ".avi";
        qDebug()<<"filename = "<< filename;
        this->writer.open(filename.toStdString(),//录制后保存的视频文件名
                          VideoWriter::fourcc('M','J','P','G'),    //编码类型
                          25,//帧率
                          Size(this->frame_width,this->fram_height),//尺寸大小
                          true);//true-彩色格式 false-灰度图
    }
}

void VideoPlayThread::initVideo()
{
    if(this->cap.open(this->getVideoPath()))
    {
        qDebug()<<"Video is opend!";
        //获取视频总帧数
        this->totalPages=cap.get(CV_CAP_PROP_FRAME_COUNT);
        qDebug()<<"totalPages = "<<this->totalPages;
        //帧宽
        this->frame_width=cap.get(CV_CAP_PROP_FRAME_WIDTH);
        qDebug()<<"frame_width = "<<this->frame_width;
        //帧高
        this->fram_height=cap.get(CV_CAP_PROP_FRAME_HEIGHT);
        qDebug()<<"frame_height = "<<this->fram_height;
        //帧率
        this->FPS=cap.get(CV_CAP_PROP_FPS);
        qDebug()<<"FPS = "<<this->FPS;
    }
}

void VideoPlayThread::pauseThread()
{
    qDebug()<<"Video play thread pause";
    if(QThread::isRunning()&&this->isRun==true)
    {
        this->isRun=false;
    }
}

void VideoPlayThread::resumeThread()
{
    qDebug()<<"Video Play thread resume.";
    if(QThread::isRunning()&&this->isRun==false)
    {
        this->isRun=true;
    }
}

void VideoPlayThread::overThread()
{
    qDebug()<<"Thread over";
    if(QThread::isRunning()&&this->isOver==false)
    {
        this->isOver=true;
        QThread::quit();
        QThread::wait();
        QThread::exit();
    }
}

bool VideoPlayThread::getIsRun() const
{
    return isRun;
}

void VideoPlayThread::setIsRun(bool value)
{
    isRun = value;
}

int VideoPlayThread::getCurrentPage() const
{
    return currentPage;
}

void VideoPlayThread::setCurrentPage(int value)
{
    currentPage = value;
    //拖动进度条，跳转播放
    this->cap.set(CV_CAP_PROP_POS_FRAMES,this->currentPage);
}

String VideoPlayThread::getVideoPath() const
{
    return videoPath;
}

void VideoPlayThread::setVideoPath(const String &value)
{
    videoPath = value;
}
