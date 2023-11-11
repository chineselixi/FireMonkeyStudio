/****************************************************************************
** Meta object code from reading C++ file 'mod_WebPage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../module/mod_WebPage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mod_WebPage.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASScppObjectENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASScppObjectENDCLASS = QtMocHelpers::stringData(
    "cppObject",
    "event_onLoad",
    "",
    "event_onCloseSign",
    "sign",
    "event_onClcloseAllSign",
    "event_onNew",
    "event_onOpen",
    "event_onSourceCodeMall",
    "event_onSetting"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScppObjectENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[10];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[5];
    char stringdata5[23];
    char stringdata6[12];
    char stringdata7[13];
    char stringdata8[23];
    char stringdata9[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScppObjectENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScppObjectENDCLASS_t qt_meta_stringdata_CLASScppObjectENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "cppObject"
        QT_MOC_LITERAL(10, 12),  // "event_onLoad"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 17),  // "event_onCloseSign"
        QT_MOC_LITERAL(42, 4),  // "sign"
        QT_MOC_LITERAL(47, 22),  // "event_onClcloseAllSign"
        QT_MOC_LITERAL(70, 11),  // "event_onNew"
        QT_MOC_LITERAL(82, 12),  // "event_onOpen"
        QT_MOC_LITERAL(95, 22),  // "event_onSourceCodeMall"
        QT_MOC_LITERAL(118, 15)   // "event_onSetting"
    },
    "cppObject",
    "event_onLoad",
    "",
    "event_onCloseSign",
    "sign",
    "event_onClcloseAllSign",
    "event_onNew",
    "event_onOpen",
    "event_onSourceCodeMall",
    "event_onSetting"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScppObjectENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    1,   57,    2, 0x0a,    2 /* Public */,
       5,    0,   60,    2, 0x0a,    4 /* Public */,
       6,    0,   61,    2, 0x0a,    5 /* Public */,
       7,    0,   62,    2, 0x0a,    6 /* Public */,
       8,    0,   63,    2, 0x0a,    7 /* Public */,
       9,    0,   64,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject cppObject::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASScppObjectENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScppObjectENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScppObjectENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<cppObject, std::true_type>,
        // method 'event_onLoad'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'event_onCloseSign'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'event_onClcloseAllSign'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'event_onNew'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'event_onOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'event_onSourceCodeMall'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'event_onSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void cppObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cppObject *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->event_onLoad(); break;
        case 1: _t->event_onCloseSign((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->event_onClcloseAllSign(); break;
        case 3: _t->event_onNew(); break;
        case 4: _t->event_onOpen(); break;
        case 5: _t->event_onSourceCodeMall(); break;
        case 6: _t->event_onSetting(); break;
        default: ;
        }
    }
}

const QMetaObject *cppObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cppObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScppObjectENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cppObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmod_WebPageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSmod_WebPageENDCLASS = QtMocHelpers::stringData(
    "mod_WebPage"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmod_WebPageENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmod_WebPageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmod_WebPageENDCLASS_t qt_meta_stringdata_CLASSmod_WebPageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11)   // "mod_WebPage"
    },
    "mod_WebPage"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmod_WebPageENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject mod_WebPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWebEngineView::staticMetaObject>(),
    qt_meta_stringdata_CLASSmod_WebPageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmod_WebPageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmod_WebPageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mod_WebPage, std::true_type>
    >,
    nullptr
} };

void mod_WebPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *mod_WebPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mod_WebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmod_WebPageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWebEngineView::qt_metacast(_clname);
}

int mod_WebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebEngineView::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
