#include "client.h"

extern int errno;

#define handle_error(msg) \
    {                     \
        perror(msg);      \
        exit(errno);      \
    }

Client::Client(char* address,int port)
{
    if ((this->socketClient = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        handle_error("[client]Error socket().\n");
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_port = htons(port);
}

bool Client::connectToServer()
{
    return true;
}
