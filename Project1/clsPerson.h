#pragma once

#include <string>
using std::string;

class clsPerson
{
private: 
	string _Id;
	string _Password; 
	string _FirstName; 
	string _LastName; 
	short _Age; 

	bool _MarkForDeletion = false;

public: 
	clsPerson(string Id, string Password, string FirstName, string LastName, short Age)
	{
		this->_Id = Id;
		this->_Password = Password;
		this->_FirstName = FirstName; 
		this->_LastName = LastName;
		this->_Age = Age; 
	}

	// read only
	string GetId()
	{
		return _Id; 
	}

	void SetPassword(string Password)
	{
		this->_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	_declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetFirstName(string FirstName)
	{
		this->_FirstName = FirstName; 
	}
	string GetFirstName()
	{
		return _FirstName; 
	}
	_declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastName)
	{
		this->_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}
	_declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	void SetAge(short Age)
	{
		this->_Age = Age;
	}
	short GetAge()
	{
		return _Age;
	}
	_declspec(property(get = GetAge, put = SetAge)) short Age;

	void SetMarkForDeletion(bool MarkForDeletion)
	{
		this->_MarkForDeletion = MarkForDeletion;
	}
	bool GetMarkForDeletion()
	{
		return _MarkForDeletion;
	}
	_declspec(property(get = GetMarkForDeletion, put = SetMarkForDeletion)) bool MarkForDeletion;
};
