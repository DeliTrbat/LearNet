#ifndef SERVER_H
#define SERVER_H

#include "dbutilities.h"

class Server
{
public:
    Server(int);
    void acceptClients();

protected:
    void executeClient(int, char *);

    // Commands:
    int login(int client);
    int signUp(int client);
    void searchFriend(int client, int id);
    void sendUserFriends(int client, int id);
    void generateInvCode(int client, int id);

    void createChatFriend(int client, int id1);
    void insertMessageFriend(int client, int id1);
    void updateChat(int client, int id1);

    void allChat(int client,int id);
    void insertMessageAllChat(int client,int id);
    //void updateAllChat(int client,int id);

    void sendData(int client);

private:
    int socketServer;
    sockaddr_in addrServer;
    sockaddr_in addrClient;
    int sizeAddr = sizeof(addrServer);
    const char *database = "databaseServer.db";
};

#endif // SERVER_H