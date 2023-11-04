#include "videoplayerwidget.h"
#include "ui_videoplayerwidget.h"

VideoPlayerWidget::VideoPlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoPlayerWidget)
{
    qRegisterMetaType<queue<IMAGET>>("queue<IMAGET>");
    ui->setupUi(this);
    ui->showVideo->setPixmap(QPixmap(QString::fromUtf8("VideoCover/cover1.png")));
    ui->showVideo->setScaledContents(true);
    //构造此时槽函数还没有将视频路径设置进来
    this->videoPlayThread=VideoPlayThread::getInstance();
    this->sc=SocketConnect::getInstance();

    memset(&this->imageOK,0,sizeof (IMAGEOKT));

    //获得写线程
    this->wt=WriteThread::getInstance();
    //读线程
    rt=ReadThread::getInstance();
    connect(this->rt,SIGNAL(image_Upload_Result(IMAGEBACKT*)),this,SLOT(imageUploadResult(IMAGEBACKT*)));

    //创建出文件拆分线程
    this->spt=new FileSplitThread();    //文件拆分线程开起来，一直运行
    this->spt->Ftype=2;
    this->spt->start();

    this->videoPlayThread->start();

    this->videoRecordhead.type=6;
    this->videoRecordhead.length=sizeof (VIDEOT);
    this->crc=CRCcheck::getInstance();
    videoEnd=false;
}

VideoPlayerWidget::~VideoPlayerWidget()
{
    delete ui;
}

QString VideoPlayerWidget::getVideoPath() const
{
    return videoPath;
}

void VideoPlayerWidget::setVideoPath(const QString &value)
{
    videoPath = value;
}

void VideoPlayerWidget::videoInitial(QString path)
{
    this->videoPlayThread->setVideoPath(path.toStdString());
    this->videoPlayThread->initVideo();
    this->videoPlayThread->setSleepMs(40);

    //进度条初始化
    this->ui->horizontalSlider->setMinimum(0);
    this->ui->horizontalSlider->setMaximum(this->videoPlayThread->getTotalPages());
    this->ui->horizontalSlider->setRange(0,this->videoPlayThread->getTotalPages());
    this->ui->horizontalSlider->setSingleStep(1);
    this->ui->horizontalSlider->setValue(0);
    //计数初始化
    this->ui->label_2->setText(QString::number(this->videoPlayThread->getCurrentPage()));//当前帧
    this->ui->label_4->setText(QString::number(this->videoPlayThread->getTotalPages()));//总帧数

    int sec = this->videoPlayThread->getTotalPages() / 30;//总秒数
    int min = sec / 60;//分钟
    sec -= min * 60;
    char time[20]={0};
    sprintf(time, "%d：%02d", min, sec); //拼合时间

    this->ui->label_6->setText(QString("%1").arg(time));

    connect(this->videoPlayThread,SIGNAL(send2UI(int,Mat)),this,SLOT(ChangeData(int,Mat)),Qt::BlockingQueuedConnection);
    connect(this->videoPlayThread,SIGNAL(videoOver()),this,SLOT(playEndSlot()),Qt::BlockingQueuedConnection);

}

void VideoPlayerWidget::openVideo(int frame)
{
    //在这里才会获取到真正的视频地址
    videoInitial(this->videoPath);
    this->videoPlayThread->setCurrentPage(frame);
    this->videoPlayThread->setIsRun(true);
}

void VideoPlayerWidget::on_playBtn_clicked()
{
    qDebug()<<"暂停/播放按钮";
    if(this->videoPlayThread->getIsRun()==false)//没有在播放
    {
        //恢复播放
        if(videoEnd)
        {
            this->videoPlayThread->setCurrentPage(0);
        }
        this->videoPlayThread->resumeThread();
        this->ui->playBtn->setText("暂停");
    }
    else {
        //暂停播放
        this->videoPlayThread->pauseThread();
        this->ui->playBtn->setText("播放");
    }
}

void VideoPlayerWidget::ChangeData(int current, Mat frame)
{   
    this->Img=QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
    this->Img=this->Img.scaled(this->ui->showVideo->size());

    this->ui->label_2->setText(QString::number(current));
    this->ui->horizontalSlider->setValue(current);
    this->update();
}

void VideoPlayerWidget::paintEvent(QPaintEvent *e)
{
    this->ui->showVideo->setPixmap(QPixmap::fromImage(this->Img));
}

void VideoPlayerWidget::on_horizontalSlider_sliderPressed()
{
    this->videoPlayThread->pauseThread();
}

void VideoPlayerWidget::on_horizontalSlider_sliderReleased()
{
    this->videoPlayThread->setCurrentPage(this->ui->horizontalSlider->value());
    this->videoPlayThread->resumeThread();
}

