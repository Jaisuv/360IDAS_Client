/********************************************************************************
** Form generated from reading UI file 'registwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTWIN_H
#define UI_REGISTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistWin
{
public:
    QFrame *frame1;
    QLabel *account_label;
    QLabel *name_label;
    QLabel *pwd_label;
    QLabel *rpwd_label;
    QLineEdit *account_lineEdit;
    QLineEdit *name_lineEdit;
    QLineEdit *pwd_lineEdit;
    QLineEdit *rpwd_lineEdit;
    QPushButton *ok_pushButton;
    QPushButton *cancel_pushButton;
    QPushButton *eyeBtn;
    QPushButton *eyeBtn_2;
    QPushButton *pushButton;
    QLabel *title_label;

    void setupUi(QWidget *RegistWin)
    {
        if (RegistWin->objectName().isEmpty())
            RegistWin->setObjectName(QStringLiteral("RegistWin"));
        RegistWin->resize(950, 450);
        RegistWin->setStyleSheet(QStringLiteral(""));
        frame1 = new QFrame(RegistWin);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setGeometry(QRect(0, 0, 950, 450));
        frame1->setStyleSheet(QLatin1String("#frame1{\n"
"	 border-image: url(:/images/background.png); \n"
"}\n"
""));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        account_label = new QLabel(frame1);
        account_label->setObjectName(QStringLiteral("account_label"));
        account_label->setGeometry(QRect(300, 100, 50, 50));
        account_label->setMaximumSize(QSize(100, 100));
        account_label->setStyleSheet(QStringLiteral(""));
        account_label->setPixmap(QPixmap(QString::fromUtf8(":/images/\347\224\250\346\210\267/\346\263\250\345\206\214.png")));
        account_label->setScaledContents(true);
        name_label = new QLabel(frame1);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(300, 160, 50, 50));
        name_label->setMaximumSize(QSize(50, 50));
        name_label->setStyleSheet(QStringLiteral(""));
        name_label->setPixmap(QPixmap(QString::fromUtf8(":/images/\347\224\250\346\210\267/\346\230\265\347\247\260.png")));
        name_label->setScaledContents(true);
        pwd_label = new QLabel(frame1);
        pwd_label->setObjectName(QStringLiteral("pwd_label"));
        pwd_label->setGeometry(QRect(300, 220, 50, 50));
        pwd_label->setMinimumSize(QSize(0, 0));
        pwd_label->setMaximumSize(QSize(50, 50));
        pwd_label->setStyleSheet(QStringLiteral(""));
        pwd_label->setPixmap(QPixmap(QString::fromUtf8(":/images/\347\224\250\346\210\267/\345\257\206\347\240\201.png")));
        pwd_label->setScaledContents(true);
        rpwd_label = new QLabel(frame1);
        rpwd_label->setObjectName(QStringLiteral("rpwd_label"));
        rpwd_label->setGeometry(QRect(300, 280, 50, 50));
        rpwd_label->setMaximumSize(QSize(50, 50));
        rpwd_label->setStyleSheet(QStringLiteral(""));
        rpwd_label->setPixmap(QPixmap(QString::fromUtf8(":/images/\347\224\250\346\210\267/\345\206\215\350\276\223\345\257\206\347\240\201.png")));
        rpwd_label->setScaledContents(true);
        account_lineEdit = new QLineEdit(frame1);
        account_lineEdit->setObjectName(QStringLiteral("account_lineEdit"));
        account_lineEdit->setGeometry(QRect(370, 100, 300, 50));
        name_lineEdit = new QLineEdit(frame1);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));
        name_lineEdit->setGeometry(QRect(370, 160, 300, 50));
        name_lineEdit->setEchoMode(QLineEdit::Normal);
        pwd_lineEdit = new QLineEdit(frame1);
        pwd_lineEdit->setObjectName(QStringLiteral("pwd_lineEdit"));
        pwd_lineEdit->setGeometry(QRect(370, 220, 240, 50));
        pwd_lineEdit->setEchoMode(QLineEdit::Password);
        rpwd_lineEdit = new QLineEdit(frame1);
        rpwd_lineEdit->setObjectName(QStringLiteral("rpwd_lineEdit"));
        rpwd_lineEdit->setGeometry(QRect(370, 280, 240, 50));
        rpwd_lineEdit->setEchoMode(QLineEdit::Password);
        ok_pushButton = new QPushButton(frame1);
        ok_pushButton->setObjectName(QStringLiteral("ok_pushButton"));
        ok_pushButton->setGeometry(QRect(300, 350, 110, 40));
        ok_pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        cancel_pushButton = new QPushButton(frame1);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));
        cancel_pushButton->setGeometry(QRect(580, 350, 110, 40));
        cancel_pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        eyeBtn = new QPushButton(frame1);
        eyeBtn->setObjectName(QStringLiteral("eyeBtn"));
        eyeBtn->setGeometry(QRect(620, 220, 50, 50));
        eyeBtn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\347\224\250\346\210\267/unvisible.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/\347\224\250\346\210\267/visible.png"), QSize(), QIcon::Normal, QIcon::On);
        eyeBtn->setIcon(icon);
        eyeBtn->setIconSize(QSize(35, 35));
        eyeBtn_2 = new QPushButton(frame1);
        eyeBtn_2->setObjectName(QStringLiteral("eyeBtn_2"));
        eyeBtn_2->setGeometry(QRect(620, 280, 50, 50));
        eyeBtn_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        eyeBtn_2->setIcon(icon);
        eyeBtn_2->setIconSize(QSize(35, 35));
        pushButton = new QPushButton(frame1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 410, 61, 25));
        title_label = new QLabel(frame1);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setGeometry(QRect(20, 20, 911, 79));
        title_label->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(255, 255, 255, 255), stop:0.373979 rgba(255, 255, 255, 255), stop:0.373991 rgba(33, 30, 255, 255), stop:0.624018 rgba(33, 30, 255, 255), stop:0.624043 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));"));
        title_label->setAlignment(Qt::AlignCenter);
        name_label->raise();
        pwd_label->raise();
        rpwd_label->raise();
        account_lineEdit->raise();
        name_lineEdit->raise();
        pwd_lineEdit->raise();
        rpwd_lineEdit->raise();
        ok_pushButton->raise();
        cancel_pushButton->raise();
        account_label->raise();
        eyeBtn->raise();
        eyeBtn_2->raise();
        pushButton->raise();
        title_label->raise();

        retranslateUi(RegistWin);

        QMetaObject::connectSlotsByName(RegistWin);
    } // setupUi

    void retranslateUi(QWidget *RegistWin)
    {
        RegistWin->setWindowTitle(QApplication::translate("RegistWin", "Form", Q_NULLPTR));
        account_label->setText(QString());
        name_label->setText(QString());
        pwd_label->setText(QString());
        rpwd_label->setText(QString());
        account_lineEdit->setText(QString());
        account_lineEdit->setPlaceholderText(QApplication::translate("RegistWin", "\350\264\246\345\217\267", Q_NULLPTR));
        name_lineEdit->setText(QString());
        name_lineEdit->setPlaceholderText(QApplication::translate("RegistWin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        pwd_lineEdit->setPlaceholderText(QApplication::translate("RegistWin", "\345\257\206\347\240\201", Q_NULLPTR));
        rpwd_lineEdit->setPlaceholderText(QApplication::translate("RegistWin", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        ok_pushButton->setText(QApplication::translate("RegistWin", "\347\241\256\345\256\232", Q_NULLPTR));
        cancel_pushButton->setText(QApplication::translate("RegistWin", "\345\217\226\346\266\210", Q_NULLPTR));
        eyeBtn->setText(QString());
        eyeBtn_2->setText(QString());
        pushButton->setText(QApplication::translate("RegistWin", "\351\207\215\347\275\256", Q_NULLPTR));
        title_label->setText(QApplication::translate("RegistWin", "360\302\260\346\231\272\350\203\275\350\241\214\350\275\246\350\276\205\345\212\251\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegistWin: public Ui_RegistWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTWIN_H
