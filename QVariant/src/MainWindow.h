#pragma once
#include "ui_MainWindow.h"
#include <QMainWindow>
#include <qvariant.h>

struct Person
{
    int id;
    QString name;
};
// 自定义类型注册
Q_DECLARE_METATYPE(Person)

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    // 两个变量进行加法运算，变量可能是整形，也可能是字符串
    QVariant dataPlus(QVariant a, QVariant b);

private:
    Ui_MainWindow* ui;
};