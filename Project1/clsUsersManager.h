#pragma once

#include "clsAddNewUserScreen.h"
#include "clsUsersListScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsDeleteUserScreen.h"

#include <iostream>
#include <Windows.h>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "clsInput.h"

class clsUsersManager : protected clsScreen
{
private: 
	short _GetUsersAmount()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();
		return vUsers.size();
	}

	enum enOption
	{
		Exit = 0,
		AddUser = 1,
		FindUser = 2,
		UpdateUser = 3,
		DeleteUser = 4,
		DisplayUsersList = 5,
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
		case enOption::AddUser:
			system("cls");
			_ShowAddNewUserScreen();
			break;

		case enOption::FindUser:
			system("cls");
			_ShowFindUserScreen();
			break;

		case enOption::UpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			break;

		case enOption::DeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			break;

		case enOption::DisplayUsersList:
			system("cls");
			_ShowDisplayUsersScreen();
			break;

		case enOption::Exit:
			system("cls");
			DrawScreenHeader("\t\t\tUsers Manager");

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

	void _PrintUsersMainMenu()
	{
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|                 Users Manager                  |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
		cout << clsScreen::Setw(40) << "|          [1]  Add    a New User.               |\n";
		cout << clsScreen::Setw(40) << "|          [2]  Find   a User.                   |\n";
		cout << clsScreen::Setw(40) << "|          [3]  Update a User.                   |\n";
		cout << clsScreen::Setw(40) << "|          [4]  Delete a User.                   |\n";
		cout << clsScreen::Setw(40) << "|          [5]  Display All Users.               |\n";
		cout << clsScreen::Setw(40) << "|          [0]  Exit.                            |\n";
		cout << clsScreen::Setw(40) << "==================================================\n";
	}
	void _StartUsersManager()
	{
		bool ExitMenu = false;

		while (!ExitMenu)
		{
			system("cls");
			DrawScreenHeader("\t\t\tUsers Manager.", ("\t\t\tUsers Amount : " + to_string(_GetUsersAmount())));

			_PrintUsersMainMenu();

			enOption Option = _ReadOption();
			_PerformMainMenuOption(Option, ExitMenu);
		}
	}

	void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::AddNewUserScreen();
	}
	void _ShowFindUserScreen()
	{
		clsFindUserScreen::FindUserScreen();
	}
	void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::UpdateUserScreen();
	}
	void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::DeleteUserScreen();
	}
	void _ShowDisplayUsersScreen()
	{
		clsUsersListScreen::PrintUsersList();
	}

public:
	void Start()
	{
		_StartUsersManager();
	}
};