//手动截图上传
void VideoPlayerWidget::on_captureBtn_clicked()
{
    //ui->captureBtn->setEnabled(false);
    //ui->exitBtn->setEnabled(false);
    this->spt->userId=this->userId;
    this->spt->equipmentId=this->equipmentId;
    //拍照的存储路径
    QDateTime datetime;
    QString timestr=datetime.currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    qDebug()<<timestr;
    QString pSavePath("./screenshot manual/");
    pSavePath+=timestr;
    pSavePath+=".jpg";
    qDebug()<<"手动截图的图片路径是:"<<pSavePath;
    this->Img.save(pSavePath);
    //    imwrite(pSavePath.toStdString(),this->capSave);
    //    qDebug()<<"自动截图的宽:"<<this->Img.width()<<"高:"<<this->Img.height();
    //截图的图片路径存入队列
    this->spt->enqueToQueue(pSavePath,1);
    //拆分线程把设置路径开启,并设置开启
    //this->spt->setFilePath(pSavePath);
    this->spt->setIsRun(true);
    //ui->captureBtn->setEnabled(true);

}

void VideoPlayerWidget::imageUploadResult(IMAGEBACKT* imagBack)
{
    if(imagBack->flag==0)
    {
        if(this->spt->getFirstType()==0)
        {
           qDebug()<<"截图上传结果**********************************************";
        }
        else {
            QMessageBox::information(nullptr,"截图上传结果","<font size='6'>截图上传成功!</font>");
        }
        this->spt->dequeLastest();//出队
         //QThread::msleep(100);
        //this->ui->exitBtn->setEnabled(true);
        this->spt->setCanContinue(true);
    }
    else if(imagBack->flag==1)
    {
        this->spt->imageBackDeal(imagBack->flag,"",imagBack->img_nums,imagBack->user_id);

    }
}

void VideoPlayerWidget::on_exitBtn_clicked()
{
    if(this->spt->ifpicPathQueueEmpty()==true)//队列若为空
    {
        this->videoPlayThread->setIsRun(false);
        this->videoRecord.user_id=this->userId;
        this->videoRecord.equipment_id=this->equipmentId;
        strcpy(this->videoRecord.video_name,this->videoName.toUtf8());
        if(this->videoEnd)
        {
            this->videoRecord.currentframe=this->videoPlayThread->getTotalPages();
        }
        else
        {
            this->videoRecord.currentframe=this->videoPlayThread->getCurrentPage();
        }

        this->videoRecordhead.CRCnum=this->crc->calculateCRC((char *)&this->videoRecord,sizeof (this->videoRecord));
        bzero(this->buf,sizeof (buf));
        memcpy(this->buf,&this->videoRecordhead,sizeof (HEAD));
        memcpy(this->buf+sizeof (HEAD),&this->videoRecord,sizeof (this->videoRecord));
        this->wt->setData(this->buf,sizeof (HEAD)+sizeof (VIDEOT));
        ui->rationcomboBox->setCurrentIndex(1);
        this->videoPlayThread->setSleepMs(40);
        emit toVideoList();
    }
    else {
        QMessageBox::information(this,"退出失败","请等待图片发送完成．");
    }
}

void VideoPlayerWidget::playEndSlot()
{
    ui->playBtn->setText("播放");
    ui->horizontalSlider->setValue(0);
    ui->label_2->setText("00");
    this->videoEnd=true;
}

bool VideoPlayerWidget::isEmpty()
{
    return  this->spt->ifpicPathQueueEmpty();
}

void VideoPlayerWidget::endAllThread()
{
    this->spt->setIsOver(true);
    this->spt->terminate();
    this->videoPlayThread->setIsOver(true);
}

void VideoPlayerWidget::setVideoName(const QString &value)
{
    videoName = value;
}

void VideoPlayerWidget::addPath(QString path,int type)
{
    this->spt->userId=this->userId;
    this->spt->equipmentId=this->equipmentId;
    this->spt->enqueToQueue(path,type);
    qDebug()<<"向列表中添加"<<path;
    //this->spt->setIsRun(true);
}

int VideoPlayerWidget::getVideoWidth()
{
    return ui->showVideo->width();
}

int VideoPlayerWidget::getVideoHeight()
{
    return ui->showVideo->height();
}

void VideoPlayerWidget::on_rationcomboBox_currentIndexChanged(int index)
{
    if(index==0)//0.5x
    {
        this->videoPlayThread->setSleepMs(80);
    }
    else if (index==1)//1.0x
    {
        this->videoPlayThread->setSleepMs(40);
    }
    else if (index==2)//2.0x
    {
        this->videoPlayThread->setSleepMs(20);
    }
}
