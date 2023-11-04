#include "camerathread.h"

CameraThread* CameraThread::cameraThread_ins=nullptr;

CameraThread *CameraThread::getInstance()
{
    if (CameraThread::cameraThread_ins==nullptr)
    {
        CameraThread::cameraThread_ins=new CameraThread();
    }
    return CameraThread::cameraThread_ins;
}

void CameraThread::detecCarDraw(Mat &frame, double scale)
{
    //灰度处理
    Mat gray;
    cvtColor(frame,gray,CV_BGR2GRAY);
    //级联分类器处理得很慢需要把灰度再进行压缩,再压缩到一半
    Mat smalling(cvRound(frame.rows/scale),cvRound(frame.cols/scale),CV_8UC1);
    resize(gray,smalling,smalling.size(),0,0,INTER_LINEAR);//采用线性压缩
    //比较平滑的，黑白分明，线条更加的清晰
    equalizeHist(smalling,smalling);
    vector<Rect>cars;
    carCas.detectMultiScale(smalling,cars,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
    //绘制矩形
    vector<Rect>::const_iterator iter;
    for (iter=cars.begin();iter!=cars.end();iter++) {
        rectangle(frame,
            CvPoint(cvRound(iter->x*scale),cvRound(iter->y*scale)),
            CvPoint(cvRound((iter->x+iter->width)*scale),cvRound((iter->y+iter->height)*scale)),
            Scalar(0,255,0),5,8);
    }
}

CameraThread::CameraThread():QThread ()
{
    this->lightCheck=new LightCheck();      //创建红绿灯识别类

#ifndef CAMERA
    this->cap.open("/root/daoche2.mp4");
#else
    this->cap.open(0);      //打开摄像头
#endif
    this->frame_width=this->cap.get(CV_CAP_PROP_FRAME_WIDTH);
    this->frame_height=this->cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    this->carCas.load("source/cars.xml");
    this->isRun=false;
    this->isRecord=false;
    this->frame_num=0;
    this->recordFPS=30;
    this->first=true;

    head.type=4;
    head.length=sizeof (VIDEOT);

    videoInfo.equipment_id=8080;

    this->wt=WriteThread::getInstance();
    this->crc=CRCcheck::getInstance();
    this->isOver=false;
    //车周图象
    //this->CarsideMat=imread("source/waterMarkLogo.png");
    CarsideMat=imread("images/bg.png");//车的背景
}

void CameraThread::setIsOver(bool value)
{
    isOver = value;
}

void CameraThread::CarSideScene(Mat sideMat)
{
    //imshow("tmp",sideMat);
    this->CarsideMat=sideMat.clone();
}

int CameraThread::getModeType() const
{
    return modeType;
}

void CameraThread::setModeType(int value)
{
    modeType = value;
}

//倒车距离检测
void CameraThread::obstacleRanging(Mat frame)
{
    Mat grayImage;
    Mat binaryImage;
    Mat reverseBinaryImage;
    Mat imgROI;
    Mat drawing;
    Mat mask = Mat::zeros(frame.size().height,frame.size().width,CV_8UC1); // 八位单通道
     //梯形ROI
    //vector(向量): C++中的一种数据结构,确切的说是一个类.它相当于一个动态的数组  相当于存放点的坐标的容器
    vector<vector<Point>> contour;  //vector<vector<Point>>。外层vector的size代表了图像中轮廓的个数，里面vector的size代表了轮廓上点的个数。
    vector<Point> pts;

#ifndef CAMERA
    pts.push_back(Point(140, 400));
    pts.push_back(Point(400, 400));
    pts.push_back(Point(540, 700));
    pts.push_back(Point(0, 700));
#else
    pts.push_back(Point(140,this->frame_height-150));
    pts.push_back(Point(this->frame_width-140,this->frame_height-150));
    pts.push_back(Point(this->frame_width,this->frame_height));
    pts.push_back(Point(0,this->frame_height));
#endif
    //push_back   在数组的最后添加一个数据  即将四个坐标点依次存入数组
    contour.push_back(pts);
    drawContours(mask, contour, 0, Scalar::all(255), -1);
    frame.copyTo(imgROI, mask); // 将 frame 的位于 mask 中的部分，拷贝到 imgROI 中
    //去噪
    //blur(imgROI,grayImage,Size(3, 3));
    medianBlur(imgROI, grayImage, 3);
    //灰度处理
    cvtColor(grayImage, grayImage, CV_BGR2GRAY);
    //二值化
    threshold(grayImage, binaryImage, 90, 255, CV_THRESH_BINARY); //转换为二值图

    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
    morphologyEx(binaryImage, binaryImage, MORPH_OPEN, element);

    Mat element1 = getStructuringElement(MORPH_RECT, Size(2, 2));
    morphologyEx(binaryImage, binaryImage, MORPH_GRADIENT, element1);

    vector< vector< Point> > contours;
    findContours(binaryImage, contours, CV_RETR_EXTERNAL, CV_RETR_TREE);
    vector<vector<Point> >::iterator itc = contours.begin();
    while (itc != contours.end())
    {
        if (itc->size() < 100)
        {
            itc = contours.erase(itc);  //删除轮廓
        }
        else
        {
            ++itc;
        }
    }
    drawContours(binaryImage, contours, -1, Scalar(255), 1);
    //计算轮廓的面积
    for (int i = 0; i < (int)contours.size(); i++)
    {
        double g_dConArea = contourArea(contours[i], false);
        if (g_dConArea < 100000)//报警
        {
            double distance;
            distance = g_dConArea / 10000;
            if(distance < 1.5)
            {
                cv::putText(frame, "WARRING", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 0, 255), 2, 8, 0);
//                QMessageBox::information(nullptr,"倒车提醒","<font color='red' size='7'>距离过近!</font>");//会阻塞程序往下运行，导致程序异常结束
            }
        }
    }
}

