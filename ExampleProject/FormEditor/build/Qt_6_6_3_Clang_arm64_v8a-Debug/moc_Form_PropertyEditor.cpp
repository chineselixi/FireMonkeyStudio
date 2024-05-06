/****************************************************************************
** Meta object code from reading C++ file 'Form_PropertyEditor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Forms/Form_PropertyEditor.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Form_PropertyEditor.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS = QtMocHelpers::stringData(
    "Form_PropertyEditor",
    "onWidgetNameChange",
    "",
    "QWidget*",
    "signBaseWidget",
    "widgetMsg*",
    "updateWidgetMessage",
    "QString&",
    "newName",
    "onWidgetUpdate",
    "PropertyValueChanged",
    "QtProperty*",
    "property",
    "value",
    "EnumValueChanged",
    "val"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[20];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[15];
    char stringdata5[11];
    char stringdata6[20];
    char stringdata7[9];
    char stringdata8[8];
    char stringdata9[15];
    char stringdata10[21];
    char stringdata11[12];
    char stringdata12[9];
    char stringdata13[6];
    char stringdata14[17];
    char stringdata15[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS_t qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "Form_PropertyEditor"
        QT_MOC_LITERAL(20, 18),  // "onWidgetNameChange"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 8),  // "QWidget*"
        QT_MOC_LITERAL(49, 14),  // "signBaseWidget"
        QT_MOC_LITERAL(64, 10),  // "widgetMsg*"
        QT_MOC_LITERAL(75, 19),  // "updateWidgetMessage"
        QT_MOC_LITERAL(95, 8),  // "QString&"
        QT_MOC_LITERAL(104, 7),  // "newName"
        QT_MOC_LITERAL(112, 14),  // "onWidgetUpdate"
        QT_MOC_LITERAL(127, 20),  // "PropertyValueChanged"
        QT_MOC_LITERAL(148, 11),  // "QtProperty*"
        QT_MOC_LITERAL(160, 8),  // "property"
        QT_MOC_LITERAL(169, 5),  // "value"
        QT_MOC_LITERAL(175, 16),  // "EnumValueChanged"
        QT_MOC_LITERAL(192, 3)   // "val"
    },
    "Form_PropertyEditor",
    "onWidgetNameChange",
    "",
    "QWidget*",
    "signBaseWidget",
    "widgetMsg*",
    "updateWidgetMessage",
    "QString&",
    "newName",
    "onWidgetUpdate",
    "PropertyValueChanged",
    "QtProperty*",
    "property",
    "value",
    "EnumValueChanged",
    "val"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSForm_PropertyEditorENDCLASS[] = {

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
       1,    3,   38,    2, 0x06,    1 /* Public */,
       9,    2,   45,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    2,   50,    2, 0x0a,    8 /* Public */,
      14,    2,   55,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11, QMetaType::QVariant,   12,   13,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form_PropertyEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSForm_PropertyEditorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form_PropertyEditor, std::true_type>,
        // method 'onWidgetNameChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<widgetMsg *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'onWidgetUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<widgetMsg *, std::false_type>,
        // method 'PropertyValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'EnumValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QtProperty *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Form_PropertyEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_PropertyEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onWidgetNameChange((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<widgetMsg*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[3]))); break;
        case 1: _t->onWidgetUpdate((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<widgetMsg*>>(_a[2]))); break;
        case 2: _t->PropertyValueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 3: _t->EnumValueChanged((*reinterpret_cast< std::add_pointer_t<QtProperty*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
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
            using _t = void (Form_PropertyEditor::*)(QWidget * , widgetMsg * , QString & );
            if (_t _q_method = &Form_PropertyEditor::onWidgetNameChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Form_PropertyEditor::*)(QWidget * , widgetMsg * );
            if (_t _q_method = &Form_PropertyEditor::onWidgetUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *Form_PropertyEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_PropertyEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSForm_PropertyEditorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_PropertyEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Form_PropertyEditor::onWidgetNameChange(QWidget * _t1, widgetMsg * _t2, QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Form_PropertyEditor::onWidgetUpdate(QWidget * _t1, widgetMsg * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
