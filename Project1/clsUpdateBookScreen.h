#pragma once

#include "clsScreen.h"
#include "clsInput.h"
#include "clsUtil.h"
#include "clsBook.h"
#include <iostream>
using namespace std; 

class clsUpdateBookScreen : protected clsScreen
{
private:
	static clsBook _ReadUpdatedBookInfo(clsBook* OriginalInfo, bool SkipAuthor = false)
	{
		cout << Setw(35) << "Enter the Title    :";
		string Title = clsInput::ReadString();

		cout << Setw(35) << "Enter the Category :";
		string Category = clsInput::ReadString();

		cout << Setw(35) << "Enter the Price    :";
		float Price = clsInput::readFloatNumber();

		cout << Setw(35) << "Enter the Quantity :";
		int Quantity = clsInput::readIntNumber();
		cout << "\n";

		return clsBook(OriginalInfo->Id, Title, OriginalInfo->Author, Category
			, Price, Quantity, OriginalInfo->SoldQuantity,
			OriginalInfo->RatingsSum, OriginalInfo->RatingsCount);
	}

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
		cout << Setw(35) << "\t\t___________________________________\n";
	}

	static void _UpdateBook()
	{
		clsScreen::DrawScreenHeader("\t\t\tUpdating Book Info");
		cout << "\n";

		string BookId = _ReadBookId();

		vector <clsBook> vBooks = clsBook::GetBooksList();
		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);

		if (BookFound == nullptr)
		{
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		cout << "\n";
		_PrintBookInfo(BookFound, "Original Info.");
		cout << "\n";

		cout << Setw(35) << "\t\t\tEnter the New Info\n";
		*BookFound = _ReadUpdatedBookInfo(BookFound);

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to update this book?");

		if (Confirm)
		{
			if (BookFound->UpdateBook())
			{
				cout << Setw(35) << "Book Updated Successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Couldn't update Book!\n";
			}
			
		}
		else
		{
			cout << Setw(35) << "Operation Aborted!\n";
		}
	}

	static void _UpdateBook_AuthorMode(string BookId)
	{
		clsScreen::DrawScreenHeader("\t\t\tUpdating Book Info");
		cout << "\n";

		vector <clsBook> vBooks = clsBook::GetBooksList();
		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);

		if (BookFound == nullptr)
		{
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		cout << "\n";
		_PrintBookInfo(BookFound, "Original Info.");
		cout << "\n";

		cout << Setw(35) << "\t\t\tEnter the New Info\n";
		*BookFound = _ReadUpdatedBookInfo(BookFound);

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to update this book?");

		if (Confirm)
		{
			if (BookFound->UpdateBook())
			{
				cout << Setw(35) << "Book Updated Successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Couldn't update Book!\n";
			}

		}
		else
		{
			cout << Setw(35) << "Operation Aborted!\n";
		}
	}

public: 
	static void UpdateBook(bool AuthorMode = false, string Id = "")
	{
		if (AuthorMode && !Id.empty())
			_UpdateBook_AuthorMode(Id);
		else
			_UpdateBook();
	}
};

