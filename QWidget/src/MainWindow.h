#pragma once
#include "ui_MainWindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void on_position_clicked();
    void on_move_clicked();
    void on_geometry_clicked();
    void on_title_clicked();

  private:
    Ui_MainWindow *ui;
};