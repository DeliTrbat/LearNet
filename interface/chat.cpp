#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) : QDialog(parent), ui(new Ui::Chat)
{
    ui->setupUi(this);
    ui->lineEdit_chat->setMaxLength(1000);
    ui->lineEdit_chat->setClearButtonEnabled(true);
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
void Chat::setFriendId(int id)
{
    this->friendId = id;
}
void Chat::receiveMessages()
{
    ui->listWidgetChat->clear();
    char message[1000];
    while(this->client->receiveBufferChar(message) != -1)
    {
        int id = this->client->receiveBufferSize();
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(QString::fromUtf8(const_cast<char *> (message)));
        this->setListItem(item,id);
    }
}
void Chat::on_pushButton_send_clicked()
{
    QString message = ui->lineEdit_chat->text();
    if( message.length() > 0 )
    {
        QByteArray msg = message.toLocal8Bit();

        this->client->sendBufferSize(13);
        this->client->sendBufferChar((char*)"messageFriend");

        this->client->sendBufferSize(this->friendId);

        this->client->sendBufferSize(message.length());
        this->client->sendBufferChar(msg.data());

        int done = this->client->receiveBufferSize();
        if(done != -1)
        {
            receiveMessages();
        }
        if(done == 0)
            QMessageBox::warning(this,"Operation failed","The message couldn't be sent!");
        ui->lineEdit_chat->clear();
    }
    else
        QMessageBox::warning(this,"Operation failed","Write at least one char!");
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
