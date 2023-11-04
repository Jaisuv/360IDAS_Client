/********************************************************************************
** Form generated from reading UI file 'videoplayerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYERWIDGET_H
#define UI_VIDEOPLAYERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayerWidget
{
public:
    QLabel *showVideo;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *playBtn;
    QComboBox *rationcomboBox;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *captureBtn;
    QPushButton *exitBtn;

    void setupUi(QWidget *VideoPlayerWidget)
    {
        if (VideoPlayerWidget->objectName().isEmpty())
            VideoPlayerWidget->setObjectName(QStringLiteral("VideoPlayerWidget"));
        VideoPlayerWidget->resize(850, 450);
        showVideo = new QLabel(VideoPlayerWidget);
        showVideo->setObjectName(QStringLiteral("showVideo"));
        showVideo->setGeometry(QRect(2, 0, 846, 370));
        showVideo->setStyleSheet(QStringLiteral("background-color: rgb(64, 191, 142);"));
        showVideo->setScaledContents(true);
        horizontalSlider = new QSlider(VideoPlayerWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(6, 380, 838, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(VideoPlayerWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 400, 92, 30));
        label->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        label_2 = new QLabel(VideoPlayerWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(105, 400, 41, 30));
        label_2->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        label_3 = new QLabel(VideoPlayerWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 400, 24, 30));
        label_3->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        label_4 = new QLabel(VideoPlayerWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 400, 61, 30));
        label_4->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        playBtn = new QPushButton(VideoPlayerWidget);
        playBtn->setObjectName(QStringLiteral("playBtn"));
        playBtn->setGeometry(QRect(330, 400, 90, 30));
        rationcomboBox = new QComboBox(VideoPlayerWidget);
        rationcomboBox->setObjectName(QStringLiteral("rationcomboBox"));
        rationcomboBox->setGeometry(QRect(580, 400, 86, 30));
        label_5 = new QLabel(VideoPlayerWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(680, 400, 81, 30));
        label_5->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        label_6 = new QLabel(VideoPlayerWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(750, 400, 91, 30));
        label_6->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        captureBtn = new QPushButton(VideoPlayerWidget);
        captureBtn->setObjectName(QStringLiteral("captureBtn"));
        captureBtn->setGeometry(QRect(450, 400, 90, 30));
        exitBtn = new QPushButton(VideoPlayerWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(220, 400, 90, 30));

        retranslateUi(VideoPlayerWidget);

        rationcomboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(VideoPlayerWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoPlayerWidget)
    {
        VideoPlayerWidget->setWindowTitle(QApplication::translate("VideoPlayerWidget", "Form", Q_NULLPTR));
        showVideo->setText(QString());
        label->setText(QApplication::translate("VideoPlayerWidget", "\345\267\262\347\273\217\346\222\255\346\224\276", Q_NULLPTR));
        label_2->setText(QApplication::translate("VideoPlayerWidget", "00", Q_NULLPTR));
        label_3->setText(QApplication::translate("VideoPlayerWidget", "/", Q_NULLPTR));
        label_4->setText(QApplication::translate("VideoPlayerWidget", "100", Q_NULLPTR));
        playBtn->setText(QApplication::translate("VideoPlayerWidget", "\346\232\202\345\201\234", Q_NULLPTR));
        rationcomboBox->clear();
        rationcomboBox->insertItems(0, QStringList()
         << QApplication::translate("VideoPlayerWidget", "0.5X", Q_NULLPTR)
         << QApplication::translate("VideoPlayerWidget", "1.0X", Q_NULLPTR)
         << QApplication::translate("VideoPlayerWidget", "2.0X", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("VideoPlayerWidget", "\346\200\273\346\227\266\351\225\277:", Q_NULLPTR));
        label_6->setText(QApplication::translate("VideoPlayerWidget", "100", Q_NULLPTR));
        captureBtn->setText(QApplication::translate("VideoPlayerWidget", "\346\210\252\345\233\276", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("VideoPlayerWidget", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayerWidget: public Ui_VideoPlayerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYERWIDGET_H
