#include "bigpicwidget.h"
#include "ui_bigpicwidget.h"

BigPicWidget::BigPicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BigPicWidget)
{
    ui->setupUi(this);
}

BigPicWidget::~BigPicWidget()
{
    delete ui;
}

void BigPicWidget::ShowPicture(QString picPath)
{
    this->img=QImage(picPath);
    this->img=this->img.scaled(ui->BigPicLabel->size());
    ui->BigPicLabel->setPixmap(QPixmap::fromImage(this->img));
    update();
}

void BigPicWidget::on_exitBtn_clicked()
{
    emit back2PicList();
}
