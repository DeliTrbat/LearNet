#include "server.h"

void Server::login(int client)
{
    int found = 0;
    char username[32], password[64];
    recvMsg(client,username);
    recvMsg(client,password);
    printf("Username: %s, Password: %s \n", username, password);
    char sql[256];
    sprintf(sql, "SELECT * FROM accounts WHERE username=\'%s\' and password=\'%s\';", username, password);
    printf("Command: %s\n", sql);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            found = 1;
        }
        else
        {
            // Not found.
            found = 0;
        }
    }
    if (write(client, &found, sizeof(int)) == -1)
        handle_error("[client]Error sendBufferSize(int).\n");
}

void Server::signUp(int client)
{
    int found = 0;
    char inviteCode[32];
    recvMsg(client,inviteCode);
    printf("InviteCode: %s \n", inviteCode);
    char sql[256];
    sprintf(sql, "SELECT * FROM invitecodes WHERE code = \'%s\'", inviteCode);
    printf("Command: %s\n", sql);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            found = 1;
        }
        else
        {
            // Not found.
            found = 0;
        }
    }
    if (write(client, &found, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
    if (found == 1)
    {
        char username[32], password[64];
        recvMsg(client,username);
        recvMsg(client,password);
        printf("Username: %s, Password: %s \n", username, password);
        char sql[256];
        sprintf(sql, "INSERT INTO accounts VALUES (\'%s\',\'%s\')", username, password);
        printf("Command: %s\n", sql);
        sqlite3_stmt *insertstmt;
        if (sqlite3_exec(db, sql, NULL, 0, NULL) != SQLITE_OK)
            handle_error("[server]Error insert");
        if (write(client, &found, sizeof(int)) == -1)
            handle_error("[server]Error sendBufferSize(int).\n");
    }
}

void Server::recvMsg(int client, char * str)
{
    int size = 0;
    if (read(client, &size, sizeof(int)) == -1)
        handle_error("[server]Error readBufferSize(int).\n");
    if (readBytes(client, str, size) == -1)
    {
        perror("[server]Error read().\n");
        close(client);
    }
    str[size] = '\0';
}