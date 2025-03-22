#include "MainWindow.h"
#include "QColorDialog"
#include "QDebug"
#include "QFileDialog"
#include "QFontDialog"
#include "QInputDialog"
#include "QMessageBox"
#include "QPainter"
#include "myDialog.h"
#include "QProgressDialog"
#include "QTimer"

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
    QString fileName =
        QFileDialog::getSaveFileName(this, "保存文件", "home/serenNan/Projects/my-blog/content");
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

// 整形输入框
#if 0
void MainWindow::on_inputdlg_clicked()
{
    int ret = QInputDialog::getInt(this, "年龄", "您的当前年龄: ", 10, 1, 100, 2);
    QMessageBox::information(this, "年龄", "您的当前年龄: " + QString::number(ret));
}
#endif

// 浮点型输入框
#if 0
void MainWindow::on_inputdlg_clicked()
{
    double ret = QInputDialog::getDouble(this, "工资", "您的工资: ", 2000, 1000, 6000, 2);
    QMessageBox::information(this, "工资", "您的当前工资: " + QString::number(ret));
}
#endif

// 带下拉菜单的输入框
#if 0
void MainWindow::on_inputdlg_clicked()
{
    QStringList items;
    items << "苹果" << "橙子" << "橘子" << "葡萄" << "香蕉" << "哈密瓜";
    QString item =
        QInputDialog::getItem(this, "请选择你喜欢的水果", "你最喜欢的水果:", items, 1, false);
    QMessageBox::information(this, "水果", "您最喜欢的水果是: " + item);
}
#endif

// 多行字符串输入框
#if 1
void MainWindow::on_inputdlg_clicked()
{
    QString info =
        QInputDialog::getMultiLineText(this, "表白", "您最想对漂亮小姐姐说什么呢?", "呦吼吼...");
    QMessageBox::information(this, "知心姐姐", "您最想对小姐姐说: " + info);
}
#endif

// 单行字符串输入框
#if 0
void MainWindow::on_inputdlg_clicked()
{
    QString text =
        QInputDialog::getText(this, "密码", "请输入新的密码", QLineEdit::Password, "helloworld");
    QMessageBox::information(this, "密码", "您设置的密码是: " + text);
}

#endif

void MainWindow::on_progressdlg_clicked()
{
    // 1. 创建进度条对话框窗口对象
    QProgressDialog *progress = new QProgressDialog("正在拷贝数据...", "取消拷贝", 0, 100, this);
    // 2. 初始化并显示进度条窗口
    progress->setWindowTitle("请稍后");
    // 设置成模态
    progress->setWindowModality(Qt::WindowModal);
    progress->show();

    // 3. 更新进度条
    static int value = 0;
    QTimer *timer = new QTimer;
    connect(timer, &QTimer::timeout, this, [=]() {
        progress->setValue(value);
        value++;
        // 当value > 最大值的时候
        if (value > progress->maximum())
        {
            timer->stop();
            value = 0;
            delete progress;
            delete timer;
        }
    });

    connect(progress, &QProgressDialog::canceled, this, [=]() {
        timer->stop();
        value = 0;
        delete progress;
        delete timer;
    });

    timer->start(50);
}
