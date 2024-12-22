#pragma once

#include <mysql_driver.h>
#include <mysql_connection.h>


class DatabaseInitializer {
public:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    DatabaseInitializer();

    ~DatabaseInitializer();

private:
    void createDatabase() const;

    void createTables() const;

    void clearData() const;
};

