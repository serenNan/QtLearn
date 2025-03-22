#include "MainWindow.h"
#include "Mythread.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);

    // 1. 创建子线程对象
    Generate *gen = new Generate;

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