#include "myDialog.h"

myDialog::myDialog(QDialog *parent) : QDialog(parent), ui(new Ui_myDialog)
{
    ui->setupUi(this);
}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_acceptBtn_clicked()
{
    this->accept();
}

void myDialog::on_rejectBtn_clicked()
{
    this->reject();
}

void myDialog::on_doneBtn_clicked()
{
    this->done(10);
}
