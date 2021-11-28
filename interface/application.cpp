#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent) : QWidget(parent), ui(new Ui::Application)
{
    ui->setupUi(this);
    // Placeholder text
    ui->lineEdit_searchBar->setPlaceholderText("Search for a new friend");

    // Clear Button Enable
    ui->lineEdit_searchBar->setClearButtonEnabled(true);

    // Set Maximum size
    ui->lineEdit_searchBar->setMaxLength(32);
}

Application::~Application()
{
    delete ui;
}
void Application::setClient(Client *client)
{
    this->client = client;
}
void Application::showPage(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}
void Application::on_pushButton_logout_clicked()
{
   emit logoutClicked();
   this->client->sendBufferSize(6);
   this->client->sendBufferChar("logout");
}

void Application::on_pushButton_friends_clicked()
{
    showPage(1);
}

void Application::on_pushButton_mainMenu_clicked()
{
    showPage(0);
}

void Application::on_pushButton_addFriend_clicked()
{
    QString username = ui->lineEdit_searchBar->text();
    QByteArray usr = username.toLocal8Bit();

    this->client->sendBufferSize(12);
    this->client->sendBufferChar("searchFriend");

    this->client->sendBufferSize(username.length());
    this->client->sendBufferChar(usr.data());

    int size = this->client->receiveBufferSize();

    if(size == 1)
    {
        QMessageBox::information(this,"searchFriend","Friend added");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
        QMessageBox::warning(this,"searchFriend","User not found");
}
