#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>
#include <sqlite3.h>
#include <string>
#include <regex>
#include "dbutilities.h"

extern int errno;

#define handle_error(msg) \
    {                     \
        perror(msg);      \
        exit(errno);      \
    }

class Server
{
public:
    Server(int);
    void acceptClients();
    void executeClient(int,char*);

    // Commands:
    int login(int client);
    int signUp(int client);
    void searchFriend(int client,int id);
    void sendUserFriends(int client,int id);

    int readBytes(int,void*,unsigned int);
    void recvMsg(int client, char * str);
    void sendMsg(int client, char *str);

private:
    int socketServer;
    sockaddr_in addrServer;
    sockaddr_in addrClient;
    int sizeAddr = sizeof(addrServer);
    const char* database = "databaseServer.db";
};

#endif // SERVER_H