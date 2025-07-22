#pragma once

#include "clsPurchasedBooks.h"

#include "clsDocument.h"
#include "clsComment.h"
#include "clsInput.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; 

static const string BooksFileName = "Books.txt";

class clsBook : public clsDocument
{
private: 
	short _RatingsSum; 
	short _RatingsCount; 
	string _CommentsFileName; 

	// comments handling
	string _MakeCommentsFileName(string Id, string Path = "books_comments/")
	{
		return Path + Id + "_file.txt";
	}
	void _AddCommentToFile(clsComment Comment, string CommentsFileName)
	{
		ofstream File; 
		File.open(CommentsFileName, ios::out | ios::app);

		if (File.is_open())
		{
			File << Comment._CommentObjectToRecord("#//#") << "\n";
			File.close();
		}
	}
	vector <clsComment> _LoadComments(string CommentsFileName)
	{
		vector <clsComment> vComments; 

		ifstream File; 
		File.open(CommentsFileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{
				clsComment Comment = clsComment::_CommentRecordToObject(Record, "#//#");
				vComments.push_back(Comment);
			}
			File.close();
		}

		return vComments;
	}
	bool _RemoveCommentsFile()
	{
		// c_str() converts std string to c style const* ptr
		return std::remove(this->_CommentsFileName.c_str());
	}

	// books handling
	static string _BookObjectToRecord(clsBook Book, string Delim = "#//#")
	{
		string Record = "";
		Record += Book.Id + Delim;
		Record += Book.Title + Delim;
		Record += Book.Author + Delim;
		Record += Book.Category + Delim;
		Record += to_string(Book.Price) + Delim;
		Record += to_string(Book.Quantity) + Delim;
		Record += to_string(Book.SoldQuantity) + Delim;
		Record += to_string(Book._RatingsSum) + Delim;
		Record += to_string(Book._RatingsCount) + Delim;
		Record += Book._CommentsFileName; 

		return Record; 
	}
	static clsBook _BookRecordToObject(string Record, string Delim = "#//#")
	{
		vector <string> Tokens = clsUtil::SplitString(Record, Delim);

		if (Tokens.size() < 10)
		{
			throw std::runtime_error("invalid book record format!");
		}

		string Id = Tokens[0], Title = Tokens[1], Author = Tokens[2], Category = Tokens[3];
		float Price = stof(Tokens[4]);
		int Quantity = stoi(Tokens[5]), SoldQuantity = stoi(Tokens[6]);
		short RatingsSum = stoi(Tokens[7]), RatingsCount = stoi(Tokens[8]);

		return clsBook(Id, Title, Author, Category, Price, Quantity,
			SoldQuantity, RatingsSum, RatingsCount);
	}

	static vector <clsBook> _LoadBooksFromFile(string BooksFileName)
	{
		vector <clsBook> vBooks; 

		ifstream File; 
		File.open(BooksFileName, ios::in);

		if (File.is_open())
		{
			string Record = "";

			while (getline(File, Record))
			{
				if (!Record.empty())
				{
					clsBook Book = _BookRecordToObject(Record, "#//#");
					vBooks.push_back(Book);
				}
			}
			File.close();
		}
		return vBooks;
	}
	static void _SaveBooksToFile(vector <clsBook> vBooks, string BooksFileName)
	{
		ofstream File; 
		File.open(BooksFileName, ios::out);

		if (File.is_open())
		{
			for (clsBook& Book : vBooks)
			{
				if (!Book.MarkForDeletion)
				{
					File << _BookObjectToRecord(Book) << "\n";
				}
			}
			File.close();
		}
	}
	static void _AddBookRecordToFile(clsBook Book, string BooksFileName)
	{
		ofstream File; 
		File.open(BooksFileName, ios::out | ios::app);

		if (File.is_open())
		{
			string Record = _BookObjectToRecord(Book);

			if (!Record.empty())
			{
				File << Record << "\n";
			}
			File.close();
		}
	}

	static clsBook* _FindBook(vector <clsBook>& vBooks, string BookId)
	{
		for (clsBook& Book : vBooks)
		{
			if (Book.Id == BookId)
			{
				return &Book;
			}
		}

		return nullptr; 
	}
	
