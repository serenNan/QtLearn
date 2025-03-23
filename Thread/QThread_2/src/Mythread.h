#pragma once
#include <QObject>
#include <QVector>

// 子线程 生成随机数
class Generate : public QObject
{
    Q_OBJECT

  public:
    Generate(QObject *parent = nullptr);

    void working(int num);
  signals:
    // 发送数据给主线程
    void sendArray(QVector<int>);
};

// 子线程 冒泡排序
class BubbleSort : public QObject
{
    Q_OBJECT

  public:
    BubbleSort(QObject *parent = nullptr);

    void working(QVector<int> num);
  signals:
    // 发送数据给主线程
    void finish(QVector<int> num);
};

// 子线程 快速排序
class QuickSort : public QObject
{
    Q_OBJECT

  public:
    QuickSort(QObject *parent = nullptr);

    void working(QVector<int> num);
  signals:
    // 发送数据给主线程
    void finish(QVector<int> num);
};