#pragma once

#include "clsAddNewBookScreen.h"
#include "clsUpdateBookScreen.h"
#include "clsFindBookScreen.h"
#include "clsDeleteBookScreen.h"
#include "clsBooksListScreen.h"
#include "clsBookTotalSalesScreen.h"
#include "clsBookAverageRatingScreen.h"
#include "clsBestSellingBooksScreen.h"
#include "clsHighestRatedBooksScreen.h"
#include "clsBookCommentsScreen.h"

#include "clsInput.h"
#include "clsScreen.h"
#include "Windows.h" // for Sleep()
#include <iostream>
using namespace std; 

class clsBooksManager : protected clsScreen
{
private: 
	short _GetBooksAmount()
	{
		vector <clsBook> vBooks = clsBook::GetBooksList();
		return vBooks.size();
	}

	enum enMainMenuOption
	{
		Exit = 0,
		AddNewBook = 1,
		FindBook = 2,
		DeleteABook = 3,
		UpdateABook = 4,
		DisplayAllBooks = 5,
		FindBookTotalSales = 6,
		FindBookAverageRating = 7,
		FindBookComments = 8,
		DisplayBestSellingBooks = 9,
		DisplayHighestRatedBooks = 10
	};
	enMainMenuOption _ReadMainMenuOption()
	{
		cout << Setw(40) << "Choose your option -->";
		short Number = clsInput::readIntInRange(0, 10);
		return (enMainMenuOption)Number;
	}
	void _PerformMainMenuOption(enMainMenuOption Option, bool& ExitMenu)
	{
		switch (Option)
		{
		case enMainMenuOption::AddNewBook:
			system("cls");
			_ShowAddNewBookScreen();
			break;

		case enMainMenuOption::FindBook:
			system("cls");
			_ShowFindBookScreen();
			break;

		case enMainMenuOption::DeleteABook:
			system("cls");
			_ShowDeleteBookScreen();
			break;

		case enMainMenuOption::UpdateABook:
			system("cls");
			_ShowUpdateBookScreen();
			break;

		case enMainMenuOption::DisplayAllBooks:
			system("cls");
			_ShowBooksListScreen();
			break;

		case enMainMenuOption::FindBookTotalSales:
			system("cls");
			_ShowBookTotalSalesScreen();
			break;

		case enMainMenuOption::FindBookAverageRating:
			system("cls");
			_ShowBookAverageRatingScreen();
			break;

		case enMainMenuOption::FindBookComments:
			system("cls");
			_ShowBookCommentsScreen();
			break;

		case enMainMenuOption::DisplayBestSellingBooks:
			system("cls");
			_ShowBestSellingBooksScreen();
			break;

		case enMainMenuOption::DisplayHighestRatedBooks:
			system("cls");
			_ShowHighestRatedBooksScreen();
			break;

		case enMainMenuOption::Exit:
			system("cls");
			DrawScreenHeader("\t\t\tBook Store");

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

	void _PrintMainMenuScreen()
	{
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|                  Books Manager                 |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|        [1]  Add New  Book.                     |\n";
		cout << clsScreen::Setw(40) << "|        [2]  Find   a Book.                     |\n";
		cout << clsScreen::Setw(40) << "|        [3]  Delete a Book.                     |\n";
		cout << clsScreen::Setw(40) << "|        [4]  Update a Book.                     |\n";
		cout << clsScreen::Setw(40) << "|        [5]  Display All Books.                 |\n";
		cout << clsScreen::Setw(40) << "|        [6]  Find a Book's Total Sales.         |\n";
		cout << clsScreen::Setw(40) << "|        [7]  Find a Book's Average Rating.      |\n";
		cout << clsScreen::Setw(40) << "|        [8]  Find a Book's Comments.            |\n";
		cout << clsScreen::Setw(40) << "|        [9]  Display Best Selling Books.        |\n";
		cout << clsScreen::Setw(40) << "|        [10] Display Highest Rated Books.       |\n";
		cout << clsScreen::Setw(40) << "|        [0]  Exit.                              |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
	}
	void _StartBookManager()
	{
		bool ExitMenu = false; 

		while (!ExitMenu)
		{
			system("cls");
			clsScreen::DrawScreenHeader("\t\t\tBooks Manager", ("\t\t\tBooks Amount : " + to_string(_GetBooksAmount())));
			_PrintMainMenuScreen();
			
			enMainMenuOption Option = _ReadMainMenuOption();
			_PerformMainMenuOption(Option, ExitMenu);
		}
	}

	// operations 
	void _ShowAddNewBookScreen()
	{
		clsAddNewBookScreen::AddBook();
	}
	void _ShowFindBookScreen()
	{
		clsFindBookScreen::FindBook();
	}
	void _ShowUpdateBookScreen()
	{
		clsUpdateBookScreen::UpdateBook();
	}
	void _ShowDeleteBookScreen()
	{
		clsDeleteBookScreen::DeleteBook();
	}
	void _ShowBooksListScreen()
	{
		clsBooksListScreen::PrintBooksList();
	}
	void _ShowBookTotalSalesScreen()
	{
		clsBookTotalSalesScreen::PrintBookTotalSalesScreen();
	}
	void _ShowBookAverageRatingScreen()
	{
		clsBookAverageRatingScreen::PrintBookAverageRatingScreen();
	}
	void _ShowBookCommentsScreen()
	{
		clsBookCommentsScreen::PrintCommentsScreen();
	}
	void _ShowBestSellingBooksScreen()
	{
		clsBestSellingBooksScreen::PrintBestSellingBooksScreen();
	}
	void _ShowHighestRatedBooksScreen()
	{
		clsHighestRatedBooksScreen::PrintHighestRatedBooksScreen();
	}

public: 
	void Start()
	{
		_StartBookManager();
	}
};

