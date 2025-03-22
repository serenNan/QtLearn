#pragma once
#include "GirlFriend.h"
#include "Me.h"
#include "ui_MainWindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void hungrySlot();

private:
  Ui_MainWindow *ui;

  Me *m_me;
  GirlFriend *m_girlfriend;
};
