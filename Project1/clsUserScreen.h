#pragma once

#include "clsPurchasedBooks.h"

#include <iostream>
#include <Windows.h> // for Sleep()
#include "clsUser.h"
#include "clsBook.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInput.h"
using namespace std; 

class clsUserScreen : protected clsScreen
{
private:
	string _UserId; 

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

	enum enOption
	{
		Exit = 0,
		PurchaseBook = 1,
		RemoveBook = 2,
		FindBook = 3,
		ListMyBooks = 4,
		ListAllBooks = 5,
		CommentABook = 6,
		DisplayBookComments = 7,
		RateBook = 8
	};
	enOption _ReadOption()
	{
		cout << Setw(35) << "\tChoose your option -->";
		short Option = clsInput::readIntInRange(0, 8);
		return (enOption)Option;
	}
	void _PerformUserMenuOption(enOption Option, bool& ExitMenu)
	{
		switch (Option)
		{
		case enOption::PurchaseBook:
			system("cls");
			_PurchaseBookScreen();
			break;

		case enOption::RemoveBook:
			system("cls");
			_RemoveBookScreen();
			break;

		case enOption::FindBook:
			system("cls");
			_FindBookScreen();
			break;

		case enOption::ListMyBooks:
			system("cls");
			_ListMyBooksScreen();
			break;

		case enOption::ListAllBooks:
			system("cls");
			_ListAllBooksScreen();
			break;

		case enOption::CommentABook:
			system("cls");
			_CommentABookScreen();
			break;

		case enOption::DisplayBookComments:
			system("cls");
			_DisplayABookCommentsScreen();
			break;

		case enOption::RateBook:
			system("cls");
			_RateABookScreen();
			break;

		case enOption::Exit:
			system("cls");
			DrawScreenHeader("\t\t\tBook Manager");

			cout << "\n\n";
			cout << Setw(35) << "\t\t\t Exiting...\n";

			Sleep(1500); // miliseconds
			ExitMenu = true;
			return;

		default:
			break;
		}

		cout << Setw(35) << "Press any key to continue...";
		system("pause>0");
	}

	void _PurchaseBookScreen()
	{
		DrawScreenHeader("\t\t\Purchasing a Book");

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

		if (clsPurchasedBooks::IsBookPurchased(this->_UserId, BookFound->Id))
		{
			cout << "\n";
			cout << Setw(35) << "\t\tYou already own this Book!\n\n";
			return;
		}

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to Purchase this book?");

		if (Confirm)
		{
			clsPurchasedBooks::AddPurchasedBook(BookFound->Id, this->_UserId);
			cout << Setw(35) << "Book Purchased Successfully!\n";
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}
	}
	void _RemoveBookScreen()
	{
		DrawScreenHeader("\t\t\Removing a Book");

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

		if (!clsPurchasedBooks::IsBookPurchased(this->_UserId, BookFound->Id))
		{
			cout << "\n";
			cout << Setw(35) << "\t\tYou don't own this Book!\n\n";
			return;
		}

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to Remove this book?");

		if (Confirm)
		{
			clsPurchasedBooks::RemovePurchasedBook(BookFound->Id, this->_UserId);
			cout << Setw(35) << "Book Removed Successfully!\n";
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}
	}
	void _FindBookScreen()
	{
		clsFindBookScreen::FindBook();
	}
	void _ListMyBooksScreen()
	{
		clsBooksListScreen::PrintBooksList(false, true, "", _UserId);
	}
	void _ListAllBooksScreen()
	{
		clsBooksListScreen::PrintBooksList();
	}
	void _CommentABookScreen()
	{
		DrawScreenHeader("\t\t\Commenting a Book");

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

		if (!clsPurchasedBooks::IsBookPurchased(this->_UserId, BookFound->Id))
		{
			cout << "\n";
			cout << Setw(35) << "\t\tYou Don't own this Book!\n\n";
			return;
		}

		cout << Setw(35) << "\t\t--+ Enter your Comment +--\n\n";

		cout << Setw(20) << "| ";
		string CommentText = clsInput::ReadString();

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to Upload this Comment?");

		if (Confirm)
		{
			clsComment Comment; 
			Comment.Read(CommentText, BookFound->Id);
			BookFound->AddComment(Comment);

			cout << Setw(35) << "Comment Added successfully!\n";
		}
		else
		{
			cout << Setw(35) << "Comment Discarded!\n";
		}
	}
	void _DisplayABookCommentsScreen()
	{
		clsBookCommentsScreen::PrintCommentsScreen();
	}
	void _RateABookScreen()
	{

	}

	void _PrintUserMenuScreen()
	{
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|         ++++      Book Store.      ++++        |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|        [1]     Purchase a book.                |\n";
		cout << clsScreen::Setw(40) << "|        [2]     Remove Purchased book.          |\n";
		cout << clsScreen::Setw(40) << "|        [3]     Find Purchased   book.          |\n";
		cout << clsScreen::Setw(40) << "|        [4]     List Purchased   books.         |\n";
		cout << clsScreen::Setw(40) << "|        [5]     List All Books.                 |\n";
		cout << clsScreen::Setw(40) << "|        [6]     Comment  Purchased Book.        |\n";
		cout << clsScreen::Setw(40) << "|        [7]     View a Book's Comments.         |\n";
		cout << clsScreen::Setw(40) << "|        [8]     Rate a Purchased Book           |\n";
		cout << clsScreen::Setw(40) << "|        [0]     Exit.                           |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
	}
	void _StartUserScreen()
	{
		bool ExitMenu = false; 

		while (!ExitMenu)
		{
			system("cls");
			string WelcomeMessage = "\t\t\tWelcome Mr/Ms. " + this->_UserId;
		
			clsScreen::DrawScreenHeader("\t\t\tBook Store.", WelcomeMessage);
			_PrintUserMenuScreen();

			enOption Option = _ReadOption();
			_PerformUserMenuOption(Option, ExitMenu);
		}
	}

public: 
	clsUserScreen(string UserId)
	{
		this->_UserId = UserId; 
	}

	void Start()
	{
		_StartUserScreen();
	}

};

