#include "dialog.h"

dialog::dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui_dialog)
{
    ui->setupUi(this);
}

dialog::~dialog()
{
    delete ui; 
}