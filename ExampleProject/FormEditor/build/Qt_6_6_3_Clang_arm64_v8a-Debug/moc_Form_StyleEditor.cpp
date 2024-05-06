/****************************************************************************
** Meta object code from reading C++ file 'Form_StyleEditor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Forms/Form_StyleEditor.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Form_StyleEditor.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS = QtMocHelpers::stringData(
    "Form_StyleEditor",
    "on_buttonBox_clicked",
    "",
    "QAbstractButton*",
    "button"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[17];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS_t qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "Form_StyleEditor"
        QT_MOC_LITERAL(17, 20),  // "on_buttonBox_clicked"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 16),  // "QAbstractButton*"
        QT_MOC_LITERAL(56, 6)   // "button"
    },
    "Form_StyleEditor",
    "on_buttonBox_clicked",
    "",
    "QAbstractButton*",
    "button"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSForm_StyleEditorENDCLASS[] = {

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
       1,    1,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form_StyleEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSForm_StyleEditorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form_StyleEditor, std::true_type>,
        // method 'on_buttonBox_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>
    >,
    nullptr
} };

void Form_StyleEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_StyleEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_buttonBox_clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Form_StyleEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_StyleEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSForm_StyleEditorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Form_StyleEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
