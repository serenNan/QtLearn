#include "Mythread.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QThread>
#include <algorithm>

Generate::Generate(QObject *parent) : QObject(parent) {}

void Generate::working(int num)
{
    qDebug() << "生成随机数的线程的线程地址:" << QThread::currentThread();
    QVector<int> list;
    QElapsedTimer time; // 计算流程执行时间
    time.start();
    for (int i = 0; i < num; i++)
    {
        list.push_back(rand() % 100000);
    }
    int milsec = time.elapsed();
    qDebug() << "生成" << num << "个随机数共用时:" << milsec << "毫秒";

    // 发送信号
    emit sendArray(list);
}

BubbleSort::BubbleSort(QObject *parent) : QObject(parent) {}

void BubbleSort::working(QVector<int> list)
{
    qDebug() << "冒泡排序的线程的线程地址:" << QThread::currentThread();
    QElapsedTimer time; // 计算流程执行时间
    time.start();
    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = 0; j < list.size() - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                // 交换相邻元素
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    int milsec = time.elapsed();
    qDebug() << "冒泡排序用时" << milsec << "毫秒";
    // 发送信号
    emit finish(list);
}

QuickSort::QuickSort(QObject *parent) : QObject(parent) {}

void QuickSort::working(QVector<int> list)
{
    qDebug() << "快速排序的线程的线程地址:" << QThread::currentThread();
    QElapsedTimer time; // 计算流程执行时间
    time.start();
    std::sort(list.begin(), list.end());
    int milsec = time.elapsed();
    qDebug() << "快速排序用时" << milsec << "毫秒";
    // 发送信号
    emit finish(list);
}
