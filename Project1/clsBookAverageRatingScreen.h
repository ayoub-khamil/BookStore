#pragma once

#include "clsScreen.h"
#include "clsBook.h"
#include <iostream>
using namespace std; 

class clsBookAverageRatingScreen : protected clsScreen
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

	static void _PrintBookAverageRating(clsBook* Book)
	{
		if (Book->RatingsCount < 1)
		{
			cout << Setw(35) << "\t\t\tNo Ratings made yet!\n";
			return;
		}

		cout << Setw(35) << "\t\tTotal Ratings  : " << Book->RatingsCount << "\n";
		cout << Setw(35) << "\t\tAverage Rating : " << Book->GetAverageRating() << "\n";
	}

	static void _PrintBookAverageRatingScreen()
	{
		DrawScreenHeader("\t\t\tBook Average Rating");

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
		_PrintBookInfo(BookFound, "Book Info.");
		cout << "\n";
		_PrintBookAverageRating(BookFound);
		cout << "\n";

	}

	static void _PrintBookAverageRatingScreen_AuthorMode(string BookId)
	{
		DrawScreenHeader("\t\t\tBook Average Rating");

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
		_PrintBookAverageRating(BookFound);
		cout << "\n";
	}

public: 
	static void PrintBookAverageRatingScreen(bool AuthorMode = false, string BookId = "")
	{
		if (!AuthorMode)
			_PrintBookAverageRatingScreen();
		else
			_PrintBookAverageRatingScreen_AuthorMode(BookId);
	}

};

