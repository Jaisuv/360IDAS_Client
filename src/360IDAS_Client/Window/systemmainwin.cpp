//系统主界面
#include "systemmainwin.h"
#include "ui_systemmainwin.h"

SystemMainWin::SystemMainWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemMainWin)
{
    qRegisterMetaType<Mat>("Mat");
//    qRegisterMetaType<SEARCHREST>("SEARCHREST");
    //获取屏幕的宽度和高度
    int screenWidth=QApplication::desktop()->width();
    int screenHeight=QApplication::desktop()->height();
    //计算坐标，移动到屏幕中间
    int x=(screenWidth-this->width())/2;
    int y=(screenHeight-this->height())/2;
    this->move(x,y);
    //窗口设置固定大小
//    this->setFixedSize(950,450);
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //设备ID
    this->equipmentID=8080;
    //CRC验证码类
    this->CRC=CRCcheck::getInstance();
    //摄像头线程
    this->cameThd=CameraThread::getInstance();
    connect(cameThd,SIGNAL(send2UI(Mat)),this,SLOT(DrivingVideo(Mat)));//行车模式，实时视频
    connect(cameThd,SIGNAL(send2ReverPage(Mat)),this,SLOT(ReverseVideoShow(Mat)));//倒车模式,实时视频
    connect(cameThd,SIGNAL(send2BirdEye(Mat,Mat)),this,SLOT(BirdEyeVideoRT(Mat,Mat)));//鸟瞰模式实时视频
    this->cameThd->start();
    this->cameThd->setIsRun(true);
    //开启定时器
    this->timer1=new QTimer();
    this->timer1->setInterval(15000);//设置计时间隔为15s
    this->timer1->start();
    connect(this->timer1,SIGNAL(timeout()),this,SLOT(autoCapture()));
    //第一次界面出来显示第一页
    this->cameThd->setModeType(1);//默认使用行车模式
    //默认进入行车模式
    this->ui->stackedWidget->setCurrentIndex(1);
    //创建读线程
    this->rt=ReadThread::getInstance();
    connect(this->rt,SIGNAL(videoSearchResSign(SEARCHREST*)),this,SLOT(videoResearchSlot(SEARCHREST*)));
    connect(this->rt,SIGNAL(imageSearchResSig(IMAGESERCHREST*)),this,SLOT(imageResearchSlot(IMAGESERCHREST*)));
    connect(this->rt,SIGNAL(LogoutSignal(int)),this,SLOT(logoutSlot(int)));
    //创建写线程
    this->wt=WriteThread::getInstance();
    //视频列表
    this->isLoading=true;//滚轮不能继续出发查询
    this->verticalScrollBar1=ui->video_listWidget->verticalScrollBar();
    this->videoNum=0;
    //包头
    this->head.type=8;
    this->head.length=sizeof (SEARCHT);
    this->videoListPage=1;
    this->picListPage=1;
    //奇数类表加载到奇数
    this->filledItem=new QListWidgetItem;
    this->filledItem->setSizeHint(QSize(412,235));
    this->filledItem->setIcon(QIcon("./VideoCover/finall.png"));
    //视频播放界面
    this->player=new VideoPlayerWidget(this);
    ui->stackedWidget->addWidget(this->player);//索引为6
    this->player->equipmentId=this->equipmentID;
    connect(this->player,SIGNAL(toVideoList()),this,SLOT(return2VideoList()));
    //特征图片查询请求头
    this->picHead.type=13;
    this->picHead.length=sizeof (SEARCHT);
    this->picListSearch.equipment_id=this->equipmentID;
    this->picNum=0;
    this->isPicLoading=true;//图片列表不能继续出发滚轮查询
    this->ListMode=0;
    this->verticalScrollBar2=ui->pic_listWidget->verticalScrollBar();
    this->bgPicWin=new BigPicWidget(this);
    ui->stackedWidget->addWidget(this->bgPicWin);
    connect(this->bgPicWin,SIGNAL(back2PicList()),this,SLOT(return2PIcList()));

    this->capW=this->player->getVideoWidth();
    this->capH=this->player->getVideoHeight();

    this->logoutHead.type=15;
    this->logoutHead.length=sizeof(BACKMSGT);

    this->bvsThread=BirdViewSideThread::getInstance();
    connect(this->bvsThread,SIGNAL(send2CarSide(Mat)),this->cameThd,SLOT(CarSideScene(Mat)));
    connect(this->bvsThread,SIGNAL(restart()),this,SLOT(restartBirdT()));
    this->bvsThread->setVideoInit("./source/carMove.mp4");
    this->bvsThread->start();

    this->ipAddressInput=new IPAddress(ui->settingPage);
    this->ipAddressInput->move(340,110);

}

