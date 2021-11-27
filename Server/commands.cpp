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

    delete username[];
    delete password[];
}

int Server::searchUsernameAndPassword(char *username, char *password)
{
    FILE *fd;
    if ((fd = fopen("accounts.txt", "r")))
    {
        int i;
        char ch;
        char usr[strlen(username)], pwd[strlen(password)];
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
}