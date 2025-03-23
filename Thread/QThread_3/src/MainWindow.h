#pragma once
#include "ui_MainWindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  signals:
    // 告诉子线程要生成多少个随机数
    void starting(int num);

private:
    Ui_MainWindow* ui;
};