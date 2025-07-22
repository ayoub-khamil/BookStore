#pragma once

#include "clsScreen.h"
#include "clsBook.h"
#include <iostream>
#include <vector>
using namespace std; 

class clsBookTotalSalesScreen : protected clsScreen
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
		cout << Setw(35) << "\t\t___________________________________\n";
	}
	
	static void _PrintBookTotalSales(clsBook* Book)
	{
		if (Book->SoldQuantity < 1)
		{
			cout << Setw(35) << "\t\t\tNo Copies sold yet!\n";
			return;
		}

		cout << Setw(35) << "\t\tCopies Sold   : " << Book->SoldQuantity << ".\n";
		cout << Setw(35) << "\t\tTotal Revenue : " << Book->GetTotalRevenue() << "$\n";
	}

	static void _PrintBookTotalSalesScreen()
	{
		DrawScreenHeader("\t\t\tBook Total Sales. ");

		string BookId = _ReadBookId();

		vector <clsBook> vBooks = clsBook::GetBooksList();
		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);

		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		cout << "\n";
		_PrintBookInfo(BookFound, "Book Info");
		cout << "\n";
		_PrintBookTotalSales(BookFound);
		cout << "\n";
		
	}

	static void _PrintBookTotalSalesScreen_AuthorMode(string BookId)
	{
		DrawScreenHeader("\t\t\tBook Total Sales. ");

		vector <clsBook> vBooks = clsBook::GetBooksList();
		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);

		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		cout << "\n";
		_PrintBookInfo(BookFound, "Book Info");
		cout << "\n";
		_PrintBookTotalSales(BookFound);
		cout << "\n";
	}

public:
	static void PrintBookTotalSalesScreen(bool AuthorMode = false, string BookId = "")
	{
		if (!AuthorMode)
			_PrintBookTotalSalesScreen();
		else
			_PrintBookTotalSalesScreen_AuthorMode(BookId);
	}
};

