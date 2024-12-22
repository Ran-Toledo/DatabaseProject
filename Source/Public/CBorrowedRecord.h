#pragma once

#include <string>

class BorrowRecord {
public:
    int id;
    int user_id;
    int book_id;
    std::string borrow_date;
    std::string return_date;

    BorrowRecord(const int id, const int user_id, const int book_id, std::string borrow_date, std::string return_date);

    void save_to_db(); // Method to save borrow record to database
    static BorrowRecord find_by_id(int id); // Method to retrieve borrow record by ID
    static void delete_from_db(int id); // Method to delete borrow record from database
};
