#include "utilities.h"

int readBytes(int socket, char *buffer, unsigned int x)
{
    unsigned int bytesRead = 0;
    int result;
    while (bytesRead < x)
    {
        result = read(socket, buffer + bytesRead, x - bytesRead);
        if (result < 1)
            return -1;
        bytesRead += result;
    }
    return 1;
}

void sendMsg(int client, char *str)
{
    int size = strlen(str);
    if (write(client, &size, sizeof(int)) == -1)
        handle_error("[server]Error writeBufferSize(int).\n");
    if (write(client, str, size) == -1)
        handle_error("[server]Error writeBufferSize(int).\n");
}

void recvMsg(int client, char *str)
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