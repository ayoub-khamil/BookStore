#pragma once

#include <iostream>
#include <Windows.h>
#include "clsScreen.h"
#include "clsBook.h"

#include "clsAdminScreen.h"
#include "clsAuthorScreen.h"
#include "clsUserScreen.h"

#include "clsAdminAccount.h"
#include "clsAuthor.h"
#include "clsUser.h"

class clsLogin : protected clsScreen
{
private: 
	class stCredentials
	{
	public:

		string _Id; 
		string _Password;

		stCredentials(string Id, string Password)
		{
			this->_Id = Id; 
			this->_Password = Password; 
		}

		static stCredentials ReadCredentials()
		{
			cout << Setw(35) << "\t\tId       : ";
			string Id = clsInput::ReadString();

			cout << Setw(35) << "\t\tPassword : ";
			string Password = clsInput::ReadString();
			return stCredentials(Id, Password);
		}

		bool AreValid(string Id, string Password)
		{
			return (Id == this->_Id && Password == this->_Password);
		}
	};

	enum enAccountType
	{
		Exit = 0,
		Admin = 1,
		Author = 2,
		User = 3
	};
	enAccountType _ReadAccountType()
	{
		cout << Setw(35) << "\t\t\t--> ";
		short Option = clsInput::readIntInRange(0, 3);
		return (enAccountType)Option;
	}
	void _LaunchAccountManager(enAccountType Type, bool& ExitMenu)
	{
		switch (Type)
		{
		case enAccountType::Admin:
			system("cls");
			_LaunchAdminPage();
			break;

		case enAccountType::Author:
			system("cls");
			_LaunchAuthorPage();
			break;

		case enAccountType::User:
			system("cls");
			_LaunchUserPage();
			break;

		case enAccountType::Exit:
			system("cls");
			DrawScreenHeader("\t\t\tBook Store.");

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
	
	void _Login()
	{
		bool ExitMenu = false; 

		while (!ExitMenu)
		{
			system("cls");
			DrawScreenHeader("\t\t\tLogin Screen.");
			_DrawLoginScreenMenu();
			
			enAccountType Type = _ReadAccountType();
			_LaunchAccountManager(Type, ExitMenu);
		}

	}
	void _DrawLoginScreenMenu()
	{
		cout << "\n";
		cout << Setw(35) << "     Admin [1]    Author [2]    User [3]    Exit[0]\n\n";
		cout << Setw(35) << "\t\t Choose Your Account Type!\n";
	}

	void _LaunchAdminPage()
	{
		bool InvalidCR = false;

		while (true)
		{
			system("cls");
			DrawScreenHeader("\t\t\tLogin Screen.");
			cout << "\n";

			if (InvalidCR)
			{
				cout << Setw(35) << "\t\t  Invalid Id or Password!\n\n";
				Sleep(1500); 
			}

			clsAdminAccount::stAdmin Admin = clsAdminAccount::GetAdminAccount();
			stCredentials CR = stCredentials::ReadCredentials();

			if (CR.AreValid(Admin._Id, Admin._Password))
			{
				InvalidCR = false; 

				clsAdminScreen Admin;

				Admin.Start();

				break; // from outer loop
			}
			else
			{
				InvalidCR = true; 
			}
		}



	}
	void _LaunchAuthorPage()
	{
		bool InvalidCR = false;

		while (true)
		{
			system("cls");
			DrawScreenHeader("\t\t\tLogin Screen.");
			cout << "\n";

			if (InvalidCR)
			{
				cout << Setw(35) << "\t\t  Invalid Id or Password!\n\n";
				Sleep(1500);
			}

			vector <clsAuthor> vAuthors = clsAuthor::GetAuthorsList();

			if (vAuthors.size() < 1)
			{
				cout << Setw(35) << "\t\t\tNo Authors Added Yet!\n"; 
				Sleep(2000);
				break;
			}

			stCredentials CR = stCredentials::ReadCredentials();
			clsAuthor* Author = clsAuthor::FindAuthor(vAuthors, CR._Id, CR._Password);

			if (Author != nullptr)
			{
				InvalidCR = false;

				clsAuthorScreen AuthorScreen(Author->FirstName);
				AuthorScreen.Start();

				break; // from outer loop
			}
			else
			{
				InvalidCR = true;
			}
		}
	}
	void _LaunchUserPage()
	{
		bool InvalidCR = false;

		while (true)
		{
			system("cls");
			DrawScreenHeader("\t\t\tLogin Screen.");
			cout << "\n";

			if (InvalidCR)
			{
				cout << Setw(35) << "\t\t  Invalid Id or Password!\n\n";
				Sleep(1500);
			}

			vector <clsUser> vUsers = clsUser::GetUsersList();

			if (vUsers.size() < 1)
			{
				cout << Setw(35) << "\t\t\tNo Users Added Yet!\n";
				Sleep(2000);
				break;
			}

			stCredentials CR = stCredentials::ReadCredentials();
			clsUser* User = clsUser::FindUser(vUsers, CR._Id, CR._Password);

			if (User != nullptr)
			{
				InvalidCR = false;

				clsUserScreen UserScreen(User->GetId());
				UserScreen.Start();

				break; // from outer loop
			}
			else
			{
				InvalidCR = true;
			}
		}
	}

public: 
	void Start()
	{
		_Login();
	}

};

