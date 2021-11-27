#include "signupdialog.h"
#include "ui_signupdialog.h"

SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog)
{
    ui->setupUi(this);
}

SignUpDialog::~SignUpDialog()
{
    delete ui;
}

void SignUpDialog::on_pushButton_SignUp_clicked()
{
    QString inviteCode = ui->lineEdit_inviteCode->text();
    QByteArray invCode = inviteCode.toLocal8Bit();

    MainWindow::this->client->sendBufferSize(5);
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
    MainWindow

    }
    else
        QMessageBox::warning(this,"SignUp","Incorrec invite code!");

}

void SignUpDialog::on_pushButton_Back_clicked()
{

}
