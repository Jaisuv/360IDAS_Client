/********************************************************************************
** Form generated from reading UI file 'csettinginit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSETTINGINIT_H
#define UI_CSETTINGINIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSettingInit
{
public:
    QFrame *frame1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *title_label;
    QLabel *iplabel;
    QLabel *portlabel;
    QLineEdit *port_lineEdit;
    QPushButton *pushButton;
    QLabel *portlabel_4;
    QRadioButton *radioButton;
    QLabel *portlabel_3;
    QLabel *label;
    QLineEdit *memoryEdt;

    void setupUi(QWidget *CSettingInit)
    {
        if (CSettingInit->objectName().isEmpty())
            CSettingInit->setObjectName(QStringLiteral("CSettingInit"));
        CSettingInit->setEnabled(true);
        CSettingInit->resize(998, 530);
        CSettingInit->setStyleSheet(QStringLiteral(""));
        frame1 = new QFrame(CSettingInit);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setGeometry(QRect(0, 0, 950, 531));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame1->sizePolicy().hasHeightForWidth());
        frame1->setSizePolicy(sizePolicy);
        frame1->setStyleSheet(QLatin1String("#frame1{\n"
"	font: 20pt \"Ubuntu\";\n"
"border-image: url(:/images/background.png);\n"
"}"));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        pushButton_3 = new QPushButton(frame1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(660, 400, 90, 50));
        pushButton_3->setStyleSheet(QLatin1String("font: 24pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);\n"
"background-color: rgb(239, 41, 41);"));
        pushButton_2 = new QPushButton(frame1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 400, 90, 50));
        pushButton_2->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        title_label = new QLabel(frame1);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setGeometry(QRect(250, 40, 501, 41));
        title_label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 30pt \"Ubuntu\";"));
        title_label->setAlignment(Qt::AlignCenter);
        iplabel = new QLabel(frame1);
        iplabel->setObjectName(QStringLiteral("iplabel"));
        iplabel->setGeometry(QRect(220, 110, 201, 59));
        sizePolicy.setHeightForWidth(iplabel->sizePolicy().hasHeightForWidth());
        iplabel->setSizePolicy(sizePolicy);
        iplabel->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        iplabel->setAlignment(Qt::AlignCenter);
        portlabel = new QLabel(frame1);
        portlabel->setObjectName(QStringLiteral("portlabel"));
        portlabel->setGeometry(QRect(230, 170, 191, 65));
        sizePolicy.setHeightForWidth(portlabel->sizePolicy().hasHeightForWidth());
        portlabel->setSizePolicy(sizePolicy);
        portlabel->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        portlabel->setAlignment(Qt::AlignCenter);
        port_lineEdit = new QLineEdit(frame1);
        port_lineEdit->setObjectName(QStringLiteral("port_lineEdit"));
        port_lineEdit->setGeometry(QRect(427, 185, 250, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(port_lineEdit->sizePolicy().hasHeightForWidth());
        port_lineEdit->setSizePolicy(sizePolicy1);
        port_lineEdit->setMinimumSize(QSize(250, 30));
        port_lineEdit->setStyleSheet(QLatin1String("#port_lineEdit{\n"
"	border-radius:3px;\n"
"}"));
        pushButton = new QPushButton(frame1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 400, 90, 50));
        pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        portlabel_4 = new QLabel(frame1);
        portlabel_4->setObjectName(QStringLiteral("portlabel_4"));
        portlabel_4->setGeometry(QRect(230, 320, 161, 39));
        sizePolicy.setHeightForWidth(portlabel_4->sizePolicy().hasHeightForWidth());
        portlabel_4->setSizePolicy(sizePolicy);
        portlabel_4->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        portlabel_4->setAlignment(Qt::AlignCenter);
        radioButton = new QRadioButton(frame1);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(430, 330, 16, 20));
        portlabel_3 = new QLabel(frame1);
        portlabel_3->setObjectName(QStringLiteral("portlabel_3"));
        portlabel_3->setGeometry(QRect(230, 240, 191, 49));
        sizePolicy.setHeightForWidth(portlabel_3->sizePolicy().hasHeightForWidth());
        portlabel_3->setSizePolicy(sizePolicy);
        portlabel_3->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        portlabel_3->setAlignment(Qt::AlignCenter);
        label = new QLabel(frame1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 240, 51, 51));
        label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 20pt \"Ubuntu\";"));
        memoryEdt = new QLineEdit(frame1);
        memoryEdt->setObjectName(QStringLiteral("memoryEdt"));
        memoryEdt->setGeometry(QRect(427, 250, 250, 40));
        sizePolicy1.setHeightForWidth(memoryEdt->sizePolicy().hasHeightForWidth());
        memoryEdt->setSizePolicy(sizePolicy1);
        memoryEdt->setMinimumSize(QSize(250, 30));
        memoryEdt->setStyleSheet(QLatin1String("#port_lineEdit{\n"
"	border-radius:3px;\n"
"}"));

        retranslateUi(CSettingInit);

        QMetaObject::connectSlotsByName(CSettingInit);
    } // setupUi

    void retranslateUi(QWidget *CSettingInit)
    {
        CSettingInit->setWindowTitle(QApplication::translate("CSettingInit", "Form", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CSettingInit", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CSettingInit", "\346\265\213\350\257\225", Q_NULLPTR));
        title_label->setText(QApplication::translate("CSettingInit", "360\302\260\346\231\272\350\203\275\350\241\214\350\275\246\350\276\205\345\212\251\347\263\273\347\273\237 v1.0", Q_NULLPTR));
        iplabel->setText(QApplication::translate("CSettingInit", "\346\234\215\345\212\241\345\231\250\347\263\273\347\273\237IP\357\274\232", Q_NULLPTR));
        portlabel->setText(QApplication::translate("CSettingInit", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CSettingInit", "\347\241\256\345\256\232", Q_NULLPTR));
        portlabel_4->setText(QApplication::translate("CSettingInit", "\345\255\230\346\273\241\350\207\252\345\212\250\345\210\240\351\231\244", Q_NULLPTR));
        radioButton->setText(QString());
        portlabel_3->setText(QApplication::translate("CSettingInit", "\346\234\254\345\234\260\345\255\230\345\202\250\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("CSettingInit", "GB", Q_NULLPTR));
        memoryEdt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CSettingInit: public Ui_CSettingInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSETTINGINIT_H
