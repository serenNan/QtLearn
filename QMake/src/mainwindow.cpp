#include "mainwindow.h"

mainwindow::mainwindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui; 
}