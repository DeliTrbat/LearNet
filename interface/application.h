#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QMessageBox>
#include "client.h"
#include <QFormLayout>
#include "chat.h"
#include <QListWidgetItem>
#include <QListWidget>

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

private slots:
    void showPage(int);
    void on_pushButton_logout_clicked();
    void on_pushButton_friends_clicked();

    void on_pushButton_mainMenu_clicked();

    void on_pushButton_addFriend_clicked();

    void openChat(const char*);

    void on_pushButton_GenInvCode_clicked();

signals:
    void logoutClicked();

private:
    Ui::Application *ui;
    Client *client;
    QFormLayout *layoutFriends = nullptr;
    char username[32];
    int userId;
};

#endif // APPLICATION_H
