#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInput.h"
#include "clsUtil.h"

class clsFindUserScreen : protected clsScreen
{
private: 
	static string _ReadUserId()
	{
		cout << Setw(35) << "Enter the Id        : ";
		string Id = clsInput::ReadString();
		return Id;
	}

	static void _PrintUserInfo(clsUser* User, string Message)
	{
		cout << Setw(35) << "\t\t\t" << Message << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
		cout << Setw(35) << "\t\t User ID      : " << User->GetId() << "\n";
		cout << Setw(35) << "\t\t Password     : " << User->Password << "\n";
		cout << Setw(35) << "\t\t First Name   : " << User->FirstName << "\n";
		cout << Setw(35) << "\t\t Last  Name   : " << User->LastName << "\n";
		cout << Setw(35) << "\t\t Age          : " << User->Age << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
	}

	static void _FindUserScreen()
	{
		DrawScreenHeader("\t\t\tFind User.");

		string UserId = _ReadUserId();

		vector <clsUser> vUsers = clsUser::GetUsersList();

		clsUser* UserFound = clsUser::FindUser(vUsers, UserId);
		if (UserFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No User Found under the Id " << UserId << "!\n";
			return;
		}

		cout << "\n";
		_PrintUserInfo(UserFound, "   User Info.");
		cout << "\n";
	}

public: 
	static void FindUserScreen()
	{
		_FindUserScreen();
	}

};

