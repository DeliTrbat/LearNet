#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include "client.h"
#include <QString>
#include <QListWidgetItem>
#include <QListWidget>

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
    void setListItem(QListWidgetItem* mess, int align);
private slots:
    void on_pushButton_send_clicked();

private:
    Ui::Chat *ui;
    Client *client;
    int userId;
    //char* str;
};

#endif // CHAT_H
