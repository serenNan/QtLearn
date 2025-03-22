#pragma once
#include "ui_dialog.h"
#include <QDialog>

class dialog : public QDialog
{
    Q_OBJECT
    
public:
    dialog(QWidget* parent = nullptr);
    ~dialog();

private:
    Ui_dialog* ui;
};