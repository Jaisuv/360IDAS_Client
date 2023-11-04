#include "birdviewsidethread.h"

BirdViewSideThread* BirdViewSideThread::BirdViewSideThread_ins=nullptr;

BirdViewSideThread *BirdViewSideThread::getInstance()
{
    if(BirdViewSideThread::BirdViewSideThread_ins==nullptr)
    {
        BirdViewSideThread::BirdViewSideThread_ins=new BirdViewSideThread;
    }
    return BirdViewSideThread::BirdViewSideThread_ins;
}

BirdViewSideThread::BirdViewSideThread()
{
    this->isRun=false;
    this->isOver=false;
    this->videoPath.clear();
    this->currentFrameNum=0;
}

bool BirdViewSideThread::getIsOver() const
{
    return isOver;
}

void BirdViewSideThread::setIsOver(bool value)
{
    isOver = value;
}

void BirdViewSideThread::setVideoInit(QString path)
{
    this->videoPath=path;
    this->cap.open(this->videoPath.toStdString());
    this->totalFrameNum=this->cap.get(CV_CAP_PROP_FRAME_COUNT);//设置总帧数

    this->fps=this->cap.get(CV_CAP_PROP_FPS);//帧率
    frame=imread(videoPath.toStdString());
}

Mat BirdViewSideThread::CarSideScene(Mat frame)
{
    this->carBg=imread("images/bg.png");//车的背景
    Mat dst=carBg.clone();
    //画面的点
    vector<Point2f> framePoint;
    framePoint.push_back(Point2f(0,0));
    framePoint.push_back(Point2f(frame.cols,0));
    framePoint.push_back(Point2f(frame.cols,frame.rows));
    framePoint.push_back(Point2f(0,frame.rows));
    //车右
    vector<Point2f> carRight;
    carRight.push_back(Point2f(carBg.cols,0));
    carRight.push_back(Point2f(carBg.cols,carBg.rows));
    carRight.push_back(Point2f(253,344));
    carRight.push_back(Point2f(253,147));
    Mat homoR=findHomography(framePoint,carRight,CV_RANSAC);
    //车底
    vector<Point2f> carB;
    carB.push_back(Point2f(carBg.cols,carBg.rows));
    carB.push_back(Point2f(0,carBg.rows));
    carB.push_back(Point2f(147,344));
    carB.push_back(Point2f(253,344));
    Mat homoB=findHomography(framePoint,carB,CV_RANSAC);
    //车左边
    vector<Point2f> carL;
    carL.push_back(Point2f(0,carBg.rows));
    carL.push_back(Point2f(0,0));
    carL.push_back(Point2f(141,147));
    carL.push_back(Point2f(141,344));
    Mat homoL=findHomography(framePoint,carL,CV_RANSAC);
    //车右边
    Point pts[4];
     warpPerspective(frame,dst,homoR,dst.size());
     for (int i=0;i<5;i++)
     {
         pts[i]=carRight[i];
     }
     fillConvexPoly(carBg,pts,4,Scalar(0),CV_AA);
     carBg+=dst;
     //车底
     warpPerspective(frame,dst,homoB,dst.size());
     for (int i=0;i<5;i++)
     {
         pts[i]=carB[i];
     }
     fillConvexPoly(carBg,pts,4,Scalar(0),CV_AA);
     carBg+=dst;
     //车左边
     warpPerspective(frame,dst,homoL,dst.size());
     for (int i=0;i<5;i++)
     {
         pts[i]=carL[i];
     }
     fillConvexPoly(carBg,pts,4,Scalar(0),CV_AA);
     carBg+=dst;
     //imshow("carbg",carBg);
     return carBg;
}

void BirdViewSideThread::restartThread()
{
    this->isRun=false;
    msleep(30);
    this->cap.set(CV_CAP_PROP_POS_FRAMES,1);//从头开始重现播放
    this->isRun=true;
}


void BirdViewSideThread::run()
{
    while (!isOver)
    {
        while(isRun)
        {
            //qDebug()<<"打印";

//            if(this->videoPath.isEmpty())//必须set1非空的视频路径
//            {
//                continue;
//            }
            if(this->cap.read(this->frame))
            {
                this->currentFrameNum++;
                this->CarSideScene(this->frame);
                qDebug()<<""<<currentFrameNum;
                //qDebug()<<totalFrameNum;
                emit send2CarSide(this->carBg);
                //imshow("carside",this->frame);

            }
            if(this->currentFrameNum>400)
            {
                this->currentFrameNum=1;
                //this->isRun=false;
                qDebug()<<"重启";
                //emit restart();
                this->cap.set(CV_CAP_PROP_POS_FRAMES,1);//从头开始重现播放

            }
            msleep(30);
        }
    }
}

bool BirdViewSideThread::getIsRun() const
{
    return isRun;
}

void BirdViewSideThread::setIsRun(bool value)
{
    isRun = value;
}
