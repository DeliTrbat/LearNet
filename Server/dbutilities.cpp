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
    sqlite3_prepare(db, "SELECT count(*) FROM accounts;", -1, &insertstmt, NULL); //preparing the statement
    sqlite3_step(insertstmt);
    int id = sqlite3_column_int(insertstmt, 0);
    sqlite3_finalize(insertstmt);
    sprintf(sql, "INSERT INTO accounts VALUES (%d,\'%s\',\'%s\')", id, username, password);
    printf("Command: %s\n", sql);

    sqlite3_prepare(db, sql, -1, &insertstmt, NULL); //preparing the statement
    sqlite3_step(insertstmt);
    // if (sqlite3_exec(db, sql, NULL, 0, NULL) != SQLITE_OK)
    // {
    //     perror("[server]Error insert");
    //     return 0;
    // }
    sqlite3_finalize(insertstmt);
    sqlite3_close(db);
    return id;
}
