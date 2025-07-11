#include "maindialog.h"
#include "ui_maindialog.h"
#include"childdialog.h"
MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_openChildBtn_clicked()
{
    close();
    ChildDialog child;
    if(child.exec()==QDialog::Accepted){
        this->show();
    }else{
        return ;
    }
}

