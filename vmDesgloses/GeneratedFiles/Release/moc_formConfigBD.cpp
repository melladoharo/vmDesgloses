/****************************************************************************
** Meta object code from reading C++ file 'formConfigBD.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../formConfigBD.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formConfigBD.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FormConfigBD_t {
    QByteArrayData data[7];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormConfigBD_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormConfigBD_t qt_meta_stringdata_FormConfigBD = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FormConfigBD"
QT_MOC_LITERAL(1, 13, 12), // "cargarConfig"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "guardarConfig"
QT_MOC_LITERAL(4, 41, 17), // "comprobarConexion"
QT_MOC_LITERAL(5, 59, 12), // "cancelarForm"
QT_MOC_LITERAL(6, 72, 9) // "crearBBDD"

    },
    "FormConfigBD\0cargarConfig\0\0guardarConfig\0"
    "comprobarConexion\0cancelarForm\0crearBBDD"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormConfigBD[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormConfigBD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormConfigBD *_t = static_cast<FormConfigBD *>(_o);
        switch (_id) {
        case 0: _t->cargarConfig(); break;
        case 1: _t->guardarConfig(); break;
        case 2: _t->comprobarConexion(); break;
        case 3: _t->cancelarForm(); break;
        case 4: _t->crearBBDD(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FormConfigBD::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FormConfigBD.data,
      qt_meta_data_FormConfigBD,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FormConfigBD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormConfigBD::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FormConfigBD.stringdata))
        return static_cast<void*>(const_cast< FormConfigBD*>(this));
    return QDialog::qt_metacast(_clname);
}

int FormConfigBD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
