#include "MainWindow.h"
#include <qcontainerinfo.h>
#include <qdebug.h>
#include <qglobal.h>
#include <qobjectdefs.h>
#include <qvariant.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_MainWindow)
{
    ui->setupUi(this);
    int value = dataPlus(10, 20).toInt();
    QString str = dataPlus("hello", "world").toString();
    qDebug() << "Int :" << value;
    qDebug() << "String :" << str;

    Person p;
    p.id = 10;
    p.name = "person";

#if 0
    QVariant v;
    v.setValue(p);
#else
    QVariant v = QVariant::fromValue(p);
#endif

    // 提取出 v 对象中的数据
    if (v.canConvert<Person>())
    {
        Person tmp = v.value<Person>();
        qDebug() << tmp.id << tmp.name;
    }
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVariant MainWindow::dataPlus(QVariant a, QVariant b)
{
    QVariant ans;
    if (a.typeId() == QMetaType::Int && b.typeId() == QMetaType::Int)
    {
        ans = QVariant(a.toInt() + b.toInt());
    }
    else if (a.typeId() == QMetaType::QString && b.typeId() == QMetaType::QString)
    {
        ans.setValue(a.toString() + b.toString());
    }
    return ans;
}