/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt-homework/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    const uint offsetsAndSize[44];
    char stringdata0[369];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 6), // "Server"
QT_MOC_LITERAL(7, 9), // "getButton"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 3), // "num"
QT_MOC_LITERAL(22, 9), // "setmyside"
QT_MOC_LITERAL(32, 5), // "mysid"
QT_MOC_LITERAL(38, 6), // "addnum"
QT_MOC_LITERAL(45, 1), // "i"
QT_MOC_LITERAL(47, 19), // "on_okbutton_clicked"
QT_MOC_LITERAL(67, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(91, 9), // "addingnum"
QT_MOC_LITERAL(101, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(125, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(149, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(173, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(197, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(221, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(245, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(269, 24), // "on_pushButton_10_clicked"
QT_MOC_LITERAL(294, 24), // "on_pushButton_12_clicked"
QT_MOC_LITERAL(319, 24), // "on_pushButton_11_clicked"
QT_MOC_LITERAL(344, 24) // "on_pushButton_13_clicked"

    },
    "Server\0getButton\0\0num\0setmyside\0mysid\0"
    "addnum\0i\0on_okbutton_clicked\0"
    "on_pushButton_2_clicked\0addingnum\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0on_pushButton_8_clicked\0"
    "on_pushButton_9_clicked\0"
    "on_pushButton_10_clicked\0"
    "on_pushButton_12_clicked\0"
    "on_pushButton_11_clicked\0"
    "on_pushButton_13_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x06,    0 /* Public */,
       4,    1,  119,    2, 0x06,    2 /* Public */,
       6,    1,  122,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  125,    2, 0x0a,    6 /* Public */,
       9,    0,  126,    2, 0x0a,    7 /* Public */,
      10,    1,  127,    2, 0x0a,    8 /* Public */,
      11,    0,  130,    2, 0x08,   10 /* Private */,
      12,    0,  131,    2, 0x08,   11 /* Private */,
      13,    0,  132,    2, 0x08,   12 /* Private */,
      14,    0,  133,    2, 0x08,   13 /* Private */,
      15,    0,  134,    2, 0x08,   14 /* Private */,
      16,    0,  135,    2, 0x08,   15 /* Private */,
      17,    0,  136,    2, 0x08,   16 /* Private */,
      18,    0,  137,    2, 0x08,   17 /* Private */,
      19,    0,  138,    2, 0x08,   18 /* Private */,
      20,    0,  139,    2, 0x08,   19 /* Private */,
      21,    0,  140,    2, 0x08,   20 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setmyside((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->addnum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_okbutton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->addingnum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        case 8: _t->on_pushButton_5_clicked(); break;
        case 9: _t->on_pushButton_6_clicked(); break;
        case 10: _t->on_pushButton_7_clicked(); break;
        case 11: _t->on_pushButton_8_clicked(); break;
        case 12: _t->on_pushButton_9_clicked(); break;
        case 13: _t->on_pushButton_10_clicked(); break;
        case 14: _t->on_pushButton_12_clicked(); break;
        case 15: _t->on_pushButton_11_clicked(); break;
        case 16: _t->on_pushButton_13_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::getButton)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::setmyside)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::addnum)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Server.offsetsAndSize,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Server_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Server::getButton(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::setmyside(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::addnum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
