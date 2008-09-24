/****************************************************************************
** Meta object code from reading C++ file 'PantocratorWindow.hpp'
**
** Created: Wed Sep 24 12:59:05 2008
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
      39,   10, // methods
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
     342,  308,   28,   28, 0x08,
     374,  370,   28,   28, 0x08,
     400,  370,   28,   28, 0x08,
     435,  426,   28,   28, 0x08,
     472,  463,   28,   28, 0x08,
     509,  500,   28,   28, 0x08,
     546,  537,   28,   28, 0x08,
     581,  574,   28,   28, 0x08,
     604,   28,   28,   28, 0x08,
     629,   28,   28,   28, 0x08,
     655,   28,   28,   28, 0x08,
     680,   28,   28,   28, 0x08,
     706,   28,   28,   28, 0x08,
     735,   28,   28,   28, 0x08,
     761,   28,   28,   28, 0x08,
     790,   28,   28,   28, 0x08,
     814,   28,   28,   28, 0x08,
     838,   28,   28,   28, 0x08,
     873,  865,   28,   28, 0x08,
     902,  865,   28,   28, 0x08,
     926,  924,   28,   28, 0x08,
     961,  959,   28,   28, 0x08,
     996,  994,   28,   28, 0x08,
    1039, 1029,   28,   28, 0x08,
    1081, 1073,   28,   28, 0x08,

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
    "setToColor()\0theta\0setParticleMinTheta(double)\0"
    "setParticleMaxTheta(double)\0phi\0"
    "setParticleMinPhi(double)\0"
    "setParticleMaxPhi(double)\0minspeed\0"
    "setParticleMinSpeed(double)\0maxspeed\0"
    "setParticleMaxSpeed(double)\0mincount\0"
    "setParticleMinCount(double)\0maxcount\0"
    "setParticleMaxCount(double)\0placer\0"
    "setParticlePlacer(int)\0setParticleTextureFire()\0"
    "setParticleTextureSmoke()\0"
    "setParticleTextureBase()\0"
    "setParticleTextureSonic()\0"
    "setParticleTextureVirulent()\0"
    "setParticleTextureLaser()\0"
    "setParticleTextureElectric()\0"
    "setParticleTextureIce()\0setParticleTextureEmp()\0"
    "setParticleTextureFlower()\0enabled\0"
    "setParticleAcceleration(int)\0"
    "setParticleFluid(int)\0x\0"
    "setParticleAccelerationX(double)\0y\0"
    "setParticleAccelerationY(double)\0z\0"
    "setParticleAccelerationZ(double)\0"
    "viscosity\0setParticleFluidViscosity(double)\0"
    "density\0setParticleFluidDensity(double)\0"
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
        case 13: setParticleMinTheta((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: setParticleMaxTheta((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: setParticleMinPhi((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: setParticleMaxPhi((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: setParticleMinSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: setParticleMaxSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: setParticleMinCount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: setParticleMaxCount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: setParticlePlacer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: setParticleTextureFire(); break;
        case 23: setParticleTextureSmoke(); break;
        case 24: setParticleTextureBase(); break;
        case 25: setParticleTextureSonic(); break;
        case 26: setParticleTextureVirulent(); break;
        case 27: setParticleTextureLaser(); break;
        case 28: setParticleTextureElectric(); break;
        case 29: setParticleTextureIce(); break;
        case 30: setParticleTextureEmp(); break;
        case 31: setParticleTextureFlower(); break;
        case 32: setParticleAcceleration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: setParticleFluid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: setParticleAccelerationX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 35: setParticleAccelerationY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: setParticleAccelerationZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: setParticleFluidViscosity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: setParticleFluidDensity((*reinterpret_cast< double(*)>(_a[1]))); break;
        }
        _id -= 39;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
