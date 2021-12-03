#ifndef SQL_H
#define SQL_H

#include <sqlite3.h>
#include <stdio.h>

namespace db
{
    int searchUsrAndPwd(const char *path, const char *username, const char *password);
    int searchInvCode(const char *path, const char *inviteCode);
    int searchUsername(const char *path, const char *username);
    int insertUsrAndPwd(const char *path,const char *username,const char *password);
    int addFriend(const char *path,const char *username,int id);
    int countRows(const char *path,const char* tablename,int id);
    int createChatTable(const char *path,int id1,int id2, char* table_name);
    int getUsrId(const char *path, const char *username);
}
#endif // SQL_H