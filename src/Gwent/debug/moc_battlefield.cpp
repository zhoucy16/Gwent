/****************************************************************************
** Meta object code from reading C++ file 'battlefield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../battlefield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battlefield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BattleField_t {
    QByteArrayData data[27];
    char stringdata0[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BattleField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BattleField_t qt_meta_stringdata_BattleField = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BattleField"
QT_MOC_LITERAL(1, 12, 9), // "isclicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "QGraphicsRectItem*"
QT_MOC_LITERAL(4, 42, 3), // "pot"
QT_MOC_LITERAL(5, 46, 11), // "powerUpdate"
QT_MOC_LITERAL(6, 58, 11), // "timerUpdate"
QT_MOC_LITERAL(7, 70, 7), // "putInfo"
QT_MOC_LITERAL(8, 78, 5), // "Card*"
QT_MOC_LITERAL(9, 84, 4), // "card"
QT_MOC_LITERAL(10, 89, 9), // "clearInfo"
QT_MOC_LITERAL(11, 99, 13), // "setChosenCard"
QT_MOC_LITERAL(12, 113, 7), // "useCard"
QT_MOC_LITERAL(13, 121, 11), // "changeACard"
QT_MOC_LITERAL(14, 133, 11), // "changeBCard"
QT_MOC_LITERAL(15, 145, 11), // "cardChanged"
QT_MOC_LITERAL(16, 157, 13), // "posAdjust_A_0"
QT_MOC_LITERAL(17, 171, 8), // "QPointF&"
QT_MOC_LITERAL(18, 180, 3), // "pos"
QT_MOC_LITERAL(19, 184, 13), // "posAdjust_A_1"
QT_MOC_LITERAL(20, 198, 13), // "posAdjust_A_2"
QT_MOC_LITERAL(21, 212, 13), // "posAdjust_A_3"
QT_MOC_LITERAL(22, 226, 13), // "posAdjust_B_0"
QT_MOC_LITERAL(23, 240, 13), // "posAdjust_B_1"
QT_MOC_LITERAL(24, 254, 13), // "posAdjust_B_2"
QT_MOC_LITERAL(25, 268, 13), // "posAdjust_B_3"
QT_MOC_LITERAL(26, 282, 16) // "posAdjust_change"

    },
    "BattleField\0isclicked\0\0QGraphicsRectItem*\0"
    "pot\0powerUpdate\0timerUpdate\0putInfo\0"
    "Card*\0card\0clearInfo\0setChosenCard\0"
    "useCard\0changeACard\0changeBCard\0"
    "cardChanged\0posAdjust_A_0\0QPointF&\0"
    "pos\0posAdjust_A_1\0posAdjust_A_2\0"
    "posAdjust_A_3\0posAdjust_B_0\0posAdjust_B_1\0"
    "posAdjust_B_2\0posAdjust_B_3\0"
    "posAdjust_change"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BattleField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  112,    2, 0x0a /* Public */,
       6,    0,  113,    2, 0x0a /* Public */,
       7,    1,  114,    2, 0x0a /* Public */,
      10,    0,  117,    2, 0x0a /* Public */,
      11,    1,  118,    2, 0x0a /* Public */,
      12,    1,  121,    2, 0x0a /* Public */,
      13,    1,  124,    2, 0x0a /* Public */,
      14,    1,  127,    2, 0x0a /* Public */,
      15,    0,  130,    2, 0x0a /* Public */,
      16,    1,  131,    2, 0x0a /* Public */,
      19,    1,  134,    2, 0x0a /* Public */,
      20,    1,  137,    2, 0x0a /* Public */,
      21,    1,  140,    2, 0x0a /* Public */,
      22,    1,  143,    2, 0x0a /* Public */,
      23,    1,  146,    2, 0x0a /* Public */,
      24,    1,  149,    2, 0x0a /* Public */,
      25,    1,  152,    2, 0x0a /* Public */,
      26,    1,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void BattleField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BattleField *_t = static_cast<BattleField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isclicked((*reinterpret_cast< QGraphicsRectItem*(*)>(_a[1]))); break;
        case 1: _t->powerUpdate(); break;
        case 2: _t->timerUpdate(); break;
        case 3: _t->putInfo((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 4: _t->clearInfo(); break;
        case 5: _t->setChosenCard((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 6: _t->useCard((*reinterpret_cast< QGraphicsRectItem*(*)>(_a[1]))); break;
        case 7: _t->changeACard((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 8: _t->changeBCard((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 9: _t->cardChanged(); break;
        case 10: _t->posAdjust_A_0((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 11: _t->posAdjust_A_1((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 12: _t->posAdjust_A_2((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 13: _t->posAdjust_A_3((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 14: _t->posAdjust_B_0((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 15: _t->posAdjust_B_1((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 16: _t->posAdjust_B_2((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 17: _t->posAdjust_B_3((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 18: _t->posAdjust_change((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Card* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Card* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Card* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Card* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BattleField::*_t)(QGraphicsRectItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleField::isclicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BattleField::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BattleField.data,
      qt_meta_data_BattleField,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BattleField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BattleField::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BattleField.stringdata0))
        return static_cast<void*>(const_cast< BattleField*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BattleField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void BattleField::isclicked(QGraphicsRectItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
