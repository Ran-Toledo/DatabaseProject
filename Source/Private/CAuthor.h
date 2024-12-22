#pragma once
#include <string>

class Author
{
public:
    int id;
    std::string name;

    Author(const int id, std::string name);

    void save_to_db(); // Method to save author to database
    //static Author find_by_id(int id); // Method to retrieve author by ID
    static void delete_from_db(int id); // Method to delete author from database
};
