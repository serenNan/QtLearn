#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    QVector<int> list;
    for (int i = 0; i < 100000; i++)
    {
        list.push_back(rand() % 100000);
    }

    for (int i = 0; i < list.size(); i++)
    {
        ui->randList->addItem(QString::number(list.at(i)));
    }
}