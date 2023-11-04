#ifndef VERIFICATIONCODE_H
#define VERIFICATIONCODE_H

#include <QFrame>
#include <QString>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QTime>
#include <QChar>
#include <QtGlobal>
#include <QPainter>
#include <QWidget>

class VerificationCode:public QFrame
{
    Q_OBJECT
public:
    explicit VerificationCode(QWidget *parent = nullptr);
    void generateRandomCode();
    //图形验证码的宽高
    int width;
    int height;

    QString getCode() const;

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
private:
    QString code;   //验证码
};

#endif // VERIFICATIONCODE_H
