/********************************************************************************
** Form generated from reading UI file 'bigpicwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIGPICWIDGET_H
#define UI_BIGPICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BigPicWidget
{
public:
    QFrame *bottomLayerFrame;
    QLabel *BigPicLabel;
    QPushButton *exitBtn;

    void setupUi(QWidget *BigPicWidget)
    {
        if (BigPicWidget->objectName().isEmpty())
            BigPicWidget->setObjectName(QStringLiteral("BigPicWidget"));
        BigPicWidget->resize(850, 450);
        bottomLayerFrame = new QFrame(BigPicWidget);
        bottomLayerFrame->setObjectName(QStringLiteral("bottomLayerFrame"));
        bottomLayerFrame->setGeometry(QRect(0, 0, 850, 450));
        bottomLayerFrame->setFrameShape(QFrame::StyledPanel);
        bottomLayerFrame->setFrameShadow(QFrame::Raised);
        BigPicLabel = new QLabel(bottomLayerFrame);
        BigPicLabel->setObjectName(QStringLiteral("BigPicLabel"));
        BigPicLabel->setGeometry(QRect(0, 0, 850, 450));
        BigPicLabel->setAlignment(Qt::AlignCenter);
        exitBtn = new QPushButton(bottomLayerFrame);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(10, 10, 61, 25));

        retranslateUi(BigPicWidget);

        QMetaObject::connectSlotsByName(BigPicWidget);
    } // setupUi

    void retranslateUi(QWidget *BigPicWidget)
    {
        BigPicWidget->setWindowTitle(QApplication::translate("BigPicWidget", "Form", Q_NULLPTR));
        BigPicLabel->setText(QApplication::translate("BigPicWidget", "\345\233\276\347\211\207\346\224\276\345\244\247", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("BigPicWidget", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BigPicWidget: public Ui_BigPicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIGPICWIDGET_H
