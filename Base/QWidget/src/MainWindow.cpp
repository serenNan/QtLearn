#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::windowTitleChanged, this,
            [=](const QString &title) { qDebug() << "新的标题:" << title; });

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &MainWindow::customContextMenuRequested, this, [=](const QPoint &pos) {
        QMenu menu;
        menu.addAction("西红柿");
        menu.addAction("西红柿");
        menu.addAction("西红柿");
        menu.exec(QCursor::pos());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 获取当前窗口的位置信息
void MainWindow::on_position_clicked()
{
    QRect rect = this->frameGeometry();
    qDebug() << "左上角: " << rect.topLeft() << "右上角: " << rect.topRight()
             << "左下角: " << rect.bottomLeft() << "右下角: " << rect.bottomRight()
             << "宽度: " << rect.width() << "高度: " << rect.height();
}

// 重新设置当前窗口的位置以及宽度, 高度
void MainWindow::on_geometry_clicked()
{
    int x = 100 + rand() % 500;
    int y = 100 + rand() % 500;
    int width = this->width() + 10;
    int height = this->height() + 10;
    setGeometry(x, y, width, height);
}

// 通过 move() 方法移动窗口
void MainWindow::on_move_clicked()
{
    QRect rect = this->frameGeometry();
    move(rect.topLeft() + QPoint(10, 20));
}

void MainWindow::on_title_clicked()
{
    setWindowTitle("new title");
}
