#include "server.h"

int Server::login(int client)
{
    int found = -1;
    char username[32], password[64];
    recvMsg(client, username);
    recvMsg(client, password);

    printf("Username: %s, Password: %s \n", username, password);
    found = db::searchUsrAndPwd(database, username, password);
    
    if (write(client, &found, sizeof(int)) == -1)
        handle_error("[client]Error sendBufferSize(int).\n");
    return found;
}

int Server::signUp(int client)
{
    int found = -1;
    char inviteCode[32];
    recvMsg(client, inviteCode);

    printf("InviteCode: %s \n", inviteCode);
    found = db::searchInvCode(database, inviteCode);

    if (write(client, &found, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
    if (found == 1)
    {
        char username[32], password[64];
        recvMsg(client, username);
        recvMsg(client, password);
        printf("Username: %s, Password: %s \n", username, password);
        // Add verification if username and password exists ( are not null or username has other chars than [a-zA-Z]) and if the username is not already in use
        found = db::insertUsrAndPwd(database,username,password);
        if (write(client, &found, sizeof(int)) == -1)
            handle_error("[server]Error sendBufferSize(int).\n");
    }
    return found;
}

void Server::searchFriend(int client)
{
    int found = 0;
    char username[32];
    recvMsg(client, username);
    printf("Username: %s \n", username);
    // char sql[256];
    // sprintf(sql, "SELECT * FROM accounts WHERE username = \'%s\'", username);
    // printf("Command: %s\n", sql);
    // sqlite3_stmt *selectstmt;
    // if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    // {
    //     if (sqlite3_step(selectstmt) == SQLITE_ROW)
    //     {
    //         // Found.
    //         found = 1;
    //     }
    //     else
    //     {
    //         // Not found.
    //         found = 0;
    //     }
    // }
    if (write(client, &found, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
}