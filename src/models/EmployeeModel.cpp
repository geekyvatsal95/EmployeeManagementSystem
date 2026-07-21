#include "EmployeeModel.h"

#include "../database/Database.h"

#include <iostream>
#include <sqlite3.h>

bool EmployeeModel::insertEmployee(const Employee& emp)
{
    sqlite3* db = Database::connect();

    if (db == nullptr)
        return false;

    const char* sql =
        "INSERT INTO employees "
        "(first_name, last_name, email, department, salary, joining_date) "
        "VALUES (?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, emp.first_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emp.last_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, emp.email.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, emp.department.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 5, emp.salary);
    sqlite3_bind_text(stmt, 6, emp.joining_date.c_str(), -1, SQLITE_TRANSIENT);

    bool success = false;

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        success = true;
        std::cout << "Employee inserted successfully!\n";
    }
    else
    {
        std::cout << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    Database::close(db);

    return success;
}

std::vector<Employee> EmployeeModel::getAllEmployees()
{
    std::vector<Employee> employees;

    sqlite3* db = Database::connect();

    if (db == nullptr)
        return employees;

    const char* sql =
        "SELECT id, first_name, last_name, email, department, salary, joining_date "
        "FROM employees;";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Employee emp;

        emp.id = sqlite3_column_int(stmt, 0);
        emp.first_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        emp.last_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        emp.email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        emp.department = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        emp.salary = sqlite3_column_double(stmt, 5);
        emp.joining_date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

        employees.push_back(emp);
    }

    sqlite3_finalize(stmt);
    Database::close(db);

    return employees;
}

Employee EmployeeModel::getEmployeeById(int id)
{
    Employee emp;

    sqlite3* db = Database::connect();

    if (db == nullptr)
        return emp;

    const char* sql =
        "SELECT id, first_name, last_name, email, department, salary, joining_date "
        "FROM employees WHERE id = ?;";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        emp.id = sqlite3_column_int(stmt, 0);
        emp.first_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        emp.last_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        emp.email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        emp.department = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        emp.salary = sqlite3_column_double(stmt, 5);
        emp.joining_date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
    }

    sqlite3_finalize(stmt);
    Database::close(db);

    return emp;
}

bool EmployeeModel::updateEmployee(const Employee& emp)
{
    sqlite3* db = Database::connect();

    if (db == nullptr)
        return false;

    const char* sql =
        "UPDATE employees SET "
        "first_name = ?, "
        "last_name = ?, "
        "email = ?, "
        "department = ?, "
        "salary = ?, "
        "joining_date = ? "
        "WHERE id = ?;";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, emp.first_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emp.last_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, emp.email.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, emp.department.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 5, emp.salary);
    sqlite3_bind_text(stmt, 6, emp.joining_date.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 7, emp.id);

    bool success = false;

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        success = true;
        std::cout << "Employee updated successfully!\n";
    }
    else
    {
        std::cout << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    Database::close(db);

    return success;
}

bool EmployeeModel::deleteEmployee(int id)
{
    sqlite3* db = Database::connect();

    if (db == nullptr)
        return false;

    const char* sql =
        "DELETE FROM employees WHERE id = ?;";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, id);

    bool success = false;

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        success = true;
        std::cout << "Employee deleted successfully!\n";
    }
    else
    {
        std::cout << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    Database::close(db);

    return success;
}