#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // 应用程序类，在一个qt应用程序中，该对象有且只有一个
    QApplication a(argc, argv);
    // 窗口对象
    MainWindow w;
    // 显示窗口
    w.show();
    // 阻塞函数，程序进入了事件循环
    return a.exec();
}
