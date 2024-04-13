/****************************************************************************
** Meta object code from reading C++ file 'qtpropertymanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtpropertybrowser/qtpropertymanager.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtpropertymanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtGroupPropertyManager"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22)   // "QtGroupPropertyManager"
    },
    "QtGroupPropertyManager"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtGroupPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject QtGroupPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtGroupPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtGroupPropertyManager, std::true_type>
    >,
    nullptr
} };

void QtGroupPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QtGroupPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtGroupPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtGroupPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtGroupPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtIntPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "singleStepChanged",
    "step",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange",
    "setSingleStep"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[21];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[7];
    char stringdata9[18];
    char stringdata10[5];
    char stringdata11[9];
    char stringdata12[11];
    char stringdata13[11];
    char stringdata14[9];
    char stringdata15[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "QtIntPropertyManager"
        QT_MOC_LITERAL(21, 12),  // "valueChanged"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 11),  // "QtProperty*"
        QT_MOC_LITERAL(47, 8),  // "property"
        QT_MOC_LITERAL(56, 3),  // "val"
        QT_MOC_LITERAL(60, 12),  // "rangeChanged"
        QT_MOC_LITERAL(73, 6),  // "minVal"
        QT_MOC_LITERAL(80, 6),  // "maxVal"
        QT_MOC_LITERAL(87, 17),  // "singleStepChanged"
        QT_MOC_LITERAL(105, 4),  // "step"
        QT_MOC_LITERAL(110, 8),  // "setValue"
        QT_MOC_LITERAL(119, 10),  // "setMinimum"
        QT_MOC_LITERAL(130, 10),  // "setMaximum"
        QT_MOC_LITERAL(141, 8),  // "setRange"
        QT_MOC_LITERAL(150, 13)   // "setSingleStep"
    },
    "QtIntPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "singleStepChanged",
    "step",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange",
    "setSingleStep"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtIntPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       6,    3,   67,    2, 0x06,    4 /* Public */,
       9,    2,   74,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    2,   79,    2, 0x0a,   11 /* Public */,
      12,    2,   84,    2, 0x0a,   14 /* Public */,
      13,    2,   89,    2, 0x0a,   17 /* Public */,
      14,    3,   94,    2, 0x0a,   20 /* Public */,
      15,    2,  101,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtIntPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtIntPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtIntPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'rangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'singleStepChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setMinimum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setMaximum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSingleStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void QtIntPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtIntPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->rangeChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->singleStepChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->setRange((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->setSingleStep((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtIntPropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtIntPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtIntPropertyManager::*)(QtProperty * , int , int );
            if (_t _q_method = &QtIntPropertyManager::rangeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtIntPropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtIntPropertyManager::singleStepChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *QtIntPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtIntPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtIntPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtIntPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QtIntPropertyManager::valueChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtIntPropertyManager::rangeChanged(QtProperty * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtIntPropertyManager::singleStepChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtBoolPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtBoolPropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 8)   // "setValue"
    },
    "QtBoolPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtBoolPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtBoolPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtBoolPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtBoolPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void QtBoolPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtBoolPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtBoolPropertyManager::*)(QtProperty * , bool );
            if (_t _q_method = &QtBoolPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtBoolPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtBoolPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtBoolPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtBoolPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtBoolPropertyManager::valueChanged(QtProperty * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtDoublePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "singleStepChanged",
    "step",
    "decimalsChanged",
    "prec",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange",
    "setSingleStep",
    "setDecimals"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[24];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[7];
    char stringdata9[18];
    char stringdata10[5];
    char stringdata11[16];
    char stringdata12[5];
    char stringdata13[9];
    char stringdata14[11];
    char stringdata15[11];
    char stringdata16[9];
    char stringdata17[14];
    char stringdata18[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "QtDoublePropertyManager"
        QT_MOC_LITERAL(24, 12),  // "valueChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 11),  // "QtProperty*"
        QT_MOC_LITERAL(50, 8),  // "property"
        QT_MOC_LITERAL(59, 3),  // "val"
        QT_MOC_LITERAL(63, 12),  // "rangeChanged"
        QT_MOC_LITERAL(76, 6),  // "minVal"
        QT_MOC_LITERAL(83, 6),  // "maxVal"
        QT_MOC_LITERAL(90, 17),  // "singleStepChanged"
        QT_MOC_LITERAL(108, 4),  // "step"
        QT_MOC_LITERAL(113, 15),  // "decimalsChanged"
        QT_MOC_LITERAL(129, 4),  // "prec"
        QT_MOC_LITERAL(134, 8),  // "setValue"
        QT_MOC_LITERAL(143, 10),  // "setMinimum"
        QT_MOC_LITERAL(154, 10),  // "setMaximum"
        QT_MOC_LITERAL(165, 8),  // "setRange"
        QT_MOC_LITERAL(174, 13),  // "setSingleStep"
        QT_MOC_LITERAL(188, 11)   // "setDecimals"
    },
    "QtDoublePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "singleStepChanged",
    "step",
    "decimalsChanged",
    "prec",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange",
    "setSingleStep",
    "setDecimals"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtDoublePropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x06,    1 /* Public */,
       6,    3,   79,    2, 0x06,    4 /* Public */,
       9,    2,   86,    2, 0x06,    8 /* Public */,
      11,    2,   91,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    2,   96,    2, 0x0a,   14 /* Public */,
      14,    2,  101,    2, 0x0a,   17 /* Public */,
      15,    2,  106,    2, 0x0a,   20 /* Public */,
      16,    3,  111,    2, 0x0a,   23 /* Public */,
      17,    2,  118,    2, 0x0a,   27 /* Public */,
      18,    2,  123,    2, 0x0a,   30 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, QMetaType::Double,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,   10,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, QMetaType::Double,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,   10,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtDoublePropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtDoublePropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtDoublePropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'rangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'singleStepChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'decimalsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setMinimum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setMaximum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setSingleStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setDecimals'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void QtDoublePropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtDoublePropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 1: _t->rangeChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 2: _t->singleStepChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 3: _t->decimalsChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 5: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 6: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 7: _t->setRange((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 8: _t->setSingleStep((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 9: _t->setDecimals((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtDoublePropertyManager::*)(QtProperty * , double );
            if (_t _q_method = &QtDoublePropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtDoublePropertyManager::*)(QtProperty * , double , double );
            if (_t _q_method = &QtDoublePropertyManager::rangeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtDoublePropertyManager::*)(QtProperty * , double );
            if (_t _q_method = &QtDoublePropertyManager::singleStepChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtDoublePropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtDoublePropertyManager::decimalsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *QtDoublePropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtDoublePropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtDoublePropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtDoublePropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QtDoublePropertyManager::valueChanged(QtProperty * _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtDoublePropertyManager::rangeChanged(QtProperty * _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtDoublePropertyManager::singleStepChanged(QtProperty * _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtDoublePropertyManager::decimalsChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtStringPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "regExpChanged",
    "regExp",
    "setValue",
    "setRegExp"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[24];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[14];
    char stringdata7[7];
    char stringdata8[9];
    char stringdata9[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "QtStringPropertyManager"
        QT_MOC_LITERAL(24, 12),  // "valueChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 11),  // "QtProperty*"
        QT_MOC_LITERAL(50, 8),  // "property"
        QT_MOC_LITERAL(59, 3),  // "val"
        QT_MOC_LITERAL(63, 13),  // "regExpChanged"
        QT_MOC_LITERAL(77, 6),  // "regExp"
        QT_MOC_LITERAL(84, 8),  // "setValue"
        QT_MOC_LITERAL(93, 9)   // "setRegExp"
    },
    "QtStringPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "regExpChanged",
    "regExp",
    "setValue",
    "setRegExp"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtStringPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       6,    2,   43,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   48,    2, 0x0a,    7 /* Public */,
       9,    2,   53,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRegularExpression,    4,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRegularExpression,    4,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtStringPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtStringPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtStringPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'regExpChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRegularExpression &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setRegExp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRegularExpression &, std::false_type>
    >,
    nullptr
} };

void QtStringPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtStringPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->regExpChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRegularExpression>>(_a[2]))); break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->setRegExp((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRegularExpression>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtStringPropertyManager::*)(QtProperty * , const QString & );
            if (_t _q_method = &QtStringPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtStringPropertyManager::*)(QtProperty * , const QRegularExpression & );
            if (_t _q_method = &QtStringPropertyManager::regExpChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QtStringPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtStringPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtStringPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtStringPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QtStringPropertyManager::valueChanged(QtProperty * _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtStringPropertyManager::regExpChanged(QtProperty * _t1, const QRegularExpression & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtDatePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[7];
    char stringdata9[9];
    char stringdata10[11];
    char stringdata11[11];
    char stringdata12[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtDatePropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 12),  // "rangeChanged"
        QT_MOC_LITERAL(74, 6),  // "minVal"
        QT_MOC_LITERAL(81, 6),  // "maxVal"
        QT_MOC_LITERAL(88, 8),  // "setValue"
        QT_MOC_LITERAL(97, 10),  // "setMinimum"
        QT_MOC_LITERAL(108, 10),  // "setMaximum"
        QT_MOC_LITERAL(119, 8)   // "setRange"
    },
    "QtDatePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtDatePropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       6,    3,   55,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    2,   62,    2, 0x0a,    8 /* Public */,
      10,    2,   67,    2, 0x0a,   11 /* Public */,
      11,    2,   72,    2, 0x0a,   14 /* Public */,
      12,    3,   77,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDate,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDate, QMetaType::QDate,    4,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDate,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDate,    4,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDate,    4,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDate, QMetaType::QDate,    4,    7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtDatePropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtDatePropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtDatePropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        // method 'rangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        // method 'setMinimum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        // method 'setMaximum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        // method 'setRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>
    >,
    nullptr
} };

void QtDatePropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtDatePropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2]))); break;
        case 1: _t->rangeChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[3]))); break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2]))); break;
        case 3: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2]))); break;
        case 4: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2]))); break;
        case 5: _t->setRange((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtDatePropertyManager::*)(QtProperty * , QDate );
            if (_t _q_method = &QtDatePropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtDatePropertyManager::*)(QtProperty * , QDate , QDate );
            if (_t _q_method = &QtDatePropertyManager::rangeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QtDatePropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtDatePropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtDatePropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtDatePropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QtDatePropertyManager::valueChanged(QtProperty * _t1, QDate _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtDatePropertyManager::rangeChanged(QtProperty * _t1, QDate _t2, QDate _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtTimePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtTimePropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 8)   // "setValue"
    },
    "QtTimePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtTimePropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QTime,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QTime,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtTimePropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtTimePropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtTimePropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>
    >,
    nullptr
} };

void QtTimePropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtTimePropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtTimePropertyManager::*)(QtProperty * , QTime );
            if (_t _q_method = &QtTimePropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtTimePropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtTimePropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtTimePropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtTimePropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtTimePropertyManager::valueChanged(QtProperty * _t1, QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtDateTimePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[26];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 25),  // "QtDateTimePropertyManager"
        QT_MOC_LITERAL(26, 12),  // "valueChanged"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 11),  // "QtProperty*"
        QT_MOC_LITERAL(52, 8),  // "property"
        QT_MOC_LITERAL(61, 3),  // "val"
        QT_MOC_LITERAL(65, 8)   // "setValue"
    },
    "QtDateTimePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtDateTimePropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDateTime,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDateTime,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtDateTimePropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtDateTimePropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtDateTimePropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>
    >,
    nullptr
} };

void QtDateTimePropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtDateTimePropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtDateTimePropertyManager::*)(QtProperty * , const QDateTime & );
            if (_t _q_method = &QtDateTimePropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtDateTimePropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtDateTimePropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtDateTimePropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtDateTimePropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtDateTimePropertyManager::valueChanged(QtProperty * _t1, const QDateTime & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtKeySequencePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "QKeySequence",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[29];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[13];
    char stringdata6[4];
    char stringdata7[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 28),  // "QtKeySequencePropertyManager"
        QT_MOC_LITERAL(29, 12),  // "valueChanged"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 11),  // "QtProperty*"
        QT_MOC_LITERAL(55, 8),  // "property"
        QT_MOC_LITERAL(64, 12),  // "QKeySequence"
        QT_MOC_LITERAL(77, 3),  // "val"
        QT_MOC_LITERAL(81, 8)   // "setValue"
    },
    "QtKeySequencePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "QKeySequence",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtKeySequencePropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtKeySequencePropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtKeySequencePropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtKeySequencePropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QKeySequence &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QKeySequence &, std::false_type>
    >,
    nullptr
} };

void QtKeySequencePropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtKeySequencePropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtKeySequencePropertyManager::*)(QtProperty * , const QKeySequence & );
            if (_t _q_method = &QtKeySequencePropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtKeySequencePropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtKeySequencePropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtKeySequencePropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtKeySequencePropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtKeySequencePropertyManager::valueChanged(QtProperty * _t1, const QKeySequence & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtCharPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtCharPropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 8)   // "setValue"
    },
    "QtCharPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtCharPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QChar,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QChar,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtCharPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtCharPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtCharPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QChar &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QChar &, std::false_type>
    >,
    nullptr
} };

void QtCharPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtCharPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QChar>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QChar>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtCharPropertyManager::*)(QtProperty * , const QChar & );
            if (_t _q_method = &QtCharPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtCharPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtCharPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtCharPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtCharPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtCharPropertyManager::valueChanged(QtProperty * _t1, const QChar & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtLocalePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[24];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "QtLocalePropertyManager"
        QT_MOC_LITERAL(24, 12),  // "valueChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 11),  // "QtProperty*"
        QT_MOC_LITERAL(50, 8),  // "property"
        QT_MOC_LITERAL(59, 3),  // "val"
        QT_MOC_LITERAL(63, 8)   // "setValue"
    },
    "QtLocalePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtLocalePropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QLocale,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QLocale,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtLocalePropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtLocalePropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtLocalePropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QLocale &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QLocale &, std::false_type>
    >,
    nullptr
} };

void QtLocalePropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtLocalePropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QLocale>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QLocale>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtLocalePropertyManager::*)(QtProperty * , const QLocale & );
            if (_t _q_method = &QtLocalePropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtLocalePropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtLocalePropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtLocalePropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtLocalePropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtLocalePropertyManager::valueChanged(QtProperty * _t1, const QLocale & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtPointPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[23];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "QtPointPropertyManager"
        QT_MOC_LITERAL(23, 12),  // "valueChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 11),  // "QtProperty*"
        QT_MOC_LITERAL(49, 8),  // "property"
        QT_MOC_LITERAL(58, 3),  // "val"
        QT_MOC_LITERAL(62, 8)   // "setValue"
    },
    "QtPointPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtPointPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPoint,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPoint,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtPointPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtPointPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtPointPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>
    >,
    nullptr
} };

void QtPointPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtPointPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtPointPropertyManager::*)(QtProperty * , const QPoint & );
            if (_t _q_method = &QtPointPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtPointPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPointPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtPointPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtPointPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtPointPropertyManager::valueChanged(QtProperty * _t1, const QPoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtPointFPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "decimalsChanged",
    "prec",
    "setValue",
    "setDecimals"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[24];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[16];
    char stringdata7[5];
    char stringdata8[9];
    char stringdata9[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "QtPointFPropertyManager"
        QT_MOC_LITERAL(24, 12),  // "valueChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 11),  // "QtProperty*"
        QT_MOC_LITERAL(50, 8),  // "property"
        QT_MOC_LITERAL(59, 3),  // "val"
        QT_MOC_LITERAL(63, 15),  // "decimalsChanged"
        QT_MOC_LITERAL(79, 4),  // "prec"
        QT_MOC_LITERAL(84, 8),  // "setValue"
        QT_MOC_LITERAL(93, 11)   // "setDecimals"
    },
    "QtPointFPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "decimalsChanged",
    "prec",
    "setValue",
    "setDecimals"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtPointFPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       6,    2,   43,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   48,    2, 0x0a,    7 /* Public */,
       9,    2,   53,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPointF,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPointF,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtPointFPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtPointFPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtPointFPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPointF &, std::false_type>,
        // method 'decimalsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPointF &, std::false_type>,
        // method 'setDecimals'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void QtPointFPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtPointFPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 1: _t->decimalsChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 3: _t->setDecimals((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtPointFPropertyManager::*)(QtProperty * , const QPointF & );
            if (_t _q_method = &QtPointFPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtPointFPropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtPointFPropertyManager::decimalsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QtPointFPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPointFPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtPointFPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtPointFPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QtPointFPropertyManager::valueChanged(QtProperty * _t1, const QPointF & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtPointFPropertyManager::decimalsChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtSizePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[7];
    char stringdata9[9];
    char stringdata10[11];
    char stringdata11[11];
    char stringdata12[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtSizePropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 12),  // "rangeChanged"
        QT_MOC_LITERAL(74, 6),  // "minVal"
        QT_MOC_LITERAL(81, 6),  // "maxVal"
        QT_MOC_LITERAL(88, 8),  // "setValue"
        QT_MOC_LITERAL(97, 10),  // "setMinimum"
        QT_MOC_LITERAL(108, 10),  // "setMaximum"
        QT_MOC_LITERAL(119, 8)   // "setRange"
    },
    "QtSizePropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtSizePropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       6,    3,   55,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    2,   62,    2, 0x0a,    8 /* Public */,
      10,    2,   67,    2, 0x0a,   11 /* Public */,
      11,    2,   72,    2, 0x0a,   14 /* Public */,
      12,    3,   77,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSize,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSize, QMetaType::QSize,    4,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSize,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSize,    4,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSize,    4,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSize, QMetaType::QSize,    4,    7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtSizePropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtSizePropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtSizePropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>,
        // method 'rangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>,
        // method 'setMinimum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>,
        // method 'setMaximum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>,
        // method 'setRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize &, std::false_type>
    >,
    nullptr
} };

void QtSizePropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtSizePropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2]))); break;
        case 1: _t->rangeChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[3]))); break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2]))); break;
        case 3: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2]))); break;
        case 4: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2]))); break;
        case 5: _t->setRange((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtSizePropertyManager::*)(QtProperty * , const QSize & );
            if (_t _q_method = &QtSizePropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtSizePropertyManager::*)(QtProperty * , const QSize & , const QSize & );
            if (_t _q_method = &QtSizePropertyManager::rangeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QtSizePropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtSizePropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtSizePropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtSizePropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QtSizePropertyManager::valueChanged(QtProperty * _t1, const QSize & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtSizePropertyManager::rangeChanged(QtProperty * _t1, const QSize & _t2, const QSize & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtSizeFPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "decimalsChanged",
    "prec",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange",
    "setDecimals"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[23];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[7];
    char stringdata9[16];
    char stringdata10[5];
    char stringdata11[9];
    char stringdata12[11];
    char stringdata13[11];
    char stringdata14[9];
    char stringdata15[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "QtSizeFPropertyManager"
        QT_MOC_LITERAL(23, 12),  // "valueChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 11),  // "QtProperty*"
        QT_MOC_LITERAL(49, 8),  // "property"
        QT_MOC_LITERAL(58, 3),  // "val"
        QT_MOC_LITERAL(62, 12),  // "rangeChanged"
        QT_MOC_LITERAL(75, 6),  // "minVal"
        QT_MOC_LITERAL(82, 6),  // "maxVal"
        QT_MOC_LITERAL(89, 15),  // "decimalsChanged"
        QT_MOC_LITERAL(105, 4),  // "prec"
        QT_MOC_LITERAL(110, 8),  // "setValue"
        QT_MOC_LITERAL(119, 10),  // "setMinimum"
        QT_MOC_LITERAL(130, 10),  // "setMaximum"
        QT_MOC_LITERAL(141, 8),  // "setRange"
        QT_MOC_LITERAL(150, 11)   // "setDecimals"
    },
    "QtSizeFPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "rangeChanged",
    "minVal",
    "maxVal",
    "decimalsChanged",
    "prec",
    "setValue",
    "setMinimum",
    "setMaximum",
    "setRange",
    "setDecimals"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtSizeFPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       6,    3,   67,    2, 0x06,    4 /* Public */,
       9,    2,   74,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    2,   79,    2, 0x0a,   11 /* Public */,
      12,    2,   84,    2, 0x0a,   14 /* Public */,
      13,    2,   89,    2, 0x0a,   17 /* Public */,
      14,    3,   94,    2, 0x0a,   20 /* Public */,
      15,    2,  101,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizeF,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizeF, QMetaType::QSizeF,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizeF,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizeF,    4,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizeF,    4,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizeF, QMetaType::QSizeF,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtSizeFPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtSizeFPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtSizeFPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        // method 'rangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        // method 'decimalsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        // method 'setMinimum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        // method 'setMaximum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        // method 'setRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizeF &, std::false_type>,
        // method 'setDecimals'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void QtSizeFPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtSizeFPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[2]))); break;
        case 1: _t->rangeChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[3]))); break;
        case 2: _t->decimalsChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[2]))); break;
        case 4: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[2]))); break;
        case 5: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[2]))); break;
        case 6: _t->setRange((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[3]))); break;
        case 7: _t->setDecimals((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtSizeFPropertyManager::*)(QtProperty * , const QSizeF & );
            if (_t _q_method = &QtSizeFPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtSizeFPropertyManager::*)(QtProperty * , const QSizeF & , const QSizeF & );
            if (_t _q_method = &QtSizeFPropertyManager::rangeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtSizeFPropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtSizeFPropertyManager::decimalsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *QtSizeFPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtSizeFPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtSizeFPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtSizeFPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QtSizeFPropertyManager::valueChanged(QtProperty * _t1, const QSizeF & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtSizeFPropertyManager::rangeChanged(QtProperty * _t1, const QSizeF & _t2, const QSizeF & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtSizeFPropertyManager::decimalsChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtRectPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "constraintChanged",
    "constraint",
    "setValue",
    "setConstraint"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[18];
    char stringdata7[11];
    char stringdata8[9];
    char stringdata9[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtRectPropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 17),  // "constraintChanged"
        QT_MOC_LITERAL(79, 10),  // "constraint"
        QT_MOC_LITERAL(90, 8),  // "setValue"
        QT_MOC_LITERAL(99, 13)   // "setConstraint"
    },
    "QtRectPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "constraintChanged",
    "constraint",
    "setValue",
    "setConstraint"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtRectPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       6,    2,   43,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   48,    2, 0x0a,    7 /* Public */,
       9,    2,   53,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRect,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRect,    4,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRect,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRect,    4,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtRectPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtRectPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtRectPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRect &, std::false_type>,
        // method 'constraintChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRect &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRect &, std::false_type>,
        // method 'setConstraint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRect &, std::false_type>
    >,
    nullptr
} };

void QtRectPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtRectPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2]))); break;
        case 1: _t->constraintChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2]))); break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2]))); break;
        case 3: _t->setConstraint((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtRectPropertyManager::*)(QtProperty * , const QRect & );
            if (_t _q_method = &QtRectPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtRectPropertyManager::*)(QtProperty * , const QRect & );
            if (_t _q_method = &QtRectPropertyManager::constraintChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QtRectPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtRectPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtRectPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtRectPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QtRectPropertyManager::valueChanged(QtProperty * _t1, const QRect & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtRectPropertyManager::constraintChanged(QtProperty * _t1, const QRect & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtRectFPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "constraintChanged",
    "constraint",
    "decimalsChanged",
    "prec",
    "setValue",
    "setConstraint",
    "setDecimals"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[23];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[18];
    char stringdata7[11];
    char stringdata8[16];
    char stringdata9[5];
    char stringdata10[9];
    char stringdata11[14];
    char stringdata12[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "QtRectFPropertyManager"
        QT_MOC_LITERAL(23, 12),  // "valueChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 11),  // "QtProperty*"
        QT_MOC_LITERAL(49, 8),  // "property"
        QT_MOC_LITERAL(58, 3),  // "val"
        QT_MOC_LITERAL(62, 17),  // "constraintChanged"
        QT_MOC_LITERAL(80, 10),  // "constraint"
        QT_MOC_LITERAL(91, 15),  // "decimalsChanged"
        QT_MOC_LITERAL(107, 4),  // "prec"
        QT_MOC_LITERAL(112, 8),  // "setValue"
        QT_MOC_LITERAL(121, 13),  // "setConstraint"
        QT_MOC_LITERAL(135, 11)   // "setDecimals"
    },
    "QtRectFPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "constraintChanged",
    "constraint",
    "decimalsChanged",
    "prec",
    "setValue",
    "setConstraint",
    "setDecimals"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtRectFPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       6,    2,   55,    2, 0x06,    4 /* Public */,
       8,    2,   60,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    2,   65,    2, 0x0a,   10 /* Public */,
      11,    2,   70,    2, 0x0a,   13 /* Public */,
      12,    2,   75,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRectF,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRectF,    4,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRectF,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRectF,    4,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtRectFPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtRectFPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtRectFPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRectF &, std::false_type>,
        // method 'constraintChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRectF &, std::false_type>,
        // method 'decimalsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRectF &, std::false_type>,
        // method 'setConstraint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRectF &, std::false_type>,
        // method 'setDecimals'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void QtRectFPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtRectFPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[2]))); break;
        case 1: _t->constraintChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[2]))); break;
        case 2: _t->decimalsChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[2]))); break;
        case 4: _t->setConstraint((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[2]))); break;
        case 5: _t->setDecimals((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtRectFPropertyManager::*)(QtProperty * , const QRectF & );
            if (_t _q_method = &QtRectFPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtRectFPropertyManager::*)(QtProperty * , const QRectF & );
            if (_t _q_method = &QtRectFPropertyManager::constraintChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtRectFPropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtRectFPropertyManager::decimalsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *QtRectFPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtRectFPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtRectFPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtRectFPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QtRectFPropertyManager::valueChanged(QtProperty * _t1, const QRectF & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtRectFPropertyManager::constraintChanged(QtProperty * _t1, const QRectF & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtRectFPropertyManager::decimalsChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtEnumPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "enumNamesChanged",
    "names",
    "enumIconsChanged",
    "QMap<int,QIcon>",
    "icons",
    "setValue",
    "setEnumNames",
    "setEnumIcons"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[17];
    char stringdata7[6];
    char stringdata8[17];
    char stringdata9[16];
    char stringdata10[6];
    char stringdata11[9];
    char stringdata12[13];
    char stringdata13[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtEnumPropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 16),  // "enumNamesChanged"
        QT_MOC_LITERAL(78, 5),  // "names"
        QT_MOC_LITERAL(84, 16),  // "enumIconsChanged"
        QT_MOC_LITERAL(101, 15),  // "QMap<int,QIcon>"
        QT_MOC_LITERAL(117, 5),  // "icons"
        QT_MOC_LITERAL(123, 8),  // "setValue"
        QT_MOC_LITERAL(132, 12),  // "setEnumNames"
        QT_MOC_LITERAL(145, 12)   // "setEnumIcons"
    },
    "QtEnumPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "enumNamesChanged",
    "names",
    "enumIconsChanged",
    "QMap<int,QIcon>",
    "icons",
    "setValue",
    "setEnumNames",
    "setEnumIcons"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtEnumPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       6,    2,   55,    2, 0x06,    4 /* Public */,
       8,    2,   60,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    2,   65,    2, 0x0a,   10 /* Public */,
      12,    2,   70,    2, 0x0a,   13 /* Public */,
      13,    2,   75,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QStringList,    4,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    4,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QStringList,    4,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    4,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtEnumPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtEnumPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtEnumPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'enumNamesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'enumIconsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<int,QIcon> &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setEnumNames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'setEnumIcons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<int,QIcon> &, std::false_type>
    >,
    nullptr
} };

void QtEnumPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtEnumPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->enumNamesChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 2: _t->enumIconsChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMap<int,QIcon>>>(_a[2]))); break;
        case 3: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->setEnumNames((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 5: _t->setEnumIcons((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMap<int,QIcon>>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtEnumPropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtEnumPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtEnumPropertyManager::*)(QtProperty * , const QStringList & );
            if (_t _q_method = &QtEnumPropertyManager::enumNamesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtEnumPropertyManager::*)(QtProperty * , const QMap<int,QIcon> & );
            if (_t _q_method = &QtEnumPropertyManager::enumIconsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *QtEnumPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtEnumPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtEnumPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtEnumPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QtEnumPropertyManager::valueChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtEnumPropertyManager::enumNamesChanged(QtProperty * _t1, const QStringList & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtEnumPropertyManager::enumIconsChanged(QtProperty * _t1, const QMap<int,QIcon> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtFlagPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "flagNamesChanged",
    "names",
    "setValue",
    "setFlagNames"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[17];
    char stringdata7[6];
    char stringdata8[9];
    char stringdata9[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtFlagPropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 16),  // "flagNamesChanged"
        QT_MOC_LITERAL(78, 5),  // "names"
        QT_MOC_LITERAL(84, 8),  // "setValue"
        QT_MOC_LITERAL(93, 12)   // "setFlagNames"
    },
    "QtFlagPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "flagNamesChanged",
    "names",
    "setValue",
    "setFlagNames"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtFlagPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       6,    2,   43,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   48,    2, 0x0a,    7 /* Public */,
       9,    2,   53,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QStringList,    4,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QStringList,    4,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtFlagPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtFlagPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtFlagPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'flagNamesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setFlagNames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>
    >,
    nullptr
} };

void QtFlagPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtFlagPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->flagNamesChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->setFlagNames((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtFlagPropertyManager::*)(QtProperty * , int );
            if (_t _q_method = &QtFlagPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtFlagPropertyManager::*)(QtProperty * , const QStringList & );
            if (_t _q_method = &QtFlagPropertyManager::flagNamesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QtFlagPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtFlagPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtFlagPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtFlagPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QtFlagPropertyManager::valueChanged(QtProperty * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtFlagPropertyManager::flagNamesChanged(QtProperty * _t1, const QStringList & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtSizePolicyPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[28];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 27),  // "QtSizePolicyPropertyManager"
        QT_MOC_LITERAL(28, 12),  // "valueChanged"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 11),  // "QtProperty*"
        QT_MOC_LITERAL(54, 8),  // "property"
        QT_MOC_LITERAL(63, 3),  // "val"
        QT_MOC_LITERAL(67, 8)   // "setValue"
    },
    "QtSizePolicyPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtSizePolicyPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizePolicy,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizePolicy,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtSizePolicyPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtSizePolicyPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtSizePolicyPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizePolicy &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSizePolicy &, std::false_type>
    >,
    nullptr
} };

void QtSizePolicyPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtSizePolicyPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizePolicy>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSizePolicy>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtSizePolicyPropertyManager::*)(QtProperty * , const QSizePolicy & );
            if (_t _q_method = &QtSizePolicyPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtSizePolicyPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtSizePolicyPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtSizePolicyPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtSizePolicyPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtSizePolicyPropertyManager::valueChanged(QtProperty * _t1, const QSizePolicy & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtFontPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtFontPropertyManager"
        QT_MOC_LITERAL(22, 12),  // "valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QtProperty*"
        QT_MOC_LITERAL(48, 8),  // "property"
        QT_MOC_LITERAL(57, 3),  // "val"
        QT_MOC_LITERAL(61, 8)   // "setValue"
    },
    "QtFontPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtFontPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QFont,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QFont,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtFontPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtFontPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtFontPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>
    >,
    nullptr
} };

void QtFontPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtFontPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QFont>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QFont>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtFontPropertyManager::*)(QtProperty * , const QFont & );
            if (_t _q_method = &QtFontPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtFontPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtFontPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtFontPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtFontPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtFontPropertyManager::valueChanged(QtProperty * _t1, const QFont & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtColorPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[23];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "QtColorPropertyManager"
        QT_MOC_LITERAL(23, 12),  // "valueChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 11),  // "QtProperty*"
        QT_MOC_LITERAL(49, 8),  // "property"
        QT_MOC_LITERAL(58, 3),  // "val"
        QT_MOC_LITERAL(62, 8)   // "setValue"
    },
    "QtColorPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtColorPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QColor,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QColor,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtColorPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtColorPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtColorPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>
    >,
    nullptr
} };

void QtColorPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtColorPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtColorPropertyManager::*)(QtProperty * , const QColor & );
            if (_t _q_method = &QtColorPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtColorPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtColorPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtColorPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtColorPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtColorPropertyManager::valueChanged(QtProperty * _t1, const QColor & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtCursorPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[24];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "QtCursorPropertyManager"
        QT_MOC_LITERAL(24, 12),  // "valueChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 11),  // "QtProperty*"
        QT_MOC_LITERAL(50, 8),  // "property"
        QT_MOC_LITERAL(59, 3),  // "val"
        QT_MOC_LITERAL(63, 8)   // "setValue"
    },
    "QtCursorPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "setValue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtCursorPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QCursor,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QCursor,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtCursorPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtCursorPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtCursorPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCursor &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCursor &, std::false_type>
    >,
    nullptr
} };

void QtCursorPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtCursorPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QCursor>>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QCursor>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtCursorPropertyManager::*)(QtProperty * , const QCursor & );
            if (_t _q_method = &QtCursorPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtCursorPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtCursorPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtCursorPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtCursorPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtCursorPropertyManager::valueChanged(QtProperty * _t1, const QCursor & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
