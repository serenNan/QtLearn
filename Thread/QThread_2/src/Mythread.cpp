#include "Mythread.h"
#include <QDebug>
#include <QElapsedTimer>
#include <algorithm>

Generate::Generate(QObject *parent) : QThread(parent) {}

void Generate::recvNum(int num)
{
    m_num = num;
}

void Generate::run()
{
    qDebug() << "生成随机数的线程的线程地址:" << QThread::currentThread();
    QVector<int> list;
    QElapsedTimer time; // 计算流程执行时间
    time.start();
    for (int i = 0; i < m_num; i++)
    {
        list.push_back(rand() % 100000);
    }
    int milsec = time.elapsed();
    qDebug() << "生成" << m_num << "个随机数共用时:" << milsec << "毫秒";

    // 发送信号
    emit sendArray(list);
}

Generate::~Generate() {}

BubbleSort::BubbleSort(QObject *parent) : QThread(parent) {}

void BubbleSort::recvArray(QVector<int> list)
{
    m_list = list;
}

void BubbleSort::run()
{
    qDebug() << "冒泡排序的线程的线程地址:" << QThread::currentThread();
    QElapsedTimer time; // 计算流程执行时间
    time.start();
    for (int i = 0; i < m_list.size() - 1; i++)
    {
        for (int j = 0; j < m_list.size() - i - 1; j++)
        {
            if (m_list[j] > m_list[j + 1])
            {
                // 交换相邻元素
                int temp = m_list[j];
                m_list[j] = m_list[j + 1];
                m_list[j + 1] = temp;
            }
        }
    }
    int milsec = time.elapsed();
    qDebug() << "冒泡排序用时" << milsec << "毫秒";
    // 发送信号
    emit finish(m_list);
}

BubbleSort::~BubbleSort(){};

QuickSort::QuickSort(QObject *parent) : QThread(parent) {}

void QuickSort::recvArray(QVector<int> list)
{
    m_list = list;
}

void QuickSort::run()
{
    qDebug() << "快速排序的线程的线程地址:" << QThread::currentThread();
    QElapsedTimer time; // 计算流程执行时间
    time.start();
    std::sort(m_list.begin(), m_list.end());
    int milsec = time.elapsed();
    qDebug() << "快速排序用时" << milsec << "毫秒";
    // 发送信号
    emit finish(m_list);
}

QuickSort::~QuickSort(){};
