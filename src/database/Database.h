#pragma once

#include <sqlite3.h>

class Database
{
public:
    static sqlite3* connect();

    static void close(sqlite3* db);

    static void createEmployeeTable(sqlite3* db);
};