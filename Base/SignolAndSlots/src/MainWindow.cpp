#include "MainWindow.h"
#include "stdlib.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);

    m_me = new Me;
    m_girlfriend = new GirlFriend;
    // lambda 表达式
    connect(ui->hungry, &QPushButton::clicked, this, [=]() {
        m_girlfriend->hungry("意大利面");
    });
    // 在MainWindow构造函数中
    connect(ui->hungry, &QPushButton::clicked, [this]() {
        // 假设通过UI元素获取选择的食物（例如QComboBox）
        QString selectedFood = ui->food->currentText();
        // 触发GirlFriend的setHungry槽，传递食物参数
        m_girlfriend->setHungry(selectedFood);
    });
    connect(m_girlfriend, &GirlFriend::hungry, m_me, &Me::eat);
    // 匿名函数的定义, 程序执行这个匿名函数是不会被调用的
    []() { qDebug() << "hello, 我是一个lambda表达式..."; };

    // 调用匿名函数
    []() { qDebug() << "hello, 我是一个lambda表达式..."; }();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::hungrySlot()
// {
//     // 发射自定义信号
//     emit m_girlfriend->hungry();
// }