/****************************************************************************
** Meta object code from reading C++ file 'readthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Thread/readthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'readthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReadThread_t {
    QByteArrayData data[18];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadThread_t qt_meta_stringdata_ReadThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ReadThread"
QT_MOC_LITERAL(1, 11, 20), // "login_Request_Result"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "flag"
QT_MOC_LITERAL(4, 38, 8), // "UserName"
QT_MOC_LITERAL(5, 47, 3), // "uid"
QT_MOC_LITERAL(6, 51, 21), // "regist_Request_Result"
QT_MOC_LITERAL(7, 73, 19), // "image_Upload_Result"
QT_MOC_LITERAL(8, 93, 11), // "IMAGEBACKT*"
QT_MOC_LITERAL(9, 105, 18), // "videoRecordInfoRes"
QT_MOC_LITERAL(10, 124, 18), // "videoSearchResSign"
QT_MOC_LITERAL(11, 143, 11), // "SEARCHREST*"
QT_MOC_LITERAL(12, 155, 13), // "videosearInfo"
QT_MOC_LITERAL(13, 169, 17), // "imageSearchResSig"
QT_MOC_LITERAL(14, 187, 15), // "IMAGESERCHREST*"
QT_MOC_LITERAL(15, 203, 12), // "imageSearRes"
QT_MOC_LITERAL(16, 216, 12), // "LogoutSignal"
QT_MOC_LITERAL(17, 229, 14) // "hearBeatSingal"

    },
    "ReadThread\0login_Request_Result\0\0flag\0"
    "UserName\0uid\0regist_Request_Result\0"
    "image_Upload_Result\0IMAGEBACKT*\0"
    "videoRecordInfoRes\0videoSearchResSign\0"
    "SEARCHREST*\0videosearInfo\0imageSearchResSig\0"
    "IMAGESERCHREST*\0imageSearRes\0LogoutSignal\0"
    "hearBeatSingal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,
       6,    1,   61,    2, 0x06 /* Public */,
       7,    1,   64,    2, 0x06 /* Public */,
       9,    1,   67,    2, 0x06 /* Public */,
      10,    1,   70,    2, 0x06 /* Public */,
      13,    1,   73,    2, 0x06 /* Public */,
      16,    1,   76,    2, 0x06 /* Public */,
      17,    0,   79,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ReadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReadThread *_t = static_cast<ReadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->login_Request_Result((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->regist_Request_Result((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->image_Upload_Result((*reinterpret_cast< IMAGEBACKT*(*)>(_a[1]))); break;
        case 3: _t->videoRecordInfoRes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->videoSearchResSign((*reinterpret_cast< SEARCHREST*(*)>(_a[1]))); break;
        case 5: _t->imageSearchResSig((*reinterpret_cast< IMAGESERCHREST*(*)>(_a[1]))); break;
        case 6: _t->LogoutSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->hearBeatSingal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ReadThread::*_t)(int , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::login_Request_Result)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::regist_Request_Result)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(IMAGEBACKT * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::image_Upload_Result)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::videoRecordInfoRes)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(SEARCHREST * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::videoSearchResSign)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(IMAGESERCHREST * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::imageSearchResSig)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::LogoutSignal)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::hearBeatSingal)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject ReadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ReadThread.data,
      qt_meta_data_ReadThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ReadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReadThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ReadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ReadThread::login_Request_Result(int _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ReadThread::regist_Request_Result(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ReadThread::image_Upload_Result(IMAGEBACKT * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ReadThread::videoRecordInfoRes(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ReadThread::videoSearchResSign(SEARCHREST * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ReadThread::imageSearchResSig(IMAGESERCHREST * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ReadThread::LogoutSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ReadThread::hearBeatSingal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
