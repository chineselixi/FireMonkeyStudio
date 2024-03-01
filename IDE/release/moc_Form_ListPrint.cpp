/****************************************************************************
** Meta object code from reading C++ file 'Form_ListPrint.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Window/Form_ListPrint.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Form_ListPrint.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSForm_ListPrintENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSForm_ListPrintENDCLASS = QtMocHelpers::stringData(
    "Form_ListPrint",
    "onFileOpen",
    "",
    "file",
    "uint16_t",
    "line",
    "lineIndex",
    "len",
    "on_treeWidget_itemDoubleClicked",
    "QTreeWidgetItem*",
    "item",
    "column"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSForm_ListPrintENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[15];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[9];
    char stringdata5[5];
    char stringdata6[10];
    char stringdata7[4];
    char stringdata8[32];
    char stringdata9[17];
    char stringdata10[5];
    char stringdata11[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSForm_ListPrintENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSForm_ListPrintENDCLASS_t qt_meta_stringdata_CLASSForm_ListPrintENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "Form_ListPrint"
        QT_MOC_LITERAL(15, 10),  // "onFileOpen"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "file"
        QT_MOC_LITERAL(32, 8),  // "uint16_t"
        QT_MOC_LITERAL(41, 4),  // "line"
        QT_MOC_LITERAL(46, 9),  // "lineIndex"
        QT_MOC_LITERAL(56, 3),  // "len"
        QT_MOC_LITERAL(60, 31),  // "on_treeWidget_itemDoubleClicked"
        QT_MOC_LITERAL(92, 16),  // "QTreeWidgetItem*"
        QT_MOC_LITERAL(109, 4),  // "item"
        QT_MOC_LITERAL(114, 6)   // "column"
    },
    "Form_ListPrint",
    "onFileOpen",
    "",
    "file",
    "uint16_t",
    "line",
    "lineIndex",
    "len",
    "on_treeWidget_itemDoubleClicked",
    "QTreeWidgetItem*",
    "item",
    "column"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSForm_ListPrintENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   44,    2, 0x06,    1 /* Public */,
       1,    3,   53,    2, 0x26,    6 /* Public | MethodCloned */,
       1,    2,   60,    2, 0x26,   10 /* Public | MethodCloned */,
       1,    1,   65,    2, 0x26,   13 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   68,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form_ListPrint::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSForm_ListPrintENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSForm_ListPrintENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSForm_ListPrintENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form_ListPrint, std::true_type>,
        // method 'onFileOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        // method 'onFileOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        // method 'onFileOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        // method 'onFileOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_treeWidget_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Form_ListPrint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_ListPrint *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onFileOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[4]))); break;
        case 1: _t->onFileOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3]))); break;
        case 2: _t->onFileOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2]))); break;
        case 3: _t->onFileOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_treeWidget_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Form_ListPrint::*)(QString , uint16_t , uint16_t , uint16_t );
            if (_t _q_method = &Form_ListPrint::onFileOpen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Form_ListPrint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_ListPrint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSForm_ListPrintENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_ListPrint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Form_ListPrint::onFileOpen(QString _t1, uint16_t _t2, uint16_t _t3, uint16_t _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
