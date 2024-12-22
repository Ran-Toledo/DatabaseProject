#include "CBorrowedRecord.h"

BorrowRecord::BorrowRecord(const int id, const int user_id, const int book_id, std::string borrow_date, std::string return_date):
	id(id),
	user_id(user_id),
	book_id(book_id),
	borrow_date(std::move(borrow_date)),
	return_date(std::move(return_date))
{
}
