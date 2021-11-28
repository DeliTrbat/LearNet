#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>

namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

private slots:
    void on_pushButton_logout_clicked();

signals:
    void logoutClicked();

private:
    Ui::Application *ui;
};

#endif // APPLICATION_H
