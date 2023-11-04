#ifndef VIDEOSCREENSHOTDELEGATE_H
#define VIDEOSCREENSHOTDELEGATE_H


#include <QStyledItemDelegate>

class VideoScreenShotDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    VideoScreenShotDelegate(QWidget *parent = nullptr);
    virtual ~VideoScreenShotDelegate();

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // VIDEOSCREENSHOTDELEGATE_H