SystemMainWin::~SystemMainWin()
{
    delete ui;
    delete this->player;
}

//视频列表界面
void SystemMainWin::on_videoRecordtoolButton_clicked()
{
    this->bvsThread->setIsRun(false);
    //进入视频列表
    this->setListMode(1);
    this->ui->stackedWidget->setCurrentIndex(0);
    this->videoNum=0;
    this->videoListPage=1;
    this->ui->video_listWidget->clear();
    this->VideoSearch();//初始视频信息查询
}

void SystemMainWin::videoResearchSlot(SEARCHREST* videoResearchRes)
{
    this->videoListPage++;
    this->videoNum=videoResearchRes->num;
    if(videoNum==4)
    {
        this->isLoading=false;
    }
    VideoRecordItemWidget *videoItem;
    QListWidgetItem *newItem;
    for(int i=0;i<videoNum;i++)
    {
       videoItem=new VideoRecordItemWidget(videoResearchRes->videoarr[i].video_cover,
                                           videoResearchRes->videoarr[i].video_path,
                                           videoResearchRes->videoarr[i].currentframe,
                                           videoResearchRes->videoarr[i].framenum,
                                           videoResearchRes->videoarr[i].video_name
                                           );
       newItem=new QListWidgetItem;
       newItem->setSizeHint(QSize(412,235));//调整Item的大小
       ui->video_listWidget->addItem(newItem);
       ui->video_listWidget->setItemWidget(newItem,videoItem);
       connect(videoItem,SIGNAL(sendVideo2Main(QString,int,QString)),this,SLOT(playVideo(QString,int,QString)));
    }
    if(videoNum%2!=0)
    {
        ui->video_listWidget->addItem(this->filledItem);
    }
}

void SystemMainWin::on_drivingModetoolButton_clicked()
{
    this->bvsThread->setIsRun(false);
    this->ui->stackedWidget->setCurrentIndex(1);
    this->cameThd->setModeType(1);
}

void SystemMainWin::on_reverseModetoolButton_clicked()
{
    this->bvsThread->setIsRun(false);
    this->ui->stackedWidget->setCurrentIndex(2);
    this->cameThd->setModeType(2);
}

void SystemMainWin::on_birdViewtoolButton_clicked()
{
    this->bvsThread->setIsRun(true);
    this->ui->stackedWidget->setCurrentIndex(3);
    this->cameThd->setModeType(3);
}

void SystemMainWin::on_featureRecordtoolButton_clicked()
{
    this->bvsThread->setIsRun(false);
    this->setListMode(2);
    this->ui->stackedWidget->setCurrentIndex(4);
    this->picNum=0;
    this->picListPage=1;
    this->ui->pic_listWidget->clear();
    this->searchPicture();
}

void SystemMainWin::imageResearchSlot(IMAGESERCHREST *imageSearRes)
{
    this->picListPage++;
    this->picNum=imageSearRes->image_num;
    if(picNum==4)
    {
        this->isPicLoading=false;
    }

    QListWidgetItem * tmp;
    for(int i=0;i<imageSearRes->image_num;i++)
    {
        QString picPath=imageSearRes->image_arr[i].image_path;
        picPath+="/";
        picPath+=imageSearRes->image_arr[i].image_name;//picPath就是图片的完整路径
        tmp=new QListWidgetItem(QIcon(picPath),imageSearRes->image_arr[i].image_name);
        tmp->setSizeHint(QSize(412,235));
        tmp->setData(Qt::UserRole,picPath);
        tmp->setData(Qt::UserRole+1,imageSearRes->image_arr[i].image_name);
        ui->pic_listWidget->addItem(tmp);
    }
    if(imageSearRes->image_num%2!=0)
    {
        ui->pic_listWidget->addItem(filledItem);
    }
}

