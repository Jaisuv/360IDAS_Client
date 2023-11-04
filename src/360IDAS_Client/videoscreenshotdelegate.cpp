#include "videoscreenshotdelegate.h"

VideoScreenShotDelegate::VideoScreenShotDelegate(QWidget *parent)
{

}

VideoScreenShotDelegate::~VideoScreenShotDelegate()
{

}

void VideoScreenShotDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // option.rect属性中保存了Item的位置
    editor->setGeometry(option.rect);
}
