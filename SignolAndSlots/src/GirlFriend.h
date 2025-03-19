#pragma once

#include <QObject>
#include <QString>

class GirlFriend : public QObject {
    Q_OBJECT
    
public:
    GirlFriend(QObject* parent = nullptr);

signals:
  // 修改为带参数的信号
  void hungry(const QString &food);
public slots:
  void setHungry(const QString& food);
};
