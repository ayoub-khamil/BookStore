#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBook.h"

class clsDeleteBookScreen : protected clsScreen
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

	static void _DeleteBook()
	{
		DrawScreenHeader("\t\t\tDeleting a book.");

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
		_PrintBookInfo(BookFound, "Selected Book Info.");
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to delete this book?");

		if (Confirm)
		{
			if (BookFound->DeleteBook())
			{
				cout << Setw(35) << "Book Deleted Successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Couldn't delete Book!\n";
			}
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}

	}

	static void _DeleteBook_AuthorMode(string BookId)
	{
		DrawScreenHeader("\t\t\tDeleting a book.");

		vector <clsBook> vBooks = clsBook::GetBooksList();

		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);
		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		cout << "\n";
		_PrintBookInfo(BookFound, "Selected Book Info.");
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to delete this book?");

		if (Confirm)
		{
			if (BookFound->DeleteBook())
			{
				cout << Setw(35) << "Book Deleted Successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Couldn't delete Book!\n";
			}
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}

	}

public:
	static void DeleteBook(bool AuthorMode = false, string BookId = "")
	{
		if (!AuthorMode)
			_DeleteBook();
		else
			_DeleteBook_AuthorMode(BookId);
	}

};

