/****************************************************************************
** Meta object code from reading C++ file 'loginwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Window/loginwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginWin_t {
    QByteArrayData data[16];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginWin_t qt_meta_stringdata_LoginWin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LoginWin"
QT_MOC_LITERAL(1, 9, 25), // "cancel_pushButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 28), // "on_cancel_pushButton_clicked"
QT_MOC_LITERAL(4, 65, 27), // "on_login_pushButton_clicked"
QT_MOC_LITERAL(5, 93, 17), // "on_eyeBtn_clicked"
QT_MOC_LITERAL(6, 111, 9), // "isChecked"
QT_MOC_LITERAL(7, 121, 4), // "flag"
QT_MOC_LITERAL(8, 126, 8), // "UserName"
QT_MOC_LITERAL(9, 135, 3), // "uid"
QT_MOC_LITERAL(10, 139, 20), // "regWinBackThisReShow"
QT_MOC_LITERAL(11, 160, 28), // "on_regist_pushButton_clicked"
QT_MOC_LITERAL(12, 189, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 211, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(14, 235, 10), // "logoutSlot"
QT_MOC_LITERAL(15, 246, 17) // "heartBeatMissSlot"

    },
    "LoginWin\0cancel_pushButton_clicked\0\0"
    "on_cancel_pushButton_clicked\0"
    "on_login_pushButton_clicked\0"
    "on_eyeBtn_clicked\0isChecked\0flag\0"
    "UserName\0uid\0regWinBackThisReShow\0"
    "on_regist_pushButton_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "logoutSlot\0heartBeatMissSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    3,   73,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,    7,    8,    9,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginWin *_t = static_cast<LoginWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cancel_pushButton_clicked(); break;
        case 1: _t->on_cancel_pushButton_clicked(); break;
        case 2: _t->on_login_pushButton_clicked(); break;
        case 3: _t->on_eyeBtn_clicked(); break;
        case 4: _t->isChecked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->regWinBackThisReShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_regist_pushButton_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->logoutSlot(); break;
        case 10: _t->heartBeatMissSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LoginWin::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWin::cancel_pushButton_clicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LoginWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginWin.data,
      qt_meta_data_LoginWin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LoginWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void LoginWin::cancel_pushButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
