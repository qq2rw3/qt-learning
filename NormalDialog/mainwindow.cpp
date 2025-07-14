#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qcolordialog.h>
#include<QDebug>
#include<qfiledialog.h>
#include<QInputDialog>
#include<qmessagebox.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_colorDialogBtn_clicked()
{
    QColorDialog colordlg(Qt::red,this);
    colordlg.setOption(QColorDialog::ShowAlphaChannel);
    colordlg.exec();//设置成模态对话框
    auto color=colordlg.currentColor();
    qDebug()<<"color is"<<color<<Qt::endl;
}


void MainWindow::on_fileDialogBtn_clicked()
{
    QString path=QDir::currentPath();
    QString title=tr("文件选择");
    QString filter=tr("文本文件(*.txt);;图片文件(*.png,*.jpg);;所有文件(*.*)");
    QString filename=QFileDialog::getOpenFileName(this,title,path,filter);
    qDebug()<<"filename is "<<filename<<Qt::endl;
}


void MainWindow::on_intInputDialogBtn_clicked()
{
    bool ok=false;
    auto number=QInputDialog::getInt(this,tr("整数对话框"),tr("请输入数字"),10,-100,100,5,&ok);
    if(ok){
        qDebug()<<number<<Qt::endl;
    }
}


void MainWindow::on_doubleInputDialogBtn_clicked()
{
    bool ok=false;
    auto number=QInputDialog::getDouble(this,tr("浮点数对话框"),tr("请输入浮点数"),1.0,-10,10,1,&ok);
    if(ok){
        qDebug()<<number<<Qt::endl;
    }
}


void MainWindow::on_inputDialogBtn_clicked()
{
    QStringList iteams;
    iteams<<tr("条目1")<<tr("条目2");
    bool ok=false;
    auto iteam=QInputDialog::getItem(this,tr("条目对话框"),tr("选择条目"),iteams,0,true,&ok);
    if(ok){
        qDebug()<<iteam<<Qt::endl;
    }
}


void MainWindow::on_messageDialogBtn_clicked()
{
    //提问对话框
    auto ans=QMessageBox::question(this,tr("消息对话框"),tr("你是单身吗"),QMessageBox::Yes,QMessageBox::No);
    if(ans==QMessageBox::Yes){
        qDebug()<<"你好！单身狗"<<Qt::endl;
    }else {
        qDebug()<<"好吧，算我没问"<<Qt::endl;
        return;
    }
    //通知对话框
    auto ans2=QMessageBox::information(this,tr("通知对话框"),tr("你好！单身狗"),QMessageBox::Yes);
    if(ans2==QMessageBox::Yes){
        qDebug()<<"two "<<ans2<<Qt::endl;
    }else {
        return ;
    }
    //警告对话框
    auto ans3=QMessageBox::warning(this,tr("警告对话框"),tr("笑死我了"),QMessageBox::Ok);
    if(ans3==QMessageBox::Ok){
        qDebug()<<"three "<<ans3<<Qt::endl;
    }else {
        return ;
    }
    //关键词对话框
    auto ans4=QMessageBox::critical(this,tr("关键提示对话框"),tr("哦吼吼~~"),QMessageBox::Ok);
    if(ans4==QMessageBox::Ok){
        qDebug()<<"four "<<ans4<<Qt::endl;
        return;
    }
}


void MainWindow::on_progressDialogBtn_clicked()
{

}

