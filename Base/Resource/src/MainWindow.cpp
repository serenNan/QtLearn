#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);
    QIcon icon(":/cpp");
    setWindowIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}