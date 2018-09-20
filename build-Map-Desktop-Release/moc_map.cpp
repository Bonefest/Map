/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Map/map.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Map_t {
    QByteArrayData data[11];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Map_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Map_t qt_meta_stringdata_Map = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Map"
QT_MOC_LITERAL(1, 4, 9), // "selectGcp"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 9), // "selectMap"
QT_MOC_LITERAL(4, 25, 8), // "addImage"
QT_MOC_LITERAL(5, 34, 9), // "loadImage"
QT_MOC_LITERAL(6, 44, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 61, 4), // "item"
QT_MOC_LITERAL(8, 66, 10), // "clickImage"
QT_MOC_LITERAL(9, 77, 16), // "clickPlaceholder"
QT_MOC_LITERAL(10, 94, 18) // "const Placeholder*"

    },
    "Map\0selectGcp\0\0selectMap\0addImage\0"
    "loadImage\0QListWidgetItem*\0item\0"
    "clickImage\0clickPlaceholder\0"
    "const Placeholder*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Map[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void Map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Map *_t = static_cast<Map *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectGcp(); break;
        case 1: _t->selectMap(); break;
        case 2: _t->addImage(); break;
        case 3: _t->loadImage((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->clickImage(); break;
        case 5: _t->clickPlaceholder((*reinterpret_cast< const Placeholder*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Map::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Map.data,
      qt_meta_data_Map,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Map::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Map.stringdata0))
        return static_cast<void*>(const_cast< Map*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
