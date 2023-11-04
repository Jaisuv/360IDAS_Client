/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

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

class Ui_LoginWin
{
public:
    QFrame *frame1;
    QPushButton *eyeBtn;
    QLabel *title_label;
    QLineEdit *account_lineEdit;
    QLabel *account_label;
    QLineEdit *verification_lineEdit;
    QLabel *verification_label;
    QLineEdit *pwd_lineEdit;
    QLabel *pwd_label;
    QPushButton *regist_pushButton;
    QPushButton *login_pushButton;
    QPushButton *cancel_pushButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QStringLiteral("LoginWin"));
        LoginWin->resize(950, 450);
        frame1 = new QFrame(LoginWin);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setGeometry(QRect(0, 0, 950, 450));
        frame1->setStyleSheet(QLatin1String("#frame1{\n"
"	 border-image: url(:/images/background.png); \n"
"}\n"
""));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        eyeBtn = new QPushButton(frame1);
        eyeBtn->setObjectName(QStringLiteral("eyeBtn"));
        eyeBtn->setGeometry(QRect(610, 200, 47, 41));
        eyeBtn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\347\224\250\346\210\267/unvisible.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/\347\224\250\346\210\267/visible.png"), QSize(), QIcon::Normal, QIcon::On);
        eyeBtn->setIcon(icon);
        eyeBtn->setIconSize(QSize(35, 35));
        title_label = new QLabel(frame1);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setGeometry(QRect(30, 50, 889, 37));
        title_label->setStyleSheet(QLatin1String("color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:0.495 rgba(255, 255, 255, 255), stop:0.505 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));\n"
"font: 18pt \"Ubuntu\";"));
        title_label->setAlignment(Qt::AlignCenter);
        account_lineEdit = new QLineEdit(frame1);
        account_lineEdit->setObjectName(QStringLiteral("account_lineEdit"));
        account_lineEdit->setGeometry(QRect(380, 130, 278, 40));
        account_lineEdit->setMinimumSize(QSize(0, 40));
        account_lineEdit->setStyleSheet(QStringLiteral(""));
        account_lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        account_lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        account_lineEdit->setClearButtonEnabled(false);
        account_label = new QLabel(frame1);
        account_label->setObjectName(QStringLiteral("account_label"));
        account_label->setGeometry(QRect(340, 130, 35, 35));
        account_label->setMaximumSize(QSize(35, 35));
        account_label->setPixmap(QPixmap(QString::fromUtf8(":/images/\347\224\250\346\210\267/\350\264\246\345\217\267.png")));
        account_label->setScaledContents(true);
        verification_lineEdit = new QLineEdit(frame1);
        verification_lineEdit->setObjectName(QStringLiteral("verification_lineEdit"));
        verification_lineEdit->setGeometry(QRect(380, 270, 142, 40));
        verification_lineEdit->setMinimumSize(QSize(0, 40));
        verification_lineEdit->setMaximumSize(QSize(300, 16777215));
        verification_label = new QLabel(frame1);
        verification_label->setObjectName(QStringLiteral("verification_label"));
        verification_label->setGeometry(QRect(340, 270, 35, 35));
        verification_label->setMaximumSize(QSize(35, 35));
        verification_label->setPixmap(QPixmap(QString::fromUtf8(":/images/\347\224\250\346\210\267/\351\252\214\350\257\201.png")));
        verification_label->setScaledContents(true);
        pwd_lineEdit = new QLineEdit(frame1);
        pwd_lineEdit->setObjectName(QStringLiteral("pwd_lineEdit"));
        pwd_lineEdit->setGeometry(QRect(380, 200, 221, 40));
        pwd_lineEdit->setMinimumSize(QSize(0, 40));
        pwd_lineEdit->setEchoMode(QLineEdit::Password);
        pwd_label = new QLabel(frame1);
        pwd_label->setObjectName(QStringLiteral("pwd_label"));
        pwd_label->setGeometry(QRect(340, 200, 35, 35));
        pwd_label->setMaximumSize(QSize(35, 35));
        pwd_label->setPixmap(QPixmap(QString::fromUtf8(":/images/\347\224\250\346\210\267/\345\257\206\347\240\201.png")));
        pwd_label->setScaledContents(true);
        regist_pushButton = new QPushButton(frame1);
        regist_pushButton->setObjectName(QStringLiteral("regist_pushButton"));
        regist_pushButton->setGeometry(QRect(410, 340, 110, 40));
        regist_pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        login_pushButton = new QPushButton(frame1);
        login_pushButton->setObjectName(QStringLiteral("login_pushButton"));
        login_pushButton->setGeometry(QRect(260, 340, 110, 40));
        login_pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        cancel_pushButton = new QPushButton(frame1);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));
        cancel_pushButton->setGeometry(QRect(560, 340, 110, 40));
        cancel_pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Ubuntu\";"));
        pushButton = new QPushButton(frame1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 400, 80, 31));
        pushButton_2 = new QPushButton(frame1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(840, 400, 80, 31));

        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QWidget *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "Form", Q_NULLPTR));
        eyeBtn->setText(QString());
        title_label->setText(QApplication::translate("LoginWin", "360\302\260\346\231\272\350\203\275\350\241\214\350\275\246\350\276\205\345\212\251\347\263\273\347\273\237", Q_NULLPTR));
        account_lineEdit->setPlaceholderText(QApplication::translate("LoginWin", "\350\264\246\345\217\267", Q_NULLPTR));
        account_label->setText(QString());
        verification_lineEdit->setText(QApplication::translate("LoginWin", "1111", Q_NULLPTR));
        verification_lineEdit->setPlaceholderText(QApplication::translate("LoginWin", "\351\252\214\350\257\201\347\240\201", Q_NULLPTR));
        verification_label->setText(QString());
        pwd_lineEdit->setText(QString());
        pwd_lineEdit->setPlaceholderText(QApplication::translate("LoginWin", "\345\257\206\347\240\201", Q_NULLPTR));
        pwd_label->setText(QString());
        regist_pushButton->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214", Q_NULLPTR));
        login_pushButton->setText(QApplication::translate("LoginWin", "\347\231\273\345\275\225", Q_NULLPTR));
        cancel_pushButton->setText(QApplication::translate("LoginWin", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LoginWin", "\351\207\215\347\275\256", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LoginWin", "\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
