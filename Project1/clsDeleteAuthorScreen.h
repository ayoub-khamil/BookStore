#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsAuthor.h"
#include "clsInput.h"
#include "clsUtil.h"
using namespace std; 

class clsDeleteAuthorScreen : protected clsScreen
{
private: 
	static string _ReadAuthorId()
	{
		cout << Setw(35) << "Enter the Id        : ";
		string Id = clsInput::ReadString();
		return Id;
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

	static void _DeleteAuthorScreen()
	{
		DrawScreenHeader("\t\t\tDelete Author.");

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
		_PrintAuthorInfo(AuthorFound, "Author Info.");
		cout << "\n";

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to delete this Author?");

		if (Confirm)
		{
			if (AuthorFound->DeleteAuthor())
			{
				cout << Setw(35) << "Author Deleted successfully!\n";
			}
			else
			{
				cout << Setw(35) << "Failed to delete Author!\n";
			}
		}
		else
		{
			cout << Setw(35) << "Operation aborted!\n";
		}
	}

public: 
	static void DeleteAuthorScreen()
	{
		_DeleteAuthorScreen();
	}

};

