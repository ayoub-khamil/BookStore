#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInput.h"

#include "clsBooksManager.h"
#include "clsUsersManager.h"
#include "clsAuthorsManager.h"

class clsAdminScreen : protected clsScreen
{
private: 

	enum enOption
	{
		ManageBooks = 1,
		ManageAuthors = 2,
		ManageUsers = 3,
		Exit = 4
	};
	enOption _ReadOption()
	{
		cout << Setw(35) << "Choose an action -->";
		short Option = clsInput::readIntInRange(1, 4);
		return (enOption)Option;
	}
	void _PerformAdminMenuOption(enOption Option, bool& ExitMenu)
	{

		switch (Option)
		{
		case enOption::ManageBooks:
			_ManageBooksScreen();
			system("cls");
			break;

		case enOption::ManageAuthors:
			_ManageAuthorsScreen();
			system("cls");
			break;

		case enOption::ManageUsers:
			_ManageUsersScreen();
			system("cls");
			break;

		case enOption::Exit:
			system("cls");
			DrawScreenHeader("\t\t\tAdmin Page");

			cout << "\n\n";
			cout << Setw(35) << "\t\t\t Exiting...\n";

			Sleep(1500); // miliseconds
			ExitMenu = true;
			return;

		default:
			break;
		}
	}

	void _PrintAdminMainMenu()
	{
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|                   Admin Page.                  |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|          [1]  Manage Books.                    |\n";
		cout << clsScreen::Setw(40) << "|          [2]  Manage Authors.                  |\n";
		cout << clsScreen::Setw(40) << "|          [3]  Manage Users.                    |\n";
		cout << clsScreen::Setw(40) << "|          [4]  Exit.                            |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
	}

	void _StartAdminPage()
	{
		bool ExitMenu = false; 

		while (!ExitMenu)
		{
			system("cls");
			DrawScreenHeader("\t\t\tManage Library.");

			_PrintAdminMainMenu();

			enOption Option = _ReadOption();
			_PerformAdminMenuOption(Option, ExitMenu);
		}
	}

	void _ManageBooksScreen()
	{
		clsBooksManager Manager; 
		Manager.Start();
	}
	void _ManageAuthorsScreen()
	{
		clsAuthorsManager Manager;
		Manager.Start();
	}
	void _ManageUsersScreen()
	{
		clsUsersManager Manager;
		Manager.Start();
	}

public: 
	void Start()
	{
		_StartAdminPage();
	}

};

