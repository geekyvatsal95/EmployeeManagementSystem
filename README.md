# Employee Management System (REST API)

## Project Overview

The Employee Management System is a backend REST API application developed using **C++17**, **Crow Framework**, and **SQLite**. It allows users to perform CRUD (Create, Read, Update, Delete) operations on employee records through RESTful APIs.

This project was developed as part of an internship assignment to demonstrate backend development, REST API design, database integration, and error handling.

---

# Technology Stack

- C++17
- Crow Framework
- SQLite3
- CMake
- Git

---

# Features

- Create Employee
- View All Employees
- View Employee by ID
- Update Employee Details
- Delete Employee
- SQLite Database Integration
- RESTful API Design
- Input Validation
- Proper HTTP Error Handling

---

# Employee Entity

| Field | Type |
|-------|------|
| id | Integer |
| first_name | String |
| last_name | String |
| email | String |
| department | String |
| salary | Double |
| joining_date | String (YYYY-MM-DD) |

---

# Project Structure

```
EmployeeManagementSystem/
│
├── database/
├── external/
├── include/
├── src/
│   ├── controllers/
│   ├── database/
│   ├── models/
│   ├── routes/
│   ├── services/
│   ├── utils/
│   └── main.cpp
│
├── tests/
├── CMakeLists.txt
└── README.md
```

---

# Database Schema

```sql
CREATE TABLE employees(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    email TEXT NOT NULL UNIQUE,
    department TEXT NOT NULL,
    salary REAL NOT NULL,
    joining_date TEXT NOT NULL
);
```

---

# Build Instructions

## Configure

```bash
cmake -S . -B build
```

## Build

```bash
cmake --build build
```

## Run

Linux / macOS

```bash
./build/EmployeeManagementSystem
```

Windows

```powershell
.\build\EmployeeManagementSystem.exe
```

---

# REST API Endpoints

| Method | Endpoint | Description |
|---------|----------|-------------|
| POST | `/employees` | Create a new employee |
| GET | `/employees` | Get all employees |
| GET | `/employees/{id}` | Get employee by ID |
| PUT | `/employees/{id}` | Update employee |
| DELETE | `/employees/{id}` | Delete employee |

---

# Sample Request

```json
{
    "first_name": "Vatsal",
    "last_name": "Mishra",
    "email": "vatsal@gmail.com",
    "department": "AI",
    "salary": 50000,
    "joining_date": "2026-07-21"
}
```

---

# Sample Response

```json
[
    {
        "id": 1,
        "first_name": "Vatsal",
        "last_name": "Mishra",
        "email": "vatsal@gmail.com",
        "department": "AI",
        "salary": 50000,
        "joining_date": "2026-07-21"
    }
]
```

---

# Validation Rules

- Employee ID is auto-generated and unique.
- First Name cannot be empty.
- Last Name cannot be empty.
- Email cannot be empty.
- Salary must be greater than zero.
- Joining Date must follow **YYYY-MM-DD** format.

---

# HTTP Status Codes

| Status Code | Description |
|-------------|-------------|
| 200 | Success |
| 201 | Created |
| 400 | Bad Request |
| 404 | Not Found |
| 500 | Internal Server Error |

---

# Testing

The REST APIs were tested using:

- Thunder Client (VS Code)
- Google Chrome
- SQLite Database

---

# Author

**Vatsal Mishra**

Software Developer Intern

HCL Tech