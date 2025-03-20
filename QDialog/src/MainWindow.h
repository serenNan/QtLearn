#pragma once
#include "ui_MainWindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    void on_modifyBtn_clicked();
    void on_msgbox_clicked();
    void on_filedlg_clicked();
    void on_fontdlg_clicked();
    void on_colordlg_clicked();
    void on_inputdlg_clicked();
    void on_progressdlg_clicked();

        private : Ui_MainWindow *ui;
};