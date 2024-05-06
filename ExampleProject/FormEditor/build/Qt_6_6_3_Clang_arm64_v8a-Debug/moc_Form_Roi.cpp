/****************************************************************************
** Meta object code from reading C++ file 'Form_Roi.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Forms/Form_Roi.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Form_Roi.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSForm_RoiENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSForm_RoiENDCLASS = QtMocHelpers::stringData(
    "Form_Roi",
    "onWidgetBaseGeometryChanged",
    "",
    "rect",
    "onWidgetSelected",
    "QList<QWidget*>",
    "widgets",
    "onWidgetGeometryChanged",
    "QWidget*",
    "widget",
    "onWidgetMove",
    "onSubWidgetsChanged",
    "parentWidget"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSForm_RoiENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[9];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[17];
    char stringdata5[16];
    char stringdata6[8];
    char stringdata7[24];
    char stringdata8[9];
    char stringdata9[7];
    char stringdata10[13];
    char stringdata11[20];
    char stringdata12[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSForm_RoiENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSForm_RoiENDCLASS_t qt_meta_stringdata_CLASSForm_RoiENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "Form_Roi"
        QT_MOC_LITERAL(9, 27),  // "onWidgetBaseGeometryChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 4),  // "rect"
        QT_MOC_LITERAL(43, 16),  // "onWidgetSelected"
        QT_MOC_LITERAL(60, 15),  // "QList<QWidget*>"
        QT_MOC_LITERAL(76, 7),  // "widgets"
        QT_MOC_LITERAL(84, 23),  // "onWidgetGeometryChanged"
        QT_MOC_LITERAL(108, 8),  // "QWidget*"
        QT_MOC_LITERAL(117, 6),  // "widget"
        QT_MOC_LITERAL(124, 12),  // "onWidgetMove"
        QT_MOC_LITERAL(137, 19),  // "onSubWidgetsChanged"
        QT_MOC_LITERAL(157, 12)   // "parentWidget"
    },
    "Form_Roi",
    "onWidgetBaseGeometryChanged",
    "",
    "rect",
    "onWidgetSelected",
    "QList<QWidget*>",
    "widgets",
    "onWidgetGeometryChanged",
    "QWidget*",
    "widget",
    "onWidgetMove",
    "onSubWidgetsChanged",
    "parentWidget"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSForm_RoiENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    1,   47,    2, 0x06,    3 /* Public */,
       7,    1,   50,    2, 0x06,    5 /* Public */,
      10,    1,   53,    2, 0x06,    7 /* Public */,
      11,    1,   56,    2, 0x06,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRect,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form_Roi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSForm_RoiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSForm_RoiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSForm_RoiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form_Roi, std::true_type>,
        // method 'onWidgetBaseGeometryChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRect, std::false_type>,
        // method 'onWidgetSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QWidget*>, std::false_type>,
        // method 'onWidgetGeometryChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'onWidgetMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QWidget*>, std::false_type>,
        // method 'onSubWidgetsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>
    >,
    nullptr
} };

void Form_Roi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_Roi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onWidgetBaseGeometryChanged((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 1: _t->onWidgetSelected((*reinterpret_cast< std::add_pointer_t<QList<QWidget*>>>(_a[1]))); break;
        case 2: _t->onWidgetGeometryChanged((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 3: _t->onWidgetMove((*reinterpret_cast< std::add_pointer_t<QList<QWidget*>>>(_a[1]))); break;
        case 4: _t->onSubWidgetsChanged((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QWidget*> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QWidget*> >(); break;
            }
            break;
        case 4:
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
            using _t = void (Form_Roi::*)(QRect );
            if (_t _q_method = &Form_Roi::onWidgetBaseGeometryChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Form_Roi::*)(QList<QWidget*> );
            if (_t _q_method = &Form_Roi::onWidgetSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Form_Roi::*)(QWidget * );
            if (_t _q_method = &Form_Roi::onWidgetGeometryChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Form_Roi::*)(QList<QWidget*> );
            if (_t _q_method = &Form_Roi::onWidgetMove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Form_Roi::*)(QWidget * );
            if (_t _q_method = &Form_Roi::onSubWidgetsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *Form_Roi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_Roi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSForm_RoiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_Roi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Form_Roi::onWidgetBaseGeometryChanged(QRect _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Form_Roi::onWidgetSelected(QList<QWidget*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Form_Roi::onWidgetGeometryChanged(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Form_Roi::onWidgetMove(QList<QWidget*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Form_Roi::onSubWidgetsChanged(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
