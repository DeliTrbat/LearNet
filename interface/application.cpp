#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent) : QWidget(parent), ui(new Ui::Application)
{
    ui->setupUi(this);
    // Placeholder text
    ui->lineEdit_searchBar->setPlaceholderText("Search for a new friend");

    // Clear Button Enable
    ui->lineEdit_searchBar->setClearButtonEnabled(true);
    ui->lineEdit_MainSearchbar->setClearButtonEnabled(true);

    // Set Maximum length
    ui->lineEdit_searchBar->setMaxLength(32);
    ui->lineEdit_MainSearchbar->setMaxLength(64);

    ui->textEdit_code->setReadOnly(true);
    ui->textEdit_data->setReadOnly(true);
    ui->textEdit_code->setAlignment(Qt::AlignCenter);
    ui->textEdit_code->hide();
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

void Application::initializeCompleter()
{
    this->client->sendBufferSize(13);
    this->client->sendBufferChar((char*)"completerData");

    QStringList dataList;
    char data[50];
    while(this->client->receiveBufferChar(data) != -1)
    {
        dataList << data;
    }
    this->stringCompleter = new QCompleter(dataList,this);
    this->stringCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_MainSearchbar->setCompleter(this->stringCompleter);
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

   ui->textEdit_code->clear();
   ui->textEdit_code->hide();

   this->client->sendBufferSize(6);
   this->client->sendBufferChar((char*)"logout");
}

void Application::on_pushButton_friends_clicked()
{
    showPage(1);
    if( layoutFriends == nullptr)
    {
        //layoutFriends = new QFormLayout(this);
        this->layoutFriends = new QGridLayout(this);
        this->layoutFriends->setAlignment(Qt::AlignTop);

        this->client->sendBufferSize(7);
        this->client->sendBufferChar((char*)"Friends");

        int count = this->client->receiveBufferSize();
        char str[32];
        for(int i = 0 ;i < count;i++)
        {
            this->client->receiveBufferChar(str);
            QPushButton *button1 = new QPushButton("Message");
            QPushButton *button2 = new QPushButton("Remove");
            //this->layoutFriends->addRow(new QLabel(str),button);
            this->layoutFriends->addWidget(new QLabel(str), i, 0);
            this->layoutFriends->addWidget(button1, i, 1);
            this->layoutFriends->addWidget(button2, i, 2);
            connect(button1,&QPushButton::clicked,this,[=]{ openChat(str);});
            connect(button2,&QPushButton::clicked,this,[=]{ deleteFriend(str);});
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

    this->client->sendBufferSize(10);
    this->client->sendBufferChar((char*)"chatFriend");

    this->client->sendBufferSize(strlen(str));
    this->client->sendBufferChar((char*)str);
    chat->setFriendId(this->client->receiveBufferSize());

    chat->receiveMessages();
    chat->setWindowTitle(str);
    chat->exec();
}
void Application::deleteFriend(const char* usr)
{
    qDebug() << usr;
    this->client->sendBufferSize(12);
    this->client->sendBufferChar((char*)"removeFriend");

    this->client->sendBufferSize(strlen(usr));
    this->client->sendBufferChar((char*)usr);

    if(this->client->receiveBufferSize() == -1)
    {
         QMessageBox::warning(this,"Remove","An error occured while removing friend!");
    }
    else
    {
        QMessageBox::information(this,"Remove","User succesfully removed from friendlist!");
    }

    // Create new grid without the deleted friend
    delete this->layoutFriends;
    this->layoutFriends = new QGridLayout(this);
    this->layoutFriends->setAlignment(Qt::AlignTop);

    this->client->sendBufferSize(7);
    this->client->sendBufferChar((char*)"Friends");

    int count = this->client->receiveBufferSize();
    char str[32];
    for(int i = 0 ;i < count;i++)
    {
        this->client->receiveBufferChar(str);
        QPushButton *button1 = new QPushButton("Message");
        QPushButton *button2 = new QPushButton("Remove");
        this->layoutFriends->addWidget(new QLabel(str), i, 0);
        this->layoutFriends->addWidget(button1, i, 1);
        this->layoutFriends->addWidget(button2, i, 2);
        connect(button1,&QPushButton::clicked,this,[=]{ openChat(str);});
        connect(button2,&QPushButton::clicked,this,[=]{ deleteFriend(str);});
    }
    QWidget *scrollContents = new QWidget(this);
    scrollContents->setLayout(this->layoutFriends);
    ui->scrollArea->setWidget(scrollContents);

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
        QPushButton *button1 = new QPushButton("Message");
        QPushButton *button2 = new QPushButton("Remove");
        int row = this->layoutFriends->count()/this->layoutFriends->columnCount();
        this->layoutFriends->addWidget(new QLabel(usr.data()), this->layoutFriends->count()/this->layoutFriends->columnCount(), 0);
        this->layoutFriends->addWidget(button1, row, 1);
        this->layoutFriends->addWidget(button2, row, 2);
        connect(button1,&QPushButton::clicked,this,[=]{ openChat(usr.data());});
        connect(button2,&QPushButton::clicked,this,[=]{ deleteFriend(usr.data());});

        QWidget *scrollContents = new QWidget(this);
        scrollContents->setLayout(this->layoutFriends);
        ui->scrollArea->setWidget(scrollContents);
    }
}


void Application::on_pushButton_GenInvCode_clicked()
{
    this->client->sendBufferSize(15);
    this->client->sendBufferChar((char*)"generateInvCode");

    char invitecode[32];

    if(this->client->receiveBufferChar(invitecode) > 0)
    {
        ui->textEdit_code->setText(invitecode);
        ui->textEdit_code->setAlignment(Qt::AlignCenter);
        ui->textEdit_code->show();
    }
    else
    {
        QMessageBox::warning(this,"Permission denied","You need a bigger rank to be able to generate invite codes!");
    }
}

void Application::on_pushButton_chats_clicked()
{
     Chat * chat = new Chat(this);
     chat->setClient(client);
     chat->setUserId(this->userId);
     QByteArray theme = ui->comboBox_chats->currentText().toLocal8Bit();
     chat->setTheme(theme.data());

     this->client->sendBufferSize(7);
     this->client->sendBufferChar((char*)"allChat");

     this->client->sendBufferSize(strlen(theme.data()));
     this->client->sendBufferChar(theme.data());
     chat->receiveMessages();
     chat->setWindowTitle(ui->comboBox_chats->currentText());
     chat->exec();
}

void Application::on_pushButton_search_clicked()
{
    this->client->sendBufferSize(8);
    this->client->sendBufferChar((char*)"sendData");

    QString dataNamestr = ui->lineEdit_MainSearchbar->text();
    QByteArray dataName = dataNamestr.toLocal8Bit();

    this->client->sendBufferSize(dataNamestr.length());
    this->client->sendBufferChar(dataName.data());

    char data[15000];

    if(this->client->receiveBufferChar(data) > 0)
    {
        ui->textEdit_data->setText(data);
        ui->textEdit_data->setAlignment(Qt::AlignCenter);
    }
}
