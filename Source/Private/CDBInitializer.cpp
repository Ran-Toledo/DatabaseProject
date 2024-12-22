#include "CDBInitializer.h"
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;
using namespace sql;

DatabaseInitializer::DatabaseInitializer()
{
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "MyPassword"); // Use your MySQL credentials
	con->setSchema("library_db");

	createDatabase();
	createTables();
}

DatabaseInitializer::~DatabaseInitializer()
{
	clearData();
	delete con;
}

void DatabaseInitializer::createDatabase() const
{
	Statement* stmt = con->createStatement();
	stmt->execute("CREATE DATABASE IF NOT EXISTS library_db");
	stmt->execute("USE library_db");
	delete stmt;
}

void DatabaseInitializer::createTables() const
{
	Statement* stmt = con->createStatement();

	stmt->execute("CREATE TABLE IF NOT EXISTS Authors ("
		"id INT AUTO_INCREMENT PRIMARY KEY, "
		"name VARCHAR(255) NOT NULL)");

	stmt->execute("CREATE TABLE IF NOT EXISTS Books ("
		"id INT AUTO_INCREMENT PRIMARY KEY, "
		"title VARCHAR(255) NOT NULL, "
		"author_id INT, "
		"genre VARCHAR(50), "
		"year_published INT, "
		"FOREIGN KEY (author_id) REFERENCES Authors(id))");

	stmt->execute("CREATE TABLE IF NOT EXISTS Users ("
		"id INT AUTO_INCREMENT PRIMARY KEY, "
		"name VARCHAR(255) NOT NULL, "
		"membership_date DATE)");

	stmt->execute("CREATE TABLE IF NOT EXISTS BorrowRecords ("
		"id INT AUTO_INCREMENT PRIMARY KEY, "
		"user_id INT, "
		"book_id INT, "
		"borrow_date DATE, "
		"return_date DATE, "
		"FOREIGN KEY (user_id) REFERENCES Users(id), "
		"FOREIGN KEY (book_id) REFERENCES Books(id))");

	delete stmt;
}

void DatabaseInitializer::clearData() const
{
	Statement* stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS BorrowRecords");
	stmt->execute("DROP TABLE IF EXISTS Users");
	stmt->execute("DROP TABLE IF EXISTS Books");
	stmt->execute("DROP TABLE IF EXISTS Authors");
	delete stmt;
}
