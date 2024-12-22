#include "CUser.h"

User::User(const int id, std::string name, std::string& membership_date):
	id(id),
	name(std::move(name)),
	membership_date(std::move(membership_date))
{
}

void User::save_to_db()
{
}

// User User::find_by_id(int id)
// {
// }

void User::delete_from_db(int id)
{
}
