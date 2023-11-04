#include "registwin.h"
#include "ui_registwin.h"

RegistWin::RegistWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistWin)
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
    //输入框限制
    //账号输入框
    QRegExp regExpAccount("^[a-zA-Z0-9_]{6,8}$"); //英文字母大小写　数字　下划线
    QRegExpValidator *validator1 = new QRegExpValidator(regExpAccount, this);
    this->ui->account_lineEdit->setValidator(validator1);
    //密码输入框
    QRegExp regExpPwd("^[a-zA-Z0-9_]{6,8}$"); //英文字母大小写　数字　下划线
    QRegExpValidator *validator2 = new QRegExpValidator(regExpPwd, this);
    this->ui->pwd_lineEdit->setValidator(validator2);
    this->ui->rpwd_lineEdit->setValidator(validator2);
    //用户名输入框
    QRegExp regExpName("^[a-zA-Z0-9_\u4e00-\u9fa5]{6,8}$");
    QRegExpValidator *validator3 = new QRegExpValidator(regExpName,this);
    this->ui->name_lineEdit->setValidator(validator3);

    this->isVisible1=false;
    this->isVisible2=false;

    this->sc=SocketConnect::getInstance();
    this->rt=ReadThread::getInstance();
    this->wt=WriteThread::getInstance();

    memset(this->buf,0,sizeof(this->buf));
    connect(this->rt,SIGNAL(regist_Request_Result(int)),this,SLOT(isChecked(int)));

    this->CRC=CRCcheck::getInstance();

}

RegistWin::~RegistWin()
{
    delete ui;
}

void RegistWin::Clear()
{
    this->ui->account_lineEdit->clear();
    this->ui->name_lineEdit->clear();
    this->ui->pwd_lineEdit->clear();
    this->ui->rpwd_lineEdit->clear();
    this->isVisible1=false;
    this->ui->pwd_lineEdit->setEchoMode(QLineEdit::Password);
    this->ui->eyeBtn->setIcon(QIcon(":/images/用户/unvisible.png"));
    this->isVisible2=false;
    this->ui->rpwd_lineEdit->setEchoMode(QLineEdit::Password);
    this->ui->eyeBtn_2->setIcon(QIcon(":/images/用户/unvisible.png"));
}

void RegistWin::on_cancel_pushButton_clicked()
{
    this->Clear();
    emit back2Login(this->ui->account_lineEdit->text());
    this->hide();
}

void RegistWin::on_ok_pushButton_clicked()
{
    qDebug()<<"点击确定";

    QString accountTemp = this->ui->account_lineEdit->text();
    QString nameTemp = this->ui->name_lineEdit->text();
    QString pwdTemp = this->ui->pwd_lineEdit->text();
    QString rpwdTemp = this->ui->rpwd_lineEdit->text();

    string accountTempC=accountTemp.toStdString();
    string nameTempC=nameTemp.toStdString();
    string pwdTempC=pwdTemp.toStdString();
    string rpwdTempC=rpwdTemp.toStdString();

    if(accountTemp.isEmpty())
    {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>未输入账号！</font>");
        return;
    }
    else if(accountTemp.length()<6)
    {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>账号不得小于６位！</font>");
        return;
    }

    if(nameTemp.isEmpty())
    {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>未输入昵称！</font>");
        return;
    }
    else if (nameTemp.length()<6)
    {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>昵称不得小于６位！</font>");
        return;
    }

    if(pwdTemp.isEmpty())
    {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>未输入密码！</font>");
        return;
    }
    else if (pwdTemp.length()<6) {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>密码不得小于６位！</font>");
        return;
    }

    if(rpwdTemp.isEmpty())
    {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>未确认密码！</font>");
        return;
    }
    else if (rpwdTemp!=pwdTemp) {
        QMessageBox::warning(this,"注册提示","<font color='red' size='6'>两次输入的密码不一致！</font>");
        return;
    }

    //表单验证结束
    this->AccountBeReturned=accountTemp;
    QString pwdMD5=Tools::generateMD5(pwdTemp);
    string MD5_str=pwdMD5.toStdString();
    const char *accountInput_cstr=accountTempC.c_str();
    const char *pwdInput_cstr=MD5_str.c_str();
    const char *nameInput_cstr=nameTempC.c_str();

    //数据装到包体
    memcpy(this->registInfo.id,accountInput_cstr,sizeof(registInfo.id));
    memcpy(this->registInfo.name,nameInput_cstr,sizeof(registInfo.name));
    memcpy(this->registInfo.pwd,pwdInput_cstr,sizeof(registInfo.pwd));

    //包头数据准备
    this->head.type=2;//注册请求
    this->head.length=sizeof(this->registInfo);
    this->head.CRCnum=this->CRC->calculateCRC((char*)&this->registInfo,sizeof(this->registInfo));  //CRC校验码

    //保险起见，写入数据之前还是要先清空一下承载数据的空间
    memset(this->buf,0,sizeof (this->buf));
    //先放包头
    memcpy(this->buf,&(this->head),sizeof(HEAD));
    //再放包体
    memcpy(this->buf+sizeof(HEAD),&(this->registInfo),sizeof(this->registInfo));

    this->wt->setData(this->buf,sizeof(this->head)+sizeof(this->registInfo));

}


void RegistWin::on_eyeBtn_clicked()
{
    this->isVisible1=!this->isVisible1;
    if(this->isVisible1)//可见
    {
        this->ui->pwd_lineEdit->setEchoMode(QLineEdit::Normal);
        this->ui->eyeBtn->setIcon(QIcon(":/images/用户/visible.png"));
    }
    else
    {
        this->ui->pwd_lineEdit->setEchoMode(QLineEdit::Password);
        this->ui->eyeBtn->setIcon(QIcon(":/images/用户/unvisible.png"));
    }
}

void RegistWin::on_eyeBtn_2_clicked()
{
    this->isVisible2=!this->isVisible2;
    if(this->isVisible2)//可见
    {
        this->ui->rpwd_lineEdit->setEchoMode(QLineEdit::Normal);
        this->ui->eyeBtn_2->setIcon(QIcon(":/images/用户/visible.png"));
    }
    else
    {
        this->ui->rpwd_lineEdit->setEchoMode(QLineEdit::Password);
        this->ui->eyeBtn_2->setIcon(QIcon(":/images/用户/unvisible.png"));
    }
}

void RegistWin::on_pushButton_clicked()
{
    this->Clear();
}

void RegistWin::isChecked(int flag)
{
    if(flag == 0)
    {
        QMessageBox::information(this,"注册提示","注册成功！");
        qDebug()<<"注册成功!去登录界面";
        emit back2Login(this->AccountBeReturned);
        this->hide();
        this->Clear();
    }
    else
    {
        QMessageBox::warning(this,"注册提醒","注册失败");
        this->AccountBeReturned.clear();
        qDebug()<<AccountBeReturned;
    }
}

void RegistWin::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_Drag=true;
        m_DragPosition=event->globalPos()-this->pos();
        event->accept();
    }
}

void RegistWin::mouseMoveEvent(QMouseEvent *event)
{
    if(m_Drag && (event->buttons() && Qt::LeftButton ))
    {
        move(event->globalPos()-m_DragPosition);
        event->accept();
    }
}

void RegistWin::mouseReleaseEvent(QMouseEvent *event)
{
    m_Drag=false;
}
