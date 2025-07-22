#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBook.h"

class clsBooksListScreen : protected clsScreen
{
private:
	static void _PrintBooksListHeader()
	{
		cout << Setw(3) << "________________________________________________________________________________________________________________________________\n\n";
		cout << Setw(3) << left << setw(8) << "ID "
			<< "| " << left << setw(25) << "Title"
			<< "| " << left << setw(15) << "Author"
			<< "| " << left << setw(15) << "Category"
			<< "| " << left << setw(15) << "Price USD $"
			<< "| " << left << setw(15) << "Quantity"
			<< "| " << left << setw(15) << "Books Sold"
			<< "| " << left << setw(15) << "rating" << "\n";

		cout << Setw(3) << "________________________________________________________________________________________________________________________________\n\n";
	}
	static void _PrintBookRow(clsBook Book)
	{
		cout << Setw(3) << left << setw(8) << Book.Id
			<< "| " << left << setw(25) << Book.Title
			<< "| " << left << setw(15) << Book.Author
			<< "| " << left << setw(15) << Book.Category
			<< "| " << left << setw(15) << Book.Price
			<< "| " << left << setw(15) << Book.Quantity
			<< "| " << left << setw(15) << Book.SoldQuantity
			<< "| " << left << setw(15) << Book.GetAverageRating() << "\n";
	}
	static void _PrintBooksListFooter()
	{
		cout << Setw(3) << "________________________________________________________________________________________________________________________________\n\n";
	}
	static void _PrintBooksListTable(vector <clsBook> vBooks)
	{
		if (vBooks.size() < 1)
		{
			cout << Setw(35) << "\t\t\tNo Books Published Yet!\n";
			return;
		}

		for (const clsBook& book : vBooks)
		{
			_PrintBookRow(book);
		}

	}

	static void _PrintBooksList()
	{
		vector <clsBook> vBooks = clsBook::GetBooksList();

		DrawScreenHeader("\t\t\tBooks List.", 
			("\t\t\tBooks Amount (" + to_string(vBooks.size()) + ")."));
	
		_PrintBooksListHeader();
		_PrintBooksListTable(vBooks);
		_PrintBooksListFooter();
	}
	static void _PrintBooksList_AuthorMode(string AuthorName)
	{
		vector <clsBook> vBooks = clsBook::GetAuthorOwnedBooksList(AuthorName);

		DrawScreenHeader("\t\t\tBooks List.",
			("\t\t\tBooks Amount (" + to_string(vBooks.size()) + ")."));

		_PrintBooksListHeader();
		_PrintBooksListTable(vBooks);
		_PrintBooksListFooter();
	}
	static void _PrintBooksList_UserMode(string UserId)
	{
		vector <clsBook> vBooks = clsBook::GetUsersPurchasedBooksList(UserId);

		DrawScreenHeader("\t\t\tBooks List.",
			("\t\t\tBooks Amount (" + to_string(vBooks.size()) + ")."));

		_PrintBooksListHeader();
		_PrintBooksListTable(vBooks);
		_PrintBooksListFooter();
	}


public:
	static void PrintBooksList(bool AuthorMode = false, bool UserMode = false, string BookAuthor = "", string UserId = "")
	{
		if (!AuthorMode)
			_PrintBooksList();
		else if (AuthorMode)
			_PrintBooksList_AuthorMode(BookAuthor);
		else if (UserMode)
			_PrintBooksList_UserMode(UserId);
	}
};

