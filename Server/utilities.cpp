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

void replaceAll(std::string &str, const std::string &from, const std::string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        //size_t end_pos = start_pos + from.length();
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}