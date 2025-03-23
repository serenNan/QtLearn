#pragma once
#include <QThread>
#include <QVector>

// 子线程 生成随机数
class Generate : public QThread
{
    Q_OBJECT

  public:
    Generate(QObject *parent = nullptr);
    ~Generate();

    // 接受主线程传递过来的数字
    void recvNum(int num);

  protected:
    void run() override;
  signals:
    // 发送数据给主线程
    void sendArray(QVector<int>);
  private:
    int m_num;
};

// 子线程 冒泡排序
class BubbleSort : public QThread
{
    Q_OBJECT

  public:
    BubbleSort(QObject *parent = nullptr);
    ~BubbleSort();

    // 接受主线程传递过来的数字
    void recvArray(QVector<int> list);

  protected:
    void run() override;
  signals:
    // 发送数据给主线程
    void finish(QVector<int> num);

  private:
    QVector<int> m_list;
};

// 子线程 快速排序
class QuickSort : public QThread
{
    Q_OBJECT

  public:
    QuickSort(QObject *parent = nullptr);
    ~QuickSort();

    // 接受主线程传递过来的数字
    void recvArray(QVector<int> list);

  protected:
    void run() override;
  signals:
    // 发送数据给主线程
    void finish(QVector<int> num);

  private:
    QVector<int> m_list;
};