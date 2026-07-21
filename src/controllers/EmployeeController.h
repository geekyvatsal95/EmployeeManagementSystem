#pragma once

#include <crow.h>
#include <regex>

#include "../models/Employee.h"
#include "../models/EmployeeModel.h"

class EmployeeController
{
public:

    static bool isValidDate(const std::string& date)
    {
        std::regex pattern(R"(^\d{4}-\d{2}-\d{2}$)");
        return std::regex_match(date, pattern);
    }

    // ==========================
    // GET ALL EMPLOYEES
    // ==========================
    static crow::json::wvalue getAllEmployees()
    {
        std::vector<Employee> employees = EmployeeModel::getAllEmployees();

        crow::json::wvalue result;

        for (size_t i = 0; i < employees.size(); i++)
        {
            result[i]["id"] = employees[i].id;
            result[i]["first_name"] = employees[i].first_name;
            result[i]["last_name"] = employees[i].last_name;
            result[i]["email"] = employees[i].email;
            result[i]["department"] = employees[i].department;
            result[i]["salary"] = employees[i].salary;
            result[i]["joining_date"] = employees[i].joining_date;
        }

        return result;
    }

    // ==========================
    // GET EMPLOYEE BY ID
    // ==========================
    static crow::response getEmployeeById(int id)
    {
        Employee emp = EmployeeModel::getEmployeeById(id);

        if (emp.id == 0)
        {
            return crow::response(404, "Employee not found.");
        }

        crow::json::wvalue result;

        result["id"] = emp.id;
        result["first_name"] = emp.first_name;
        result["last_name"] = emp.last_name;
        result["email"] = emp.email;
        result["department"] = emp.department;
        result["salary"] = emp.salary;
        result["joining_date"] = emp.joining_date;

        return crow::response(result);
    }

    // ==========================
    // ADD EMPLOYEE
    // ==========================
    static crow::response addEmployee(const crow::request& req)
    {
        auto body = crow::json::load(req.body);

        if (!body)
        {
            return crow::response(400, "Invalid JSON.");
        }

        Employee emp;

        emp.first_name = body["first_name"].s();
        emp.last_name = body["last_name"].s();
        emp.email = body["email"].s();
        emp.department = body["department"].s();
        emp.salary = body["salary"].d();
        emp.joining_date = body["joining_date"].s();

        // Validation
        if (emp.first_name.empty())
            return crow::response(400, "First name cannot be empty.");

        if (emp.last_name.empty())
            return crow::response(400, "Last name cannot be empty.");

        if (emp.email.empty())
            return crow::response(400, "Email cannot be empty.");

        if (emp.department.empty())
            return crow::response(400, "Department cannot be empty.");

        if (emp.salary <= 0)
            return crow::response(400, "Salary must be greater than zero.");

        if (emp.joining_date.empty())
            return crow::response(400, "Joining date cannot be empty.");

        if (!isValidDate(emp.joining_date))
            return crow::response(400, "Joining date must be in YYYY-MM-DD format.");

        if (EmployeeModel::insertEmployee(emp))
        {
            return crow::response(201, "Employee inserted successfully!");
        }

        return crow::response(500, "Failed to insert employee.");
    }

    // ==========================
    // UPDATE EMPLOYEE
    // ==========================
    static crow::response updateEmployee(const crow::request& req, int id)
    {
        auto body = crow::json::load(req.body);

        if (!body)
        {
            return crow::response(400, "Invalid JSON.");
        }

        Employee emp;

        emp.id = id;
        emp.first_name = body["first_name"].s();
        emp.last_name = body["last_name"].s();
        emp.email = body["email"].s();
        emp.department = body["department"].s();
        emp.salary = body["salary"].d();
        emp.joining_date = body["joining_date"].s();

        // Validation
        if (emp.first_name.empty())
            return crow::response(400, "First name cannot be empty.");

        if (emp.last_name.empty())
            return crow::response(400, "Last name cannot be empty.");

        if (emp.email.empty())
            return crow::response(400, "Email cannot be empty.");

        if (emp.department.empty())
            return crow::response(400, "Department cannot be empty.");

        if (emp.salary <= 0)
            return crow::response(400, "Salary must be greater than zero.");

        if (emp.joining_date.empty())
            return crow::response(400, "Joining date cannot be empty.");

        if (!isValidDate(emp.joining_date))
            return crow::response(400, "Joining date must be in YYYY-MM-DD format.");

        if (EmployeeModel::updateEmployee(emp))
        {
            return crow::response(200, "Employee updated successfully!");
        }

        return crow::response(404, "Employee not found.");
    }

    // ==========================
    // DELETE EMPLOYEE
    // ==========================
    static crow::response deleteEmployee(int id)
    {
        if (EmployeeModel::deleteEmployee(id))
        {
            return crow::response(200, "Employee deleted successfully!");
        }

        return crow::response(404, "Employee not found.");
    }
};