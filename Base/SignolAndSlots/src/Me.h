#pragma once

#include <QMainWindow>
#include <qobject.h>

class Me : public QObject
{
    Q_OBJECT

  public:
    Me(QObject *parent = nullptr);
    // 槽函数

  public slots:
    // 槽函数
    void eat(const QString& food);
};