#pragma once

#include <iostream>
#include "clsInput.h"
#include "clsScreen.h"
#include "clsAuthor.h"
using namespace std; 

class clsAddNewAuthorScreen : protected clsScreen
{
private: 
	static string _ReadAuthorId()
	{
		cout << Setw(35) << "Enter the Id        : ";
		string Id = clsInput::ReadString();
		return Id; 
	}

	static clsAuthor _ReadAuthor()
	{
		cout << Setw(35) << "Enter the Id          : ";
		string Id = clsInput::ReadString();
		while (clsAuthor::DoesAuthorExist(Id))
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

		return clsAuthor(Id, Password, FirstName, LastName, Age);
	}

	static void _AddNewAuthorScreen()
	{
		DrawScreenHeader("\t\t\tAdd New Author.");

		clsAuthor AuthorInfo = _ReadAuthor();
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to add this Author?");

		if (Confirm)
		{
			AuthorInfo.AddNewAuthor();
			cout << Setw(35) << "Author Added successfully!\n";
		}
		else
		{
			cout << Setw(35) << "Operation Aborted!\n";
		}
	}

public: 
	static void AddNewAuthorScreen()
	{
		_AddNewAuthorScreen();
	}
};
