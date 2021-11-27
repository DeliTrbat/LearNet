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
#include <pthread.h>

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
    int readBytes(int,void*,unsigned int);
    // Commands
    void login(int client);
    int searchUsernameAndPassword(char *, char *);
    int searchInviteCode(char*);
    int createAccount(char*,char*);
    void signUp(int client);

private:
    int socketServer;
    sockaddr_in addrServer;
    sockaddr_in addrClient;
    int sizeAddr = sizeof(addrServer);
};

#endif // SERVER_H