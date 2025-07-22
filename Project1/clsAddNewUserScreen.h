#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "clsInput.h"

class clsAddNewUserScreen : protected clsScreen
{
private:
	static string _ReadUserId()
	{
		cout << Setw(35) << "Enter the Id        : ";
		string Id = clsInput::ReadString();
		return Id;
	}

	static clsUser _ReadUser()
	{
		cout << Setw(35) << "Enter the Id          : ";
		string Id = clsInput::ReadString();
		while (clsUser::DoesUserExist(Id))
		{
			cout << Setw(35) << "This Id is in use, choose another!\n";
			cout << Setw(35) << "Enter the id          : ";
			Id = clsInput::ReadString();
		}

		cout << Setw(35) << "Enter the password    : ";
		string Password = clsInput::ReadString();

		cout << Setw(35) << "Enter First Name      : ";
		string FirstName = clsInput::ReadString();

		cout << Setw(35) << "Enter Last Name       : ";
		string LastName = clsInput::ReadString();

		cout << Setw(35) << "Enter the Age (5 - 95): ";
		int Age = clsInput::readIntInRange(5, 95);

		return clsUser(Id, Password, FirstName, LastName, Age);
	}

	static void _AddNewUserScreen()
	{
		DrawScreenHeader("\t\t\tAdd New User.");

		clsUser UserInfo = _ReadUser();
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to add this User?");

		if (Confirm)
		{
			UserInfo.AddNewUser();
			cout << Setw(35) << "User Added successfully!\n";
		}
		else
		{
			cout << Setw(35) << "Operation Aborted!\n";
		}
	}

public: 
	static void AddNewUserScreen()
	{
		_AddNewUserScreen();
	}

};

