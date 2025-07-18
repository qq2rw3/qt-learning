#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRegularExpressionValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString ip_mask="000.000.000.000;_";
    ui->ip_dizhi->setInputMask(ip_mask);
    QString mac_mask="HH:HH:HH:HH:HH:HH;_";
    ui->mac_dizhi->setInputMask(mac_mask);
    ui->psd->setEchoMode(QLineEdit::Password);
    QRegularExpression regx("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$");
    auto valid=new QRegularExpressionValidator(regx,ui->youxiang);
    ui->youxiang->setValidator(valid);
}

MainWindow::~MainWindow()
{
    delete ui;
}
