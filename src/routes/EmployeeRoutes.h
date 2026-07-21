#pragma once

#include <crow.h>

#include "../controllers/EmployeeController.h"

void registerEmployeeRoutes(crow::SimpleApp& app)
{
    // ==========================
    // GET All Employees
    // ==========================
    CROW_ROUTE(app, "/employees")
    .methods(crow::HTTPMethod::Get)
    ([]()
    {
        return EmployeeController::getAllEmployees();
    });

    // ==========================
    // GET Employee By ID
    // ==========================
    CROW_ROUTE(app, "/employees/<int>")
    .methods(crow::HTTPMethod::Get)
    ([](int id)
    {
        return EmployeeController::getEmployeeById(id);
    });

    // ==========================
    // Add Employee
    // ==========================
    CROW_ROUTE(app, "/employees")
    .methods(crow::HTTPMethod::Post)
    ([](const crow::request& req)
    {
        return EmployeeController::addEmployee(req);
    });

    // ==========================
    // Update Employee
    // ==========================
    CROW_ROUTE(app, "/employees/<int>")
    .methods(crow::HTTPMethod::Put)
    ([](const crow::request& req, int id)
    {
        return EmployeeController::updateEmployee(req, id);
    });

    // ==========================
    // Delete Employee
    // ==========================
    CROW_ROUTE(app, "/employees/<int>")
    .methods(crow::HTTPMethod::Delete)
    ([](int id)
    {
        return EmployeeController::deleteEmployee(id);
    });
}