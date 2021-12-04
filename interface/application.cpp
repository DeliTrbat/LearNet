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
void Application::setUserId(int id)
{
    this->userId = id;
}
void Application::setUsername(char* username)
{
    strcpy(this->username,username);
}
void Application::showPage(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}
void Application::on_pushButton_logout_clicked()
{
   emit logoutClicked();
   ui->lineEdit_searchBar->clear();
   delete layoutFriends;
   layoutFriends = nullptr;

   this->client->sendBufferSize(6);
   this->client->sendBufferChar((char*)"logout");
}

void Application::on_pushButton_friends_clicked()
{
    showPage(1);
    if( layoutFriends == nullptr)
    {
        layoutFriends = new QFormLayout(this);

        this->client->sendBufferSize(7);
        this->client->sendBufferChar((char*)"Friends");

        int count = this->client->receiveBufferSize();
        char str[32];
        for(int i = 0 ;i < count;i++)
        {
            this->client->receiveBufferChar(str);
            QPushButton * button = new QPushButton("Message");
            this->layoutFriends->addRow(new QLabel(str),button);
            connect(button,&QPushButton::clicked,this,[=]{ openChat(str);});
        }
        QWidget *scrollContents = new QWidget(this);
        scrollContents->setLayout(this->layoutFriends);
        ui->scrollArea->setWidget(scrollContents);
    }
}
void Application::openChat(const char* str)
{
    Chat * chat = new Chat(this);
    chat->setClient(client);
    chat->setUserId(this->userId);

    //QFormLayout* layoutChat = new QFormLayout(this);

    this->client->sendBufferSize(10);
    this->client->sendBufferChar((char*)"chatFriend");

    this->client->sendBufferSize(strlen(str));
    this->client->sendBufferChar((char*)str);
    chat->setFriendId(this->client->receiveBufferSize());

    chat->receiveMessages();
    /*char message[1000];
    while(this->client->receiveBufferChar(message) != -1)
    {
        int id = this->client->receiveBufferSize();
        //QLabel *mess = new QLabel(message);
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(QString::fromUtf8(const_cast<char *> (message)));
        chat->setListItem(item,id);
        //layoutChat->addRow(mess);
    }*/

    //QWidget *scrollContents = new QWidget(this);
    //scrollContents->setLayout(layoutChat);
    //chat->setScrollContents(scrollContents);
    chat->setWindowTitle(str);
    chat->exec();
}
void Application::on_pushButton_mainMenu_clicked()
{
    showPage(0);
    ui->lineEdit_searchBar->clear();
}

void Application::on_pushButton_addFriend_clicked()
{
    QString username = ui->lineEdit_searchBar->text();
    QByteArray usr = username.toLocal8Bit();

    this->client->sendBufferSize(12);
    this->client->sendBufferChar((char*)"searchFriend");

    this->client->sendBufferSize(username.length());
    this->client->sendBufferChar(usr.data());

    int size = this->client->receiveBufferSize();

    switch(size)
    {
    case -1: QMessageBox::warning(this,"searchFriend","User not found!");
        break;
    case 0: QMessageBox::warning(this,"searchFriend","User already in friend list!");
        break;
    case 1: QMessageBox::information(this,"searchFriend","Friend added");
        break;
    case 2: QMessageBox::warning(this,"searchFriend","Why are you so lonely?");
        break;
    default: break;
    }
    if(size == 1)
    {
        QPushButton * button = new QPushButton("Message");
        this->layoutFriends->addRow(new QLabel(usr.data()),button);
        connect(button,&QPushButton::clicked,this,[=]{ openChat(usr.data());});

        QWidget *scrollContents = new QWidget(this);
        scrollContents->setLayout(this->layoutFriends);
        ui->scrollArea->setWidget(scrollContents);
    }
}
