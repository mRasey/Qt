/****************************************************************************
** Meta object code from reading C++ file 'udp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../udp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UDP_t {
    QByteArrayData data[8];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDP_t qt_meta_stringdata_UDP = {
    {
QT_MOC_LITERAL(0, 0, 3), // "UDP"
QT_MOC_LITERAL(1, 4, 12), // "GetNameAndIp"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 13), // "flushTextView"
QT_MOC_LITERAL(4, 32, 12), // "getClickedIp"
QT_MOC_LITERAL(5, 45, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 62, 5), // "newly"
QT_MOC_LITERAL(7, 68, 12) // "getAppointIp"

    },
    "UDP\0GetNameAndIp\0\0flushTextView\0"
    "getClickedIp\0QListWidgetItem*\0newly\0"
    "getAppointIp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void UDP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UDP *_t = static_cast<UDP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetNameAndIp(); break;
        case 1: _t->flushTextView(); break;
        case 2: _t->getClickedIp((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->getAppointIp(); break;
        default: ;
        }
    }
}

const QMetaObject UDP::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UDP.data,
      qt_meta_data_UDP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UDP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UDP.stringdata0))
        return static_cast<void*>(const_cast< UDP*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UDP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
