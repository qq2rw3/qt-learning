#ifndef CHILDDIALOG_H
#define CHILDDIALOG_H

#include <QDialog>

namespace Ui {
class ChildDialog;
}

class ChildDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChildDialog(QWidget *parent = nullptr);
    ~ChildDialog();

private slots:
    void showhanshu();

signals:
    void showsig();

private:
    Ui::ChildDialog *ui;
    QWidget *_parent;
};

#endif // CHILDDIALOG_H
