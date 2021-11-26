#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

class Client
{
public:
    Client(char*,int);
    bool connectToServer();
private:
    int socketClient;
    sockaddr_in addr;
    int sizeAddr = sizeof(addr);
};

#endif // CLIENT_H
