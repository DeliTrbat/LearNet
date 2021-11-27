#include "server.h"

void Server::login(int client)
{
    int size = 0;
    char *username, *password;
    if (read(client, &size, sizeof(int)) == -1)
        handle_error("[server]Error readBufferSize(int).\n");
    username = new char[size];
    if (readBytes(client, username, size) == -1)
    {
        perror("[server]Error read().\n");
        close(client);
    }
    username[size] = '\0';
    size = 0;
    if (read(client, &size, sizeof(int)) == -1)
        handle_error("[server]Error readBufferSize(int).\n");
    password = new char[size];
    if (readBytes(client, password, size) == -1)
    {
        perror("[server]Error read().\n");
        close(client);
    }
    password[size] = '\0';
    printf("Username: %s, Password: %s \n", username, password);
    char sql[200];
    sprintf(sql, "SELECT * FROM accounts WHERE username=\'%s\' and password=\'%s\';", username, password);
    printf("Command: %s\n", sql);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            size = 1;
        }
        else
        {
            // Not found.
            size = 0;
        }
    }
    //size = searchUsernameAndPassword(username, password);
    if (write(client, &size, sizeof(int)) == -1)
        handle_error("[client]Error sendBufferSize(int).\n");
}

// int Server::searchUsernameAndPassword(char *username, char *password)
// {
//     FILE *fd;
//     if ((fd = fopen("accounts.txt", "r")))
//     {
//         int i;
//         char ch;
//         char usr[100], pwd[100];
//         do
//         {
//             i = 0;
//             do
//             {
//                 ch = fgetc(fd);
//                 if (ferror(fd))
//                     handle_error("[server]Error fgetc.\n");
//                 if (ch != ':' && ch != EOF)
//                     usr[i++] = ch;
//             } while (ch != EOF && ch != ':');
//             usr[i] = '\0';
//             i = 0;
//             do
//             {
//                 ch = fgetc(fd);
//                 if (ferror(fd))
//                     handle_error("[server]Error fgetc.\n");
//                 if (ch != '\n' && ch != EOF)
//                     pwd[i++] = ch;
//             } while (ch != EOF && ch != '\n');
//             pwd[i] = '\0';
//             if (strcmp(usr, username) == 0 && strcmp(pwd, password) == 0)
//                 return 1;
//         } while (ch != EOF);
//         fclose(fd);
//     }
//     else
//         handle_error("Error fopen Users [server]");
//     return 0;
// }

void Server::signUp(int client)
{
    int size = 0;
    char *inviteCode;
    if (read(client, &size, sizeof(int)) == -1)
        handle_error("[server]Error readBufferSize(int).\n");
    inviteCode = new char[size];
    if (readBytes(client, inviteCode, size) == -1)
    {
        perror("[server]Error read().\n");
        close(client);
    }
    inviteCode[size] = '\0';
    printf("InviteCode: %s \n", inviteCode);
    char sql[200];
    sprintf(sql, "SELECT * FROM invitecodes WHERE code = \'%s\'", inviteCode);
    printf("Command: %s\n", sql);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            size = 1;
        }
        else
        {
            // Not found.
            size = 0;
        }
    }
    //size = searchInviteCode(inviteCode);
    printf("Size: %d\n", size);
    if (write(client, &size, sizeof(int)) == -1)
        handle_error("[client]Error sendBufferSize(int).\n");
    if (size == 1)
    {
        size = 0;
        char *username, *password;
        if (read(client, &size, sizeof(int)) == -1)
            handle_error("[server]Error readBufferSize(int).\n");
        username = new char[size];
        if (readBytes(client, username, size) == -1)
        {
            perror("[server]Error read().\n");
            close(client);
        }
        username[size] = '\0';
        size = 0;
        if (read(client, &size, sizeof(int)) == -1)
            handle_error("[server]Error readBufferSize(int).\n");
        password = new char[size];
        if (readBytes(client, password, size) == -1)
        {
            perror("[server]Error read().\n");
            close(client);
        }
        password[size] = '\0';
        printf("Username: %s, Password: %s \n", username, password);
        //size = createAccount(username, password);
        char sql[200];
        sprintf(sql, "INSERT INTO accounts VALUES (\'%s\',\'%s\')",username,password);
        printf("Command: %s\n", sql);
        sqlite3_stmt *insertstmt;
        if (sqlite3_exec(db, sql, NULL,0, NULL) != SQLITE_OK)
            handle_error("[server]Error insert");
        if (write(client, &size, sizeof(int)) == -1)
            handle_error("[client]Error sendBufferSize(int).\n");
    }
}

int Server::searchInviteCode(char *inviteCode)
{
    FILE *fd;
    if ((fd = fopen("invites.txt", "r")))
    {
        int i;
        char ch;
        char invCode[100];
        do
        {
            i = 0;
            do
            {
                ch = fgetc(fd);
                if (ferror(fd))
                    handle_error("[server]Error fgetc.\n");
                if (ch != '\n' && ch != EOF)
                    invCode[i++] = ch;
            } while (ch != EOF && ch != '\n');
            invCode[i] = '\0';
            if (strcmp(invCode, inviteCode) == 0)
                return 1;
            printf("Invite code : %s\n", invCode);
        } while (ch != EOF);
        fclose(fd);
    }
    else
        handle_error("Error fopen Users [server]");
    return 0;
}
int Server::createAccount(char *username, char *password)
{
    FILE *fd;
    if ((fd = fopen("accounts.txt", "a")))
    {
        fprintf(fd, "\n%s:%s", username, password);
        fclose(fd);
    }
    else
        handle_error("Error fopen Users [server]");
    return 0;
}