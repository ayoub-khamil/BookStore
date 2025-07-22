#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "clsInput.h"

class clsUpdateUserScreen : protected clsScreen
{
private: 
	static string _ReadUserId()
	{
		cout << Setw(35) << "Enter the Id        : ";
		string Id = clsInput::ReadString();
		return Id;
	}

	static clsUser _ReadUpdatedUserInfo(string OriginalId)
	{
		cout << Setw(35) << "Enter the password    : ";
		string Password = clsInput::ReadString();

		cout << Setw(35) << "Enter First Name      : ";
		string FirstName = clsInput::ReadString();

		cout << Setw(35) << "Enter Last Name       : ";
		string LastName = clsInput::ReadString();

		cout << Setw(35) << "Enter the Age (5 - 95): ";
		int Age = clsInput::readIntInRange(5, 95);

		return clsUser(OriginalId, Password, FirstName, LastName, Age);
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

	static void _UpdateUserScreen()
	{
		DrawScreenHeader("\t\t\tUpdate User");

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
		_PrintUserInfo(UserFound, "Original Info.");
		cout << "\n";

		cout << Setw(35) << "\t\t\tEnter the New Info\n";
		*UserFound = _ReadUpdatedUserInfo(UserFound->GetId());
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to update this User?");

		if (Confirm)
		{
			if (UserFound->UpdateUser())
			{
				cout << Setw(35) << "User Updated Successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Couldn't update User!\n";
			}
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}
	}

public:
	static void UpdateUserScreen()
	{
		_UpdateUserScreen();
	}

};

