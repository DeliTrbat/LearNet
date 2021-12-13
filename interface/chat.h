#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include "client.h"
#include <QString>
#include <QListWidgetItem>
#include <QListWidget>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();
    void setClient(Client*);
    void setUserId(int id);
    void setFriendId(int id);
    void setTheme(char* theme);
    void setListItem(QListWidgetItem* mess, int align);
    void receiveMessages();

private slots:
    void updateChat();
    void on_pushButton_send_clicked();

private:
    Ui::Chat *ui;
    Client *client;
    int userId;
    int friendId = -1;
    char* theme;
    QTimer *timer;
    //char* friendUsername[32];
};

#endif // CHAT_H
