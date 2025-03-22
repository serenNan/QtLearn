#pragma once
#include <QThread>
#include <QVector>

// 生成随机数
class Generate : public QThread
{
    Q_OBJECT

  public:
    Generate(QObject *parent = nullptr);
    ~Generate();
    void recvNum(int num);

  protected:
    void run() override;
  signals:
    void sendArray(QVector<int>);
  private:
    int m_num;
};