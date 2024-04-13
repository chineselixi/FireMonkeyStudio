/****************************************************************************
** Meta object code from reading C++ file 'qtpropertybrowser.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtpropertybrowser/qtpropertybrowser.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtpropertybrowser.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS = QtMocHelpers::stringData(
    "QtAbstractPropertyManager",
    "propertyInserted",
    "",
    "QtProperty*",
    "property",
    "parent",
    "after",
    "propertyChanged",
    "propertyRemoved",
    "propertyDestroyed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[26];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[7];
    char stringdata6[6];
    char stringdata7[16];
    char stringdata8[16];
    char stringdata9[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS_t qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 25),  // "QtAbstractPropertyManager"
        QT_MOC_LITERAL(26, 16),  // "propertyInserted"
        QT_MOC_LITERAL(43, 0),  // ""
        QT_MOC_LITERAL(44, 11),  // "QtProperty*"
        QT_MOC_LITERAL(56, 8),  // "property"
        QT_MOC_LITERAL(65, 6),  // "parent"
        QT_MOC_LITERAL(72, 5),  // "after"
        QT_MOC_LITERAL(78, 15),  // "propertyChanged"
        QT_MOC_LITERAL(94, 15),  // "propertyRemoved"
        QT_MOC_LITERAL(110, 17)   // "propertyDestroyed"
    },
    "QtAbstractPropertyManager",
    "propertyInserted",
    "",
    "QtProperty*",
    "property",
    "parent",
    "after",
    "propertyChanged",
    "propertyRemoved",
    "propertyDestroyed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtAbstractPropertyManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   38,    2, 0x06,    1 /* Public */,
       7,    1,   45,    2, 0x06,    5 /* Public */,
       8,    2,   48,    2, 0x06,    7 /* Public */,
       9,    1,   53,    2, 0x06,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtAbstractPropertyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtAbstractPropertyManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtAbstractPropertyManager, std::true_type>,
        // method 'propertyInserted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        // method 'propertyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        // method 'propertyRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        // method 'propertyDestroyed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>
    >,
    nullptr
} };

void QtAbstractPropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtAbstractPropertyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->propertyInserted((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[3]))); break;
        case 1: _t->propertyChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1]))); break;
        case 2: _t->propertyRemoved((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[2]))); break;
        case 3: _t->propertyDestroyed((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtAbstractPropertyManager::*)(QtProperty * , QtProperty * , QtProperty * );
            if (_t _q_method = &QtAbstractPropertyManager::propertyInserted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtAbstractPropertyManager::*)(QtProperty * );
            if (_t _q_method = &QtAbstractPropertyManager::propertyChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtAbstractPropertyManager::*)(QtProperty * , QtProperty * );
            if (_t _q_method = &QtAbstractPropertyManager::propertyRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtAbstractPropertyManager::*)(QtProperty * );
            if (_t _q_method = &QtAbstractPropertyManager::propertyDestroyed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *QtAbstractPropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtAbstractPropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtAbstractPropertyManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtAbstractPropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QtAbstractPropertyManager::propertyInserted(QtProperty * _t1, QtProperty * _t2, QtProperty * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtAbstractPropertyManager::propertyChanged(QtProperty * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtAbstractPropertyManager::propertyRemoved(QtProperty * _t1, QtProperty * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtAbstractPropertyManager::propertyDestroyed(QtProperty * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS = QtMocHelpers::stringData(
    "QtAbstractEditorFactoryBase",
    "managerDestroyed",
    "",
    "manager"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[28];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS_t qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS = {
    {
        QT_MOC_LITERAL(0, 27),  // "QtAbstractEditorFactoryBase"
        QT_MOC_LITERAL(28, 16),  // "managerDestroyed"
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 7)   // "manager"
    },
    "QtAbstractEditorFactoryBase",
    "managerDestroyed",
    "",
    "manager"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtAbstractEditorFactoryBaseENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x09,    1 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtAbstractEditorFactoryBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtAbstractEditorFactoryBaseENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtAbstractEditorFactoryBase, std::true_type>,
        // method 'managerDestroyed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>
    >,
    nullptr
} };

void QtAbstractEditorFactoryBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtAbstractEditorFactoryBase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->managerDestroyed((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *QtAbstractEditorFactoryBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtAbstractEditorFactoryBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtAbstractEditorFactoryBaseENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtAbstractEditorFactoryBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS = QtMocHelpers::stringData(
    "QtAbstractPropertyBrowser",
    "currentItemChanged",
    "",
    "QtBrowserItem*",
    "addProperty",
    "QtProperty*",
    "property",
    "insertProperty",
    "afterProperty",
    "removeProperty"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[26];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[12];
    char stringdata5[12];
    char stringdata6[9];
    char stringdata7[15];
    char stringdata8[14];
    char stringdata9[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS_t qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS = {
    {
        QT_MOC_LITERAL(0, 25),  // "QtAbstractPropertyBrowser"
        QT_MOC_LITERAL(26, 18),  // "currentItemChanged"
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 14),  // "QtBrowserItem*"
        QT_MOC_LITERAL(61, 11),  // "addProperty"
        QT_MOC_LITERAL(73, 11),  // "QtProperty*"
        QT_MOC_LITERAL(85, 8),  // "property"
        QT_MOC_LITERAL(94, 14),  // "insertProperty"
        QT_MOC_LITERAL(109, 13),  // "afterProperty"
        QT_MOC_LITERAL(123, 14)   // "removeProperty"
    },
    "QtAbstractPropertyBrowser",
    "currentItemChanged",
    "",
    "QtBrowserItem*",
    "addProperty",
    "QtProperty*",
    "property",
    "insertProperty",
    "afterProperty",
    "removeProperty"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtAbstractPropertyBrowserENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   41,    2, 0x0a,    3 /* Public */,
       7,    2,   44,    2, 0x0a,    5 /* Public */,
       9,    1,   49,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    0x80000000 | 3, 0x80000000 | 5,    6,
    0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5,    6,    8,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtAbstractPropertyBrowser::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtAbstractPropertyBrowserENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtAbstractPropertyBrowser, std::true_type>,
        // method 'currentItemChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtBrowserItem *, std::false_type>,
        // method 'addProperty'
        QtPrivate::TypeAndForceComplete<QtBrowserItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        // method 'insertProperty'
        QtPrivate::TypeAndForceComplete<QtBrowserItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        // method 'removeProperty'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>
    >,
    nullptr
} };

void QtAbstractPropertyBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtAbstractPropertyBrowser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentItemChanged((*reinterpret_cast< std::add_pointer_t<QtBrowserItem*>>(_a[1]))); break;
        case 1: { QtBrowserItem* _r = _t->addProperty((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QtBrowserItem**>(_a[0]) = std::move(_r); }  break;
        case 2: { QtBrowserItem* _r = _t->insertProperty((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QtBrowserItem**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->removeProperty((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtAbstractPropertyBrowser::*)(QtBrowserItem * );
            if (_t _q_method = &QtAbstractPropertyBrowser::currentItemChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QtAbstractPropertyBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtAbstractPropertyBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtAbstractPropertyBrowserENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QtAbstractPropertyBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void QtAbstractPropertyBrowser::currentItemChanged(QtBrowserItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
