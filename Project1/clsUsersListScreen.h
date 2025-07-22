#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "clsInput.h"
using namespace std; 

class clsUsersListScreen : protected clsScreen
{
private: 

	static void _PrintUsersListHeader()
	{
		cout << Setw(20) << "_____________________________________________________________________________________________\n\n";
		cout << Setw(35) << left << setw(10) << "ID "
			<< "| " << left << setw(10) << "Password"
			<< "| " << left << setw(15) << "First Name"
			<< "| " << left << setw(15) << "Last Name"
			<< "| " << left << setw(10) << "Age" << "\n";
		cout << Setw(20) << "_____________________________________________________________________________________________\n\n";
	}
	static void _PrintUserRow(clsUser User)
	{
		cout << Setw(35) << left << setw(10) << User.GetId()
			<< "| " << left << setw(10) << User.Password
			<< "| " << left << setw(15) << User.FirstName
			<< "| " << left << setw(15) << User.LastName
			<< "| " << left << setw(10) << User.Age << "\n";
	}
	static void _PrintUsersListFooter()
	{
		cout << Setw(20) << "_____________________________________________________________________________________________\n\n";
	}
	static void _PrintUsersListTable(vector <clsUser> vUsers)
	{
		if (vUsers.size() < 1)
		{
			cout << Setw(35) << "\t\t\tNo Users Added Yet!\n";
			return;
		}

		for (const clsUser& book : vUsers)
		{
			_PrintUserRow(book);
		}
	}

	static void _PrintUsersList()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		DrawScreenHeader("\t\t\tUsers List.",
			("\t\t\tUsers Amount (" + to_string(vUsers.size()) + ")."));

		_PrintUsersListHeader();
		_PrintUsersListTable(vUsers);
		_PrintUsersListFooter();
	}

public: 
	static void PrintUsersList()
	{
		_PrintUsersList();
	}

};

