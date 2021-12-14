#include "dbutilities.h"

int db::createTables(const char *path)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    char *errorMsg;
    std::string sql = "CREATE TABLE IF NOT EXISTS accounts (id INT UNIQUE, username VARCHAR(32) PRIMARY KEY, password VARCHAR(64) NOT NULL, rank VARCHAR(16) NOT NULL DEFAULT 'Member');";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }
    sql = "CREATE TABLE IF NOT EXISTS invitecodes (id INT UNIQUE, code VARCHAR(32) NOT NULL, FOREIGN KEY(id) REFERENCES accounts(id) ON UPDATE CASCADE ON DELETE CASCADE);";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sql = "CREATE TABLE IF NOT EXISTS friends (id1 INT NOT NULL, id2 INT NOT NULL, FOREIGN KEY(id1) REFERENCES accounts(id) ON UPDATE CASCADE ON DELETE CASCADE);";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sql = "CREATE TABLE IF NOT EXISTS chats (theme VARCHAR(16) NOT NULL,id INT NOT NULL,username VARCHAR(32) NOT NULL DEFAULT 'Deleted',rank VARCHAR(16) NOT NULL DEFAULT 'Member', message VARCHAR(1052), FOREIGN KEY(id,username) REFERENCES accounts(id,username) ON UPDATE CASCADE ON DELETE SET DEFAULT);";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sqlite3_close(db);
    return 1;
}
int db::deleteTables(const char *path)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    char *errorMsg;
    std::string sql = "DROP TABLE IF EXISTS accounts;";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sql = "DROP TABLE IF EXISTS invitecodes;";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sql = "DROP TABLE IF EXISTS friends;";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sql = "DROP TABLE IF EXISTS chats;";

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sqlite3_close(db);
    return 1;
}

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
    sprintf(sql, "INSERT INTO accounts (id, username, password) VALUES (%d,\'%s\',\'%s\')", id, username, password);
    printf("Command: %s\n", sql);

    char *errorMsg;
    if (sqlite3_exec(db, sql, NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error insertUsrAndPwd(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }
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
int db::sendFriendsNames(const char *path, int id, int socket)
{
    char str[32];
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    sqlite3_stmt *stmt;
    char sql[256];
    sprintf(sql, "SELECT username FROM friends f JOIN accounts a ON f.id2 = a.id and f.id1 = %d;", id);
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            sprintf(str, "%s", sqlite3_column_text(stmt, 0));
            sendMsg(socket, str);
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
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
    printf("Creating table: %s\n", sql);
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) == SQLITE_OK)
    {
        printf("Table: %s was created\n", table_name);
    }
    sqlite3_close(db);
    return 1;
}
int db::sendChatMessages(const char *path, const char *table_name, int socket)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    sqlite3_stmt *stmt;
    char sql[256], message[1000];
    sprintf(sql, "SELECT id,message FROM %s;", table_name);
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            sprintf(message, "%s", sqlite3_column_text(stmt, 1));
            int id = sqlite3_column_int(stmt, 0);
            printf("User: %d Sending message: %s\n", id, message);
            sendMsg(socket, message); // Send messages
            if (write(socket, &id, sizeof(int)) == -1)
                handle_error("[server]Error sendBufferSize(int).\n");
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    int signalFinish = -1;
    if (write(socket, &signalFinish, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
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
int db::insertMessage(const char *path, const char *message, const char *table_name, int id)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char sql[1256];
    sprintf(sql, "INSERT INTO %s VALUES (%d,\'%s\',CURRENT_TIMESTAMP)", table_name, id, message);
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) == SQLITE_OK)
    {
        printf("The message: %s was inserted in table %s\n", message, table_name);
    }
    else
    {
        sqlite3_close(db);
        return 0;
    }
    sqlite3_close(db);
    return 1;
}
int db::checkRank(const char *path, int id)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    std::string sql = "SELECT rank FROM accounts WHERE id=" + std::to_string(id) + ";";
    std::cout << sql << '\n';

    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            char str[16];
            sprintf(str, "%s", sqlite3_column_text(selectstmt, 0));
            if (strcmp(str, "Member") == 0)
            {
                sqlite3_finalize(selectstmt);
                sqlite3_close(db);
                return 0;
            }
            else if (strcmp(str, "Member2") == 0)
            {
                sqlite3_finalize(selectstmt);
                sqlite3_close(db);
                return 1;
            }
            else if (strcmp(str, "Owner") == 0)
            {
                sqlite3_finalize(selectstmt);
                sqlite3_close(db);
                return 2;
            }
            sqlite3_finalize(selectstmt);
        }
    }
    else
    {
        fprintf(stderr, "Error while creating select statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(selectstmt);
        sqlite3_close(db);
        return -1;
    }
    sqlite3_close(db);
    return -1;
}
int db::saveInvCode(const char *path, int id, const char *invitecode)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char *errorMsg;
    std::string sql = "INSERT INTO invitecodes VALUES( " + std::to_string(id) + ",'" + invitecode + "');";
    std::cout << sql << '\n';

    if (sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error createTables(): %s\n", errorMsg);
        sqlite3_free(errorMsg);
        sqlite3_close(db);
        return -1;
    }

    sqlite3_close(db);
    return 1;
}
int db::alreadyGenInvCode(const char *path, int id, char *invitecode)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    std::string sql = "SELECT code FROM invitecodes WHERE id=" + std::to_string(id) + ";";
    std::cout << sql << '\n';

    sqlite3_stmt *selectstmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &selectstmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            sprintf(invitecode, "%s", sqlite3_column_text(selectstmt, 0));
            sqlite3_finalize(selectstmt);
            sqlite3_close(db);
            return 1;
        }
    }
    else
    {
        fprintf(stderr, "Error while creating select statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(selectstmt);
        sqlite3_close(db);
        return -1;
    }
    sqlite3_close(db);
    return -1;
}
int db::sendAllChatMessages(const char *path, const char *theme, int id, int socket)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    sqlite3_stmt *stmt;
    char sql[256], message[1052];
    sprintf(sql, "SELECT * FROM chats where theme = '%s';", theme);
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int idMsg = sqlite3_column_int(stmt, 1);
            if (idMsg != id)
            {
                sprintf(message, "%s %s: %s", sqlite3_column_text(stmt, 3), sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 4));
            }
            else
            {
                sprintf(message, "Me: %s", sqlite3_column_text(stmt, 4));
            }
            printf("Sending message: %s\n", message);
            sendMsg(socket, message); // Send messages
            if (write(socket, &idMsg, sizeof(int)) == -1)
                handle_error("[server]Error sendBufferSize(int).\n");
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    int signalFinish = -1;
    if (write(socket, &signalFinish, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
    return 1;
}
int db::insertAllChatMessage(const char *path, const char *theme, const char *message, int id)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    char sql[1320];
    sprintf(sql, "SELECT username,rank FROM accounts where id =%d;", id);
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            sprintf(sql, "INSERT INTO chats VALUES (\'%s\',%d,\'%s\',\'%s\',\'%s\');", theme, id, sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1), message);
            printf("Command: %s\n", sql);
            sqlite3_finalize(stmt);
        }
    }
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) == SQLITE_OK)
    {
        printf("The message: %s was inserted.\n", message);
    }
    else
    {
        sqlite3_close(db);
        return 0;
    }
    sqlite3_close(db);
    return 1;
}

int db::sendCompleterData(const char *path, int socket)
{
    sqlite3 *db;
    if (sqlite3_open(path, &db))
    {
        perror("Error sqlite3_open()");
        return -1;
    }
    sqlite3_stmt *stmt;
    char sql[256], data[50];
    sprintf(sql, "SELECT type FROM data;");
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            sprintf(data,"%s",sqlite3_column_text(stmt, 0));
            printf("Sending message: %s\n", data);
            sendMsg(socket, data); // Send completer data
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    int signalFinish = -1;
    if (write(socket, &signalFinish, sizeof(int)) == -1)
        handle_error("[server]Error sendBufferSize(int).\n");
    return 1;
}