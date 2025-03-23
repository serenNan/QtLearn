#include "MainWindow.h"
#include "MyWork.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);

    qDebug() << "主线程对象地址:  " << QThread::currentThread();
    // 创建线程对象
    QThread *subThread = new QThread;

    // 创建工作的类对象
    // 不要给创建的对象指定父对象
    // 不然会导致错误：QObject::moveToThread: Cannot move objects with a parent
    MyWork *work = new MyWork;

    // 将工作的类对象移动到创建的子线程中
    work->moveToThread(subThread);

    // 启动线程
    subThread->start();
    // 让工作的对象开始工作, 点击开始按钮, 开始工作
    connect(ui->startBtn, &QPushButton::clicked, work, &MyWork::working);
    // 显示数据
    connect(work, &MyWork::curNumber, this, [=](int num) { ui->label->setNum(num); });
}

MainWindow::~MainWindow()
{
    delete ui;
}