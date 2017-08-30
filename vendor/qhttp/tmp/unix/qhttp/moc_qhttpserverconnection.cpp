/****************************************************************************
** Meta object code from reading C++ file 'qhttpserverconnection.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/qhttpserverconnection.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpserverconnection.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qhttp__server__QHttpConnection_t {
    QByteArrayData data[8];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qhttp__server__QHttpConnection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qhttp__server__QHttpConnection_t qt_meta_stringdata_qhttp__server__QHttpConnection = {
    {
QT_MOC_LITERAL(0, 0, 30),
QT_MOC_LITERAL(1, 31, 10),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 13),
QT_MOC_LITERAL(4, 57, 3),
QT_MOC_LITERAL(5, 61, 14),
QT_MOC_LITERAL(6, 76, 3),
QT_MOC_LITERAL(7, 80, 12)
    },
    "qhttp::server::QHttpConnection\0"
    "newRequest\0\0QHttpRequest*\0req\0"
    "QHttpResponse*\0res\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qhttp__server__QHttpConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       7,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

       0        // eod
};

void qhttp::server::QHttpConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHttpConnection *_t = static_cast<QHttpConnection *>(_o);
        switch (_id) {
        case 0: _t->newRequest((*reinterpret_cast< QHttpRequest*(*)>(_a[1])),(*reinterpret_cast< QHttpResponse*(*)>(_a[2]))); break;
        case 1: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QHttpConnection::*_t)(QHttpRequest * , QHttpResponse * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpConnection::newRequest)) {
                *result = 0;
            }
        }
        {
            typedef void (QHttpConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpConnection::disconnected)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject qhttp::server::QHttpConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qhttp__server__QHttpConnection.data,
      qt_meta_data_qhttp__server__QHttpConnection,  qt_static_metacall, 0, 0}
};


const QMetaObject *qhttp::server::QHttpConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qhttp::server::QHttpConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qhttp__server__QHttpConnection.stringdata))
        return static_cast<void*>(const_cast< QHttpConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int qhttp::server::QHttpConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qhttp::server::QHttpConnection::newRequest(QHttpRequest * _t1, QHttpResponse * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qhttp::server::QHttpConnection::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
