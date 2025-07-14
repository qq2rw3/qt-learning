#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_colorDialogBtn_clicked();

    void on_fileDialogBtn_clicked();

    void on_intInputDialogBtn_clicked();

    void on_doubleInputDialogBtn_clicked();

    void on_inputDialogBtn_clicked();

    void on_messageDialogBtn_clicked();

    void on_progressDialogBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
