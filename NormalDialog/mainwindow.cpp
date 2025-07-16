#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qcolordialog.h>
#include<QDebug>
#include<qfiledialog.h>
#include<QInputDialog>
#include<qmessagebox.h>
#include<QWizard>
#include<QVBoxLayout>//垂直布局
#include<QLabel>
#include<QButtonGroup>
#include<QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,_count(0)
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
    _progressdlg=new QProgressDialog(tr("正在复制当中..."),tr("取消复制"),0,5000,this);
    _progressdlg->setWindowTitle(tr("复制进度狂"));
    _progressdlg->setWindowModality(Qt::ApplicationModal);
    _timer=new QTimer(this);
    connect(_timer,&QTimer::timeout,this,&MainWindow::update);
    connect(_progressdlg,&QProgressDialog::canceled,this,&MainWindow::cancle);
    _timer->start(2);
}

void MainWindow::cancle(){
    _timer->stop();
    delete _timer;
    _timer=nullptr;
    delete _progressdlg;
    _progressdlg=nullptr;
    _count=0;
    return;
}

void MainWindow::update(){
    _count++;
    if(_count>5000){
        MainWindow::cancle();
    }
    _progressdlg->setValue(_count);
}


void MainWindow::on_wizardDialogBtn_clicked()
{
    QWizard xdk(this);
    xdk.setWindowTitle(tr("向导对话框"));


    auto page1=new QWizardPage();
    page1->setTitle(tr("start!!!"));
    auto label1=new QLabel();
    label1->setText(tr("this is lable1"));
    auto layout=new QVBoxLayout();
    layout->addWidget(label1);
    page1->setLayout(layout);
    xdk.addPage(page1);


    auto page2=new QWizardPage();
    page2->setTitle(tr("this is page2!!!"));
    auto buttongroup=new QButtonGroup(page2);
    auto b1=new QRadioButton();
    b1->setText(tr("one"));
    buttongroup->addButton(b1);

    auto b2=new QRadioButton();
    b2->setText(tr("two"));
    buttongroup->addButton(b2);

    auto b3=new QRadioButton();
    b3->setText(tr("three"));
    buttongroup->addButton(b3);

    auto b4=new QRadioButton();
    b4->setText(tr("all"));
    buttongroup->addButton(b4);

    auto layout2=new QVBoxLayout();
    for(int i=0;i<buttongroup->buttons().size();i++){
        layout2->addWidget(buttongroup->buttons()[i]);
    }
    page2->setLayout(layout2);
    xdk.addPage(page2);

    QWizardPage* page3 = new QWizardPage();
    page3->setTitle(tr("你的缘分即将到来"));
    auto label3 = new QLabel();
    label3->setText(tr("感谢您的参与，接下来的一个月会遇到对的人"));
    QVBoxLayout *layout3 = new QVBoxLayout();
    layout3->addWidget(label3);
    page3->setLayout(layout3);
    xdk.addPage(page3);

    xdk.show();
    xdk.exec();

}

