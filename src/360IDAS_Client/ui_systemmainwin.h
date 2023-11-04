/********************************************************************************
** Form generated from reading UI file 'systemmainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMAINWIN_H
#define UI_SYSTEMMAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemMainWin
{
public:
    QWidget *leftWidget;
    QLabel *headLabel;
    QPushButton *logoutBtn;
    QToolButton *videoRecordtoolButton;
    QLabel *nameLabel;
    QToolButton *drivingModetoolButton;
    QToolButton *reverseModetoolButton;
    QToolButton *birdViewtoolButton;
    QToolButton *featureRecordtoolButton;
    QToolButton *systemSettingtoolButton;
    QStackedWidget *stackedWidget;
    QWidget *videoRecordPage;
    QListWidget *video_listWidget;
    QWidget *drivingModePage;
    QLabel *drivingVideo;
    QWidget *reverseModePage;
    QLabel *reverseVideo;
    QWidget *birdEyeMode;
    QLabel *birdEyeLabel;
    QLabel *realTimeLabel;
    QWidget *featureRecordPage;
    QListWidget *pic_listWidget;
    QWidget *settingPage;
    QLabel *title_label;
    QLabel *iplabel;
    QLabel *label;
    QLabel *portlabel_3;
    QLineEdit *memoryEdt;
    QLabel *portlabel;
    QLineEdit *port_lineEdit;
    QLabel *portlabel_5;
    QRadioButton *radioButton;
    QPushButton *pushButton;
    QFrame *bottomLayerFrame;

    void setupUi(QWidget *SystemMainWin)
    {
        if (SystemMainWin->objectName().isEmpty())
            SystemMainWin->setObjectName(QStringLiteral("SystemMainWin"));
        SystemMainWin->resize(1051, 551);
        leftWidget = new QWidget(SystemMainWin);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setGeometry(QRect(40, 40, 100, 450));
        leftWidget->setStyleSheet(QStringLiteral(""));
        headLabel = new QLabel(leftWidget);
        headLabel->setObjectName(QStringLiteral("headLabel"));
        headLabel->setGeometry(QRect(0, 0, 100, 100));
        headLabel->setStyleSheet(QStringLiteral(""));
        headLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/head.jpg")));
        headLabel->setScaledContents(true);
        headLabel->setAlignment(Qt::AlignCenter);
        logoutBtn = new QPushButton(leftWidget);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));
        logoutBtn->setGeometry(QRect(0, 400, 100, 30));
        logoutBtn->setMinimumSize(QSize(30, 30));
        logoutBtn->setMaximumSize(QSize(200, 200));
        logoutBtn->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));
        logoutBtn->setIconSize(QSize(30, 30));
        videoRecordtoolButton = new QToolButton(leftWidget);
        videoRecordtoolButton->setObjectName(QStringLiteral("videoRecordtoolButton"));
        videoRecordtoolButton->setGeometry(QRect(0, 140, 100, 35));
        nameLabel = new QLabel(leftWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(-10, 100, 101, 31));
        nameLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 13pt \"Ubuntu\";"));
        nameLabel->setAlignment(Qt::AlignCenter);
        drivingModetoolButton = new QToolButton(leftWidget);
        drivingModetoolButton->setObjectName(QStringLiteral("drivingModetoolButton"));
        drivingModetoolButton->setGeometry(QRect(0, 180, 100, 35));
        reverseModetoolButton = new QToolButton(leftWidget);
        reverseModetoolButton->setObjectName(QStringLiteral("reverseModetoolButton"));
        reverseModetoolButton->setGeometry(QRect(0, 220, 100, 35));
        birdViewtoolButton = new QToolButton(leftWidget);
        birdViewtoolButton->setObjectName(QStringLiteral("birdViewtoolButton"));
        birdViewtoolButton->setGeometry(QRect(0, 260, 100, 35));
        featureRecordtoolButton = new QToolButton(leftWidget);
        featureRecordtoolButton->setObjectName(QStringLiteral("featureRecordtoolButton"));
        featureRecordtoolButton->setGeometry(QRect(0, 300, 100, 35));
        systemSettingtoolButton = new QToolButton(leftWidget);
        systemSettingtoolButton->setObjectName(QStringLiteral("systemSettingtoolButton"));
        systemSettingtoolButton->setGeometry(QRect(0, 340, 100, 35));
        stackedWidget = new QStackedWidget(SystemMainWin);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(160, 40, 850, 450));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        videoRecordPage = new QWidget();
        videoRecordPage->setObjectName(QStringLiteral("videoRecordPage"));
        videoRecordPage->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        video_listWidget = new QListWidget(videoRecordPage);
        video_listWidget->setObjectName(QStringLiteral("video_listWidget"));
        video_listWidget->setGeometry(QRect(0, -10, 850, 450));
        video_listWidget->setStyleSheet(QStringLiteral(""));
        video_listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        video_listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        video_listWidget->setIconSize(QSize(412, 235));
        video_listWidget->setMovement(QListView::Static);
        video_listWidget->setResizeMode(QListView::Adjust);
        video_listWidget->setSpacing(2);
        video_listWidget->setGridSize(QSize(416, 235));
        video_listWidget->setViewMode(QListView::IconMode);
        stackedWidget->addWidget(videoRecordPage);
        drivingModePage = new QWidget();
        drivingModePage->setObjectName(QStringLiteral("drivingModePage"));
        drivingVideo = new QLabel(drivingModePage);
        drivingVideo->setObjectName(QStringLiteral("drivingVideo"));
        drivingVideo->setGeometry(QRect(0, 0, 850, 450));
        drivingVideo->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(drivingModePage);
        reverseModePage = new QWidget();
        reverseModePage->setObjectName(QStringLiteral("reverseModePage"));
        reverseVideo = new QLabel(reverseModePage);
        reverseVideo->setObjectName(QStringLiteral("reverseVideo"));
        reverseVideo->setGeometry(QRect(0, 0, 850, 450));
        reverseVideo->setStyleSheet(QLatin1String("#reverseVideo{\n"
"	background-color: rgb(173, 127, 168);\n"
"}"));
        reverseVideo->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(reverseModePage);
        birdEyeMode = new QWidget();
        birdEyeMode->setObjectName(QStringLiteral("birdEyeMode"));
        birdEyeLabel = new QLabel(birdEyeMode);
        birdEyeLabel->setObjectName(QStringLiteral("birdEyeLabel"));
        birdEyeLabel->setGeometry(QRect(0, 0, 300, 475));
        birdEyeLabel->setStyleSheet(QLatin1String("#birdEyeLabel{\n"
"	background-color: rgb(138, 226, 52);\n"
"}"));
        birdEyeLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/bg.png")));
        birdEyeLabel->setScaledContents(true);
        realTimeLabel = new QLabel(birdEyeMode);
        realTimeLabel->setObjectName(QStringLiteral("realTimeLabel"));
        realTimeLabel->setGeometry(QRect(300, 0, 550, 475));
        realTimeLabel->setStyleSheet(QStringLiteral("background-color: rgb(233, 185, 110);"));
        stackedWidget->addWidget(birdEyeMode);
        featureRecordPage = new QWidget();
        featureRecordPage->setObjectName(QStringLiteral("featureRecordPage"));
        pic_listWidget = new QListWidget(featureRecordPage);
        pic_listWidget->setObjectName(QStringLiteral("pic_listWidget"));
        pic_listWidget->setGeometry(QRect(0, 0, 850, 450));
        pic_listWidget->setStyleSheet(QStringLiteral(""));
        pic_listWidget->setMidLineWidth(3);
        pic_listWidget->setIconSize(QSize(415, 235));
        pic_listWidget->setMovement(QListView::Static);
        pic_listWidget->setResizeMode(QListView::Adjust);
        pic_listWidget->setGridSize(QSize(416, 235));
        pic_listWidget->setViewMode(QListView::IconMode);
        stackedWidget->addWidget(featureRecordPage);
        settingPage = new QWidget();
        settingPage->setObjectName(QStringLiteral("settingPage"));
        settingPage->setStyleSheet(QLatin1String("#settingPage\n"
"{background-color: rgb(18, 25, 115);\n"
"}"));
        title_label = new QLabel(settingPage);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setGeometry(QRect(180, 10, 491, 59));
        title_label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 30pt \"Ubuntu\";"));
        iplabel = new QLabel(settingPage);
        iplabel->setObjectName(QStringLiteral("iplabel"));
        iplabel->setGeometry(QRect(70, 100, 339, 59));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iplabel->sizePolicy().hasHeightForWidth());
        iplabel->setSizePolicy(sizePolicy);
        iplabel->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        iplabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(settingPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 240, 33, 51));
        label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 15pt \"Ubuntu\";"));
        portlabel_3 = new QLabel(settingPage);
        portlabel_3->setObjectName(QStringLiteral("portlabel_3"));
        portlabel_3->setGeometry(QRect(140, 240, 211, 49));
        sizePolicy.setHeightForWidth(portlabel_3->sizePolicy().hasHeightForWidth());
        portlabel_3->setSizePolicy(sizePolicy);
        portlabel_3->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        portlabel_3->setAlignment(Qt::AlignCenter);
        memoryEdt = new QLineEdit(settingPage);
        memoryEdt->setObjectName(QStringLiteral("memoryEdt"));
        memoryEdt->setGeometry(QRect(340, 250, 250, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(memoryEdt->sizePolicy().hasHeightForWidth());
        memoryEdt->setSizePolicy(sizePolicy1);
        memoryEdt->setMinimumSize(QSize(250, 30));
        memoryEdt->setStyleSheet(QLatin1String("#port_lineEdit{\n"
"	border-radius:3px;\n"
"}"));
        portlabel = new QLabel(settingPage);
        portlabel->setObjectName(QStringLiteral("portlabel"));
        portlabel->setGeometry(QRect(120, 170, 243, 59));
        sizePolicy.setHeightForWidth(portlabel->sizePolicy().hasHeightForWidth());
        portlabel->setSizePolicy(sizePolicy);
        portlabel->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        portlabel->setAlignment(Qt::AlignCenter);
        port_lineEdit = new QLineEdit(settingPage);
        port_lineEdit->setObjectName(QStringLiteral("port_lineEdit"));
        port_lineEdit->setGeometry(QRect(340, 180, 250, 40));
        sizePolicy1.setHeightForWidth(port_lineEdit->sizePolicy().hasHeightForWidth());
        port_lineEdit->setSizePolicy(sizePolicy1);
        port_lineEdit->setMinimumSize(QSize(250, 30));
        port_lineEdit->setStyleSheet(QLatin1String("#port_lineEdit{\n"
"	border-radius:3px;\n"
"}"));
        portlabel_5 = new QLabel(settingPage);
        portlabel_5->setObjectName(QStringLiteral("portlabel_5"));
        portlabel_5->setGeometry(QRect(130, 310, 211, 39));
        sizePolicy.setHeightForWidth(portlabel_5->sizePolicy().hasHeightForWidth());
        portlabel_5->setSizePolicy(sizePolicy);
        portlabel_5->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        portlabel_5->setAlignment(Qt::AlignCenter);
        radioButton = new QRadioButton(settingPage);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(340, 313, 25, 37));
        radioButton->setMinimumSize(QSize(25, 25));
        pushButton = new QPushButton(settingPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 380, 91, 41));
        pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        stackedWidget->addWidget(settingPage);
        bottomLayerFrame = new QFrame(SystemMainWin);
        bottomLayerFrame->setObjectName(QStringLiteral("bottomLayerFrame"));
        bottomLayerFrame->setGeometry(QRect(0, 0, 1051, 521));
        bottomLayerFrame->setStyleSheet(QStringLiteral("border-image: url(:/images/background.png);"));
        bottomLayerFrame->setFrameShape(QFrame::StyledPanel);
        bottomLayerFrame->setFrameShadow(QFrame::Raised);
        bottomLayerFrame->raise();
        leftWidget->raise();
        stackedWidget->raise();

        retranslateUi(SystemMainWin);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(SystemMainWin);
    } // setupUi

    void retranslateUi(QWidget *SystemMainWin)
    {
        SystemMainWin->setWindowTitle(QApplication::translate("SystemMainWin", "Form", Q_NULLPTR));
        headLabel->setText(QString());
        logoutBtn->setText(QApplication::translate("SystemMainWin", "\351\200\200\345\207\272", Q_NULLPTR));
        videoRecordtoolButton->setText(QApplication::translate("SystemMainWin", "\350\247\206\351\242\221\350\256\260\345\275\225", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("SystemMainWin", "\351\231\210\346\237\220\344\272\272", Q_NULLPTR));
        drivingModetoolButton->setText(QApplication::translate("SystemMainWin", "\350\241\214\350\275\246\346\250\241\345\274\217", Q_NULLPTR));
        reverseModetoolButton->setText(QApplication::translate("SystemMainWin", "\345\200\222\350\275\246\346\250\241\345\274\217", Q_NULLPTR));
        birdViewtoolButton->setText(QApplication::translate("SystemMainWin", "\351\270\237\347\236\260\346\250\241\345\274\217", Q_NULLPTR));
        featureRecordtoolButton->setText(QApplication::translate("SystemMainWin", "\347\211\271\345\276\201\350\256\260\345\275\225", Q_NULLPTR));
        systemSettingtoolButton->setText(QApplication::translate("SystemMainWin", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        drivingVideo->setText(QApplication::translate("SystemMainWin", "\350\241\214\350\275\246\346\250\241\345\274\217", Q_NULLPTR));
        reverseVideo->setText(QApplication::translate("SystemMainWin", "\345\200\222\350\275\246\346\250\241\345\274\217", Q_NULLPTR));
        birdEyeLabel->setText(QString());
        realTimeLabel->setText(QString());
        title_label->setText(QApplication::translate("SystemMainWin", "360\302\260\346\231\272\350\203\275\350\241\214\350\275\246\350\276\205\345\212\251\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        iplabel->setText(QApplication::translate("SystemMainWin", "\346\234\215\345\212\241\345\231\250\347\263\273\347\273\237IP\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("SystemMainWin", "GB", Q_NULLPTR));
        portlabel_3->setText(QApplication::translate("SystemMainWin", "\346\234\254\345\234\260\345\255\230\345\202\250\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        memoryEdt->setText(QString());
        portlabel->setText(QApplication::translate("SystemMainWin", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        portlabel_5->setText(QApplication::translate("SystemMainWin", "\345\255\230\346\273\241\350\207\252\345\212\250\345\210\240\351\231\244", Q_NULLPTR));
        radioButton->setText(QString());
        pushButton->setText(QApplication::translate("SystemMainWin", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SystemMainWin: public Ui_SystemMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMAINWIN_H