void SystemMainWin::on_systemSettingtoolButton_clicked()
{
    this->bvsThread->setIsRun(false);
    this->ui->stackedWidget->setCurrentIndex(5);
    QSettings *settingConfig=new QSettings("./systemInit.ini",QSettings::IniFormat);
    this->ipAddressInput->setIP(settingConfig->value("/set/ip").toString());
    ui->port_lineEdit->setText(settingConfig->value("/set/port").toString());
    ui->memoryEdt->setText(settingConfig->value("/set/storage").toString());
    ui->radioButton->setChecked(settingConfig->value("/set/autoDeletion").toBool());
}

//视频点播播放
void SystemMainWin::playVideo(QString path,int frameNum,QString videoName)
{
    ui->birdViewtoolButton->setEnabled(false);
    ui->drivingModetoolButton->setEnabled(false);
    ui->featureRecordtoolButton->setEnabled(false);
    ui->reverseModetoolButton->setEnabled(false);
    ui->systemSettingtoolButton->setEnabled(false);
    ui->videoRecordtoolButton->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(6);
    this->player->userId=this->user_id;
    this->player->setVideoPath(path);
    this->player->setVideoName(videoName);
    qDebug()<<"play videoPath:"<<this->player->getVideoPath();
    this->player->openVideo(frameNum);
}

void SystemMainWin::DrivingVideo(Mat frame)
{
    capframe=frame.clone();
    Mat frameT=frame.clone();
    //需要红蓝转换
    cvtColor(frameT,frameT,CV_BGR2RGB);
    this->drivingImg=QImage(frameT.data,frameT.cols,frameT.rows,QImage::Format_RGB888);
    this->capSaveImg=this->drivingImg.scaled(this->capW,this->capH);
    this->drivingImg=this->drivingImg.scaled(ui->drivingVideo->size());

    ui->drivingVideo->setPixmap(QPixmap::fromImage(drivingImg));
    update();
}

//自动截图
void SystemMainWin::autoCapture()
{
    QDateTime current_date_time;
    QString timeStr=current_date_time.currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString pSavePath("./screenshot auto/");
    pSavePath+=timeStr;
    pSavePath+=".jpg";
    qDebug()<<"自动截图的路径是:"<<pSavePath;
    if(cameThd->getModeType()==1)//行车模式
    {
        qDebug()<<"行车模式自动截图";
        this->capSaveImg.save(pSavePath);
        this->player->userId=this->user_id;
        this->player->equipmentId=this->equipmentID;
        this->player->addPath(pSavePath,0);//传给拆分线程去发送给服务器
    }
}

void SystemMainWin::ReverseVideoShow(Mat frame)
{
    Mat frameR=frame.clone();
    //需要红蓝转换
    cvtColor(frameR,frameR,CV_BGR2RGB);
    this->reverserImg=QImage(frameR.data,frameR.cols,frameR.rows,QImage::Format_RGB888);
    this->reverserImg=this->reverserImg.scaled(ui->reverseVideo->size());
    ui->reverseVideo->setPixmap(QPixmap::fromImage(reverserImg));
    update();
}

