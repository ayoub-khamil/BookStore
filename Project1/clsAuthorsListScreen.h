#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsAuthor.h"
#include "clsUtil.h"
#include "clsInput.h"
using namespace std; 

class clsAuthorsListScreen : protected clsScreen
{
private: 
	static void _PrintAuthorsListHeader()
	{
		cout << Setw(20) << "_____________________________________________________________________________________________\n\n";
		cout << Setw(35) << left << setw(10) << "ID "
			<< "| " << left << setw(10) << "Password"
			<< "| " << left << setw(15) << "First Name"
			<< "| " << left << setw(15) << "Last Name"
			<< "| " << left << setw(10) << "Age" << "\n";
		cout << Setw(20) << "_____________________________________________________________________________________________\n\n";
	}
	static void _PrintAuthorRow(clsAuthor Author)
	{
		cout << Setw(35) << left << setw(10) << Author.GetId()
			<< "| " << left << setw(10) << Author.Password
			<< "| " << left << setw(15) << Author.FirstName
			<< "| " << left << setw(15) << Author.LastName
			<< "| " << left << setw(10) << Author.Age << "\n";
	}
	static void _PrintAuthorsListFooter()
	{
		cout << Setw(20) << "_____________________________________________________________________________________________\n\n";
	}
	static void _PrintAuthorsListTable(vector <clsAuthor> vAuthors)
	{
		if (vAuthors.size() < 1)
		{
			cout << Setw(35) << "\t\t\tNo Authors Added Yet!\n";
			return;
		}

		for (const clsAuthor& book : vAuthors)
		{
			_PrintAuthorRow(book);
		}
	}

	static void _PrintAuthorsList()
	{
		vector <clsAuthor> vAuthors = clsAuthor::GetAuthorsList();

		DrawScreenHeader("\t\t\tAuthors List.",
			("\t\t\tAuthors Amount (" + to_string(vAuthors.size()) + ")."));

		_PrintAuthorsListHeader();
		_PrintAuthorsListTable(vAuthors);
		_PrintAuthorsListFooter();
	}

public: 
	static void PrintAuthorsList()
	{
		_PrintAuthorsList();
	}

};

