#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LearNet");

    // Placeholder text
    ui->lineEdit_username->setPlaceholderText("Username");
    ui->lineEdit_password->setPlaceholderText("Password");
    ui->lineEdit_inviteCode->setPlaceholderText("Invitation code");

    // Clear Button Enable
    ui->lineEdit_username->setClearButtonEnabled(true);
    ui->lineEdit_password->setClearButtonEnabled(true);
    ui->lineEdit_inviteCode->setClearButtonEnabled(true);

    // Set Maximum size
    ui->lineEdit_username->setMaxLength(32);
    ui->lineEdit_password->setMaxLength(64);
    ui->lineEdit_inviteCode->setMaxLength(32);

    ui->stackedWidget->insertWidget(1,&appMenu);

    connect(&appMenu,SIGNAL(logoutClicked()),this,SLOT(logout()));
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
    this->appMenu.setClient(client);
}
void MainWindow::logout()
{
    ui->stackedWidget->setCurrentIndex(0);
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

    if(size >= 0)
    {
        QMessageBox::information(this,"Login","Username and password are correct");

        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        ui->lineEdit_inviteCode->clear();

        ui->stackedWidget->setCurrentIndex(1);
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

    int correctCredentials = this->client->receiveBufferSize();
    if(correctCredentials >= 0)
    {
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        ui->lineEdit_inviteCode->clear();
        QMessageBox::information(this,"SignUp","You have been succesfully registered");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        QMessageBox::warning(this,"SignUp","You introduced incorrect credentials");
    }
    }
    else
        QMessageBox::warning(this,"SignUp","Incorrect invite code!");
}
