#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setClient(Client *client)
{
    this->client = client;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QByteArray usr = username.toLocal8Bit();
    QByteArray pwd = password.toLocal8Bit();

    this->client->sendBufferSize(5);
    this->client->sendBufferChar("login");

    this->client->sendBufferSize(username.length());
    this->client->sendBufferChar(usr.data());

    this->client->sendBufferSize(password.length());
    this->client->sendBufferChar(pwd.data());

    int size = this->client->receiveBufferSize();
    //char msg[size];
    //this->client->receiveBufferChar(msg);

    if(size == 1)
    {
        QMessageBox::information(this,"Login","Username and password are correct");
        hide();
        this->appDialog = new AppDialog(this);
        appDialog->show();
    }
    else
        QMessageBox::warning(this,"Login","Username or password is not correct");

}

void MainWindow::on_pushButton_SignUp_clicked()
{
    hide();
    this->signUpDialog = new SignUpDialog(this);
    signUpDialog->show();
}
