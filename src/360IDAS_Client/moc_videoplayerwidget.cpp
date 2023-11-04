/****************************************************************************
** Meta object code from reading C++ file 'videoplayerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Window/videoplayerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoplayerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoPlayerWidget_t {
    QByteArrayData data[17];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPlayerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPlayerWidget_t qt_meta_stringdata_VideoPlayerWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "VideoPlayerWidget"
QT_MOC_LITERAL(1, 18, 11), // "toVideoList"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "on_playBtn_clicked"
QT_MOC_LITERAL(4, 50, 10), // "ChangeData"
QT_MOC_LITERAL(5, 61, 7), // "current"
QT_MOC_LITERAL(6, 69, 3), // "Mat"
QT_MOC_LITERAL(7, 73, 5), // "frame"
QT_MOC_LITERAL(8, 79, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(9, 113, 34), // "on_horizontalSlider_sliderRel..."
QT_MOC_LITERAL(10, 148, 21), // "on_captureBtn_clicked"
QT_MOC_LITERAL(11, 170, 17), // "imageUploadResult"
QT_MOC_LITERAL(12, 188, 11), // "IMAGEBACKT*"
QT_MOC_LITERAL(13, 200, 18), // "on_exitBtn_clicked"
QT_MOC_LITERAL(14, 219, 11), // "playEndSlot"
QT_MOC_LITERAL(15, 231, 37), // "on_rationcomboBox_currentInde..."
QT_MOC_LITERAL(16, 269, 5) // "index"

    },
    "VideoPlayerWidget\0toVideoList\0\0"
    "on_playBtn_clicked\0ChangeData\0current\0"
    "Mat\0frame\0on_horizontalSlider_sliderPressed\0"
    "on_horizontalSlider_sliderReleased\0"
    "on_captureBtn_clicked\0imageUploadResult\0"
    "IMAGEBACKT*\0on_exitBtn_clicked\0"
    "playEndSlot\0on_rationcomboBox_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPlayerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    2,   66,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    5,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void VideoPlayerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoPlayerWidget *_t = static_cast<VideoPlayerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toVideoList(); break;
        case 1: _t->on_playBtn_clicked(); break;
        case 2: _t->ChangeData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 3: _t->on_horizontalSlider_sliderPressed(); break;
        case 4: _t->on_horizontalSlider_sliderReleased(); break;
        case 5: _t->on_captureBtn_clicked(); break;
        case 6: _t->imageUploadResult((*reinterpret_cast< IMAGEBACKT*(*)>(_a[1]))); break;
        case 7: _t->on_exitBtn_clicked(); break;
        case 8: _t->playEndSlot(); break;
        case 9: _t->on_rationcomboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (VideoPlayerWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPlayerWidget::toVideoList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject VideoPlayerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoPlayerWidget.data,
      qt_meta_data_VideoPlayerWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VideoPlayerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPlayerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPlayerWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VideoPlayerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void VideoPlayerWidget::toVideoList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
