#include "videorecorditemwidget.h"
#include "ui_videorecorditemwidget.h"



VideoRecordItemWidget::VideoRecordItemWidget(QString coverPath, QString videoPath,int currentFrame,int frameNum,QString videoName,QWidget *parent):
    QWidget(parent),
    ui(new Ui::VideoRecordItemWidget)
{
    this->coverPath=coverPath;
    this->videoPath=videoPath;

    this->videoName=videoName;

    this->currentFrame=currentFrame;
    this->frameNum=frameNum;
    ui->setupUi(this);


    this->ui->time_label->setText(videoName);//用文件名来设置
    float percent=this->currentFrame/this->frameNum;
    char p[10];
    sprintf(p,"%.02f",percent*100);
    qDebug()<<"百分比:"<<percent;
    this->ui->percentNum_label->setText(QString("%1%").arg(p));
    this->ui->cover_label->setPixmap(QPixmap(this->coverPath));
    if(this->currentFrame==this->frameNum)
    {
        this->currentFrame=0;
    }
}

VideoRecordItemWidget::~VideoRecordItemWidget()
{
    delete ui;
}

void VideoRecordItemWidget::on_pushButton_clicked()
{
    emit sendVideo2Main(this->videoPath,this->currentFrame,videoName);
}


QString VideoRecordItemWidget::getVideoPath() const
{
    return videoPath;
}

void VideoRecordItemWidget::setVideoPath(const QString &value)
{
    videoPath = value;
}

void VideoRecordItemWidget::ChangeCover()
{
    this->ui->cover_label->setPixmap(QPixmap(this->coverPath));
}

QPushButton *VideoRecordItemWidget::getButton()
{
    return this->ui->pushButton;
}

QString VideoRecordItemWidget::getCoverPath() const
{
    return coverPath;
}

void VideoRecordItemWidget::setCoverPath(const QString &value)
{
    coverPath = value;
}

