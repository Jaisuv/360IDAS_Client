#include "verificationcode.h"

VerificationCode::VerificationCode(QWidget *parent): QFrame(parent)
{
    this->setStyleSheet("background-color:white");
    this->setFixedSize(120,45);
    this->width=120;
    this->height=45;
    this->setLineWidth(1);
    this->setMidLineWidth(2);
    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Raised);
    //随机素数种子初始
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    this->generateRandomCode();
}

void VerificationCode::generateRandomCode()
{
    this->code.clear();
    for (int i=0;i<4;i++) {
        int num=qrand()%3;//随机生成０　１　２ 三种元素
        if(num==0)
        {
            //数字
            this->code += QString::number(qrand()%10);
        }
        else if (num==1)
        {
            //大写字母
            int temp='A';//字母Ａ的ASCII码
            this->code += static_cast<QChar>(temp+qrand()%26);
        }
        else if (num==2)
        {
            //小写字母
            int temp='a';
            this->code += static_cast<QChar>(temp+qrand()%26);
        }
    }
}

void VerificationCode::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen;
    QFont font("楷体",25,QFont::Bold,true);
    painter.setFont(font);

    //背景噪点的绘制
    for (int i=0;i<150;i++) //画１００个噪点
    {
        pen = QPen(QColor(qrand()%256,qrand()%256,qrand()%256));//随机颜色
        painter.setPen(pen);
        painter.drawPoint(qrand()%(width+15),qrand()%(height+5));//在验证码宽高的范围内画点
    }
    //画线
    for (int i=0;i<5;i++)//5条干扰线
    {
        pen = QPen(QColor(qrand()%256,qrand()%256,qrand()%256));//随机颜色
        painter.setPen(pen);
        painter.drawLine(qrand()%width,qrand()%height,qrand()%width,qrand()%height);
    }
    //画验证码
    for (int i=0;i<4;i++)
    {
        pen = QPen(QColor(qrand()%256,qrand()%256,qrand()%256));//随机颜色
        painter.setPen(pen);
        painter.drawText(i*30,qrand()%15,30,30,Qt::AlignCenter,QString(code[i]));
    }
}

void VerificationCode::mousePressEvent(QMouseEvent *e)
{
    this->generateRandomCode();
    update();
}

QString VerificationCode::getCode() const
{
    return code;
}

