/****************************************************************************
** Meta object code from reading C++ file 'Form_WorkSpace.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Window/Form_WorkSpace.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Form_WorkSpace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
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
struct qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS = QtMocHelpers::stringData(
    "Form_WorkSpace",
    "on_action_file_newCreate_triggered",
    "",
    "on_action_file_open_triggered",
    "on_action_dock_project_triggered",
    "checked",
    "on_action_dock_compilePrint_triggered",
    "on_action_dock_runTip_triggered",
    "on_action_pluginManger_triggered",
    "on_action_menu_about_triggered",
    "on_action_dock_debug_triggered",
    "on_action_dock_find_triggered",
    "on_dockWidget_ProjectManger_visibilityChanged",
    "visible",
    "on_dockWidget_compilePrint_visibilityChanged",
    "on_dockWidget_print_visibilityChanged",
    "on_dockWidget_debug_visibilityChanged",
    "on_dockWidget_find_visibilityChanged",
    "on_comboBox_compileMode_currentIndexChanged",
    "index",
    "on_action_menu_run_enabledChanged",
    "enabled",
    "on_action_menu_Rerun_enabledChanged",
    "on_action_menu_stop_enabledChanged",
    "on_action_menu_compile_enabledChanged",
    "on_action_menu_staticCompile_enabledChanged",
    "on_action_systemSettings_triggered",
    "on_action_toolBar_blue_triggered",
    "on_action_toolBar_white_triggered",
    "on_action_toolBar_Dark_triggered",
    "on_action_file_save_triggered",
    "on_action_file_saveAll_triggered"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS_t {
    uint offsetsAndSizes[64];
    char stringdata0[15];
    char stringdata1[35];
    char stringdata2[1];
    char stringdata3[30];
    char stringdata4[33];
    char stringdata5[8];
    char stringdata6[38];
    char stringdata7[32];
    char stringdata8[33];
    char stringdata9[31];
    char stringdata10[31];
    char stringdata11[30];
    char stringdata12[46];
    char stringdata13[8];
    char stringdata14[45];
    char stringdata15[38];
    char stringdata16[38];
    char stringdata17[37];
    char stringdata18[44];
    char stringdata19[6];
    char stringdata20[34];
    char stringdata21[8];
    char stringdata22[36];
    char stringdata23[35];
    char stringdata24[38];
    char stringdata25[44];
    char stringdata26[35];
    char stringdata27[33];
    char stringdata28[34];
    char stringdata29[33];
    char stringdata30[30];
    char stringdata31[33];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS_t qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "Form_WorkSpace"
        QT_MOC_LITERAL(15, 34),  // "on_action_file_newCreate_trig..."
        QT_MOC_LITERAL(50, 0),  // ""
        QT_MOC_LITERAL(51, 29),  // "on_action_file_open_triggered"
        QT_MOC_LITERAL(81, 32),  // "on_action_dock_project_triggered"
        QT_MOC_LITERAL(114, 7),  // "checked"
        QT_MOC_LITERAL(122, 37),  // "on_action_dock_compilePrint_t..."
        QT_MOC_LITERAL(160, 31),  // "on_action_dock_runTip_triggered"
        QT_MOC_LITERAL(192, 32),  // "on_action_pluginManger_triggered"
        QT_MOC_LITERAL(225, 30),  // "on_action_menu_about_triggered"
        QT_MOC_LITERAL(256, 30),  // "on_action_dock_debug_triggered"
        QT_MOC_LITERAL(287, 29),  // "on_action_dock_find_triggered"
        QT_MOC_LITERAL(317, 45),  // "on_dockWidget_ProjectManger_v..."
        QT_MOC_LITERAL(363, 7),  // "visible"
        QT_MOC_LITERAL(371, 44),  // "on_dockWidget_compilePrint_vi..."
        QT_MOC_LITERAL(416, 37),  // "on_dockWidget_print_visibilit..."
        QT_MOC_LITERAL(454, 37),  // "on_dockWidget_debug_visibilit..."
        QT_MOC_LITERAL(492, 36),  // "on_dockWidget_find_visibility..."
        QT_MOC_LITERAL(529, 43),  // "on_comboBox_compileMode_curre..."
        QT_MOC_LITERAL(573, 5),  // "index"
        QT_MOC_LITERAL(579, 33),  // "on_action_menu_run_enabledCha..."
        QT_MOC_LITERAL(613, 7),  // "enabled"
        QT_MOC_LITERAL(621, 35),  // "on_action_menu_Rerun_enabledC..."
        QT_MOC_LITERAL(657, 34),  // "on_action_menu_stop_enabledCh..."
        QT_MOC_LITERAL(692, 37),  // "on_action_menu_compile_enable..."
        QT_MOC_LITERAL(730, 43),  // "on_action_menu_staticCompile_..."
        QT_MOC_LITERAL(774, 34),  // "on_action_systemSettings_trig..."
        QT_MOC_LITERAL(809, 32),  // "on_action_toolBar_blue_triggered"
        QT_MOC_LITERAL(842, 33),  // "on_action_toolBar_white_trigg..."
        QT_MOC_LITERAL(876, 32),  // "on_action_toolBar_Dark_triggered"
        QT_MOC_LITERAL(909, 29),  // "on_action_file_save_triggered"
        QT_MOC_LITERAL(939, 32)   // "on_action_file_saveAll_triggered"
    },
    "Form_WorkSpace",
    "on_action_file_newCreate_triggered",
    "",
    "on_action_file_open_triggered",
    "on_action_dock_project_triggered",
    "checked",
    "on_action_dock_compilePrint_triggered",
    "on_action_dock_runTip_triggered",
    "on_action_pluginManger_triggered",
    "on_action_menu_about_triggered",
    "on_action_dock_debug_triggered",
    "on_action_dock_find_triggered",
    "on_dockWidget_ProjectManger_visibilityChanged",
    "visible",
    "on_dockWidget_compilePrint_visibilityChanged",
    "on_dockWidget_print_visibilityChanged",
    "on_dockWidget_debug_visibilityChanged",
    "on_dockWidget_find_visibilityChanged",
    "on_comboBox_compileMode_currentIndexChanged",
    "index",
    "on_action_menu_run_enabledChanged",
    "enabled",
    "on_action_menu_Rerun_enabledChanged",
    "on_action_menu_stop_enabledChanged",
    "on_action_menu_compile_enabledChanged",
    "on_action_menu_staticCompile_enabledChanged",
    "on_action_systemSettings_triggered",
    "on_action_toolBar_blue_triggered",
    "on_action_toolBar_white_triggered",
    "on_action_toolBar_Dark_triggered",
    "on_action_file_save_triggered",
    "on_action_file_saveAll_triggered"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSForm_WorkSpaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  170,    2, 0x08,    1 /* Private */,
       3,    0,  171,    2, 0x08,    2 /* Private */,
       4,    1,  172,    2, 0x08,    3 /* Private */,
       6,    1,  175,    2, 0x08,    5 /* Private */,
       7,    1,  178,    2, 0x08,    7 /* Private */,
       8,    0,  181,    2, 0x08,    9 /* Private */,
       9,    0,  182,    2, 0x08,   10 /* Private */,
      10,    1,  183,    2, 0x08,   11 /* Private */,
      11,    1,  186,    2, 0x08,   13 /* Private */,
      12,    1,  189,    2, 0x08,   15 /* Private */,
      14,    1,  192,    2, 0x08,   17 /* Private */,
      15,    1,  195,    2, 0x08,   19 /* Private */,
      16,    1,  198,    2, 0x08,   21 /* Private */,
      17,    1,  201,    2, 0x08,   23 /* Private */,
      18,    1,  204,    2, 0x08,   25 /* Private */,
      20,    1,  207,    2, 0x08,   27 /* Private */,
      22,    1,  210,    2, 0x08,   29 /* Private */,
      23,    1,  213,    2, 0x08,   31 /* Private */,
      24,    1,  216,    2, 0x08,   33 /* Private */,
      25,    1,  219,    2, 0x08,   35 /* Private */,
      26,    0,  222,    2, 0x08,   37 /* Private */,
      27,    0,  223,    2, 0x08,   38 /* Private */,
      28,    0,  224,    2, 0x08,   39 /* Private */,
      29,    0,  225,    2, 0x08,   40 /* Private */,
      30,    0,  226,    2, 0x08,   41 /* Private */,
      31,    0,  227,    2, 0x08,   42 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form_WorkSpace::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSForm_WorkSpaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form_WorkSpace, std::true_type>,
        // method 'on_action_file_newCreate_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_file_open_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_dock_project_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_dock_compilePrint_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_dock_runTip_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_pluginManger_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_menu_about_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_dock_debug_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_dock_find_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_dockWidget_ProjectManger_visibilityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_dockWidget_compilePrint_visibilityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_dockWidget_print_visibilityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_dockWidget_debug_visibilityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_dockWidget_find_visibilityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_comboBox_compileMode_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_action_menu_run_enabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_menu_Rerun_enabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_menu_stop_enabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_menu_compile_enabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_menu_staticCompile_enabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_action_systemSettings_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_toolBar_blue_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_toolBar_white_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_toolBar_Dark_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_file_save_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_file_saveAll_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Form_WorkSpace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_WorkSpace *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_action_file_newCreate_triggered(); break;
        case 1: _t->on_action_file_open_triggered(); break;
        case 2: _t->on_action_dock_project_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_action_dock_compilePrint_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_action_dock_runTip_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_action_pluginManger_triggered(); break;
        case 6: _t->on_action_menu_about_triggered(); break;
        case 7: _t->on_action_dock_debug_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->on_action_dock_find_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->on_dockWidget_ProjectManger_visibilityChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->on_dockWidget_compilePrint_visibilityChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->on_dockWidget_print_visibilityChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_dockWidget_debug_visibilityChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->on_dockWidget_find_visibilityChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->on_comboBox_compileMode_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_action_menu_run_enabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_action_menu_Rerun_enabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_action_menu_stop_enabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->on_action_menu_compile_enabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_action_menu_staticCompile_enabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_action_systemSettings_triggered(); break;
        case 21: _t->on_action_toolBar_blue_triggered(); break;
        case 22: _t->on_action_toolBar_white_triggered(); break;
        case 23: _t->on_action_toolBar_Dark_triggered(); break;
        case 24: _t->on_action_file_save_triggered(); break;
        case 25: _t->on_action_file_saveAll_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject *Form_WorkSpace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_WorkSpace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSForm_WorkSpaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Form_WorkSpace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
