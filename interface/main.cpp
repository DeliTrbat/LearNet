
#include "mainwindow.h"
#include <cstddef>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client client((char*)"127.0.0.1",2000);
    if(!client.connectToServer())
    {
        return a.exec();
    }
    MainWindow w;
    w.setClient(&client);
    w.show();
    return a.exec();
}
