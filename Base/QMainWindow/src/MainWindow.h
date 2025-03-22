#pragma once
#include "QLineEdit"
#include "ui_MainWindow.h"
#include <QMainWindow>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui_MainWindow* ui;
};