void CameraThread::reverseLine(Mat frame)
{
#ifdef CAMERA
    //left
    cv::line(frame,Point(0,this->frame_height),Point(50,this->frame_height-100),Scalar(0,0,255),2,CV_AA);
    cv::line(frame,Point(50,this->frame_height-100),Point(100,this->frame_height-200),Scalar(0,255,255),2,CV_AA);
    cv::line(frame,Point(100,this->frame_height-200),Point(140,this->frame_height-300),Scalar(0,255,0),2,CV_AA);
    //right
    cv::line(frame,Point(this->frame_width,this->frame_height),Point(this->frame_width-50,this->frame_height-100),Scalar(0,0,255),2,CV_AA);
    cv::line(frame,Point(this->frame_width-50,this->frame_height-100),Point(this->frame_width-100,this->frame_height-200),Scalar(0,255,255),2,CV_AA);
    cv::line(frame,Point(this->frame_width-100,this->frame_height-200),Point(this->frame_width-140,this->frame_height-300),Scalar(0,255,0),2,CV_AA);
#else
    //left
    cv::line(frame,Point(0,700),Point(50,600),Scalar(0,0,255),3,CV_AA);//red
    cv::line(frame,Point(50,600),Point(100,500),Scalar(0,255,255),3,CV_AA);//yellow
    cv::line(frame,Point(100,500),Point(140,400),Scalar(0,255,0),3,CV_AA);//green
    //rignt
    cv::line(frame,Point(540,700),Point(490,600),Scalar(0,0,255),3,CV_AA);
    cv::line(frame,Point(490,600),Point(440,500),Scalar(0,255,255),3,CV_AA);//yellow
    cv::line(frame,Point(440,500),Point(400,400),Scalar(0,255,0),3,CV_AA);//green
#endif
}

void CameraThread::birdEyeView(Mat &currentFrame)
{


    //this->carBg=imread("images/bg.png");//车的背景
    Mat dst=this->CarsideMat.clone();
    //画面的点
    vector<Point2f> framePoint;
    framePoint.push_back(Point2f(0,0));
    framePoint.push_back(Point2f(currentFrame.cols,0));
    framePoint.push_back(Point2f(currentFrame.cols,currentFrame.rows));
    framePoint.push_back(Point2f(0,currentFrame.rows));
    //车前方
    vector<Point2f> carTop;
    carTop.push_back(Point2f(0,0));
    carTop.push_back(Point2f(CarsideMat.cols,0));
    carTop.push_back(Point2f(253,147));
    carTop.push_back(Point2f(141,147));
    Mat homo=findHomography(framePoint,carTop,CV_RANSAC);
    //车前
    warpPerspective(currentFrame,dst,homo,dst.size());
    Point pts[4];
    for (int i=0;i<5;i++)
    {
        pts[i]=carTop[i];
    }
    fillConvexPoly(CarsideMat,pts,4,Scalar(0),CV_AA);
    CarsideMat+=dst;
    //imshow("CarsideMat",CarsideMat);
}

void CameraThread::setUid(int value)
{
    this->videoInfo.user_id=value;
}

bool CameraThread::getIsRecord() const
{
    return isRecord;
}

