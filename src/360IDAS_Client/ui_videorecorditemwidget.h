/********************************************************************************
** Form generated from reading UI file 'videorecorditemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEORECORDITEMWIDGET_H
#define UI_VIDEORECORDITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoRecordItemWidget
{
public:
    QLabel *cover_label;
    QPushButton *pushButton;
    QLabel *time_label;
    QLabel *percent_label;
    QLabel *percentNum_label;

    void setupUi(QWidget *VideoRecordItemWidget)
    {
        if (VideoRecordItemWidget->objectName().isEmpty())
            VideoRecordItemWidget->setObjectName(QStringLiteral("VideoRecordItemWidget"));
        VideoRecordItemWidget->resize(412, 235);
        cover_label = new QLabel(VideoRecordItemWidget);
        cover_label->setObjectName(QStringLiteral("cover_label"));
        cover_label->setGeometry(QRect(0, 0, 412, 235));
        QFont font;
        font.setPointSize(3);
        cover_label->setFont(font);
        cover_label->setStyleSheet(QStringLiteral("background-color: rgb(173, 127, 168);"));
        cover_label->setScaledContents(true);
        pushButton = new QPushButton(VideoRecordItemWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 190, 35, 35));
        time_label = new QLabel(VideoRecordItemWidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(0, 190, 331, 20));
        time_label->setStyleSheet(QLatin1String("\n"
"	font: 15pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"	background:transparent;\n"
""));
        percent_label = new QLabel(VideoRecordItemWidget);
        percent_label->setObjectName(QStringLiteral("percent_label"));
        percent_label->setGeometry(QRect(0, 210, 71, 20));
        percent_label->setStyleSheet(QLatin1String("\n"
"	font: 15pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"	background:transparent;\n"
""));
        percentNum_label = new QLabel(VideoRecordItemWidget);
        percentNum_label->setObjectName(QStringLiteral("percentNum_label"));
        percentNum_label->setGeometry(QRect(70, 210, 131, 20));
        percentNum_label->setStyleSheet(QLatin1String("\n"
"	font: 15pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"	background:transparent;\n"
""));

        retranslateUi(VideoRecordItemWidget);

        QMetaObject::connectSlotsByName(VideoRecordItemWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoRecordItemWidget)
    {
        VideoRecordItemWidget->setWindowTitle(QApplication::translate("VideoRecordItemWidget", "Form", Q_NULLPTR));
        cover_label->setText(QString());
        pushButton->setText(QApplication::translate("VideoRecordItemWidget", "\346\222\255\346\224\276", Q_NULLPTR));
        time_label->setText(QApplication::translate("VideoRecordItemWidget", "2023-10-13 11:59:30", Q_NULLPTR));
        percent_label->setText(QApplication::translate("VideoRecordItemWidget", "\345\267\262\350\247\202\347\234\213:", Q_NULLPTR));
        percentNum_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoRecordItemWidget: public Ui_VideoRecordItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEORECORDITEMWIDGET_H
