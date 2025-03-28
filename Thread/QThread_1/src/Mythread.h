#pragma once
#include <QThread>
#include <QVector>

class MyThread : public QThread
{
    Q_OBJECT
  public:
    explicit MyThread(QObject *parent = nullptr);

  protected:
    void run();

  signals:
    // 自定义信号, 传递数据
    void curNumber(int num);

};
