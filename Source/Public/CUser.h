#pragma once

#include <string>

class User {
public:
    int id;
    std::string name;
    std::string membership_date;

    User(const int id, std::string name, std::string& membership_date);

    void save_to_db(); // Method to save user to database
    //static User find_by_id(int id); // Method to retrieve user by ID
    static void delete_from_db(int id); // Method to delete user from database
};
