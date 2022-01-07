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
        handle_error("[server]Error write().\n");
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
        handle_error("[server]Error write().\n");
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
                    handle_error("[server]Error write().\n");
                return found;
            }
            else
            {
                found = db::insertUsrAndPwd(database, username, password);
                if (write(client, &found, sizeof(int)) == -1)
                    handle_error("[server]Error write().\n");
            }
        }
        else
        {
            if (write(client, &found, sizeof(int)) == -1)
                handle_error("[server]Error write().\n");
        }
    }
    return found;
}

void Server::generateInvCode(int client, int id)
{
    int permission = db::checkRank(database, id); // returns -1 on error rank permissions on success 0 - Member < 1 - Member2 < 2 - Owner
    if (permission > 0)
    {
        char invitecode[32];
        if (db::alreadyGenInvCode(database, id, invitecode) == 1)
        {
            sendMsg(client, invitecode); // send it to client
        }
        else
        {
            strcpy(invitecode, "invitecodegenerated");               // generate random invitecode
            int success = db::saveInvCode(database, id, invitecode); // save it in database
            if (success == 1)
                sendMsg(client, invitecode); // send it to client
            else
            {
                if (write(client, &success, sizeof(int)) == -1) // signal error in saveInvCode
                    handle_error("[server]Error write().\n");
            }
        }
    }
    else
    {
        permission = -1;
        if (write(client, &permission, sizeof(int)) == -1) // signal error or no permision
            handle_error("[server]Error write().\n");
    }
}

void Server::searchFriend(int client, int id)
{
    int found = -1;
    char username[32];
    recvMsg(client, username);
    printf("Username: %s \n", username);
    found = db::addFriend(database, username, id);
    if (write(client, &found, sizeof(int)) == -1)
        handle_error("[server]Error write().\n");
}
void Server::removeFriend(int client, int id)
{
    int result = -1;
    char username[32];
    recvMsg(client, username);
    printf("Username: %s \n", username);
    result = db::removeFriend(database, username, id, client);
    if (write(client, &result, sizeof(int)) == -1)
        handle_error("[server]Error write().\n");
}
void Server::sendUserFriends(int client, int id)
{
    int count = 0;
    count = db::countRows(database, "friends", id); // Count the number of friends
    printf("Count: %d\n", count);
    if (write(client, &count, sizeof(int)) == -1)
        handle_error("[server]Error write().\n");
    if (db::sendFriendsNames(database, id, client) == -1)
    {
        // Send message to client that something went wrong
    }
}

void Server::createChatFriend(int client, int id1)
{
    int finish = -1;
    char username[32], table_name[30];
    recvMsg(client, username);
    int id2 = db::getUsrId(database, username); // returns id or -1 in case of error
    if (id2 == -1)
    {
        if (write(client, &finish, sizeof(int)) == -1)
            handle_error("[server]Error write().\n");
        perror("[server]Error createChat()");
        return;
    }
    if (write(client, &id2, sizeof(int)) == -1)
        handle_error("[server]Error write().\n");
    if (db::createChatTable(database, id1, id2, table_name) == -1) // Create table if not exists
    {
        if (write(client, &finish, sizeof(int)) == -1)
            handle_error("[server]Error write().\n");
        perror("[server]Error createChat()");
        return;
    }
    if (db::sendChatMessages(database, table_name, client) == -1)
    {
        // Send message to client that something went wrong
    }
}
void Server::insertMessageFriend(int client, int id1)
{
    int id2 = 0;
    if (read(client, &id2, sizeof(int)) == -1)
        handle_error("[server]Error readBufferSize(int).\n");
    char message[1000];
    recvMsg(client, message);
    std::string msg = message;
    replaceAll(msg, "'", "''"); // Replace all ' with '' to be able to add it to the database
    printf("Inserting message: %s\n", msg.c_str());
    char table_name[30];
    if (id1 < id2)
        sprintf(table_name, "u%du%d", id1, id2);
    else
        sprintf(table_name, "u%du%d", id2, id1);

    int done = db::insertMessage(database, msg.c_str(), table_name, id1);
    printf("Sending result to the client.\n");
    if (write(client, &done, sizeof(int)) == -1)
        handle_error("[server]Error write().\n");

    if (done == -1)
    {
        handle_error("[server]Error db::insertMessage() iMF.\n");
    }
    else
    {
        if (db::sendChatMessages(database, table_name, client) == -1)
        {
            // Send message to client that something went wrong
        }
    }
}
void Server::updateChat(int client, int id1)
{
    int id2 = 0;
    if (read(client, &id2, sizeof(int)) == -1) // Receive id friend
        handle_error("[server]Error readBufferSize(int).\n");
    char table_name[30];
    if (id1 < id2) // Generate chat table name
        sprintf(table_name, "u%du%d", id1, id2);
    else
        sprintf(table_name, "u%du%d", id2, id1);

    if (db::sendChatMessages(database, table_name, client) == -1)
    {
        // Send message to client that something went wrong
    }
}
void Server::allChat(int client, int id)
{
    char theme[16];
    recvMsg(client, theme);
    printf("AllChat on theme: %s\n", theme);
    if (db::sendAllChatMessages(database, theme, id, client) == -1)
    {
        // Send message to client that something went wrong
    }
}
void Server::insertMessageAllChat(int client, int id)
{
    char theme[16];
    recvMsg(client, theme);
    printf("AllChat on theme: %s\n", theme);

    char message[1052]; // 1000 message + 16 rank + 32 username
    recvMsg(client, message);
    std::string msg = message;
    replaceAll(msg, "'", "''"); // Replace all ' with '' to be able to add it to the database
    printf("Inserting message: %s\n", msg.c_str());

    int done = db::insertAllChatMessage(database, theme, msg.c_str(), id);
    printf("Sending result to the client.\n");
    if (write(client, &done, sizeof(int)) == -1)
        handle_error("[server]Error write().\n");

    if (done == -1)
    {
        handle_error("[server]Error db::insertMessage() iMF.\n");
    }
    else
    {
        if (db::sendAllChatMessages(database, theme, id, client) == -1)
        {
            // Send message to client that something went wrong
        }
    }
}
void Server::sendCompleterData(int client)
{
    if (db::sendCompleterData(database, client) == 1)
    {
        printf("Completer data sent.\n");
    }
    else
    {
        perror("Error while sending completer data.\n");
    }
}
void Server::sendData(int client) // Create a function in dbutilities to search for type
{
    char type[64];
    recvMsg(client, type);
    sqlite3 *db;
    if (sqlite3_open(database, &db))
    {
        perror("Error sqlite3_open()");
        return;
    }
    sqlite3_stmt *stmt;
    char sql[256];
    printf("Searching for: %s\n", type);
    sprintf(sql, "SELECT data FROM data where type like \'%s\';", type);
    char data[15000];
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            sprintf(data, "%s", sqlite3_column_text(stmt, 0));
            sendMsg(client, data); // Send data
            printf("Data: '%s' sent\n", type);
        }
        else
        {
            sendMsg(client, (char *)"No data found!");
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}