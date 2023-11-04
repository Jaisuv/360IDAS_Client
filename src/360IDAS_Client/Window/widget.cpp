#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //获取屏幕的宽度和高度
    int screenWidth=QApplication::desktop()->width();
    int screenHeight=QApplication::desktop()->height();
    //计算坐标，移动到屏幕中间
    int x=(screenWidth-this->width())/2;
    int y=(screenHeight-this->height())/2;
    this->move(x,y);
    ui->setupUi(this);
    //隐藏边框和背景
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    this->setVideo("./source/OP.mp4");
    this->OPthread->start();
    this->OPthread->setIsRun(true);
    qDebug()<<"开始播放";
    this->setWin=new CSettingInit();
    connect(this->OPthread,SIGNAL(videoOver()),this,SLOT(switchWIn()));
}

Widget::~Widget()
{
    disconnect(this->OPthread,SIGNAL(send2UI(int,Mat)),this,SLOT(ChangeData(int,Mat)));
    delete ui;
}

void Widget::setVideo(String path)
{
    //播放线程初始化，指定播放的视频
    this->OPthread=VideoPlayThread::getInstance();
    this->OPthread->setVideoPath(path);
    this->OPthread->initVideo();
    this->OPthread->setSleepMs(0);
    connect(this->OPthread,SIGNAL(send2UI(int,Mat)),this,SLOT(ChangeData(int,Mat)),Qt::BlockingQueuedConnection);
}

void Widget::paintEvent(QPaintEvent *e)
{
    this->ui->label->setPixmap(QPixmap::fromImage(this->Img));
}

void Widget::ChangeData(int current,Mat frame)
{
    //把frame Mat对象转化成QImage
    this->Img=QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
    //图片大小适应QLable的比例
    this->Img=this->Img.scaled(this->ui->label->size());

    this->update();//更新页面
}

//视频播放结束，线程发送信号通知界面，隐藏开机动画界面，设置界面显示
void Widget::switchWIn()
{
    this->hide();
    this->setWin->show();
}
