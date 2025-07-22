#pragma once

#include "clsPerson.h"
#include "clsUtil.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

static const string AuthorsFileName = "Authors.txt";

class clsAuthor : public clsPerson
{
private: 
	static string _AuthorObjectToRecord(clsAuthor Author, string Delim = "#//#")
	{
		string Record = "";
		Record += Author.GetId() + Delim;
		Record += Author.Password + Delim;
		Record += Author.FirstName + Delim;
		Record += Author.LastName + Delim;
		Record += to_string(Author.Age);
		return Record;
	}
	static clsAuthor _AuthorRecordToObject(string Record, string Delim = "#//#")
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

		return clsAuthor(Id, Password, FirstName, LastName, Age);
	}

	static vector <clsAuthor> _LoadAuthorsFromFile(string AuthorsFileName)
	{
		vector <clsAuthor> vAuthors; 

		ifstream File; 
		File.open(AuthorsFileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{
				if (!Record.empty())
					vAuthors.push_back(_AuthorRecordToObject(Record));
			}

			File.close();
		}
		else
		{
			throw std::runtime_error("failed to open " + AuthorsFileName + " file");
		}

		return vAuthors;
	}
	static void _SaveAuthorsToFile(const vector <clsAuthor>& vAuthors, string AuthorsFileName)
	{
		ofstream File; 
		File.open(AuthorsFileName, ios::out);

		if (File.is_open())
		{
			for (clsAuthor Author : vAuthors)
			{
				if (!Author.MarkForDeletion)
				{
					File << _AuthorObjectToRecord(Author) << "\n";
				}
			}

			File.close();
		}
		else
		{
			throw std::runtime_error("failed to open " + AuthorsFileName + " file");
		}
	}
	static void _AddAuthorRecordToFile(clsAuthor Author, string AuthorsFileName)
	{
		ofstream File; 
		File.open(AuthorsFileName, ios::app);

		if (File.is_open())
		{
			File << _AuthorObjectToRecord(Author) << "\n";
			File.close();
		}
		else
		{
			throw std::runtime_error("failed to open " + AuthorsFileName + " file");
		}
	}

	static clsAuthor* _FindAuthor(vector <clsAuthor>& vAuthors, string Id)
	{
		for (clsAuthor& Author : vAuthors)
		{
			if (Author.GetId() == Id)
			{
				return &Author; 
			}
		}
		return nullptr; 
	}
	static clsAuthor* _FindAuthor(vector <clsAuthor>& vAuthors, string Id, string Password)
	{
		for (clsAuthor& Author : vAuthors)
		{
			if (Author.GetId() == Id && Author.Password == Password)
			{
				return &Author;
			}
		}
		return nullptr;
	}
	
	bool _UpdateAuthor()
	{
		vector <clsAuthor> vAuthors = _LoadAuthorsFromFile(AuthorsFileName);

		clsAuthor* IsFound = _FindAuthor(vAuthors, this->GetId()); 

		if (IsFound != nullptr)
		{
			*IsFound = *this; 
			_SaveAuthorsToFile(vAuthors, AuthorsFileName);
			return true; 
		}

		return false; 
	}

	bool _DeleteAuthor()
	{
		vector <clsAuthor> vAuthors = _LoadAuthorsFromFile(AuthorsFileName);

		clsAuthor* IsFound = _FindAuthor(vAuthors, this->GetId());
		
		if (IsFound != nullptr)
		{
			IsFound->MarkForDeletion = true; 
			_SaveAuthorsToFile(vAuthors, AuthorsFileName);
			return true; 
		}

		return false; 
	}

	bool _AddNewAuthor()
	{
		_AddAuthorRecordToFile(*this, AuthorsFileName);
	}

	static bool _DoesAuthorExist(string AuthorsFileName, string Id)
	{
		vector <clsAuthor> vAuthors = _LoadAuthorsFromFile(AuthorsFileName);
		return _FindAuthor(vAuthors, Id);
	}

public: 
	clsAuthor(string Id, string Password, string FirstName, string LastName, int Age)
		: clsPerson(Id, Password, FirstName, LastName, Age)
	{
	}

	static clsAuthor* FindAuthor(vector <clsAuthor>& vAuthors, string Id)
	{
		return _FindAuthor(vAuthors, Id);
	}

	static clsAuthor* FindAuthor(vector <clsAuthor>& vAuthors, string Id, string Password)
	{
		return _FindAuthor(vAuthors, Id, Password);
	}

	void AddNewAuthor()
	{
		_AddAuthorRecordToFile(*this, ::AuthorsFileName);
	}

	bool UpdateAuthor()
	{
		return _UpdateAuthor();
	}

	bool DeleteAuthor()
	{
		return _DeleteAuthor();
	}

	static bool DoesAuthorExist(string Id)
	{
		return _DoesAuthorExist(::AuthorsFileName, Id);
	}

	static vector <clsAuthor> GetAuthorsList()
	{
		return _LoadAuthorsFromFile(::AuthorsFileName);
	}
};

