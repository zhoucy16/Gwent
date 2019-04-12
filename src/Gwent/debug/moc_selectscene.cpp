/****************************************************************************
** Meta object code from reading C++ file 'selectscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../selectscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectScene_t {
    QByteArrayData data[21];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectScene_t qt_meta_stringdata_SelectScene = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SelectScene"
QT_MOC_LITERAL(1, 12, 10), // "sumChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "putInfo"
QT_MOC_LITERAL(4, 32, 5), // "Card*"
QT_MOC_LITERAL(5, 38, 4), // "card"
QT_MOC_LITERAL(6, 43, 9), // "clearInfo"
QT_MOC_LITERAL(7, 53, 9), // "posAdjust"
QT_MOC_LITERAL(8, 63, 8), // "QPointF&"
QT_MOC_LITERAL(9, 72, 3), // "pos"
QT_MOC_LITERAL(10, 76, 10), // "posAdjust1"
QT_MOC_LITERAL(11, 87, 10), // "posAdjust4"
QT_MOC_LITERAL(12, 98, 10), // "posAdjust2"
QT_MOC_LITERAL(13, 109, 10), // "posAdjust3"
QT_MOC_LITERAL(14, 120, 10), // "chooseCard"
QT_MOC_LITERAL(15, 131, 11), // "cancelCard4"
QT_MOC_LITERAL(16, 143, 11), // "cancelCard3"
QT_MOC_LITERAL(17, 155, 11), // "cancelCard2"
QT_MOC_LITERAL(18, 167, 11), // "cancelCard1"
QT_MOC_LITERAL(19, 179, 9), // "changeSum"
QT_MOC_LITERAL(20, 189, 7) // "addDeck"

    },
    "SelectScene\0sumChanged\0\0putInfo\0Card*\0"
    "card\0clearInfo\0posAdjust\0QPointF&\0pos\0"
    "posAdjust1\0posAdjust4\0posAdjust2\0"
    "posAdjust3\0chooseCard\0cancelCard4\0"
    "cancelCard3\0cancelCard2\0cancelCard1\0"
    "changeSum\0addDeck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   90,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    1,   94,    2, 0x0a /* Public */,
      10,    1,   97,    2, 0x0a /* Public */,
      11,    1,  100,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      13,    1,  106,    2, 0x0a /* Public */,
      14,    1,  109,    2, 0x0a /* Public */,
      15,    1,  112,    2, 0x0a /* Public */,
      16,    1,  115,    2, 0x0a /* Public */,
      17,    1,  118,    2, 0x0a /* Public */,
      18,    1,  121,    2, 0x0a /* Public */,
      19,    0,  124,    2, 0x0a /* Public */,
      20,    0,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelectScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectScene *_t = static_cast<SelectScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sumChanged(); break;
        case 1: _t->putInfo((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 2: _t->clearInfo(); break;
        case 3: _t->posAdjust((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->posAdjust1((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 5: _t->posAdjust4((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 6: _t->posAdjust2((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 7: _t->posAdjust3((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 8: _t->chooseCard((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 9: _t->cancelCard4((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 10: _t->cancelCard3((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 11: _t->cancelCard2((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 12: _t->cancelCard1((*reinterpret_cast< Card*(*)>(_a[1]))); break;
        case 13: _t->changeSum(); break;
        case 14: _t->addDeck(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Card* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Card* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Card* >(); break;
            }
            break;
        case 12:
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
            typedef void (SelectScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectScene::sumChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SelectScene::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SelectScene.data,
      qt_meta_data_SelectScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SelectScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SelectScene.stringdata0))
        return static_cast<void*>(const_cast< SelectScene*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SelectScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SelectScene::sumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
