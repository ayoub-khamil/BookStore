#pragma once

#include "clsAddNewAuthorScreen.h"
#include "clsUpdateAuthorScreen.h"
#include "clsDeleteAuthorScreen.h"
#include "clsFindAuthorScreen.h"
#include "clsAuthorsListScreen.h"

#include "clsInput.h"
#include "clsScreen.h"
#include "clsAuthor.h" // remove later
#include <Windows.h> // For Sleep()
#include <iostream>

class clsAuthorsManager : protected clsScreen
{
private:
	short _GetAuthorsAmount()
	{
		vector <clsAuthor> vAuthors = clsAuthor::GetAuthorsList();
		return vAuthors.size();
	}

	enum enOption
	{
		Exit = 0,
		AddAuthor = 1,
		FindAuthor = 2, 
		UpdateAuthor = 3,
		DeleteAuthor = 4,
		DisplayAuthorsList = 5, 
	};
	enOption _ReadOption()
	{
		cout << Setw(35) << "Choose an option -->";
		short Option = clsInput::readIntInRange(0, 5);
		return (enOption)Option; 
	}
	void _PerformMainMenuOption(enOption Option, bool& ExitMenu)
	{
		switch (Option)
		{
		case enOption::AddAuthor:
			system("cls");
			_ShowAddNewAuthorScreen();
			break;

		case enOption::FindAuthor:
			system("cls");
			_ShowFindAuthorScreen();
			break;

		case enOption::UpdateAuthor:
			system("cls");
			_ShowUpdateAuthorScreen();
			break;

		case enOption::DeleteAuthor:
			system("cls");
			_ShowDeleteAuthorScreen();
			break;

		case enOption::DisplayAuthorsList:
			system("cls");
			_ShowDisplayAuthorsScreen();
			break;

		case enOption::Exit:
			system("cls");
			DrawScreenHeader("\t\t\tAuthors Manager");

			cout << "\n\n";
			cout << Setw(35) << "\t\t\t   Exiting...\n";

			Sleep(1500); // miliseconds
			ExitMenu = true;
			return;

		default:
			break;
		}

		cout << Setw(35) << "Press any key to continue...";
		system("pause>0");
	}

	void _PrintAuthorsMainMenu()
	{
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|                Authors Manager                 |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|          [1]  Add   New Author.                |\n";
		cout << clsScreen::Setw(40) << "|          [2]  Find   an Author.                |\n";
		cout << clsScreen::Setw(40) << "|          [3]  Update an Author.                |\n";
		cout << clsScreen::Setw(40) << "|          [4]  Delete an Author.                |\n";
		cout << clsScreen::Setw(40) << "|          [5]  Display All Authors.             |\n";
		cout << clsScreen::Setw(40) << "|          [0]  Exit.                            |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
	}
	void _StartAuthorsManager()
	{
		bool ExitMenu = false;

		while (!ExitMenu)
		{
			system("cls");
			DrawScreenHeader("\t\t\tAuthors Manager.", ("\t\t\tAuthors Amount : " + to_string(_GetAuthorsAmount())));
		
			_PrintAuthorsMainMenu();

			enOption Option = _ReadOption();
			_PerformMainMenuOption(Option, ExitMenu);
		}
	}

	void _ShowAddNewAuthorScreen()
	{
		clsAddNewAuthorScreen::AddNewAuthorScreen();
	}
	void _ShowFindAuthorScreen()
	{
		clsFindAuthorScreen::FindAuthorScreen();
	}
	void _ShowUpdateAuthorScreen()
	{
		clsUpdateAuthorScreen::UpdateAuthorScreen();
	}
	void _ShowDeleteAuthorScreen()
	{
		clsDeleteAuthorScreen::DeleteAuthorScreen();
	}
	void _ShowDisplayAuthorsScreen()
	{
		clsAuthorsListScreen::PrintAuthorsList();
	}

public: 
	void Start()
	{
		_StartAuthorsManager();
	}
};

