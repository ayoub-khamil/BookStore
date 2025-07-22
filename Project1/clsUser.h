#pragma once

#include "clsPerson.h"
#include "clsUtil.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

static const string UsersFileName = "Users.txt";

class clsUser : public clsPerson
{
private:

	static string _UserObjectToRecord(clsUser User, string Delim = "#//#")
	{
		string Record = "";
		Record += User.GetId() + Delim;
		Record += User.Password + Delim;
		Record += User.FirstName + Delim;
		Record += User.LastName + Delim;
		Record += to_string(User.Age);
		return Record;
	}
	static clsUser _UserRecordToObject(string Record, string Delim = "#//#")
	{
		vector <string> RecordTokens = clsUtil::SplitString(Record, Delim);

		if (RecordTokens.size() < 5)
		{
			throw std::runtime_error("invalid author record format!");
		}

		string Id = RecordTokens[0];
		string Password = RecordTokens[1];
		string FirstName = RecordTokens[2];
		string LastName = RecordTokens[3];
		short Age = stoi(RecordTokens[4]);

		return clsUser(Id, Password, FirstName, LastName, Age);
	}

	static string _GetUserOwnedBooksFileName(string UserId)
	{
		return "users_purchased_books/" + UserId + "_owned_books.txt";
	}
	void _CreateUserOwnedBooksFile()
	{
		string OwnedBooksFileName = _GetUserOwnedBooksFileName(this->GetId());
		fstream File; 
		File.open(OwnedBooksFileName, ios::out);
		File.close();
	}
	void _RemoveUserOwnedBooksFile()
	{
		// c_str() converts std string to c style const* ptr
		string OwnedBooksFileName = _GetUserOwnedBooksFileName(this->GetId());
		std::remove(OwnedBooksFileName.c_str());
	}

	static vector <clsUser> _LoadUsersFromFile(string UsersFileName)
	{
		vector <clsUser> vUsers;

		ifstream File;
		File.open(UsersFileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{
				if (!Record.empty())
					vUsers.push_back(_UserRecordToObject(Record));
			}

			File.close();
		}
		else
		{
			throw std::runtime_error("failed to open " + UsersFileName + " file");
		}

		return vUsers;
	}
	static void _SaveUsersToFile(const vector <clsUser>& vUsers, string UsersFileName)
	{
		ofstream File;
		File.open(UsersFileName, ios::out);

		if (File.is_open())
		{
			for (clsUser User : vUsers)
			{
				if (!User.MarkForDeletion)
				{
					File << _UserObjectToRecord(User) << "\n";
				}
			}

			File.close();
		}
		else
		{
			throw std::runtime_error("failed to open " + UsersFileName + " file");
		}
	}
	static void _AddUserRecordToFile(clsUser User, string UsersFileName)
	{
		ofstream File;
		File.open(UsersFileName, ios::app);

		if (File.is_open())
		{
			File << _UserObjectToRecord(User) << "\n";
			File.close();
		}
		else
		{
			throw std::runtime_error("failed to open " + UsersFileName + " file");
		}
	}

	static clsUser* _FindUser(vector <clsUser>& vUsers, string Id)
	{
		for (clsUser& User : vUsers)
		{
			if (User.GetId() == Id)
			{
				return &User;
			}
		}
		return nullptr;
	}
	static clsUser* _FindUser(vector <clsUser>& vUsers, string Id, string Password)
	{
		for (clsUser& User : vUsers)
		{
			if (User.GetId() == Id && User.Password == Password)
			{
				return &User;
			}
		}
		return nullptr;
	}

	bool _UpdateUser()
	{
		vector <clsUser> vUsers = _LoadUsersFromFile(UsersFileName);

		clsUser* IsFound = _FindUser(vUsers, this->GetId());

		if (IsFound != nullptr)
		{
			*IsFound = *this;
			_SaveUsersToFile(vUsers, UsersFileName);
			return true;
		}

		return false;
	}

	bool _DeleteUser()
	{
		vector <clsUser> vUsers = _LoadUsersFromFile(UsersFileName);

		clsUser* IsFound = _FindUser(vUsers, this->GetId());

		if (IsFound != nullptr)
		{
			IsFound->MarkForDeletion = true;
			_SaveUsersToFile(vUsers, UsersFileName);
			_RemoveUserOwnedBooksFile();
			return true;
		}

		return false;
	}

	void _AddNewUser()
	{
		_AddUserRecordToFile(*this, UsersFileName);
		_CreateUserOwnedBooksFile();
	}

	static bool _DoesUserExist(string UsersFileName, string Id)
	{
		vector <clsUser> vUsers = _LoadUsersFromFile(UsersFileName);
		return _FindUser(vUsers, Id);
	}

public: 
	clsUser(string Id, string Password, string FirstName, string LastName, short Age)
		: clsPerson(Id, Password, FirstName, LastName, Age)
	{
		
	}

	static clsUser* FindUser(vector <clsUser>& vUsers, string Id)
	{
		return _FindUser(vUsers, Id);
	}
	
	static clsUser* FindUser(vector <clsUser>& vUsers, string Id, string Password)
	{
		return _FindUser(vUsers, Id, Password);
	}

	void AddNewUser()
	{
		_AddNewUser();
	}

	bool UpdateUser()
	{
		return _UpdateUser();
	}

	bool DeleteUser()
	{
		return _DeleteUser();
	}

	static bool DoesUserExist(string Id)
	{
		return _DoesUserExist(::UsersFileName, Id);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersFromFile(::UsersFileName);
	}

	static string GetUserOwnedBooksFileName(string UserId)
	{
		return _GetUserOwnedBooksFileName(UserId);
	}
};

