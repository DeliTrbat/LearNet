#ifndef SQL_H
#define SQL_H

#include <sqlite3.h>
#include <stdio.h>

namespace db
{
    int searchUsrAndPwd(const char *path, const char *username, const char *password);
    int searchInvCode(const char *path, const char *inviteCode);
    int insertUsrAndPwd(const char *path,const char *username,const char *password);
}

#endif // SQL_H