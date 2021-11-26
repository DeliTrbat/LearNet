
#include "mainwindow.h"
#include <cstddef>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client client("127.0.0.1",1234);
    if(!client.connectToServer())
    {
        return a.exec();
    }
    MainWindow w;
    w.setClient(&client);
    w.show();
    return a.exec();
}
