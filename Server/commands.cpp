#include "server.h"
#include <iostream>
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
        found = db::searchUsername(database, username); // returns 1 if the user is not found, -1 for error, -3 if user already exists
        if (found == 1)
        {
            std::string usr = username;
            std::string pwd = password;
            std::cout << usr << '\n';
            std::regex usr_expr("^([A-Za-z]+[0-9]*)+$");
            std::regex pwd_expr("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$");
            std::cout << "User regex result: " << regex_match(usr.begin(), usr.end(), usr_expr) << " Password regex result: " << regex_match(pwd.begin(), pwd.end(), pwd_expr) << '\n';
            if (regex_match(usr.begin(), usr.end(), usr_expr) == 0 || regex_match(pwd.begin(), pwd.end(), pwd_expr) == 0)
            {
                found = -2;
                if (write(client, &found, sizeof(int)) == -1)
                    handle_error("[server]Error sendBufferSize(int).\n");
                return found;
            }
            else
            {
                found = db::insertUsrAndPwd(database, username, password);
                if (write(client, &found, sizeof(int)) == -1)
                    handle_error("[server]Error sendBufferSize(int).\n");
            }
        }
        else
        {
            if (write(client, &found, sizeof(int)) == -1)
                handle_error("[server]Error sendBufferSize(int).\n");
        }
    }
    return found;
}

void Server::searchFriend(int client, int id)
{
    int found = -1;
    char username[32];
    recvMsg(client, username);
    printf("Username: %s \n", username);
    found = db::addFriend(database, username, id);
    if (write(client, &found, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
}

void Server::sendUserFriends(int client, int id)
{
    int count = 0;
    count = db::countRows(database, "friends", id);
    printf("Count: %d\n", count);
    if (write(client, &count, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
    char str[32];
    sqlite3 *db;
    if (sqlite3_open(database, &db))
    {
        perror("Error sqlite3_open()");
        return;
    }
    sqlite3_stmt *stmt;
    char sql[256];
    sprintf(sql, "SELECT username FROM friends f JOIN accounts a ON f.id2 = a.id and f.id1 = %d;", id);
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        //will continue to go down the rows (columns in your table) till there are no more
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            sprintf(str, "%s", sqlite3_column_text(stmt, 0));
            sendMsg(client, str);
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}