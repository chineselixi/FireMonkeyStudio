/****************************************************************************
** Meta object code from reading C++ file 'Widget_MdiArea.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Widgets/Widget_MdiArea.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_MdiArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS = QtMocHelpers::stringData(
    "Widget_MdiArea",
    "event_onScrollBarChange",
    "",
    "dx",
    "dy",
    "event_onResize",
    "QResizeEvent*",
    "resizeEvent"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[15];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[3];
    char stringdata4[3];
    char stringdata5[15];
    char stringdata6[14];
    char stringdata7[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS_t qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "Widget_MdiArea"
        QT_MOC_LITERAL(15, 23),  // "event_onScrollBarChange"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 2),  // "dx"
        QT_MOC_LITERAL(43, 2),  // "dy"
        QT_MOC_LITERAL(46, 14),  // "event_onResize"
        QT_MOC_LITERAL(61, 13),  // "QResizeEvent*"
        QT_MOC_LITERAL(75, 11)   // "resizeEvent"
    },
    "Widget_MdiArea",
    "event_onScrollBarChange",
    "",
    "dx",
    "dy",
    "event_onResize",
    "QResizeEvent*",
    "resizeEvent"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidget_MdiAreaENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,
       5,    1,   31,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget_MdiArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QMdiArea::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidget_MdiAreaENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget_MdiArea, std::true_type>,
        // method 'event_onScrollBarChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'event_onResize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>
    >,
    nullptr
} };

void Widget_MdiArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget_MdiArea *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->event_onScrollBarChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->event_onResize((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget_MdiArea::*)(int , int );
            if (_t _q_method = &Widget_MdiArea::event_onScrollBarChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget_MdiArea::*)(QResizeEvent * );
            if (_t _q_method = &Widget_MdiArea::event_onResize; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *Widget_MdiArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_MdiArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidget_MdiAreaENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMdiArea::qt_metacast(_clname);
}

int Widget_MdiArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiArea::qt_metacall(_c, _id, _a);
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
void Widget_MdiArea::event_onScrollBarChange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget_MdiArea::event_onResize(QResizeEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
