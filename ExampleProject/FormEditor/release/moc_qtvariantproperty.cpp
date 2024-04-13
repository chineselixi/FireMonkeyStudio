/****************************************************************************
** Meta object code from reading C++ file 'qtvariantproperty.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtpropertybrowser/qtvariantproperty.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtvariantproperty.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtVariantPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "attributeChanged",
    "attribute",
    "setValue",
    "setAttribute",
    "value"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[25];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[17];
    char stringdata7[10];
    char stringdata8[9];
    char stringdata9[13];
    char stringdata10[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 24),  // "QtVariantPropertyManager"
        QT_MOC_LITERAL(25, 12),  // "valueChanged"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 11),  // "QtProperty*"
        QT_MOC_LITERAL(51, 8),  // "property"
        QT_MOC_LITERAL(60, 3),  // "val"
        QT_MOC_LITERAL(64, 16),  // "attributeChanged"
        QT_MOC_LITERAL(81, 9),  // "attribute"
        QT_MOC_LITERAL(91, 8),  // "setValue"
        QT_MOC_LITERAL(100, 12),  // "setAttribute"
        QT_MOC_LITERAL(113, 5)   // "value"
    },
    "QtVariantPropertyManager",
    "valueChanged",
    "",
    "QtProperty*",
    "property",
    "val",
    "attributeChanged",
    "attribute",
    "setValue",
    "setAttribute",
    "value"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtVariantPropertyManagerENDCLASS[] = {

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
       6,    3,   43,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   50,    2, 0x0a,    8 /* Public */,
       9,    3,   55,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QVariant,    4,    7,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QVariant,    4,    7,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtVariantPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyManager::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtVariantPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtVariantPropertyManager, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'attributeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'setAttribute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>
    >,
    nullptr
} };

void QtVariantPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtVariantPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 1: _t->attributeChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 3: _t->setAttribute((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtVariantPropertyManager::*)(QtProperty * , const QVariant & );
            if (_t _q_method = &QtVariantPropertyManager::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtVariantPropertyManager::*)(QtProperty * , const QString & , const QVariant & );
            if (_t _q_method = &QtVariantPropertyManager::attributeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QtVariantPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVariantPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtVariantPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyManager::qt_metacast(_clname);
}

int QtVariantPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QtVariantPropertyManager::valueChanged(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtVariantPropertyManager::attributeChanged(QtProperty * _t1, const QString & _t2, const QVariant & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS = QtMocHelpers::stringData(
    "QtVariantEditorFactory"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS_t qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22)   // "QtVariantEditorFactory"
    },
    "QtVariantEditorFactory"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtVariantEditorFactoryENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject QtVariantEditorFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractEditorFactory<QtVariantPropertyManager>::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtVariantEditorFactoryENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtVariantEditorFactory, std::true_type>
    >,
    nullptr
} };

void QtVariantEditorFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QtVariantEditorFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVariantEditorFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtVariantEditorFactoryENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractEditorFactory<QtVariantPropertyManager>::qt_metacast(_clname);
}

int QtVariantEditorFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractEditorFactory<QtVariantPropertyManager>::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
