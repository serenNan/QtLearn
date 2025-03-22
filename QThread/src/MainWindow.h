#pragma once
#include "ui_MainWindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  signals:
    void starting(int num);

private:
    Ui_MainWindow* ui;
};