#include "loginwin.h"
#include "ui_loginwin.h"

LoginWin::LoginWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWin)
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

    this->pwdVisFlag=false;//不可见，密文
    //输入框限制
    //账号输入框
    QRegExp regExpAccount("^[a-zA-Z0-9_]{6,8}$"); //英文字母大小写　数字　下划线
    QRegExpValidator *validator1 = new QRegExpValidator(regExpAccount, this);
    this->ui->account_lineEdit->setValidator(validator1);
    ui->account_lineEdit->setText("123456");
    //密码输入框
    QRegExp regExpPwd("^[a-zA-Z0-9_]{6,8}$"); //英文字母大小写　数字　下划线
    QRegExpValidator *validator2 = new QRegExpValidator(regExpPwd, this);
    this->ui->pwd_lineEdit->setValidator(validator2);
    ui->pwd_lineEdit->setText("123456");
    //验证码输入框
    QRegExp regExpVerification("^[a-zA-Z0-9]{4}$");
    QRegExpValidator *validator3 = new QRegExpValidator(regExpVerification,this);
    this->ui->verification_lineEdit->setValidator(validator3);

    //验证码
    VerifyCode=new VerificationCode(this);
    int VerifyCodeX=ui->verification_lineEdit->x()+ui->verification_lineEdit->width()+10;
    int VerifyCodeY=ui->verification_lineEdit->y()-5;
    VerifyCode->move(540,264);


    this->sc=SocketConnect::getInstance();
    this->rt=ReadThread::getInstance();
    this->wt=WriteThread::getInstance();

    this->rt->setSocketfd(this->sc->getSocketfd());
    this->wt->setSocketfd(this->sc->getSocketfd());

    memset(this->buf,0,sizeof(this->buf));
    connect(this->rt,SIGNAL(login_Request_Result(int,QString,int)),this,SLOT(isChecked(int,QString,int)), Qt::BlockingQueuedConnection);

    this->rt->start();
    this->wt->start();

    this->regWin=new RegistWin();//构造不能传this
    connect(this->regWin,SIGNAL(back2Login(QString)),this,SLOT(regWinBackThisReShow(QString)));

    this->CRC=CRCcheck::getInstance();
}

LoginWin::~LoginWin()
{
    delete ui;
}

void LoginWin::on_cancel_pushButton_clicked()
{
    this->Clear();
    emit cancel_pushButton_clicked();
    this->close();
}

void LoginWin::on_login_pushButton_clicked()
{
    QString accountValue = this->ui->account_lineEdit->text();
    QString passwdValue = this->ui->pwd_lineEdit->text();
    QString verificationValue = this->ui->verification_lineEdit->text();

    if(accountValue.isEmpty())
    {
        QMessageBox::critical(this,tr("登录提醒"),"<font color='red' size='6'>未输入账号！</font>");
        return;
    }
    else if (accountValue.length()<6) {
        QMessageBox::critical(this,tr("登录提醒"),"<font color='red' size='6'>账号不得小于6位！</font>");
        return;        QString videoFileName="./Driving Video/";   //实时视频的
    }

    if(passwdValue.isEmpty())
    {
        QMessageBox::critical(this,tr("登录提醒"),"<font color='red' size='6'>未输入密码！</font>");
        return;
    }
    else if (passwdValue.length()<6) {
        QMessageBox::critical(this,tr("登录提醒"),"<font color='red' size='6'>密码不得小于6位！</font>");
        return;
    }

    //验证码判断
    if(verificationValue.isEmpty())
    {
        QMessageBox::critical(this,tr("登录提醒"),"<font color='red' size='6'>未输入验证码！</font>");
        return;
    }
    else if (verificationValue.length()<4) {
        QMessageBox::critical(this,tr("登录提醒"),"<font color='red' size='6'>验证码不得小于４位！</font>");
        return;
    }
    //全部转成小写来判断
    QString verifyCodeInputLower=verificationValue.toLower();
    QString GraphicTextLower=VerifyCode->getCode().toLower();
    if(verifyCodeInputLower!=GraphicTextLower)
    {
        qDebug()<<"您输入的是:"<<verifyCodeInputLower;
        qDebug()<<"正确的验证码的值:"<<GraphicTextLower;
        QMessageBox::critical(this,tr("登录提醒"),"<font color='red' size='6'>验证码错误！</font>");
        return;
    }
    //经过上述的表单验证数据都已经没有问题了

    string userAccount1=accountValue.toStdString();
    string userPwd1=this->generateMD5(passwdValue).toStdString();

    const char* userAccount = userAccount1.c_str();
    const char* userPwd = userPwd1.c_str();

    //准备发送请求包的包体
    //账号和密码都装到包体里面
    memcpy(this->loginInfo.id,userAccount,sizeof(loginInfo.id));
    memcpy(this->loginInfo.pwd,userPwd,sizeof (loginInfo.pwd));
//    memcpy(this->loginInfo.pwd,md5.result().toHex(),sizeof (loginInfo.pwd));

    //包头数据准备
    this->head.type=0;//登录请求
    this->head.length=sizeof(this->loginInfo);
    this->head.CRCnum=this->CRC->calculateCRC((char*)&(this->loginInfo),sizeof(this->loginInfo));

    //保险起见，写入数据之前还是要先清空一下承载数据的空间
    memset(this->buf,0,sizeof (this->buf));
    //先放包头
    memcpy(this->buf,&(this->head),sizeof(HEAD));
    //再放包体
    memcpy(this->buf+sizeof(HEAD),&(this->loginInfo),sizeof(this->loginInfo));

//    this->rt->start();
    this->wt->setData(this->buf,sizeof(this->head)+sizeof(this->loginInfo));
//    this->wt->start();

}

