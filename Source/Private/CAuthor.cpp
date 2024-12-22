#include "CAuthor.h"

Author::Author(const int id, std::string name):
	id(id),
	name(std::move(name))
{
}

void Author::save_to_db()
{
}

// Author Author::find_by_id(int id)
// {
// }

void Author::delete_from_db(int id)
{
}
