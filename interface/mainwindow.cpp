#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resetButton = QMessageBox::question( this, "LearNet",tr("Are you sure?\n"), QMessageBox::No | QMessageBox::Yes ,QMessageBox::Yes);

    if (resetButton != QMessageBox::Yes) {
        event->ignore();
    } else {
        this->client->sendBufferSize(4);
        this->client->sendBufferChar("quit");
        event->accept();
    }
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
    QString inviteCode = ui->lineEdit_inviteCode->text();
    QByteArray invCode = inviteCode.toLocal8Bit();

    this->client->sendBufferSize(6);
    this->client->sendBufferChar("signUp");

    this->client->sendBufferSize(inviteCode.length());
    this->client->sendBufferChar(invCode.data());

    int correctInvCode = this->client->receiveBufferSize();
    if(correctInvCode == 1)
    {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QByteArray usr = username.toLocal8Bit();
    QByteArray pwd = password.toLocal8Bit();

    this->client->sendBufferSize(username.length());
    this->client->sendBufferChar(usr.data());

    this->client->sendBufferSize(password.length());
    this->client->sendBufferChar(pwd.data());

    QMessageBox::information(this,"SignUp","You have been succesfully registered");
    hide();
    this->appDialog = new AppDialog(this);
    appDialog->show();
    }
    else
        QMessageBox::warning(this,"SignUp","Incorrec invite code!");
}
