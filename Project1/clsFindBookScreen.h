#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBook.h"
using namespace std; 

class clsFindBookScreen : protected clsScreen
{
private:
	static string _ReadBookId()
	{
		cout << Setw(35) << "Enter the Book's id : ";
		string BookId = clsInput::ReadString();
		return BookId;
	}

	static void _PrintBookInfo(clsBook* Book, string Message)
	{
		cout << Setw(35) << "\t\t\t" << Message << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
		cout << Setw(35) << "\t\tId            : " << Book->Id << "\n";
		cout << Setw(35) << "\t\tTitle         : " << Book->Title << "\n";
		cout << Setw(35) << "\t\tAuthor        : " << Book->Author << "\n";
		cout << Setw(35) << "\t\tCategory      : " << Book->Category << "\n";
		cout << Setw(35) << "\t\tQuantity      : " << Book->Quantity << "\n";
		cout << Setw(35) << "\t\tSold Quantity : " << Book->SoldQuantity << "\n";
		cout << Setw(35) << "\t\tAverage Rating: " << Book->GetAverageRating() << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
	}

	static void _FindBook()
	{
		DrawScreenHeader("\t\t\tSearching For a Book");

		vector <clsBook> vBooks = clsBook::GetBooksList();

		string BookId = _ReadBookId();

		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);
		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		cout << "\n";
		_PrintBookInfo(BookFound, "Book Info.");
		cout << "\n";
	}

	static void _FindBook_AuthorMode(string BookId)
	{
		DrawScreenHeader("\t\t\tSearching For a Book");

		vector <clsBook> vBooks = clsBook::GetBooksList();

		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);
		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		cout << "\n";
		_PrintBookInfo(BookFound, "Book Info.");
		cout << "\n";
	}

public:
	static void FindBook(bool AuthorMode = false, string BookId = "")
	{
		if (!AuthorMode)
			_FindBook();
		else
			_FindBook_AuthorMode(BookId);
	}
};

