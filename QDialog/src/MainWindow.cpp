#include "MainWindow.h"
#include "myDialog.h"
#include "QDebug"

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

void MainWindow::on_modifyBtn_clicked()
{
    myDialog dlg;
    connect(&dlg, &myDialog::finished, this, [=](int res) { qDebug() << "result:" << res; });
    connect(&dlg, &myDialog::accepted, this, [=]() { qDebug() << "accepted 信号"; });
    connect(&dlg, &myDialog::rejected, this, [=]() { qDebug() << "rejected 信号"; });
    // 模态显示
    int ret = dlg.exec();
    if (ret == QDialog::Accepted)
    {
        qDebug() << "accept button";
    }
    else if (ret == QDialog::Rejected)
    {
        qDebug() << "reject button";
    }
    else
    {
        qDebug() << "done button";
    }
}