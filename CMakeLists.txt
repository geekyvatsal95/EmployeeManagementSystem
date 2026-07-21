cmake_minimum_required(VERSION 3.20)

project(EmployeeManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(external/crow/include)

find_package(SQLite3 REQUIRED)

add_executable(EmployeeManagementSystem
    src/main.cpp
    src/database/Database.cpp
    src/models/EmployeeModel.cpp
)

target_link_libraries(EmployeeManagementSystem PRIVATE
    ws2_32
    mswsock
    SQLite3::SQLite3
)