#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LearNet");
    ui->statusbar->hide();

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
        this->client->sendBufferChar((char*)"quit");
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
    //delete appMenu;
}
void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QByteArray usr = username.toLocal8Bit();
    QByteArray pwd = password.toLocal8Bit();

    this->client->sendBufferSize(5);
    this->client->sendBufferChar((char*)"login");

    this->client->sendBufferSize(username.length());
    this->client->sendBufferChar(usr.data());

    this->client->sendBufferSize(password.length());
    this->client->sendBufferChar(pwd.data());

    int size = this->client->receiveBufferSize();

    if(size >= 0)
    {
        QMessageBox::information(this,"Welcome!","Username and password are correct");

        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        ui->lineEdit_inviteCode->clear();

        appMenu.setUsername(usr.data());
        appMenu.setUserId(size);
        appMenu.initializeCompleter();

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
    this->client->sendBufferChar((char*)"signUp");

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
        QMessageBox::information(this,"Welcome!","You have been succesfully registered");

        appMenu.setUsername(usr.data());
        appMenu.setUserId(correctCredentials);
        appMenu.initializeCompleter();

        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        switch (correctCredentials)
        {
        case -1:
        QMessageBox::warning(this,"Fatal error","Some error ocurred try to reconnect to the server!");
            break;
        case -2:
        QMessageBox::warning(this,"Incorrect credentials","You introduced incorrect credentials!\nPlease make sure the username and password follow the rules:\n The username has to start with a letter and contain only letters and digits. \nThe password has to have minimum 10 characters, one number, one special character, uppercase and lowercase letters!\n Spaces are not permitted!");
            break;
        case -3: QMessageBox::warning(this,"Username already in user","The username is already in use!");
            break;
        default:
            break;
        }
    }
    }
    else
        QMessageBox::warning(this,"Incorrect invite code","Incorrect invite code!");
}
