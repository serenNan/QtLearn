#include "Login.h"

Login::Login(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui_Login)
{
    ui->setupUi(this);
    setFixedSize(306,338);
}

Login::~Login()
{
    delete ui; 
}