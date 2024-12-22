#include <iostream>
#include "CDBInitializer.h"

int main()
{
    std::cout << "Welcome to Database Project!\n";

    try {
        DatabaseInitializer dbInit; // Database is set up here
        // Your application logic here
        std::cout << "Database initialized." << "\n";
    }
    catch (sql::SQLException& e) {
        std::cerr << "MySQL error: " << e.what() << "\n";
    }

    return 0;
}
