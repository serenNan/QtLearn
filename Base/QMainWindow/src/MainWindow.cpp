#include "MainWindow.h"
#include "QMessageBox"
#include "QTimer"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);

    // save_action 是某个菜单项对象名, 点击这个菜单项会弹出一个对话框
    connect(ui->save_action, &QAction::triggered, this,
            [=]() { QMessageBox::information(this, "Triggered", "我是菜单项, 你不要调戏我..."); });

    // 添加第二个工具栏
    QToolBar *toolbar = new QToolBar("toolbar");
    this->addToolBar(Qt::LeftToolBarArea, toolbar);
    toolbar->addWidget(new QPushButton("搜索"));

    // 给工具栏添加按钮和单行输入框
    ui->toolBar->addWidget(new QPushButton("搜索"));
    QLineEdit *edit = new QLineEdit;
    // edit->setMaximumWidth(200);
    edit->setFixedWidth(100);
    ui->toolBar->addWidget(edit);
    // 添加QAction类型的菜单项
    ui->toolBar->addAction(QIcon(":/er-dog"), "action");

    ui->statusbar->showMessage("show11111111111111111111111111111111111111", 2000);

    // 状态栏添加子控件
    // 按钮
    QPushButton *button = new QPushButton("按钮");
    ui->statusbar->addWidget(button);
    // 标签
    QLabel *label = new QLabel("label");
    ui->statusbar->addWidget(label);

    QTimer::singleShot(5000, this, [=]() {
        button->show();
        label->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}