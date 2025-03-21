#pragma once
#include "ui_Login.h"
#include <QDialog>

class Login : public QDialog
{
    Q_OBJECT
    
public:
    Login(QWidget* parent = nullptr);
    ~Login();

private:
    Ui_Login* ui;
};