#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) : QDialog(parent), ui(new Ui::Chat)
{
    ui->setupUi(this);
    ui->lineEdit_chat->setMaxLength(1000);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::setClient(Client *client)
{
    this->client = client;
}

void Chat::on_pushButton_send_clicked()
{

}
void Chat::setScrollContents(QWidget * scrollContents)
{
    ui->scrollArea->setWidget(scrollContents);
}
