#ifndef BIGPICWIDGET_H
#define BIGPICWIDGET_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QImage>

namespace Ui {
class BigPicWidget;
}

class BigPicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BigPicWidget(QWidget *parent = nullptr);
    ~BigPicWidget();

    void ShowPicture(QString picPath);

private slots:
    void on_exitBtn_clicked();

private:
    Ui::BigPicWidget *ui;
    QImage img;

signals:
    void back2PicList();

};

#endif // BIGPICWIDGET_H
