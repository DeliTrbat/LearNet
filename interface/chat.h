#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include "client.h"

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
    void setScrollContents(QWidget * scrollContents);
private slots:
    void on_pushButton_send_clicked();

private:
    Ui::Chat *ui;
    Client *client;
    //char* str;
};

#endif // CHAT_H
