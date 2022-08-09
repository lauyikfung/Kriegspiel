/****************************************************************************
** Meta object code from reading C++ file 'Create_the_connection.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt-homework/Create_the_connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Create_the_connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_creating_connection_t {
    const uint offsetsAndSize[14];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_creating_connection_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_creating_connection_t qt_meta_stringdata_creating_connection = {
    {
QT_MOC_LITERAL(0, 19), // "creating_connection"
QT_MOC_LITERAL(20, 9), // "getButton"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 3), // "num"
QT_MOC_LITERAL(35, 9), // "setmyside"
QT_MOC_LITERAL(45, 5), // "mysid"
QT_MOC_LITERAL(51, 21) // "on_pushButton_clicked"

    },
    "creating_connection\0getButton\0\0num\0"
    "setmyside\0mysid\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_creating_connection[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    0 /* Public */,
       4,    1,   35,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   38,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void creating_connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<creating_connection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setmyside((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (creating_connection::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&creating_connection::getButton)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (creating_connection::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&creating_connection::setmyside)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject creating_connection::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_creating_connection.offsetsAndSize,
    qt_meta_data_creating_connection,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_creating_connection_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *creating_connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *creating_connection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_creating_connection.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int creating_connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void creating_connection::getButton(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void creating_connection::setmyside(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
