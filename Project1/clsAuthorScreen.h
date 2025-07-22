#pragma once

#include "clsAddNewBookScreen.h"
#include "clsUpdateBookScreen.h"
#include "clsFindBookScreen.h"
#include "clsDeleteBookScreen.h"
#include "clsBooksListScreen.h"
#include "clsBookTotalSalesScreen.h"
#include "clsBookAverageRatingScreen.h"
#include "clsBookCommentsScreen.h"

#include <iostream>
#include <Windows.h>
#include "clsBook.h"
#include "clsAuthor.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInput.h"
using namespace std; 

class clsAuthorScreen : protected clsScreen
{
private: 
	string _AuthorName; 

	static string _ReadBookId()
	{
		cout << Setw(35) << "Enter the Book's id : ";
		string BookId = clsInput::ReadString();
		return BookId;
	}

	bool ValidateBookOwnership(string& outBookId)
	{
		string Id = _ReadBookId();

		vector <clsBook> vBooks = clsBook::GetBooksList();
		clsBook* BookFound = clsBook::FindBook(vBooks, Id);

		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "\t\tNo Book found under the Id " << Id << "!\n";
			cout << "\n";
			return false;
		}

		if (!BookFound->IsOwnedBy(this->_AuthorName))
		{
			cout << "\n";
			cout << Setw(35) << "\t\tYou Don't own this book!\n";
			cout << "\n";
			return false; 
		}
		
		outBookId = BookFound->Id;
		return true;
	}

	enum enMainMenuOption
	{
		Exit = 0,
		PublishNewBook = 1,
		FindBook = 2,
		DeleteABook = 3,
		UpdateABook = 4,
		DisplayAllBooks = 5,
		FindBookTotalSales = 6,
		FindBookAverageRating = 7,
		FindBookComments = 8,
	};
	enMainMenuOption _ReadMainMenuOption()
	{
		cout << Setw(40) << "Choose your option -->";
		short Number = clsInput::readIntInRange(0, 8);
		return (enMainMenuOption)Number;
	}
	void _PerformMainMenuOption(enMainMenuOption Option, bool& ExitMenu)
	{
		switch (Option)
		{
		case enMainMenuOption::PublishNewBook:
			system("cls");
			_PublishNewBookScreen();
			break;

		case enMainMenuOption::FindBook:
			system("cls");
			_FindBookScreen();
			break;

		case enMainMenuOption::DeleteABook:
			system("cls");
			_DeleteBookScreen();
			break;

		case enMainMenuOption::UpdateABook:
			system("cls");
			_UpdateBookScreen();
			break;

		case enMainMenuOption::DisplayAllBooks:
			system("cls");
			_BooksListScreen();
			break;

		case enMainMenuOption::FindBookTotalSales:
			system("cls");
			_BookTotalSalesScreen();
			break;

		case enMainMenuOption::FindBookAverageRating:
			system("cls");
			_BookAverageRatingScreen();
			break;

		case enMainMenuOption::FindBookComments:
			system("cls");
			_BookCommentsScreen();
			break;

		case enMainMenuOption::Exit:
			system("cls");
			DrawScreenHeader("\t\t\tBook Manager");

			cout << "\n\n";
			cout << Setw(35) << "\t\t\t Exiting...\n";

			Sleep(1500); // miliseconds
			ExitMenu = true;
			return;

		default:
			system("cls");
			break;
		}

		cout << Setw(35) << "Press any key to continue...";
		system("pause>0");
	}

	void _PublishNewBookScreen()
	{
		DrawScreenHeader("\t\t\Adding a Book.");

		system("cls");
		clsAddNewBookScreen::AddBook(true, this->_AuthorName);
		
	}
	void _FindBookScreen()
	{
		DrawScreenHeader("\t\t\tFinding a Book.");

		string BookId;
		bool IsOwnedByAuthor = ValidateBookOwnership(BookId);

		if (IsOwnedByAuthor)
		{
			system("cls");
			clsFindBookScreen::FindBook(true, BookId);
		}
	}
	void _UpdateBookScreen()
	{
		DrawScreenHeader("\t\t\tUpdating a Book.");

		string BookId;
		bool IsOwnedByAuthor = ValidateBookOwnership(BookId);

		if (IsOwnedByAuthor)
		{
			system("cls");
			clsUpdateBookScreen::UpdateBook(true, BookId);
		}
	}
	void _DeleteBookScreen()
	{
		DrawScreenHeader("\t\t\tDeleting a Book.");

		string BookId;
		bool IsOwnedByAuthor = ValidateBookOwnership(BookId);

		if (IsOwnedByAuthor)
		{
			system("cls");
			clsDeleteBookScreen::DeleteBook(true, BookId);
		}
	}
	void _BooksListScreen()
	{
		clsBooksListScreen::PrintBooksList(true, false, this->_AuthorName);
	}
	void _BookTotalSalesScreen()
	{
		DrawScreenHeader("\t\t\tBook Total Sales.");

		string BookId;
		bool IsOwnedByAuthor = ValidateBookOwnership(BookId);

		if (IsOwnedByAuthor)
		{
			system("cls");
			clsBookTotalSalesScreen::PrintBookTotalSalesScreen(true, BookId);
		}
	}
	void _BookAverageRatingScreen()
	{
		DrawScreenHeader("\t\t\tBook Average Rating.");

		string BookId;
		bool IsOwnedByAuthor = ValidateBookOwnership(BookId);

		if (IsOwnedByAuthor)
		{
			system("cls");
			clsBookAverageRatingScreen::PrintBookAverageRatingScreen(true, BookId);
		}
	}
	void _BookCommentsScreen()
	{
		DrawScreenHeader("\t\t\tBook Comments.");

		string BookId;
		bool IsOwnedByAuthor = ValidateBookOwnership(BookId);

		if (IsOwnedByAuthor)
		{
			system("cls");
			clsBookCommentsScreen::PrintCommentsScreen(true, BookId);
		}
	}

	void _PrintMainMenuScreen()
	{
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|         ++++     Books Manager     ++++        |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|        [1]  Publish New  Book.                 |\n";
		cout << clsScreen::Setw(40) << "|        [2]  Find   a Book.                     |\n";
		cout << clsScreen::Setw(40) << "|        [3]  Delete a Book.                     |\n";
		cout << clsScreen::Setw(40) << "|        [4]  Update a Book.                     |\n";
		cout << clsScreen::Setw(40) << "|        [5]  Display All Books.                 |\n";
		cout << clsScreen::Setw(40) << "|        [6]  Find a Book's Total Sales.         |\n";
		cout << clsScreen::Setw(40) << "|        [7]  Find a Book's Average Rating.      |\n";
		cout << clsScreen::Setw(40) << "|        [8]  Find a Book's Comments.            |\n";
		cout << clsScreen::Setw(40) << "|        [0]  Exit.                              |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
	}
	void _StartBookManager()
	{
		bool ExitMenu = false;

		while (!ExitMenu)
		{
			system("cls");
			string WelcomeMessage = "\t\t\tWelcome Mr/Ms. " + this->_AuthorName; 
			clsScreen::DrawScreenHeader("\t\t\tBooks Manager", WelcomeMessage);
			_PrintMainMenuScreen();

			enMainMenuOption Option = _ReadMainMenuOption();
			_PerformMainMenuOption(Option, ExitMenu);
		}
	}

public: 
	clsAuthorScreen(string AuthorName)
	{
		this->_AuthorName = AuthorName;
	}

	void Start()
	{
		_StartBookManager();
	}

};

