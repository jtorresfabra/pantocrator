/****************************************************************************
** Meta object code from reading C++ file 'PantocratorWindow.hpp'
**
** Created: Wed Jul 16 12:21:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "PantocratorWindow.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PantocratorWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_osgParti__PantocratorWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x08,
      41,   28,   36,   28, 0x08,
      48,   28,   36,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_osgParti__PantocratorWindow[] = {
    "osgParti::PantocratorWindow\0\0open()\0"
    "bool\0save()\0saveAs()\0"
};

const QMetaObject osgParti::PantocratorWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_osgParti__PantocratorWindow,
      qt_meta_data_osgParti__PantocratorWindow, 0 }
};

const QMetaObject *osgParti::PantocratorWindow::metaObject() const
{
    return &staticMetaObject;
}

void *osgParti::PantocratorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_osgParti__PantocratorWindow))
	return static_cast<void*>(const_cast< PantocratorWindow*>(this));
    if (!strcmp(_clname, "MainWindow"))
	return static_cast< MainWindow*>(const_cast< PantocratorWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int osgParti::PantocratorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open(); break;
        case 1: { bool _r = save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        }
        _id -= 3;
    }
    return _id;
}