#include "widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent), // 初始化列表也要记得修改类型
      ui(new Ui_widget)
{
    ui->setupUi(this);
}

widget::~widget()
{
    delete ui;
}