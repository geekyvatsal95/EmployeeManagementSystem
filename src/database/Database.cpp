#include "Database.h"

#include <iostream>

sqlite3* Database::connect()
{
    sqlite3* db = nullptr;

    int rc = sqlite3_open("src/database/employee.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Cannot open database!" << std::endl;
        return nullptr;
    }

    std::cout << "Database Connected Successfully!" << std::endl;

    return db;
}

void Database::close(sqlite3* db)
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        std::cout << "Database Closed Successfully!" << std::endl;
    }
}

void Database::createEmployeeTable(sqlite3* db)
{
    const char* sql =
        "CREATE TABLE IF NOT EXISTS employees ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "first_name TEXT NOT NULL,"
        "last_name TEXT NOT NULL,"
        "email TEXT NOT NULL UNIQUE,"
        "department TEXT NOT NULL,"
        "salary REAL NOT NULL,"
        "joining_date TEXT NOT NULL"
        ");";

    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cout << "Table creation failed: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "Employee table is ready!" << std::endl;
    }
}