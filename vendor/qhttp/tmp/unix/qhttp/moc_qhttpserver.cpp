/****************************************************************************
** Meta object code from reading C++ file 'qhttpserver.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/qhttpserver.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpserver.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qhttp__server__QHttpServer_t {
    QByteArrayData data[11];
    char stringdata[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qhttp__server__QHttpServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qhttp__server__QHttpServer_t qt_meta_stringdata_qhttp__server__QHttpServer = {
    {
QT_MOC_LITERAL(0, 0, 26),
QT_MOC_LITERAL(1, 27, 10),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 13),
QT_MOC_LITERAL(4, 53, 7),
QT_MOC_LITERAL(5, 61, 14),
QT_MOC_LITERAL(6, 76, 8),
QT_MOC_LITERAL(7, 85, 13),
QT_MOC_LITERAL(8, 99, 16),
QT_MOC_LITERAL(9, 116, 10),
QT_MOC_LITERAL(10, 127, 7)
    },
    "qhttp::server::QHttpServer\0newRequest\0"
    "\0QHttpRequest*\0request\0QHttpResponse*\0"
    "response\0newConnection\0QHttpConnection*\0"
    "connection\0timeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qhttp__server__QHttpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       7,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // properties: name, type, flags
      10, QMetaType::UInt, 0x00095103,

       0        // eod
};

void qhttp::server::QHttpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHttpServer *_t = static_cast<QHttpServer *>(_o);
        switch (_id) {
        case 0: _t->newRequest((*reinterpret_cast< QHttpRequest*(*)>(_a[1])),(*reinterpret_cast< QHttpResponse*(*)>(_a[2]))); break;
        case 1: _t->newConnection((*reinterpret_cast< QHttpConnection*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QHttpServer::*_t)(QHttpRequest * , QHttpResponse * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpServer::newRequest)) {
                *result = 0;
            }
        }
        {
            typedef void (QHttpServer::*_t)(QHttpConnection * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpServer::newConnection)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject qhttp::server::QHttpServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qhttp__server__QHttpServer.data,
      qt_meta_data_qhttp__server__QHttpServer,  qt_static_metacall, 0, 0}
};


const QMetaObject *qhttp::server::QHttpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qhttp::server::QHttpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qhttp__server__QHttpServer.stringdata))
        return static_cast<void*>(const_cast< QHttpServer*>(this));
    return QObject::qt_metacast(_clname);
}

int qhttp::server::QHttpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< quint32*>(_v) = timeOut(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTimeOut(*reinterpret_cast< quint32*>(_v)); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void qhttp::server::QHttpServer::newRequest(QHttpRequest * _t1, QHttpResponse * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qhttp::server::QHttpServer::newConnection(QHttpConnection * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
