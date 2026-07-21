#pragma once

#include <crow.h>
#include "../controllers/HomeController.h"

void registerHomeRoutes(crow::SimpleApp& app)
{
    CROW_ROUTE(app, "/")
    ([]() {
        return HomeController::getHomeMessage();
    });
}