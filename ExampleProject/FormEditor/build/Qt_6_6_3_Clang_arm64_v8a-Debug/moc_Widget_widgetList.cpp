/****************************************************************************
** Meta object code from reading C++ file 'Widget_widgetList.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Widgets/Widget_widgetList.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_widgetList.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWidget_widgetListENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWidget_widgetListENDCLASS = QtMocHelpers::stringData(
    "Widget_widgetList",
    "event_Menu_onItemRemove",
    "",
    "QWidget*",
    "item",
    "event_onItemClick",
    "on_treeWidget_itemClicked",
    "QTreeWidgetItem*",
    "column"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidget_widgetListENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[18];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[5];
    char stringdata5[18];
    char stringdata6[26];
    char stringdata7[17];
    char stringdata8[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidget_widgetListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidget_widgetListENDCLASS_t qt_meta_stringdata_CLASSWidget_widgetListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "Widget_widgetList"
        QT_MOC_LITERAL(18, 23),  // "event_Menu_onItemRemove"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 8),  // "QWidget*"
        QT_MOC_LITERAL(52, 4),  // "item"
        QT_MOC_LITERAL(57, 17),  // "event_onItemClick"
        QT_MOC_LITERAL(75, 25),  // "on_treeWidget_itemClicked"
        QT_MOC_LITERAL(101, 16),  // "QTreeWidgetItem*"
        QT_MOC_LITERAL(118, 6)   // "column"
    },
    "Widget_widgetList",
    "event_Menu_onItemRemove",
    "",
    "QWidget*",
    "item",
    "event_onItemClick",
    "on_treeWidget_itemClicked",
    "QTreeWidgetItem*",
    "column"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidget_widgetListENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       5,    1,   35,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   38,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    4,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget_widgetList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidget_widgetListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidget_widgetListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidget_widgetListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget_widgetList, std::true_type>,
        // method 'event_Menu_onItemRemove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'event_onItemClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'on_treeWidget_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Widget_widgetList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget_widgetList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->event_Menu_onItemRemove((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 1: _t->event_onItemClick((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 2: _t->on_treeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget_widgetList::*)(QWidget * );
            if (_t _q_method = &Widget_widgetList::event_Menu_onItemRemove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget_widgetList::*)(QWidget * );
            if (_t _q_method = &Widget_widgetList::event_onItemClick; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *Widget_widgetList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_widgetList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidget_widgetListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget_widgetList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Widget_widgetList::event_Menu_onItemRemove(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget_widgetList::event_onItemClick(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
