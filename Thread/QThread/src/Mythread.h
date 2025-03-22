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