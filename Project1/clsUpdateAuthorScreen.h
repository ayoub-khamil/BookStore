#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsAuthor.h"
#include "clsUtil.h"
#include "clsInput.h"
using namespace std; 

class clsUpdateAuthorScreen : protected clsScreen
{
private:
	static string _ReadAuthorId()
	{
		cout << Setw(35) << "Enter the Id        : ";
		string Id = clsInput::ReadString();
		return Id;
	}

	static clsAuthor _ReadUpdatedAuthorInfo(string OriginalId)
	{
		cout << Setw(35) << "Enter the password    : ";
		string Password = clsInput::ReadString();

		cout << Setw(35) << "Enter First Name      : ";
		string FirstName = clsInput::ReadString();

		cout << Setw(35) << "Enter Last Name       : ";
		string LastName = clsInput::ReadString();

		cout << Setw(35) << "Enter the Age (5 - 95): ";
		int Age = clsInput::readIntInRange(5, 95);

		return clsAuthor(OriginalId, Password, FirstName, LastName, Age);
	}

	static void _PrintAuthorInfo(clsAuthor* Author, string Message)
	{
		cout << Setw(35) << "\t\t\t" << Message << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
		cout << Setw(35) << "\t\t Author ID    : " << Author->GetId() << "\n";
		cout << Setw(35) << "\t\t Password     : " << Author->Password << "\n";
		cout << Setw(35) << "\t\t First Name   : " << Author->FirstName << "\n";
		cout << Setw(35) << "\t\t Last  Name   : " << Author->LastName << "\n";
		cout << Setw(35) << "\t\t Age          : " << Author->Age << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
	}

	static void _UpdateAuthorScreen()
	{
		DrawScreenHeader("\t\t\tUpdate Author");

		string AuthorId = _ReadAuthorId();

		vector <clsAuthor> vAuthors = clsAuthor::GetAuthorsList();

		clsAuthor* AuthorFound = clsAuthor::FindAuthor(vAuthors, AuthorId);
		if (AuthorFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Author Found under the Id " << AuthorId << "!\n";
			return;
		}

		cout << "\n";
		_PrintAuthorInfo(AuthorFound, "Original Info.");
		cout << "\n";

		cout << Setw(35) << "\t\t\tEnter the New Info\n";
		*AuthorFound = _ReadUpdatedAuthorInfo(AuthorFound->GetId());
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to update this Author?");

		if (Confirm)
		{
			if (AuthorFound->UpdateAuthor())
			{
				cout << Setw(35) << "Author Updated Successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Couldn't update Author!\n";
			}
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}
	}

public: 
	static void UpdateAuthorScreen()
	{
		_UpdateAuthorScreen();
	}
};

