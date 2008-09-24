/****************************************************************************
** Meta object code from reading C++ file 'PantocratorWindow.hpp'
**
** Created: Wed Sep 24 20:30:51 2008
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
      40,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x08,
      41,   28,   36,   28, 0x08,
      48,   28,   36,   28, 0x08,
      57,   28,   28,   28, 0x08,
      77,   28,   28,   28, 0x08,
      87,   28,   28,   28, 0x08,
     115,  113,   28,   28, 0x08,
     137,  129,   28,   28, 0x08,
     172,  164,   28,   28, 0x08,
     204,  199,   28,   28, 0x08,
     233,  228,   28,   28, 0x08,
     264,  257,   28,   28, 0x08,
     290,   28,   28,   28, 0x08,
     305,   28,   28,   28, 0x08,
     324,  318,   28,   28, 0x08,
     352,  318,   28,   28, 0x08,
     384,  380,   28,   28, 0x08,
     410,  380,   28,   28, 0x08,
     445,  436,   28,   28, 0x08,
     482,  473,   28,   28, 0x08,
     519,  510,   28,   28, 0x08,
     556,  547,   28,   28, 0x08,
     591,  584,   28,   28, 0x08,
     614,   28,   28,   28, 0x08,
     639,   28,   28,   28, 0x08,
     665,   28,   28,   28, 0x08,
     690,   28,   28,   28, 0x08,
     716,   28,   28,   28, 0x08,
     745,   28,   28,   28, 0x08,
     771,   28,   28,   28, 0x08,
     800,   28,   28,   28, 0x08,
     824,   28,   28,   28, 0x08,
     848,   28,   28,   28, 0x08,
     883,  875,   28,   28, 0x08,
     912,  875,   28,   28, 0x08,
     936,  934,   28,   28, 0x08,
     971,  969,   28,   28, 0x08,
    1006, 1004,   28,   28, 0x08,
    1049, 1039,   28,   28, 0x08,
    1091, 1083,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_osgParti__PantocratorWindow[] = {
    "osgParti::PantocratorWindow\0\0open()\0"
    "bool\0save()\0saveAs()\0newParticleSystem()\0"
    "newFile()\0setParticleAlignment(int)\0"
    "i\0setShape(int)\0minsize\0"
    "setParticleMinSize(double)\0maxsize\0"
    "setParticleMaxSize(double)\0life\0"
    "setParticleLife(double)\0mass\0"
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
        case 4: newFile(); break;
        case 5: setParticleAlignment((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: setShape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: setParticleMinSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: setParticleMaxSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: setParticleLife((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: setParticleMass((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: setParticleRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: setFromColor(); break;
        case 13: setToColor(); break;
        case 14: setParticleMinTheta((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: setParticleMaxTheta((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: setParticleMinPhi((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: setParticleMaxPhi((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: setParticleMinSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: setParticleMaxSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: setParticleMinCount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: setParticleMaxCount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: setParticlePlacer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: setParticleTextureFire(); break;
        case 24: setParticleTextureSmoke(); break;
        case 25: setParticleTextureBase(); break;
        case 26: setParticleTextureSonic(); break;
        case 27: setParticleTextureVirulent(); break;
        case 28: setParticleTextureLaser(); break;
        case 29: setParticleTextureElectric(); break;
        case 30: setParticleTextureIce(); break;
        case 31: setParticleTextureEmp(); break;
        case 32: setParticleTextureFlower(); break;
        case 33: setParticleAcceleration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: setParticleFluid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: setParticleAccelerationX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: setParticleAccelerationY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: setParticleAccelerationZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: setParticleFluidViscosity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 39: setParticleFluidDensity((*reinterpret_cast< double(*)>(_a[1]))); break;
        }
        _id -= 40;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
