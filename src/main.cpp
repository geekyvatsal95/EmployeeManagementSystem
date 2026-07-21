#include <crow.h>

#include "database/Database.h"
#include "routes/HomeRoutes.h"
#include "routes/EmployeeRoutes.h"

int main()
{
    crow::SimpleApp app;

    sqlite3* db = Database::connect();

    if (db == nullptr)
        return 1;

    Database::createEmployeeTable(db);

    Database::close(db);

    registerHomeRoutes(app);
    registerEmployeeRoutes(app);

    app.port(18080).multithreaded().run();
}