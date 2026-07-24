# Employee Management System REST API

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Crow](https://img.shields.io/badge/Framework-Crow-green)
![SQLite](https://img.shields.io/badge/Database-SQLite-blue)
![CMake](https://img.shields.io/badge/Build-CMake-orange)
![Git](https://img.shields.io/badge/Version_Control-Git-red)

---

## Project Overview

The **Employee Management System** is a RESTful backend application developed using **C++17**, **Crow Framework**, and **SQLite3**.

The application provides complete CRUD (Create, Read, Update, Delete) functionality for managing employee records through REST APIs. It demonstrates REST API development, database integration, routing, input validation, and error handling using a modular architecture.

This project was developed as part of a backend development internship assignment.

---

## Features

- Create Employee
- Get All Employees
- Get Employee by ID
- Update Employee Details
- Delete Employee
- SQLite Database Integration
- RESTful API Architecture
- JSON Request & Response
- Input Validation
- HTTP Status Code Handling
- Modular Project Structure

---

## Technology Stack

- C++17
- Crow Framework
- SQLite3
- nlohmann/json
- CMake
- Git
- Postman

---

## Requirements

Before running the project, ensure the following are installed:

- C++17 Compatible Compiler
- CMake 3.20 or above
- SQLite3
- Git

---

## Employee Entity

| Field | Type |
|--------|------|
| id | Integer |
| first_name | String |
| last_name | String |
| email | String |
| department | String |
| salary | Double |
| joining_date | String (YYYY-MM-DD) |

---

## Project Structure

```text
EmployeeManagementSystem/
│
├── src/
│   ├── controllers/
│   ├── database/
│   ├── models/
│   ├── routes/
│   ├── services/
│   ├── utils/
│   └── main.cpp
│
├── include/
├── database/
├── external/
├── tests/
│
├── CMakeLists.txt
├── database.sql
├── README.md
├── Employee Management System.postman_collection.json
└── .gitignore
```

---

## Database Schema

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

## Build Instructions

### Clone Repository

```bash
git clone https://github.com/geekyvatsal95/EmployeeManagementSystem.git
```

### Navigate to Project

```bash
cd EmployeeManagementSystem
```

### Configure Project

```bash
cmake -S . -B build
```

### Build Project

```bash
cmake --build build
```

### Run Application

#### Windows

```powershell
.\build\EmployeeManagementSystem.exe
```

#### Linux / macOS

```bash
./build/EmployeeManagementSystem
```

The server starts on:

```
http://localhost:18080
```

---

## REST API Endpoints

| Method | Endpoint | Description |
|---------|----------|-------------|
| POST | `/employees` | Create Employee |
| GET | `/employees` | Get All Employees |
| GET | `/employees/{id}` | Get Employee by ID |
| PUT | `/employees/{id}` | Update Employee |
| DELETE | `/employees/{id}` | Delete Employee |

---

## Sample Create Employee Request

```json
{
    "first_name": "Vatsal",
    "last_name": "Mishra",
    "email": "vatsal@gmail.com",
    "department": "Backend",
    "salary": 50000,
    "joining_date": "2026-07-21"
}
```

---

## Sample GET Response

```json
[
    {
        "id": 1,
        "first_name": "Vatsal",
        "last_name": "Mishra",
        "email": "vatsal@gmail.com",
        "department": "Backend",
        "salary": 50000,
        "joining_date": "2026-07-21"
    }
]
```

---

## Validation Rules

- Employee ID is auto-generated and unique.
- First Name cannot be empty.
- Last Name cannot be empty.
- Email must be unique.
- Department cannot be empty.
- Salary must be greater than zero.
- Joining Date must follow the **YYYY-MM-DD** format.
- Invalid requests return appropriate HTTP error responses.

---

## HTTP Status Codes

| Code | Description |
|------|-------------|
| 200 | Success |
| 201 | Created |
| 400 | Bad Request |
| 404 | Employee Not Found |
| 500 | Internal Server Error |

---

## Testing

The REST APIs were successfully tested using:

- Postman
- SQLite Database

The exported Postman collection is included in the repository:

```
Employee Management System.postman_collection.json
```

---

## Author

**Vatsal Mishra**

Backend Developer

GitHub: **https://github.com/geekyvatsal95**

---
