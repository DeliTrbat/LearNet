#include "client.h"

extern int errno;

#define handle_error(msg) \
    {                     \
        perror(msg);      \
        exit(errno);      \
    }

Client::Client(char* address,int port)
{
    if ((this->socketClient = socket(AF_INET, SOCK_STREAM, 0)) == -1) // TCP
        handle_error("[client]Error socket().\n");
    bzero(&addr,sizeAddr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_port = htons(port);
}

bool Client::connectToServer()
{
    if(connect(this->socketClient,(sockaddr*)&addr,this->sizeAddr) == -1)
        handle_error("[client]Error connect().\n");
    return true;
}
// Send
bool Client::sendBufferSize(int size)
{
    if (write(this->socketClient, &size, sizeof(int)) == -1)
        handle_error("[client]Error sendBufferSize(int).\n");
    return true;
}
bool Client::sendBufferChar(char* msg)
{
    if (write(this->socketClient,msg,strlen(msg)) == -1)
        handle_error("[client]Error sendBuffer(std::string).\n");
    return true;
}
//  Receive
int Client::receiveBufferSize()
{
    int size = 0;
    if (read(this->socketClient, &size, sizeof(int)) == -1)
        handle_error("[client]Error sendBufferSize(int).\n");
    return size;
}

bool Client::receiveBufferChar(char* msg)
{
    if (read(this->socketClient,msg,sizeof(msg)) == -1)
        handle_error("[client]Error sendBuffer(std::string).\n");
    return true;
}

