/****************************************************************************
** Meta object code from reading C++ file 'registwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Window/registwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegistWin_t {
    QByteArrayData data[11];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RegistWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RegistWin_t qt_meta_stringdata_RegistWin = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RegistWin"
QT_MOC_LITERAL(1, 10, 10), // "back2Login"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 17), // "AccountBeReturned"
QT_MOC_LITERAL(4, 40, 28), // "on_cancel_pushButton_clicked"
QT_MOC_LITERAL(5, 69, 24), // "on_ok_pushButton_clicked"
QT_MOC_LITERAL(6, 94, 17), // "on_eyeBtn_clicked"
QT_MOC_LITERAL(7, 112, 19), // "on_eyeBtn_2_clicked"
QT_MOC_LITERAL(8, 132, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 154, 9), // "isChecked"
QT_MOC_LITERAL(10, 164, 4) // "flag"

    },
    "RegistWin\0back2Login\0\0AccountBeReturned\0"
    "on_cancel_pushButton_clicked\0"
    "on_ok_pushButton_clicked\0on_eyeBtn_clicked\0"
    "on_eyeBtn_2_clicked\0on_pushButton_clicked\0"
    "isChecked\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegistWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void RegistWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RegistWin *_t = static_cast<RegistWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back2Login((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_cancel_pushButton_clicked(); break;
        case 2: _t->on_ok_pushButton_clicked(); break;
        case 3: _t->on_eyeBtn_clicked(); break;
        case 4: _t->on_eyeBtn_2_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->isChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RegistWin::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegistWin::back2Login)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RegistWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RegistWin.data,
      qt_meta_data_RegistWin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RegistWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegistWin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RegistWin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RegistWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RegistWin::back2Login(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
