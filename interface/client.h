#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <string.h>

class Client
{
public:
    Client(char*,int);
    bool connectToServer();
    bool sendBufferSize(int);
    bool sendBufferChar(char*);

    int receiveBufferSize();
    int receiveBufferChar(char*);
    int readBytes(int,void*,unsigned int);

private:
    int socketClient;
    sockaddr_in addr;
    int sizeAddr = sizeof(addr);
};

#endif // CLIENT_H
