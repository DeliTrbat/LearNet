#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "appdialog.h"
#include "signupdialog.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    AppDialog *appDialog;
    SignUpDialog *signUpDialog;
    Client *client;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setClient(Client*);


private slots:
    void on_pushButton_Login_clicked();
    void on_pushButton_SignUp_clicked();
};
#endif // MAINWINDOW_H
