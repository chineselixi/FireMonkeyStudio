/****************************************************************************
** Meta object code from reading C++ file 'mod_TipList.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../module/mod_TipList.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mod_TipList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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
struct qt_meta_stringdata_CLASSmod_TipListENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSmod_TipListENDCLASS = QtMocHelpers::stringData(
    "mod_TipList",
    "onTipOut",
    "",
    "tipText",
    "getList",
    "QList<QString>*",
    "listType",
    "type",
    "onItemClicked",
    "QListWidgetItem*",
    "item",
    "findStringLike",
    "src",
    "parentStr",
    "getStringLikeList",
    "QList<strLikeMsg>",
    "parentList"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmod_TipListENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[12];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[8];
    char stringdata5[16];
    char stringdata6[9];
    char stringdata7[5];
    char stringdata8[14];
    char stringdata9[17];
    char stringdata10[5];
    char stringdata11[15];
    char stringdata12[4];
    char stringdata13[10];
    char stringdata14[18];
    char stringdata15[18];
    char stringdata16[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmod_TipListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmod_TipListENDCLASS_t qt_meta_stringdata_CLASSmod_TipListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "mod_TipList"
        QT_MOC_LITERAL(12, 8),  // "onTipOut"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 7),  // "tipText"
        QT_MOC_LITERAL(30, 7),  // "getList"
        QT_MOC_LITERAL(38, 15),  // "QList<QString>*"
        QT_MOC_LITERAL(54, 8),  // "listType"
        QT_MOC_LITERAL(63, 4),  // "type"
        QT_MOC_LITERAL(68, 13),  // "onItemClicked"
        QT_MOC_LITERAL(82, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(99, 4),  // "item"
        QT_MOC_LITERAL(104, 14),  // "findStringLike"
        QT_MOC_LITERAL(119, 3),  // "src"
        QT_MOC_LITERAL(123, 9),  // "parentStr"
        QT_MOC_LITERAL(133, 17),  // "getStringLikeList"
        QT_MOC_LITERAL(151, 17),  // "QList<strLikeMsg>"
        QT_MOC_LITERAL(169, 10)   // "parentList"
    },
    "mod_TipList",
    "onTipOut",
    "",
    "tipText",
    "getList",
    "QList<QString>*",
    "listType",
    "type",
    "onItemClicked",
    "QListWidgetItem*",
    "item",
    "findStringLike",
    "src",
    "parentStr",
    "getStringLikeList",
    "QList<strLikeMsg>",
    "parentList"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmod_TipListENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   47,    2, 0x08,    3 /* Private */,
       8,    1,   50,    2, 0x08,    5 /* Private */,
      11,    2,   53,    2, 0x08,    7 /* Private */,
      14,    3,   58,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    0x80000000 | 5, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   12,   13,
    0x80000000 | 15, QMetaType::QString, QMetaType::QStringList, 0x80000000 | 6,   12,   16,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject mod_TipList::staticMetaObject = { {
    QMetaObject::SuperData::link<QListWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSmod_TipListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmod_TipListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmod_TipListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mod_TipList, std::true_type>,
        // method 'onTipOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getList'
        QtPrivate::TypeAndForceComplete<QVector<QString> *, std::false_type>,
        QtPrivate::TypeAndForceComplete<listType, std::false_type>,
        // method 'onItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'findStringLike'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getStringLikeList'
        QtPrivate::TypeAndForceComplete<QVector<strLikeMsg>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<listType, std::false_type>
    >,
    nullptr
} };

void mod_TipList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mod_TipList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onTipOut((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: { QList<QString>* _r = _t->getList((*reinterpret_cast< std::add_pointer_t<listType>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->onItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 3: { int _r = _t->findStringLike((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<strLikeMsg> _r = _t->getStringLikeList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<listType>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QList<strLikeMsg>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mod_TipList::*)(QString );
            if (_t _q_method = &mod_TipList::onTipOut; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *mod_TipList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mod_TipList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmod_TipListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int mod_TipList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
void mod_TipList::onTipOut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
