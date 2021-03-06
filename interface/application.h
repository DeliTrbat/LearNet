#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QMessageBox>
#include "client.h"
#include <QFormLayout>
#include "chat.h"
#include <QListWidgetItem>
#include <QListWidget>
#include <QCompleter>

namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT
public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();
    void setClient(Client*);
    void setUserId(int);
    void setUsername(char*);
    void initializeCompleter();

private slots:
    void showPage(int);
    void on_pushButton_logout_clicked();
    void on_pushButton_friends_clicked();

    void on_pushButton_mainMenu_clicked();

    void on_pushButton_addFriend_clicked();

    void openChat(const char*);
    void deleteFriend(const char*);

    void on_pushButton_GenInvCode_clicked();

    void on_pushButton_chats_clicked();

    void on_pushButton_search_clicked();

signals:
    void logoutClicked();

private:
    Ui::Application *ui;
    Client *client;
    QGridLayout *layoutFriends = nullptr;
    QCompleter *stringCompleter;
    char username[32];
    int userId;
};

#endif // APPLICATION_H
