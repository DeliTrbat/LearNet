#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) : QDialog(parent), ui(new Ui::Chat)
{
    ui->setupUi(this);
    ui->lineEdit_chat->setMaxLength(1000);
    ui->lineEdit_chat->setClearButtonEnabled(true);

    //ui->listWidgetChat->setWordWrap(true);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateChat()));
    timer->start(2500);
    this->setAttribute(Qt::WA_DeleteOnClose);
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

void Chat::setTheme(char *theme)
{
    this->theme = theme;
}
void Chat::receiveMessages()
{
    ui->listWidgetChat->clear();
    char message[1052];
    while(this->client->receiveBufferChar(message) != -1)
    {
        int id = this->client->receiveBufferSize();
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(QString::fromUtf8(const_cast<char *> (message)));
        //item->setText(fontMetrics().elidedText(message, Qt::ElideMiddle, width(), Qt::TextShowMnemonic));
        this->setListItem(item,id);
    }
}
void Chat::setListItem( QListWidgetItem * item, int align)
{
    ui->listWidgetChat->addItem( item );
    if(align != this->userId)
    {    item->setTextAlignment(Qt::AlignLeft);
         item->setBackground(Qt::gray);
    }
    else
    {
        item->setTextAlignment(Qt::AlignRight);
        item->setBackground(Qt::blue);
    }
}
void Chat::updateChat()
{
    if(this->friendId != -1)
    {
        this->client->sendBufferSize(10);
        this->client->sendBufferChar((char*)"updateChat");

        this->client->sendBufferSize(this->friendId);
        receiveMessages();
        qDebug() << "Chat updated.";
    }
    else
    {
        this->client->sendBufferSize(7);
        this->client->sendBufferChar((char*)"allChat");

        this->client->sendBufferSize(strlen(this->theme));
        this->client->sendBufferChar(this->theme);
        receiveMessages();
        qDebug() << "AllChat updated.";
    }
}
void Chat::on_pushButton_send_clicked()
{
    QString message = ui->lineEdit_chat->text();
    if( message.length() > 0 )
    {
        QByteArray msg = message.toLocal8Bit();
        if(this->friendId != -1)
        {
            this->client->sendBufferSize(13);
            this->client->sendBufferChar((char*)"messageFriend");

            this->client->sendBufferSize(this->friendId);
        }
        else
        {
            this->client->sendBufferSize(14);
            this->client->sendBufferChar((char*)"messageAllChat");

            this->client->sendBufferSize(strlen(this->theme));
            this->client->sendBufferChar(this->theme);
        }

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
