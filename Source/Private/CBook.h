#pragma once
#include <string>

class Book {
public:
    int id;
    std::string title;
    int author_id;
    std::string genre;
    int year_published;

    Book(const int id, std::string title, const int author_id, std::string genre, const int year_published);

    void save_to_db(); // Method to save book to database
    //static Book find_by_id(int id); // Method to retrieve book by ID
    static void delete_from_db(int id); // Method to delete book from database
};
