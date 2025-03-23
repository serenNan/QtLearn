#include "MainWindow.h"
#include "Mythread.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);

    // 1. 创建子线程对象
    QThread *t1 = new QThread;
    QThread *t2 = new QThread;
    QThread *t3 = new QThread;

    // 2. 创建任务类的对象
    Generate *gen = new Generate;
    BubbleSort *bubble = new BubbleSort;
    QuickSort *quick = new QuickSort;

    // 3. 将任务对象移动到某个子线程中
    gen->moveToThread(t1);
    bubble->moveToThread(t2);
    quick->moveToThread(t3);

    // 将主线程的数据发送给子线程
    // 需要在启动子线程之前
    // 如果你先启动子线程，然后连接信号和槽，那么在 start 被调用之前，Generate 类的 recvNum
    // 槽可能还没有准备好接收信号。 这会导致信号发出时，槽函数没有被调用。
    connect(this, &MainWindow::starting, gen, &Generate::working);

    // 2. 启动子线程
    connect(ui->startBtn, &QPushButton::clicked, this, [=]() {
        emit starting(10000);
        t1->start();
    });

    connect(gen, &Generate::sendArray, bubble, &BubbleSort::working);
    connect(gen, &Generate::sendArray, quick, &QuickSort::working);

    // 接收子线程发送的数据
    connect(gen, &Generate::sendArray, this, [=](QVector<int> list) {
        t2->start();
        t3->start();
        for (int i = 0; i < list.size(); i++)
        {
            ui->randList->addItem(QString::number(list.at(i)));
        }
    });

    connect(bubble, &BubbleSort::finish, this, [=](QVector<int> list) {
        for (int i = 0; i < list.size(); i++)
        {
            ui->bubbleList->addItem(QString::number(list.at(i)));
        }
    });

    connect(quick, &QuickSort::finish, this, [=](QVector<int> list) {
        for (int i = 0; i < list.size(); i++)
        {
            ui->quickList->addItem(QString::number(list.at(i)));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}