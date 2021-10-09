#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileInfoList"
#include "QDir"
#include "qdebug.h"
#include "list"
#include "QFileDialog"
#include "QMessageBox"
QFileInfoList GetFileList(QString path)
{
    QDir dir(path);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i != folder_list.size(); i++)
    {
         QString name = folder_list.at(i).absoluteFilePath();
         QFileInfoList child_file_list = GetFileList(name);
         file_list.append(child_file_list);
    }
    return file_list;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->fileDirText->setReadOnly(true);
    m_ptrTypeData = make_unique<CTypeData>();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString srcDirPath = QFileDialog::getExistingDirectory(this, tr("选择文件夹"),"/");
    QFileInfoList infoList = GetFileList(srcDirPath);
    for (auto i : infoList) {
        if (i.isFile() && (i.fileName().toStdString().find(".cpp") != std::string::npos || i.fileName().toStdString().find(".h") != std::string::npos)) {
            m_fileInfoList.push_back(i);
        }
    }
    m_ptrTypeData->Init();

    ui->fileDirText->setText(QString("当前目录：") + srcDirPath);
    qDebug() << srcDirPath;
}

void MainWindow::on_pushButton_2_clicked()
{
    if (m_fileInfoList.empty()) {
        QMessageBox::critical(nullptr, "错误", "目录下没有cpp或者.h文件");
    }
    auto i = m_fileInfoList.begin();
    qDebug() << (i->filePath());
    QFile file(i->filePath());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        ui->plainTextEdit->appendPlainText(line);
    }


    file.close();
}
