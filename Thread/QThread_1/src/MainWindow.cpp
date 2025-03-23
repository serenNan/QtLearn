#include "MainWindow.h"
#include "Mythread.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);

    qDebug() << "主线程对象地址:  " << QThread::currentThread();
    // 创建子线程
    MyThread *subThread = new MyThread;

    connect(subThread, &MyThread::curNumber, this, [=](int num) { ui->label->setNum(num); });

    connect(ui->startBtn, &QPushButton::clicked, this, [=]() {
        // 启动子线程
        subThread->start();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}