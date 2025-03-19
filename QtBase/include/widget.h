#pragma once
#include "ui_widget.h"
#include <QWidget>

class widget : public QWidget // 继承 QWidget 而不是 QMainWindow
{ 
    Q_OBJECT

  public:
    widget(QWidget *parent = nullptr);
    ~widget();

  private:
    Ui_widget *ui;
};