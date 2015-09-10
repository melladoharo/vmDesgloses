/****************************************************************************
** Meta object code from reading C++ file 'formNuevoDesg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../formNuevoDesg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formNuevoDesg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FormNuevoDesg_t {
    QByteArrayData data[11];
    char stringdata[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormNuevoDesg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormNuevoDesg_t qt_meta_stringdata_FormNuevoDesg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FormNuevoDesg"
QT_MOC_LITERAL(1, 14, 15), // "comprobarNumero"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "QWidget*"
QT_MOC_LITERAL(4, 40, 6), // "widget"
QT_MOC_LITERAL(5, 47, 15), // "comprobarCadena"
QT_MOC_LITERAL(6, 63, 14), // "agregarCliente"
QT_MOC_LITERAL(7, 78, 15), // "agregarDesglose"
QT_MOC_LITERAL(8, 94, 16), // "terminarDesglose"
QT_MOC_LITERAL(9, 111, 14), // "cambiarCliente"
QT_MOC_LITERAL(10, 126, 15) // "cambiarDesglose"

    },
    "FormNuevoDesg\0comprobarNumero\0\0QWidget*\0"
    "widget\0comprobarCadena\0agregarCliente\0"
    "agregarDesglose\0terminarDesglose\0"
    "cambiarCliente\0cambiarDesglose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormNuevoDesg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormNuevoDesg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormNuevoDesg *_t = static_cast<FormNuevoDesg *>(_o);
        switch (_id) {
        case 0: _t->comprobarNumero((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->comprobarCadena((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->agregarCliente(); break;
        case 3: _t->agregarDesglose(); break;
        case 4: _t->terminarDesglose(); break;
        case 5: _t->cambiarCliente(); break;
        case 6: _t->cambiarDesglose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject FormNuevoDesg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FormNuevoDesg.data,
      qt_meta_data_FormNuevoDesg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FormNuevoDesg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormNuevoDesg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FormNuevoDesg.stringdata))
        return static_cast<void*>(const_cast< FormNuevoDesg*>(this));
    return QDialog::qt_metacast(_clname);
}

int FormNuevoDesg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
