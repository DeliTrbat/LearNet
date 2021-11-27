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
    size = 0;
    if (read(client, &size, sizeof(int)) == -1)
        handle_error("[server]Error readBufferSize(int).\n");
    password = new char[size];
    if (readBytes(client, password, size) == -1)
    {
        perror("[server]Error read().\n");
        close(client);
    }
    printf("Username: %s, Password: %s \n", username, password);
    size = searchUsernameAndPassword(username, password);
    if (write(client, &size, sizeof(int)) == -1)
        handle_error("[client]Error sendBufferSize(int).\n");
}

int Server::searchUsernameAndPassword(char *username, char *password)
{
    FILE *fd;
    if ((fd = fopen("accounts.txt", "r")))
    {
        int i;
        char ch;
        char usr[100], pwd[100];
        do
        {
            i = 0;
            do
            {
                ch = fgetc(fd);
                if (ferror(fd))
                    handle_error("[server]Error fgetc.\n");
                if (ch != ':' && ch != EOF)
                    usr[i++] = ch;
            } while (ch != EOF && ch != ':');
            usr[i] = '\0';
            i = 0;
            do
            {
                ch = fgetc(fd);
                if (ferror(fd))
                    handle_error("[server]Error fgetc.\n");
                if (ch != '\n' && ch != EOF)
                    pwd[i++] = ch;
            } while (ch != EOF && ch != '\n');
            pwd[i] = '\0';
            if (strcmp(usr, username) == 0 && strcmp(pwd, password) == 0)
                return 1;
        } while (ch != EOF);
        fclose(fd);
    }
    else
        handle_error("Error fopen Users [server]");
    return 0;
}
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
    printf("InviteCode: %s \n", inviteCode);
    size = searchInviteCode(inviteCode);
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
        size = 0;
        if (read(client, &size, sizeof(int)) == -1)
            handle_error("[server]Error readBufferSize(int).\n");
        password = new char[size];
        if (readBytes(client, password, size) == -1)
        {
            perror("[server]Error read().\n");
            close(client);
        }
        printf("Username: %s, Password: %s \n", username, password);
        size = createAccount(username, password);
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
        fprintf(fd,"\n%s:%s",username,password);
        fclose(fd);
    }
    else
        handle_error("Error fopen Users [server]");
    return 0;
}