#pragma once
#include "ui_widget.h"
#include "ui_mainwindow.h"
#include <QMainWindow> // Qt 标准窗口类头文件

class mainwindow : public QMainWindow
{
    Q_OBJECT; // 这个宏是为了能够使用Qt中的信号槽机制

  public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

  private:
    Ui_mainwindow *ui; // 定义指针指向窗口的 UI 对象
};