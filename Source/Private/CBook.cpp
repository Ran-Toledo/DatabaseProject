#include "CBook.h"

Book::Book(const int id, std::string title, const int author_id, std::string genre, const int year_published):
	id(id),
	title(std::move(title)),
	author_id(author_id),
	genre(std::move(genre)),
	year_published(year_published)
{
}

void Book::save_to_db()
{
}

// Book Book::find_by_id(int id)
// {
// }

void Book::delete_from_db(int id)
{
}
