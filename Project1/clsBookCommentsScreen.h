#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBook.h"
#include "clsComment.h"
using namespace std; 

class clsBookCommentsScreen : protected clsScreen
{
private:
	static string _ReadBookId()
	{
		cout << Setw(35) << "Enter the Book's id : ";
		string BookId = clsInput::ReadString();
		return BookId;
	}

	static string _FormatCommentText(string CommentText, short LineLength)
	{
		vector <string> vBrokenCommentText = clsUtil::AddLineBreaks(CommentText, LineLength);

		for (string& Token : vBrokenCommentText)
		{
			cout << "\t" << Setw(35) << Token << "\n";
		}

		return "";
	}

	static void _PrintComment(clsComment Comment)
	{
		cout << Setw(35) << "\t____________________________________________________\n";
		cout << Setw(35) << "\t\t\t   " << Comment.Date << "\n";
		cout << Setw(35) << "\t" << _FormatCommentText(Comment.Text, 50) << "\n";
		cout << Setw(35) << "\t____________________________________________________\n";
	}

	static void _PrintComments(vector <clsComment> vComments)
	{
		if (vComments.size() < 1)
		{
			cout << "\n";
			cout << Setw(35) << "\t\t\tNo Comments Made Yet!\n\n";
			return;
		}

		for (clsComment& Comment : vComments)
		{
			_PrintComment(Comment);
		}
	}

	static void _PrintCommentsScreen()
	{
		DrawScreenHeader("\t\t\tBook Comments.");

		string BookId = _ReadBookId();

		vector <clsBook> vBooks = clsBook::GetBooksList();
		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);

		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		vector <clsComment> vComments = BookFound->GetComments();
		_PrintComments(vComments);
	}

	static void _PrintCommentsScreen_AuthorMode(string BookId)
	{
		DrawScreenHeader("\t\t\tBook Comments.");

		vector <clsBook> vBooks = clsBook::GetBooksList();
		clsBook* BookFound = clsBook::FindBook(vBooks, BookId);

		if (BookFound == nullptr)
		{
			cout << "\n";
			cout << Setw(35) << "No Book found under the Id " << BookId << "!\n";
			return;
		}

		vector <clsComment> vComments = BookFound->GetComments();
		_PrintComments(vComments);
	}


public: 
	static void PrintCommentsScreen(bool AuthorMode = false, string BookId = "")
	{
		if (!AuthorMode)
			_PrintCommentsScreen();
		else
			_PrintCommentsScreen_AuthorMode(BookId);
	}
};

