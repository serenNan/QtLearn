#include "MainWindow.h"
#include "QColorDialog"
#include "QDebug"
#include "QFileDialog"
#include "QFontDialog"
#include "QMessageBox"
#include "QPainter"
#include "myDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_MainWindow)
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

void MainWindow::on_msgbox_clicked()
{
    QMessageBox::about(this, "about", "这是一个简单的消息提示框!!!");
    QMessageBox::critical(this, "critical", "这是一个错误对话框-critical...");
    int ret = QMessageBox::question(this, "question", "你要保存修改的文件内容吗???",
                                    QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
    {
        QMessageBox::information(this, "information", "恭喜你保存成功了, o(*￣︶￣*)o!!!");
    }
    else if (ret == QMessageBox::Cancel)
    {
        QMessageBox::warning(this, "warning", "你放弃了保存, ┭┮﹏┭┮ !!!");
    }
}

// 打开一个本地目录
#if 0
void MainWindow::on_filedlg_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "打开目录", "/home/serenNan");
    QMessageBox::information(this, "打开目录", "您选择的目录是: " + dirName);
}
#endif

// 打开一个本地文件
#if 0
void MainWindow::on_filedlg_clicked()
{
    QString arg("Text files (*.txt)");
    QString fileName = QFileDialog::getOpenFileName(
        this, "Open File", "/home/serenNan", "Images (*.png *.jpg);;Text files (*.txt)", &arg);
    QMessageBox::information(this, "打开文件", "您选择的文件是: " + fileName);
}
#endif

// 打开多个本地文件
#if 0
void MainWindow::on_filedlg_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(
        this, "Open File", "/home/serenNan", "Images (*.png *.jpg);;Text files (*.txt)");
    QString names;
    for (int i = 0; i < fileNames.size(); ++i)
    {
        names += fileNames.at(i) + " ";
    }
    QMessageBox::information(this, "打开文件(s)", "您选择的文件是: " + names);
}
#endif

// 打开保存文件对话框
#if 1
void MainWindow::on_filedlg_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "home/serenNan/Projects/my-blog/content");
    QMessageBox::information(this, "保存文件", "您指定的保存数据的文件是: " + fileName);
}
#endif

void MainWindow::on_fontdlg_clicked()
{
#if 0
    // 方式1
    bool ok;
    QFont ft = QFontDialog::getFont(&ok, QFont("微软雅黑", 12, QFont::Bold), this, "选择字体");
    qDebug() << "ok value is: " << ok;
#else
    // 方式2
    QFont ft = QFontDialog::getFont(NULL);
#endif
    // 将选择的字体设置给当前窗口对象
    ui->fontlabel->setFont(ft);
}

void MainWindow::on_colordlg_clicked()
{
    QColor color = QColorDialog::getColor();
    QBrush brush(color);
    QRect rect(0, 0, ui->color->width(), ui->color->height());
    QPixmap pix(rect.width(), rect.height());
    QPainter p(&pix);
    p.fillRect(rect, brush);
    ui->color->setPixmap(pix);
    QString text = QString("red: %1, green: %2, blue: %3, 透明度: %4")
                       .arg(color.red())
                       .arg(color.green())
                       .arg(color.blue())
                       .arg(color.alpha());
    ui->colorlabel->setText(text);
}

#if 0



#endif