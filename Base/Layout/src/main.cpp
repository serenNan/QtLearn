#include "MainWindow.h"
#include "Login.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Login login;
    login.exec();
    
    w.show();
    return a.exec();
}