#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QMessageBox>
#include "client.h"

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

private slots:
    void showPage(int);
    void on_pushButton_logout_clicked();
    void on_pushButton_friends_clicked();

    void on_pushButton_mainMenu_clicked();

    void on_pushButton_addFriend_clicked();

signals:
    void logoutClicked();

private:
    Ui::Application *ui;
    Client *client;
};

#endif // APPLICATION_H
