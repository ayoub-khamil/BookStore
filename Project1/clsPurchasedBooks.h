#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "clsBook.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "clsInput.h"
using namespace std; 

class clsPurchasedBooks
{
public: 
	static void AddPurchasedBook(string BookId, string UserId, string Delim = "#//#")
	{
		fstream File; 
		File.open(clsUser::GetUserOwnedBooksFileName(UserId), ios::out | ios::app);
		File << BookId << "#//#";
		File.close();
	}

	static void RemovePurchasedBook(string BookId, string UserId, string Delim = "#//#")
	{
		vector <string> vBooks = LoadPurchasedBooksFromFile(UserId);
		vector <string> New_vBooks; 

		for (string& Book : vBooks)
		{
			if (Book != BookId)
			{
				New_vBooks.push_back(Book);
			}
		}
	
		SavePurchasedBooksToFile(New_vBooks, UserId);
	}

	static vector <string> LoadPurchasedBooksFromFile(string UserId, string Delim = "#//#")
	{
		string Record = "";

		string FileName = clsUser::GetUserOwnedBooksFileName(UserId);
		fstream File;
		File.open(FileName, ios::in);

		getline(File, Record);
		return clsUtil::SplitString(Record, Delim);
	}

	static void SavePurchasedBooksToFile(vector <string> vBooks, string UserId, string Delim = "#//#")
	{
		string BooksRecord = "";

		for (string& Book : vBooks)
		{
			BooksRecord += Book + Delim;
		}

		string FileName = clsUser::GetUserOwnedBooksFileName(UserId);

		fstream File;
		File.open(FileName, ios::out);
		File << BooksRecord; 
		File.close();
	}

	static bool IsBookPurchased(string UserId, string BookId)
	{
		vector <string> vBooks = LoadPurchasedBooksFromFile(UserId);

		for (string& Book : vBooks)
		{
			if (Book == BookId)
				return true; 
		}

		return false; 
	}
};