void CameraThread::setIsRecord(bool value)
{
    isRecord = value;
    if(isRecord)
    {
        QDateTime current_data_time=QDateTime::currentDateTime();

        QString videoFileName="./Driving Video/";   //实时视频的
        videoFileName += current_data_time.toString("yyyy-MM-dd_hh_mm_ss");
        videoFileName += ".avi";

        QString videoName=current_data_time.toString("yyyy-MM-dd_hh_mm_ss");
        videoCoverName="./VideoCover/";
        videoCoverName+=videoName;
        videoCoverName+="Cover.png";
        videoName+=".avi";


        qDebug()<<"行车模式录制的视频文件名:"<<videoFileName;
        this->writer.open(videoFileName.toStdString(),  //视频文件名
                          VideoWriter::fourcc('M','J','P','G'),//编码类型
                          this->recordFPS,//帧率 300帧就是10秒
                          Size(this->frame_width,this->frame_height),//尺寸大小
                          true);//彩色格式为true 灰度为false

        strcpy(videoInfo.video_name,videoName.toUtf8());
        qDebug()<<videoName;

        strcpy(videoInfo.video_path,videoFileName.toUtf8());
        strcpy(videoInfo.video_cover,videoCoverName.toUtf8());

    }
}

void CameraThread::addWaterMark(Mat &frame)
{
    //起始位置的点
    cv::Point p = cv::Point(frame.cols-120,frame.rows  - 30);
    cv::putText(frame, "Chen Ji An", p, cv::FONT_HERSHEY_COMPLEX, 0.6, cv::Scalar(255, 0, 0),2,8,false);
}

void CameraThread::addWaterMark2(Mat &frame)
{
    Mat logo_rgba=imread("source/waterMarkLogo.png",IMREAD_UNCHANGED);//獲取logo的圖片
    resize(logo_rgba,logo_rgba,Size(),0.1,0.1);
    Mat logo_rgb(logo_rgba.rows,logo_rgba.cols,CV_8UC3);
    Mat logo_alpha(logo_rgba.rows,logo_rgba.cols,CV_8UC1);

    std::vector<cv::Mat> rgba_channels;
    cv::split(logo_rgba, rgba_channels);
    std::vector<cv::Mat> rgb_channels(rgba_channels.begin(), rgba_channels.end()-1);
    cv::merge(rgb_channels, logo_rgb);
    logo_alpha = rgba_channels.back();
    Mat img1,img2,img3;

    //如果logo圖片太大，超出了frame的範圍，程式會異常結束，因此要對logo的圖片進行縮放
    if (frame.rows >= logo_rgba.rows && frame.cols >= logo_rgba.cols) {
        cv::Mat roi = frame(cv::Rect(frame.cols - logo_rgba.cols, 0, logo_rgba.cols, logo_rgba.rows));
        cv::bitwise_and(roi, roi, img1, ~logo_alpha);
        cv::bitwise_and(logo_rgb, logo_rgb, img2, logo_alpha);
        cv::add(img1, img2, img3);
        img3.copyTo(roi);
    }
}

bool CameraThread::getIsRun() const
{
    return isRun;
}

void CameraThread::setIsRun(bool value)
{
    isRun = value;
}

void CameraThread::run()
{   
    while(!isOver)
    {
        while (cap.read(this->frame))
        {
            if(this->isRun==false)//false不显示，也不录制
            {
                continue;
            }

            Mat frame1=this->frame.clone();
            if(this->modeType==1)
            {
                detecCarDraw(frame1,2);
                this->lightCheck->LightCheckFunc(frame1);
                this->addWaterMark2(frame1);
                emit send2UI(frame1);
            }
            else if (this->modeType==2)//倒车
            {
                this->reverseLine(frame1);
                this->obstacleRanging(frame1);
                this->addWaterMark2(frame1);
    #ifndef CAMERA
                msleep(30);//视频延时间３０ms
    #endif
                emit send2ReverPage(frame1);
            }
            else if (this->modeType==3)//鸟瞰
            {

                birdEyeView(frame1);
                emit send2BirdEye(CarsideMat,frame1);
            }
            if(this->frame_num==0)
            {
                this->setIsRecord(true);
            }
            //录制
            if(this->isRecord)
            {
                if(this->frame_num==0)
                {
                    //视频首帧作为封面
    //                Mat frame2=this->frame.clone();
//                    qDebug()<<videoCoverName;
                    cv::imwrite(videoCoverName.toStdString(),frame1);
                }
                //300帧
                if(this->frame_num<300)
                {
                    this->writer.write(frame1);
                    this->frame_num++;
//                    qDebug()<<"record num = "<<this->frame_num;
                }
                else
                {
                    //录制保存
                    this->setIsRecord(false);
                    this->writer.release();
                    this->videoInfo.framenum=300;
                    this->head.CRCnum=crc->calculateCRC((char*)&videoInfo,sizeof (videoInfo));
                    memcpy(data,&head,sizeof (HEAD));
                    memcpy(data+sizeof (HEAD),&videoInfo,sizeof (videoInfo));
                    this->wt->setData(data,sizeof (HEAD)+sizeof (VIDEOT));
                    this->frame_num=0;
                }
            }
        }
    }
}


