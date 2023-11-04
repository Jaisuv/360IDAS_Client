#ifndef VIDEORECORDITEMWIDGET_H
#define VIDEORECORDITEMWIDGET_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QPaintEvent>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class VideoRecordItemWidget;
}

class VideoRecordItemWidget : public QWidget
{
    Q_OBJECT

public:
    VideoRecordItemWidget(QString coverPath,QString videoPath,int currentFrame,int frameNum,QString videoName,QWidget *parent = nullptr);
    ~VideoRecordItemWidget();

    QString getTime() const;
    void setTime(const QString &value);

    QString getPercent() const;
    void setPercent(const QString &value);

    QString getCoverPath() const;
    void setCoverPath(const QString &value);

    QString getVideoPath() const;
    void setVideoPath(const QString &value);

    void ChangeCover();

    QPushButton *getButton();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VideoRecordItemWidget *ui;
    QString coverPath;
    QString videoPath;
    QString videoName;
    float frameNum;//视频总帧数
    float currentFrame;

signals:
    void sendVideo2Main(QString path,int currentFrame,QString videoName);

};

#endif // VIDEORECORDITEMWIDGET_H
