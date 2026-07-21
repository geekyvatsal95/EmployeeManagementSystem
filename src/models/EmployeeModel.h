#pragma once

#include "Employee.h"

#include <vector>

class EmployeeModel
{
public:

    // Create
    static bool insertEmployee(const Employee& emp);

    // Read
    static std::vector<Employee> getAllEmployees();
    static Employee getEmployeeById(int id);

    // Update
    static bool updateEmployee(const Employee& emp);

    // Delete
    static bool deleteEmployee(int id);
};