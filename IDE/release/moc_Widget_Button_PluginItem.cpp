/****************************************************************************
** Meta object code from reading C++ file 'Widget_Button_PluginItem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Widget/Widget_Button_PluginItem.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_Button_PluginItem.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS = QtMocHelpers::stringData(
    "Widget_Button_PluginItem",
    "event_onPluginEnable",
    "",
    "enable",
    "event_onPluginUnload",
    "event_onDown",
    "on_But_enable_clicked",
    "on_But_unload_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[25];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[21];
    char stringdata5[13];
    char stringdata6[22];
    char stringdata7[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS_t qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS = {
    {
        QT_MOC_LITERAL(0, 24),  // "Widget_Button_PluginItem"
        QT_MOC_LITERAL(25, 20),  // "event_onPluginEnable"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 6),  // "enable"
        QT_MOC_LITERAL(54, 20),  // "event_onPluginUnload"
        QT_MOC_LITERAL(75, 12),  // "event_onDown"
        QT_MOC_LITERAL(88, 21),  // "on_But_enable_clicked"
        QT_MOC_LITERAL(110, 21)   // "on_But_unload_clicked"
    },
    "Widget_Button_PluginItem",
    "event_onPluginEnable",
    "",
    "enable",
    "event_onPluginUnload",
    "event_onDown",
    "on_But_enable_clicked",
    "on_But_unload_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidget_Button_PluginItemENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    0,   47,    2, 0x06,    3 /* Public */,
       5,    0,   48,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget_Button_PluginItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidget_Button_PluginItemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget_Button_PluginItem, std::true_type>,
        // method 'event_onPluginEnable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'event_onPluginUnload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'event_onDown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_But_enable_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_But_unload_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Widget_Button_PluginItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget_Button_PluginItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->event_onPluginEnable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->event_onPluginUnload(); break;
        case 2: _t->event_onDown(); break;
        case 3: _t->on_But_enable_clicked(); break;
        case 4: _t->on_But_unload_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget_Button_PluginItem::*)(bool );
            if (_t _q_method = &Widget_Button_PluginItem::event_onPluginEnable; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget_Button_PluginItem::*)();
            if (_t _q_method = &Widget_Button_PluginItem::event_onPluginUnload; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget_Button_PluginItem::*)();
            if (_t _q_method = &Widget_Button_PluginItem::event_onDown; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Widget_Button_PluginItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_Button_PluginItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidget_Button_PluginItemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget_Button_PluginItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Widget_Button_PluginItem::event_onPluginEnable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget_Button_PluginItem::event_onPluginUnload()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Widget_Button_PluginItem::event_onDown()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
