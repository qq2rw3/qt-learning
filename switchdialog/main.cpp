#include "maindialog.h"

#include <QApplication>
#include"childdialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    //这是模态化窗口的第一种方式
    ChildDialog child;
    if(child.exec()==QDialog::Accepted){
        w.show();
        a.exec();
    }else {
        return 0;
    }
    //这是第二种方式
    // ChildDialog child=new ChildDialog();
    // child.setModal(true);
    //return a.exec();
}
