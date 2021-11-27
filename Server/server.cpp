#include "server.h"

Server::Server(int port)
{
    if ((this->socketServer = socket(AF_INET, SOCK_STREAM, 0)) == -1) // TCP
        handle_error("[server]Error socket().\n");

    bzero(&addrServer, sizeAddr);
    bzero(&addrClient, sizeAddr);

    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY);
    addrServer.sin_port = htons(port);

    int optval = 1;
    setsockopt(this->socketServer, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    if (bind(this->socketServer, (struct sockaddr *)&addrServer, sizeAddr) == -1)
        handle_error("[server]Error bind().\n");

    if (listen(this->socketServer, 20) == -1)
        handle_error("[server]Error listen().\n");
}

void Server::acceptClients()
{
    while (1)
    {
        int client;
        char msg[1024];
        socklen_t length = sizeof(this->addrClient);
        client = accept(this->socketServer, (struct sockaddr *)&addrClient, &length);
        pid_t pidClient;
        if ((pidClient = fork()) == -1)
        {
            perror("[server]Error fork()Client.\n");
            pidClient = 1; // Make sure pidClient is not 0
        }
        if (pidClient == 0)
            //pthread_create (&th[clientsCounter], NULL, &executeClient(client,msg), NULL);
            executeClient(client, msg);
    }
}

void Server::executeClient(int client, char *command)
{
    while (1)
    {

        if (client < 0)
        {
            perror("[server]Error accept().\n");
            break;
        }
        bzero(command, 1024);
        int size = 0;
        if (read(client, &size, sizeof(int)) == -1)
            handle_error("[server]Error readBufferSize(int).\n");

        if (readBytes(client, command, size) == -1)
        {
            perror("[server]Error read().\n");
            close(client);
            break;
        }
        printf("Command: %s, size: %d \n",command,size);
        if(strcmp(command,"login") == 0)
        {
            login(client);
        } else if( strcmp(command,"signUp") == 0)
        {
            signUp(client);
        } else if(strcmp(command,"quit") == 0)
            break;
    }
    close(client);
    exit(1);
}

int Server::readBytes(int socket, void *buffer, unsigned int x)
{
    int bytesRead = 0;
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
