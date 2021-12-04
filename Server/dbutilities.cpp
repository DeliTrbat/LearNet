#include "dbutilities.h"

int db::searchUsrAndPwd(const char *path, const char *username, const char *password)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        printf("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    sprintf(sql, "SELECT * FROM accounts WHERE username=\'%s\' and password=\'%s\';", username, password);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            int id = sqlite3_column_int(selectstmt, 0);
            printf("ID: %d\n", id);
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return id;
        }
        else
        {
            // Not found.
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return -1;
        }
    }
    sqlite3_finalize(selectstmt);
    sqlite3_close(db);
    return -1;
}
int db::searchInvCode(const char *path, const char *inviteCode)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        printf("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    sprintf(sql, "SELECT * FROM invitecodes WHERE code = \'%s\'", inviteCode);
    printf("Command: %s\n", sql);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return 1;
        }
        else
        {
            // Not found.
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return -1;
        }
    }
    sqlite3_finalize(selectstmt);
    sqlite3_close(db);
    return -1;
}
int db::searchUsername(const char *path, const char *username)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        printf("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    sprintf(sql, "SELECT * FROM accounts WHERE username = \'%s\'", username);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return -3;
        }
        else
        {
            // Not found.
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return 1;
        }
    }
    sqlite3_finalize(selectstmt);
    sqlite3_close(db);
    return -1;
}
int db::insertUsrAndPwd(const char *path, const char *username, const char *password)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    sqlite3_stmt *insertstmt;
    sqlite3_prepare_v2(db, "SELECT max(id) FROM accounts;", -1, &insertstmt, NULL); //preparing the statement
    sqlite3_step(insertstmt);
    int id = sqlite3_column_int(insertstmt, 0) + 1;
    sqlite3_finalize(insertstmt);
    sprintf(sql, "INSERT INTO accounts VALUES (%d,\'%s\',\'%s\')", id, username, password);
    printf("Command: %s\n", sql);

    sqlite3_prepare_v2(db, sql, -1, &insertstmt, NULL); //preparing the statement
    sqlite3_step(insertstmt);
    sqlite3_finalize(insertstmt);
    sqlite3_close(db);
    return id;
}
int db::addFriend(const char *path, const char *username, int id1)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    int id2 = -1;
    sprintf(sql, "SELECT * FROM accounts WHERE username=\'%s\';", username); // Search friend id
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            id2 = sqlite3_column_int(selectstmt, 0);
            printf("ID friend: %d\n", id2);
            if (id1 == id2)
            {
                sqlite3_finalize(selectstmt);
                sqlite3_close(db);
                return 2;
            }
        }
        else
        {
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return -1;
        }
    }
    sqlite3_finalize(selectstmt);

    sprintf(sql, "SELECT * FROM friends WHERE id1=%d and id2=%d;", id1, id2); // Check if they are not already friends
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            // Found.
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return 0;
        }
    }
    sqlite3_finalize(selectstmt);

    sprintf(sql, "INSERT INTO friends VALUES (%d,%d),(%d,%d)", id1, id2, id2, id1); // Add friend
    sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL);                             //preparing the statement
    sqlite3_step(selectstmt);
    sqlite3_finalize(selectstmt);
    sqlite3_close(db);
    return 1;
}
int db::countRows(const char *path, const char *tablename, int id)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    sqlite3_stmt *insertstmt;
    sprintf(sql, "SELECT count(*) FROM %s WHERE id1 = %d;", tablename, id);
    sqlite3_prepare_v2(db, sql, -1, &insertstmt, NULL); //preparing the statement
    sqlite3_step(insertstmt);
    int count = sqlite3_column_int(insertstmt, 0);
    sqlite3_finalize(insertstmt);
    sqlite3_close(db);
    return count;
}
int db::createChatTable(const char *path, int id1, int id2, char *table_name)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    if (id1 < id2)
    {
        sprintf(sql, "CREATE TABLE IF NOT EXISTS u%du%d (id int, message varchar(1000), timestamp datetime);", id1, id2);
        sprintf(table_name, "u%du%d", id1, id2);
    }
    else
    {
        sprintf(sql, "CREATE TABLE IF NOT EXISTS u%du%d (id int, message varchar(1000), timestamp datetime);", id2, id1);
        sprintf(table_name, "u%du%d", id2, id1);
    }
    printf("Creating table: %s\n",sql);
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) == SQLITE_OK)
    {
        printf("Table: %s was created\n", table_name);
    }
    sqlite3_close(db);
    return 1;
}
int db::getUsrId(const char *path, const char *username)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        printf("Error sqlite3_open()");
        return -1;
    }
    char sql[256];
    sprintf(sql, "SELECT * FROM accounts WHERE username = \'%s\'", username);
    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(selectstmt, 0);
            printf("ID %s: %d\n", username, id);
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return id;
        }
    }
    sqlite3_finalize(selectstmt);
    sqlite3_close(db);
    return -1;
}
int db::insertMessage(const char *path, const char* message, const char* table_name, int id)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char sql[1256];
    sprintf(sql, "INSERT INTO %s VALUES (%d,\'%s\',CURRENT_TIMESTAMP)", table_name,id, message);
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) == SQLITE_OK)
    {
        printf("The message: %s was inserted in table %s\n",message, table_name);
    }
    else
    {
        sqlite3_close(db);
        return 0;
    }
    sqlite3_close(db);
    return 1;
}