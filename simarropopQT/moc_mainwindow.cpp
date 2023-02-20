/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "slotDialogoValoracion"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 46, 31), // "slotPeticionValoracionTerminada"
QT_MOC_LITERAL(5, 78, 29), // "slotDialogoValoracionInsertar"
QT_MOC_LITERAL(6, 108, 31), // "slotDialogoValoracionFinalizado"
QT_MOC_LITERAL(7, 140, 19), // "slotDialogoArticulo"
QT_MOC_LITERAL(8, 160, 29), // "slotPeticionArticuloTerminada"
QT_MOC_LITERAL(9, 190, 27), // "slotDialogoArticuloInsertar"
QT_MOC_LITERAL(10, 218, 29), // "slotDialogoArticuloFinalizado"
QT_MOC_LITERAL(11, 248, 18), // "slotDialogoUsuario"
QT_MOC_LITERAL(12, 267, 28), // "slotPeticionUsuarioTerminada"
QT_MOC_LITERAL(13, 296, 26), // "slotDialogoUsuarioInsertar"
QT_MOC_LITERAL(14, 323, 28), // "slotDialogoUsuarioFinalizado"
QT_MOC_LITERAL(15, 352, 20) // "slotActualizarTablas"

    },
    "MainWindow\0slotDialogoValoracion\0\0"
    "QModelIndex\0slotPeticionValoracionTerminada\0"
    "slotDialogoValoracionInsertar\0"
    "slotDialogoValoracionFinalizado\0"
    "slotDialogoArticulo\0slotPeticionArticuloTerminada\0"
    "slotDialogoArticuloInsertar\0"
    "slotDialogoArticuloFinalizado\0"
    "slotDialogoUsuario\0slotPeticionUsuarioTerminada\0"
    "slotDialogoUsuarioInsertar\0"
    "slotDialogoUsuarioFinalizado\0"
    "slotActualizarTablas"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    0,   82,    2, 0x0a /* Public */,
       5,    0,   83,    2, 0x0a /* Public */,
       6,    1,   84,    2, 0x0a /* Public */,
       7,    1,   87,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    1,   92,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    1,  100,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotDialogoValoracion((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->slotPeticionValoracionTerminada(); break;
        case 2: _t->slotDialogoValoracionInsertar(); break;
        case 3: _t->slotDialogoValoracionFinalizado((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotDialogoArticulo((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->slotPeticionArticuloTerminada(); break;
        case 6: _t->slotDialogoArticuloInsertar(); break;
        case 7: _t->slotDialogoArticuloFinalizado((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotDialogoUsuario((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->slotPeticionUsuarioTerminada(); break;
        case 10: _t->slotDialogoUsuarioInsertar(); break;
        case 11: _t->slotDialogoUsuarioFinalizado((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slotActualizarTablas(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
