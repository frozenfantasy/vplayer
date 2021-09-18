/****************************************************************************
** Meta object code from reading C++ file 'multi_player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test/multi_player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multi_player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_multi_player_t {
    QByteArrayData data[12];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_multi_player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_multi_player_t qt_meta_stringdata_multi_player = {
    {
QT_MOC_LITERAL(0, 0, 12), // "multi_player"
QT_MOC_LITERAL(1, 13, 5), // "flush"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "on_rbsz_checked"
QT_MOC_LITERAL(4, 36, 1), // "i"
QT_MOC_LITERAL(5, 38, 17), // "on_mp_off_clicked"
QT_MOC_LITERAL(6, 56, 18), // "on_mp_save_clicked"
QT_MOC_LITERAL(7, 75, 18), // "on_mp_load_clicked"
QT_MOC_LITERAL(8, 94, 26), // "on_mp_stop_continue_cicked"
QT_MOC_LITERAL(9, 121, 17), // "on_player_clicked"
QT_MOC_LITERAL(10, 139, 3), // "row"
QT_MOC_LITERAL(11, 143, 3) // "col"

    },
    "multi_player\0flush\0\0on_rbsz_checked\0"
    "i\0on_mp_off_clicked\0on_mp_save_clicked\0"
    "on_mp_load_clicked\0on_mp_stop_continue_cicked\0"
    "on_player_clicked\0row\0col"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_multi_player[] = {

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
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   50,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    2,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,   10,   11,

       0        // eod
};

void multi_player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        multi_player *_t = static_cast<multi_player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->flush(); break;
        case 1: _t->on_rbsz_checked((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->on_mp_off_clicked(); break;
        case 3: _t->on_mp_save_clicked(); break;
        case 4: _t->on_mp_load_clicked(); break;
        case 5: _t->on_mp_stop_continue_cicked(); break;
        case 6: _t->on_player_clicked((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (multi_player::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&multi_player::flush)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject multi_player::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_multi_player.data,
      qt_meta_data_multi_player,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *multi_player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *multi_player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_multi_player.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int multi_player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void multi_player::flush()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
