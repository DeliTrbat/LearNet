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
void Chat::setUserId(int id)
{
    this->userId = id;
}
void Chat::on_pushButton_send_clicked()
{

}
void Chat::setListItem( QListWidgetItem * item, int align)
{
    ui->listWidgetChat->addItem( item );

    if(align == this->userId)
    {    item->setTextAlignment(Qt::AlignLeft);
         item->setBackground(Qt::gray);
    }
    else
    {
        item->setTextAlignment(Qt::AlignRight);
        item->setBackground(Qt::blue);
    }
}