	bool _UpdateBook()
	{
		vector <clsBook> vBooks = _LoadBooksFromFile(BooksFileName);

		clsBook* IsFound = _FindBook(vBooks, this->GetId());

		if (IsFound != nullptr)
		{
			*IsFound = *this;
			_SaveBooksToFile(vBooks, BooksFileName);
			return true;
		}

		return false;
	}

	bool _DeleteBook()
	{
		vector <clsBook> vBooks = _LoadBooksFromFile(BooksFileName);

		clsBook* IsFound = _FindBook(vBooks, this->GetId());

		if (IsFound != nullptr)
		{
			IsFound->MarkForDeletion = true;
			_SaveBooksToFile(vBooks, BooksFileName);
			_RemoveCommentsFile();
			return true;
		}

		return false;
	}

	void _AddNewBook()
	{
		_AddBookRecordToFile(*this, BooksFileName);
	}

	static bool _DoesBookExist(string BooksFileName, string Id)
	{
		vector <clsBook> vBooks = _LoadBooksFromFile(BooksFileName);
		return _FindBook(vBooks, Id);
	}

public: 
	clsBook(string Id, string Title, string Author, string Category, 
		float Price, int Quantity, int SoldQuantity, short RatingsSum, short RatingsCount)
		: clsDocument(Id, Title, Author, Category, Price, Quantity, SoldQuantity)
	{
		this->_RatingsCount = RatingsCount;
		this->_RatingsSum = RatingsSum;
		this->_CommentsFileName = _MakeCommentsFileName(Id);
	}

	short GetRatingsSum()
	{
		return _RatingsSum;
	}
	_declspec(property(get = GetRatingsSum)) short RatingsSum;

	short GetRatingsCount()
	{
		return _RatingsCount;
	}
	_declspec(property(get = GetRatingsCount)) short RatingsCount;

	string GetCommentsFileName()
	{
		return _CommentsFileName; 
	}
	_declspec(property(get = GetCommentsFileName)) string CommentsFileName; 

	static void Swap(clsBook& Book1, clsBook& Book2)
	{
		clsBook temp = Book1; 
		Book1 = Book2; 
		Book2 = temp;;
	}

	void AddRating(short Rating)
	{
		_RatingsSum += Rating; 
		_RatingsCount++;
	}

	void AddComment(clsComment Comment)
	{
		_AddCommentToFile(Comment, this->CommentsFileName);
	}

	vector <clsComment> GetComments()
	{
		return _LoadComments(this->_CommentsFileName);
	}
	
	short GetAverageRating()
	{
		return (RatingsCount > 0) ? _RatingsSum / _RatingsCount : 0;
	}

	double GetTotalRevenue()
	{
		return this->SoldQuantity * this->Price; 
	}

	// crud ops

	void AddNewBook()
	{
		_AddNewBook();
	}

	bool UpdateBook()
	{
		return _UpdateBook();
	}

	bool DeleteBook()
	{
		return _DeleteBook();
	}

	static bool DoesBookExist(string Id)
	{
		return _DoesBookExist(::BooksFileName, Id);
	}

	static clsBook* FindBook(vector <clsBook>& vBooks, string Id)
	{
		return _FindBook(vBooks, Id);
	}

	static vector <clsBook> GetBooksList()
	{
		return _LoadBooksFromFile(::BooksFileName);
	}

	static vector <clsBook> GetAuthorOwnedBooksList(string AuthorName)
	{
		vector <clsBook> vBooks = _LoadBooksFromFile(::BooksFileName);
		vector <clsBook> vOwnedBooks;

		for (clsBook& Book : vBooks)
		{
			if (Book.Author == AuthorName)
			{
				vOwnedBooks.push_back(Book);
			}
		}

		return vOwnedBooks; 
	}

	static vector <clsBook> GetUsersPurchasedBooksList(string UserId)
	{
		vector <clsBook> vBooks = _LoadBooksFromFile(::BooksFileName);
		vector <string> OwnedBooksIds = clsPurchasedBooks::LoadPurchasedBooksFromFile(UserId);

		vector <clsBook> vPurchasedBooks;

		for (clsBook& Book : vBooks)
		{
			for (string& BookId : OwnedBooksIds)
			{
				if (Book.Id == BookId)
				{
					vPurchasedBooks.push_back(Book);
				}
			}
		}

		return vPurchasedBooks; 
	}

	// validate author

	bool IsOwnedBy(string AuthorName)
	{
		return this->Author == AuthorName; 
	}
};

