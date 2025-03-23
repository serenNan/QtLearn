#include "MyWork.h"
#include <QDebug>
#include <QThread>

MyWork::MyWork(QObject *parent) : QObject(parent) {}

void MyWork::working()
{
    qDebug() << "当前线程对象的地址: " << QThread::currentThread();

    int num = 0;
    while (1)
    {
        emit curNumber(num++);
        if (num == 10000000)
        {
            break;
        }
        QThread::usleep(1);
    }
    qDebug() << "run() 执行完毕, 子线程退出...";
}
