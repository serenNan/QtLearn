#include "mainwindow.h"
#include "dialog.h"
#include "widget.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_mainwindow) // 基于 mainwindow.ui 创建一个实例对象
{
    // 将 mainwindow.ui 的示例对象和当前类的对象进行关联
    ui->setupUi(this);

    // 一般在 qt 的构造函数中进行初始化操作（窗口，数据，...）
    // 显示当前窗口的时候，显示另外一个窗口 widget
#if 1
    // 创建窗口对象，没有给 w 对象指定父对象
    widget *w = new widget;
    w->show();
#else
    // 创建窗口对象，没有给 w 对象指定父对象
    // widget(QWidget* parent = nullptr);
    widget *w = new widget(this);

#endif

#if 0
    // 创建对话框窗口
    dialog *dlg = new dialog(this);
    // 非模态
    dlg->show();
#else
    // 创建对话框窗口
    dialog *dlg = new dialog(this);
    // 模态,exec()
    // 阻塞程序运行
    dlg->exec();
#endif
    
}

mainwindow::~mainwindow()
{
    delete ui;
}