void SystemMainWin::BirdEyeVideoRT(Mat effec,Mat camera)
{
    Mat frameC=camera.clone();
    Size size(300,475);//UI
    Mat frameB1=effec.clone();//已经拼接上车前的画面
//    imshow("frameB1",frameB1);
    Mat resizeB1;
    cv::resize(frameB1,resizeB1,size);//


//    imshow("resizeB1",resizeB1);
//    Mat resizeB2;
//    cv::resize(this->CarsideMat,resizeB2,size);


//    Mat resizeB=resizeB1+resizeB2;

//    imshow("resizeB",resizeB1);
    waitKey(10);
    //需要红蓝转换
    cvtColor(resizeB1,resizeB1,CV_BGR2RGB);
    cvtColor(frameC,frameC,CV_BGR2RGB);
    this->birdImgLeft=QImage(resizeB1.data,resizeB1.cols,resizeB1.rows,QImage::Format_RGB888);
    this->birdImgLeft=this->birdImgLeft.scaled(ui->birdEyeLabel->width(),ui->birdEyeLabel->height());
    ui->birdEyeLabel->setPixmap(QPixmap::fromImage(birdImgLeft));

    this->birdImgRight=QImage(frameC.data,frameC.cols,frameC.rows,QImage::Format_RGB888);
    this->birdImgRight=this->birdImgRight.scaled(ui->realTimeLabel->size());
    ui->realTimeLabel->setPixmap(QPixmap::fromImage(birdImgRight));

    update();
}

void SystemMainWin::return2VideoList()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->birdViewtoolButton->setEnabled(true);
    ui->drivingModetoolButton->setEnabled(true);
    ui->featureRecordtoolButton->setEnabled(true);
    ui->reverseModetoolButton->setEnabled(true);
    ui->systemSettingtoolButton->setEnabled(true);
    ui->videoRecordtoolButton->setEnabled(true);
    ui->logoutBtn->setEnabled(true);
}

void SystemMainWin::setListMode(int value)
{
    ListMode = value;
}

void SystemMainWin::searchPicture()
{
    if(this->picListPage==1 || this->picNum==4)
    {
        this->picListSearch.user_id=this->user_id;
        this->picListSearch.currentPage=this->picListPage;
        this->picHead.CRCnum=this->CRC->calculateCRC((char*)(&this->picListSearch),sizeof(SEARCHT));

        bzero(this->picbuf,sizeof (this->picbuf));

        memcpy(this->picbuf,&this->picHead,sizeof (HEAD));
        memcpy(this->picbuf+sizeof(HEAD),&this->picListSearch,sizeof (SEARCHT));

        this->wt->setData(this->picbuf,sizeof (HEAD)+sizeof (SEARCHT));
    }
    else {
        qDebug()<<"已经没有图片了";
    }
}

void SystemMainWin::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
        // Scroll up
        QWidget::wheelEvent(event);
    } else {
        // Scroll down
        if(this->ListMode==1)
        {
            if (!isLoading &&  verticalScrollBar1->value()== verticalScrollBar1->maximum()) //滚动到最底部
            {
                isLoading = true;
                qDebug()<<"视频滚动条滚动到最底部";
                VideoSearch();
            }
        }
        else if (this->ListMode==2)
        {
            if (!isPicLoading &&  verticalScrollBar2->value()== verticalScrollBar2->maximum()) //滚动到最底部
            {
                isPicLoading = true;
                qDebug()<<"图片滚动条滚动到最底部";
                searchPicture();
            }
        }
        QWidget::wheelEvent(event);
    }
}

void SystemMainWin::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_Drag=true;
        m_DragPosition=event->globalPos()-this->pos();
        event->accept();
    }
}

void SystemMainWin::mouseMoveEvent(QMouseEvent *event)
{
    if(m_Drag && (event->buttons() && Qt::LeftButton ))
    {
        move(event->globalPos()-m_DragPosition);
        event->accept();
    }
}

void SystemMainWin::mouseReleaseEvent(QMouseEvent *event)
{
    m_Drag=false;
}

int SystemMainWin::getUser_id() const
{
    return user_id;
}

void SystemMainWin::setUser_id(int value)
{
    user_id = value;
    this->cameThd->setUid(value);
    this->videoListSearch.user_id=value;
    this->videoListSearch.equipment_id=8080;
}

void SystemMainWin::VideoSearch()
{
    if(this->videoListPage==1 || this->videoNum==4)
    {
        this->videoListSearch.currentPage=this->videoListPage;
        this->head.CRCnum=this->CRC->calculateCRC((char*)(&this->videoListSearch),sizeof(SEARCHT));

        bzero(this->buf,sizeof (this->buf));

        memcpy(this->buf,&this->head,sizeof (HEAD));
        memcpy(this->buf+sizeof(HEAD),&this->videoListSearch,sizeof (SEARCHT));

        this->wt->setData(this->buf,sizeof (HEAD)+sizeof (SEARCHT));
    }
    else {
        qDebug()<<"已经没有视频了";
    }
}

