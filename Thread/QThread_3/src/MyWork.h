#pragma once
#include <QObject>
#include <QVector>

class MyWork : public QObject
{
    Q_OBJECT
  public:
    explicit MyWork(QObject *parent = nullptr);

    // 工作函数
    void working();

  signals:
    // 自定义信号, 传递数据
    void curNumber(int num);

};
