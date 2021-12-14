#ifndef SQL_H
#define SQL_H

#include "utilities.h"

namespace db
{
    int createTables(const char *path);
    int deleteTables(const char *path);

    int searchUsrAndPwd(const char *path, const char *username, const char *password);
    int searchInvCode(const char *path, const char *inviteCode);
    int searchUsername(const char *path, const char *username);
    int insertUsrAndPwd(const char *path,const char *username,const char *password);
    int addFriend(const char *path,const char *username,int id);
    int countRows(const char *path,const char* tablename,int id);
    int sendFriendsNames(const char *path,int id, int socket);

    // Chat
    int createChatTable(const char *path,int id1,int id2, char* table_name);
    int sendChatMessages(const char *path, const char *table_name, int socket);
    int insertMessage(const char *path, const char* message, const char* table_name, int id);
    int sendAllChatMessages(const char *path,const char* theme,int id,int socket);
    int insertAllChatMessage(const char *path,const char* theme,const char* message,int id);

    int getUsrId(const char *path, const char *username);
    int checkRank(const char *path, int id);
    int saveInvCode(const char *path, int id, const char * invitecode);
    int alreadyGenInvCode(const char *path, int id,char * invitecode);

    int sendCompleterData(const char *path, int socket);
    
}
#endif // SQL_H