QString SystemMainWin::getUsrName() const
{
    return usrName;
}

void SystemMainWin::setUsrName(const QString &value)
{
    usrName = value;
    this->ui->nameLabel->setText(value);
}

void SystemMainWin::on_logoutBtn_clicked()
{
    if(this->player->isEmpty())
    {
        qDebug()<<"准备登出";
        memset(&this->logoutRequst,0,sizeof (this->logoutRequst));
        //登出信息结构体
        this->logoutRequst.flag=0;
        this->logoutRequst.user_id=this->user_id;
        this->logoutHead.CRCnum=CRCcheck::getInstance()->calculateCRC((char*)&this->logoutRequst,sizeof (this->logoutRequst));
        char logoutBuf[1500]={0};
        memcpy(logoutBuf,&this->logoutHead,sizeof (HEAD));
        memcpy(logoutBuf+sizeof (HEAD),&this->logoutRequst,sizeof (BACKMSGT));
        this->wt->setData(logoutBuf,sizeof(HEAD)+sizeof (BACKMSGT));
    }
    else
    {
        QMessageBox::warning(this,"登出提醒","还有图片正在上传.");
    }
}

void SystemMainWin::logoutSlot(int flag)
{
    if(flag==-1)
    {
        this->cameThd->setIsOver(true);
        this->player->endAllThread();
        QMessageBox::information(nullptr,  "强制停止",  "心跳业务长时间无响应，强制下线");
        exit(0);
    }
    else if(flag==0)
    {
        emit logoutSigal();
        this->cameThd->setIsOver(true);
        this->player->endAllThread();
        QMessageBox::information(nullptr,  "登出成功",  "退出程序");
        exit(0);
    }
    else
    {
        QMessageBox::warning(this,"登出提醒","下线出错");
    }
}

void SystemMainWin::restartBirdT()
{

}

void SystemMainWin::on_pic_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug()<<"图片的路径是:"<<item->data(Qt::UserRole).toString();
    QString picPath=item->data(Qt::UserRole).toString();
    this->bgPicWin->ShowPicture(picPath);
    ui->stackedWidget->setCurrentIndex(7);
    ui->birdViewtoolButton->setEnabled(false);
    ui->drivingModetoolButton->setEnabled(false);
    ui->featureRecordtoolButton->setEnabled(false);
    ui->reverseModetoolButton->setEnabled(false);
    ui->systemSettingtoolButton->setEnabled(false);
    ui->videoRecordtoolButton->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
}

void SystemMainWin::return2PIcList()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->birdViewtoolButton->setEnabled(true);
    ui->drivingModetoolButton->setEnabled(true);
    ui->featureRecordtoolButton->setEnabled(true);
    ui->reverseModetoolButton->setEnabled(true);
    ui->systemSettingtoolButton->setEnabled(true);
    ui->videoRecordtoolButton->setEnabled(true);
    ui->logoutBtn->setEnabled(true);
}

void SystemMainWin::on_pushButton_clicked()
{
    QSettings* settingConfig=new QSettings("./systemInit.ini",QSettings::IniFormat);
    QString ipAddress=this->ipAddressInput->getIP();
    settingConfig->setValue("/set/ip",ipAddress);
    settingConfig->setValue("/set/port",ui->port_lineEdit->text());
    settingConfig->setValue("/set/storage",ui->memoryEdt->text());
    settingConfig->setValue("/set/autoDeletion",ui->radioButton->isChecked());

    if(QMessageBox::information(NULL,  "开始测试",  "确定退出吗?\nｙｅｓ－确定，ｎｏ－取消",
                                    QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
        {
            qDebug()<<"退出程序";
            on_logoutBtn_clicked();

        }
        else
        {
            qDebug()<<"取消退出";
        }


}
