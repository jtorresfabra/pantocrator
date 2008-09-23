/****************************************************************************
** Meta object code from reading C++ file 'PantocratorWindow.hpp'
**
** Created: Tue Sep 23 12:44:03 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "PantocratorWindow.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PantocratorWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_osgParti__PantocratorWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x08,
      41,   28,   36,   28, 0x08,
      48,   28,   36,   28, 0x08,
      57,   28,   28,   28, 0x08,
      77,   28,   28,   28, 0x08,
     105,  103,   28,   28, 0x08,
     127,  119,   28,   28, 0x08,
     162,  154,   28,   28, 0x08,
     194,  189,   28,   28, 0x08,
     223,  218,   28,   28, 0x08,
     254,  247,   28,   28, 0x08,
     280,   28,   28,   28, 0x08,
     295,   28,   28,   28, 0x08,
     314,  308,   28,   28, 0x08,
     345,  336,   28,   28, 0x08,
     382,  373,   28,   28, 0x08,
     419,  410,   28,   28, 0x08,
     456,  447,   28,   28, 0x08,
     491,  484,   28,   28, 0x08,
     514,   28,   28,   28, 0x08,
     539,   28,   28,   28, 0x08,
     565,   28,   28,   28, 0x08,
     590,   28,   28,   28, 0x08,
     616,   28,   28,   28, 0x08,
     645,   28,   28,   28, 0x08,
     671,   28,   28,   28, 0x08,
     700,   28,   28,   28, 0x08,
     724,   28,   28,   28, 0x08,
     748,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_osgParti__PantocratorWindow[] = {
    "osgParti::PantocratorWindow\0\0open()\0"
    "bool\0save()\0saveAs()\0newParticleSystem()\0"
    "setParticleAlignment(int)\0i\0setShape(int)\0"
    "minsize\0setParticleMinSize(double)\0"
    "maxsize\0setParticleMaxSize(double)\0"
    "life\0setParticleLife(double)\0mass\0"
    "setParticleMass(double)\0radius\0"
    "setParticleRadius(double)\0setFromColor()\0"
    "setToColor()\0theta\0setParticleTheta(int)\0"
    "minspeed\0setParticleMinSpeed(double)\0"
    "maxspeed\0setParticleMaxSpeed(double)\0"
    "mincount\0setParticleMinCount(double)\0"
    "maxcount\0setParticleMaxCount(double)\0"
    "placer\0setParticlePlacer(int)\0"
    "setParticleTextureFire()\0"
    "setParticleTextureSmoke()\0"
    "setParticleTextureBase()\0"
    "setParticleTextureSonic()\0"
    "setParticleTextureVirulent()\0"
    "setParticleTextureLaser()\0"
    "setParticleTextureElectric()\0"
    "setParticleTextureIce()\0setParticleTextureEmp()\0"
    "setParticleTextureFlower()\0"
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
        case 3: newParticleSystem(); break;
        case 4: setParticleAlignment((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: setShape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: setParticleMinSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: setParticleMaxSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: setParticleLife((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: setParticleMass((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: setParticleRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: setFromColor(); break;
        case 12: setToColor(); break;
        case 13: setParticleTheta((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: setParticleMinSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: setParticleMaxSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: setParticleMinCount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: setParticleMaxCount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: setParticlePlacer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: setParticleTextureFire(); break;
        case 20: setParticleTextureSmoke(); break;
        case 21: setParticleTextureBase(); break;
        case 22: setParticleTextureSonic(); break;
        case 23: setParticleTextureVirulent(); break;
        case 24: setParticleTextureLaser(); break;
        case 25: setParticleTextureElectric(); break;
        case 26: setParticleTextureIce(); break;
        case 27: setParticleTextureEmp(); break;
        case 28: setParticleTextureFlower(); break;
        }
        _id -= 29;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