void LoginWin::on_eyeBtn_clicked()
{
    this->pwdVisFlag=!this->pwdVisFlag;//翻转
    if(this->pwdVisFlag)//可见
    {
        this->ui->eyeBtn->setIcon(QIcon(":/images/用户/visible.png"));
        this->ui->pwd_lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        this->ui->eyeBtn->setIcon(QIcon(":/images/用户/unvisible.png"));
        this->ui->pwd_lineEdit->setEchoMode(QLineEdit::Password);
    }
}

void LoginWin::isChecked(int flag,QString UserName,int uid)
{
    if(flag == 0)
    {
        QMessageBox::information(this,"登录提示","登录成功！");
        qDebug()<<"接下去进入主界面";
        this->hide();
        this->sysMainWin=new SystemMainWin();//构造不能传this
        this->sysMainWin->setUsrName(UserName);
        this->sysMainWin->setUser_id(uid);
        qDebug()<<"登录界面获取到的id"<<uid;
        this->sysMainWin->show();
        this->hbt=new HeartBeatThread;
        this->hbgt=new HeartBeatGetThread;
        connect(this->hbgt,SIGNAL(forceExit()),this,SLOT(heartBeatMissSlot()));
        connect(this->sysMainWin,SIGNAL(logoutSigal()),this,SLOT(logoutSlot()));
        this->hbt->start();
        this->hbgt->start();
    }
    else
    {
        QMessageBox::warning(this,"登录提醒","登录失败!");
        this->Clear();//清空表单重新输入
    }
}

void LoginWin::regWinBackThisReShow(QString value)
{
    this->ui->account_lineEdit->setText(value);
    this->show();
}

bool LoginWin::getPwdVisFlag() const
{
    return pwdVisFlag;
}

void LoginWin::setPwdVisFlag(bool value)
{
    pwdVisFlag = value;
}

QString LoginWin::generateMD5(const QString &value)
{
    QString md5;
    QByteArray bb;
    bb=QCryptographicHash::hash(value.toUtf8(),QCryptographicHash::Md5);
    md5.append(bb.toHex());
    return md5;
}

void LoginWin::Clear()
{
    this->ui->account_lineEdit->clear();
    this->ui->pwd_lineEdit->clear();
    this->ui->verification_lineEdit->clear();
}

void LoginWin::on_regist_pushButton_clicked()
{
//    this->hide();
    this->regWin->show();
    this->hide();
}

void LoginWin::on_pushButton_clicked()
{
    this->Clear();
}


void LoginWin::on_pushButton_2_clicked()
{
    ui->account_lineEdit->setText("111111");
    ui->pwd_lineEdit->setText("123456");
    ui->verification_lineEdit->setText("1111");
}

void LoginWin::logoutSlot()
{
    this->hbt->setIsStop(true);
    this->hbgt->setIsOver(true);
}

void LoginWin::heartBeatMissSlot()
{
    this->hbt->setIsStop(true);
    this->hbgt->setIsOver(true);
    this->sysMainWin->logoutSlot(-1);
}

void LoginWin::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_Drag=true;
        m_DragPosition=event->globalPos()-this->pos();
        event->accept();
    }
}

void LoginWin::mouseMoveEvent(QMouseEvent *event)
{
    if(m_Drag && (event->buttons() && Qt::LeftButton ))
    {
        move(event->globalPos()-m_DragPosition);
        event->accept();
    }
}

void LoginWin::mouseReleaseEvent(QMouseEvent *event)
{
    m_Drag=false;
}
