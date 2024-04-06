#include "GlobalMsg.h"



//组件盒子指针
Form_WidgetBox* Form::widgetBoxPtr = nullptr;

//控件属性编辑器指针
Form_PropertyEditor* Form::PropertyEditorPtr = nullptr;


//当前选择的插件
Plugin_Base* Plugin::nowSelectPlugin = nullptr;
