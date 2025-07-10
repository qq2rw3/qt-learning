#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qdialog.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //auto s=new QDialog(this);
    //s->setModal(true);
    //s->show();
    //槽函数的参数个数必须小于等于信号的个数
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::on_pushButton_clicked);
    _child_dialog=new ChildDialog(this);
    connect(_child_dialog,&ChildDialog::showsig,this,&MainWindow::showMainWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(_child_dialog){
        delete _child_dialog;
        _child_dialog=nullptr;
    }
}

void MainWindow::on_pushButton_clicked()
{
    // auto childDialog=new QDialog(this);
    // //设置成模态对话框
    // childDialog->setModal(true);
    // childDialog->show();
    _child_dialog->show();
    this->hide();
}

void MainWindow::showMainWindow()
{
    this->show();
    _child_dialog->hide();
}

