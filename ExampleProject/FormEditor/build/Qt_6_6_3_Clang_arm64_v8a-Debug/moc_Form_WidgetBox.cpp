/****************************************************************************
** Meta object code from reading C++ file 'Form_WidgetBox.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Forms/Form_WidgetBox.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Form_WidgetBox.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS = QtMocHelpers::stringData(
    "Form_WidgetBox",
    "onPluginSelectChanged",
    "",
    "Plugin_Base*",
    "plg",
    "on_listWidget_itemClicked",
    "QListWidgetItem*",
    "item"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[15];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[4];
    char stringdata5[26];
    char stringdata6[17];
    char stringdata7[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS_t qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "Form_WidgetBox"
        QT_MOC_LITERAL(15, 21),  // "onPluginSelectChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 12),  // "Plugin_Base*"
        QT_MOC_LITERAL(51, 3),  // "plg"
        QT_MOC_LITERAL(55, 25),  // "on_listWidget_itemClicked"
        QT_MOC_LITERAL(81, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(98, 4)   // "item"
    },
    "Form_WidgetBox",
    "onPluginSelectChanged",
    "",
    "Plugin_Base*",
    "plg",
    "on_listWidget_itemClicked",
    "QListWidgetItem*",
    "item"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSForm_WidgetBoxENDCLASS[] = {

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
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   29,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form_WidgetBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSForm_WidgetBoxENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form_WidgetBox, std::true_type>,
        // method 'onPluginSelectChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Plugin_Base *, std::false_type>,
        // method 'on_listWidget_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>
    >,
    nullptr
} };

void Form_WidgetBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_WidgetBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onPluginSelectChanged((*reinterpret_cast< std::add_pointer_t<Plugin_Base*>>(_a[1]))); break;
        case 1: _t->on_listWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Form_WidgetBox::*)(Plugin_Base * );
            if (_t _q_method = &Form_WidgetBox::onPluginSelectChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Form_WidgetBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_WidgetBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSForm_WidgetBoxENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_WidgetBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Form_WidgetBox::onPluginSelectChanged(Plugin_Base * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
