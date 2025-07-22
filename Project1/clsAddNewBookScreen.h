#pragma once

#include "clsScreen.h"
#include "clsInput.h"
#include "clsUtil.h"
#include "clsBook.h"
#include <iostream>
using namespace std; 

class clsAddNewBookScreen : protected clsScreen
{
private: 
	static clsBook _ReadNewBookInfo(bool SkipAuthor = false)
	{
		cout << Setw(35) << "Enter the id       :";
		string Id = clsInput::ReadString();
		while (clsBook::DoesBookExist(Id))
		{
			cout << Setw(35) << "This Id is in use, choose another!\n";
			cout << Setw(35) << "Enter the id       :";
			Id = clsInput::ReadString();
		}

		cout << Setw(35) << "Enter the Title    :";
		string Title = clsInput::ReadString();

		string Author = "";
		if (!SkipAuthor)
		{
			cout << Setw(35) << "Enter the Author   :";
			Author = clsInput::ReadString();
		}

		cout << Setw(35) << "Enter the Category :";
		string Category = clsInput::ReadString();
		
		cout << Setw(35) << "Enter the Price    :";
		float Price = clsInput::readFloatNumber();
		
		cout << Setw(35) << "Enter the Quantity :";
		int Quantity = clsInput::readIntNumber();
		cout << "\n";
		return clsBook(Id, Title, Author, Category, Price, Quantity,
			0, 0, 0);
	}

	static void _AddBook()
	{
		clsScreen::DrawScreenHeader("\t\t\tAdding New Book");
		cout << "\n";

		clsBook NewBook = _ReadNewBookInfo();

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to add this book?");

		if (Confirm)
		{
			NewBook.AddNewBook();
			cout << Setw(35) << "Book Added Successfully!\n";
		}
		else
		{
			cout << Setw(35) << "Operation Aborted!\n";
		}
	}

	static void _AddBook_AuthorMode(string BookAuthor)
	{
		clsScreen::DrawScreenHeader("\t\t\tAdding New Book");
		cout << "\n";

		clsBook NewBook = _ReadNewBookInfo(true);
		NewBook.Author = BookAuthor; 

		bool Confirm = clsUtil::ConfirmOperation("Are you sure you want to add this book?");

		if (Confirm)
		{
			NewBook.AddNewBook();
			cout << Setw(35) << "Book Added Successfully!\n";
		}
		else
		{
			cout << Setw(35) << "Operation Aborted!\n";
		}
	}

public: 
	static void AddBook(bool AuthorMode = false, string BookAuthor = "")
	{
		if (!AuthorMode)
			_AddBook();
		else
			_AddBook_AuthorMode(BookAuthor);
	}
};

