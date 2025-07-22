#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "clsInput.h"

class clsDeleteUserScreen : protected clsScreen
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

	static void _DeleteUserScreen()
	{
		DrawScreenHeader("\t\t\tDelete User.");

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
		_PrintUserInfo(UserFound, "User Info.");
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to delete this User?");

		if (Confirm)
		{
			if (UserFound->DeleteUser())
			{
				cout << Setw(35) << "User Deleted successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Failed to delete User!\n";
			}
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}
	}

public: 
	static void DeleteUserScreen()
	{
		_DeleteUserScreen();
	}

};

