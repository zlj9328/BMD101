/****************************************************************************
** Meta object code from reading C++ file 'DataCollectThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DataCollectThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataCollectThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataCollectThread_t {
    QByteArrayData data[8];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataCollectThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataCollectThread_t qt_meta_stringdata_DataCollectThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DataCollectThread"
QT_MOC_LITERAL(1, 18, 20), // "SerialPortFlagSignal"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 4), // "flag"
QT_MOC_LITERAL(4, 45, 28), // "SerialPortRawWaveValueSignal"
QT_MOC_LITERAL(5, 74, 5), // "value"
QT_MOC_LITERAL(6, 80, 30), // "SerialPortHeartRateValueSignal"
QT_MOC_LITERAL(7, 111, 33) // "SerialPortPoorSignalQualitySi..."

    },
    "DataCollectThread\0SerialPortFlagSignal\0"
    "\0flag\0SerialPortRawWaveValueSignal\0"
    "value\0SerialPortHeartRateValueSignal\0"
    "SerialPortPoorSignalQualitySignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataCollectThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       7,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void DataCollectThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataCollectThread *_t = static_cast<DataCollectThread *>(_o);
        switch (_id) {
        case 0: _t->SerialPortFlagSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SerialPortRawWaveValueSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SerialPortHeartRateValueSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SerialPortPoorSignalQualitySignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataCollectThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataCollectThread::SerialPortFlagSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (DataCollectThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataCollectThread::SerialPortRawWaveValueSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (DataCollectThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataCollectThread::SerialPortHeartRateValueSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (DataCollectThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataCollectThread::SerialPortPoorSignalQualitySignal)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject DataCollectThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DataCollectThread.data,
      qt_meta_data_DataCollectThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataCollectThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataCollectThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataCollectThread.stringdata))
        return static_cast<void*>(const_cast< DataCollectThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DataCollectThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DataCollectThread::SerialPortFlagSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataCollectThread::SerialPortRawWaveValueSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataCollectThread::SerialPortHeartRateValueSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataCollectThread::SerialPortPoorSignalQualitySignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
