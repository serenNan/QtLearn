#pragma once
#include "ui_myDialog.h"
#include <QDialog>

class myDialog : public QDialog
{
    Q_OBJECT

  public:
    myDialog(QDialog *parent = nullptr);
    ~myDialog();

  public slots:
    void on_acceptBtn_clicked();
    void on_rejectBtn_clicked();
    void on_doneBtn_clicked();

  private:
    Ui_myDialog *ui;
};