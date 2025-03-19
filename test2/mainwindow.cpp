#include "mainwindow.h"
#include "newwidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NewWidget *w = new NewWidget(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
