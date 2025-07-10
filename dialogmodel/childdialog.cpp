#include "childdialog.h"
#include "ui_childdialog.h"

ChildDialog::ChildDialog(QWidget *parent)
    : QDialog(parent),_parent(parent)
    , ui(new Ui::ChildDialog)
{
    ui->setupUi(this);
    connect(ui->cancelButton,&QPushButton::clicked,this,&ChildDialog::showhanshu);
}

ChildDialog::~ChildDialog()
{
    delete ui;
}

void ChildDialog::showhanshu()
{
    this->hide();
    //要考虑高内聚低耦合的关系
    //_parent->show();
    emit showsig();
}

