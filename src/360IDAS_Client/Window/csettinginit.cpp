#include "csettinginit.h"
#include "ui_csettinginit.h"

CSettingInit::CSettingInit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSettingInit)
{
    //获取屏幕的宽度和高度
    int screenWidth=QApplication::desktop()->width();
    int screenHeight=QApplication::desktop()->height();
    //计算坐标，移动到屏幕中间
    int x=(screenWidth-this->width())/2;
    int y=(screenHeight-this->height())/2;
    this->move(x,y);
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    this->effect=new QGraphicsDropShadowEffect;
    effect->setOffset(4,4);
    effect->setColor(QColor(0,0,0,50));
    effect->setBlurRadius(10);
    ui->frame1->setGraphicsEffect(effect);
    this->ipAddressInput=new IPAddress(this);
    this->ipAddressInput->move(427,120);

    QRegExp regExp2("^(102[4-9]|10[3-9]\\d|1[1-9]\\d{2}|[2-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5])$");
    QRegExpValidator *validator2 = new QRegExpValidator(regExp2, this);
    ui->port_lineEdit->setValidator(validator2);
    ui->port_lineEdit->setPlaceholderText("1024~65535");
    //创建网络连接成员
    this->sc=SocketConnect::getInstance();
}

CSettingInit::~CSettingInit()
{
    delete ui;
    delete effect;
}

void CSettingInit::saveSettings()
{
    QSettings* settingConfig=new QSettings("./systemInit.ini",QSettings::IniFormat);
    QString ipAddress=this->ipAddressInput->getIP();
    settingConfig->setValue("/set/ip",ipAddress);
    settingConfig->setValue("/set/port",ui->port_lineEdit->text());
    settingConfig->setValue("/set/storage",ui->memoryEdt->text());
    settingConfig->setValue("/set/autoDeletion",ui->radioButton->isChecked());
}

void CSettingInit::readSettings()
{
    QSettings* settingConfig=new QSettings("./systemInit.ini",QSettings::IniFormat);
    this->ipAddressInput->setIP(settingConfig->value("/set/ip").toString());
    ui->port_lineEdit->setText(settingConfig->value("/set/port").toString());
    ui->memoryEdt->setText(settingConfig->value("/set/storage").toString());
    ui->radioButton->setChecked(settingConfig->value("/set/autoDeletion").toBool());
}

void CSettingInit::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_Drag=true;
        m_DragPosition=event->globalPos()-this->pos();
        event->accept();
    }
}

void CSettingInit::mouseMoveEvent(QMouseEvent *event)
{
    if(m_Drag && (event->buttons() && Qt::LeftButton ))
    {
        move(event->globalPos()-m_DragPosition);
        event->accept();
    }
}

void CSettingInit::mouseReleaseEvent(QMouseEvent *event)
{
    m_Drag=false;
}

//确定按钮
void CSettingInit::on_pushButton_clicked()
{
    //获取输入的IP地址
    QString ipAddres=this->ipAddressInput->getIP();
    //获取输入的端口号
    QString portNum=this->ui->port_lineEdit->text();
    //获取输入的存储空间大小
    QString storageSize=this->ui->memoryEdt->text();

    qDebug()<<ipAddres;
    qDebug()<<portNum;
    qDebug()<<storageSize;

    //检测ip地址是否合法
    QRegExp regExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    if (!regExp.exactMatch(ipAddres)) {
        QMessageBox::critical(this,"设置提醒","<font color='red'>IP地址不合法！</font>");
        qDebug()<<"IP地址不合法！";
        return;
    }

    //判断是否输入端口号
    if(portNum.isEmpty())
    {
        QMessageBox::critical(this,"设置提醒","<font color='red'>未输入端口号！</font>");
        qDebug()<<"未输入端口号！";
        return;
    }

    if(storageSize.isEmpty())
    {
        QMessageBox::critical(this,"设置提醒","<font color='red'>未输入存储空间大小！</font>");
        qDebug()<<"未输入存储空间大小！";
        return;
    }

    this->sc->setIPAddr(ipAddres.toStdString());
    this->sc->setPortNum(portNum.toUShort());

    saveSettings();
    this->sc->createConnect();//创建网络连接
    QMessageBox::information(this,"设置提醒","设置成功！");
    this->loginWin=new LoginWin();
    this->hide();
    this->loginWin->show();
}

//测试按钮
void CSettingInit::on_pushButton_2_clicked()
{
    this->readSettings();
}

void CSettingInit::on_pushButton_3_clicked()
{
    exit(0);
}
