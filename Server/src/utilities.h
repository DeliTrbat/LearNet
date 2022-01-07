#ifndef UTILITIES_H
#define UTILITIES_H

#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>
#include <sqlite3.h>
#include <string>
#include <regex>
#include <iostream>

extern int errno;

#define handle_error(msg) \
    {                     \
        perror(msg);      \
        exit(errno);      \
    }

int readBytes(int, char *, unsigned int);
void recvMsg(int client, char *str);
void sendMsg(int client, char *str);
void replaceAll(std::string &str, const std::string &from, const std::string &to);

#endif // UTILITIES_H