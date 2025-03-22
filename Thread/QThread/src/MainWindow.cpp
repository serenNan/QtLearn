#include "MainWindow.h"
#include "Mythread.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);

    // 1. 创建子线程对象
    Generate *gen = new Generate;

    // 将主线程的数据发送给子线程
    // 需要在启动子线程之前
    // 如果你先启动子线程，然后连接信号和槽，那么在 start 被调用之前，Generate 类的 recvNum 槽可能还没有准备好接收信号。
    // 这会导致信号发出时，槽函数没有被调用。
    connect(this, &MainWindow::starting, gen, &Generate::recvNum);

    // 2. 启动子线程
    connect(ui->startBtn, &QPushButton::clicked, this, [=]() {
        emit starting(100000);
        gen->start();
    });
    
    // 接收子线程发送的数据
    connect(gen, &Generate::sendArray, this, [=](QVector<int> list) {
        for (int i = 0; i < list.size(); i++)
        {
            ui->randList->addItem(QString::number(list.at(i)));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}