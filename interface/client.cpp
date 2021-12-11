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
        handle_error("[client]Error receiveBufferSize(int).\n");
    return size;
}

int Client::receiveBufferChar(char *str)
{
    int size = 0;
    if (read(this->socketClient, &size, sizeof(int)) == -1)
        handle_error("[client]Error readBufferSize(int).\n");
    if(size == -1)
        return -1;
    if (readBytes(this->socketClient, str, size) == -1)
        handle_error("[client]Error read().\n");
    str[size] = '\0';
    return 1;
}

int Client::readBytes(int socket, char *buffer, unsigned int x)
{
    unsigned int bytesRead = 0;
    int result;
    while (bytesRead < x)
    {
        result = read(socket, buffer + bytesRead, x - bytesRead);
        if (result < 1)
            return -1;
        bytesRead += result;
    }
    return 1;
}

