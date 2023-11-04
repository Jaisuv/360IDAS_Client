//开机动画
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Thread/videoplaythread.h"
#include "csettinginit.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void setVideo(String path);
private:
    Ui::Widget *ui;
    VideoPlayThread* OPthread;
    QImage Img;
    CSettingInit *setWin;
protected:
    void paintEvent(QPaintEvent *e);
public slots:
    void ChangeData(int current,Mat frame);
    void switchWIn();
};

#endif // WIDGET_H
