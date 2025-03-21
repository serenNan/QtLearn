#pragma once
#include "ui_MainWindow.h"
#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui_MainWindow* ui;
};