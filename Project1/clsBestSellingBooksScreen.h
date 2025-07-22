#pragma once

#include "clsBook.h"
#include "clsScreen.h"
#include <iostream>
using namespace std; 

class clsBestSellingBooksScreen : protected clsScreen
{
private: 
	static void _PrintBookInfo(clsBook Book, string Message)
	{
		cout << Setw(35) << "\t\t\t" << Message << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
		cout << Setw(35) << "\t\tId            : " << Book.Id << "\n";
		cout << Setw(35) << "\t\tTitle         : " << Book.Title << "\n";
		cout << Setw(35) << "\t\tAuthor        : " << Book.Author << "\n";
		cout << Setw(35) << "\t\tCategory      : " << Book.Category << "\n";
		cout << Setw(35) << "\t\tQuantity      : " << Book.Quantity << "\n";
		cout << Setw(35) << "\t\t___________________________________\n";
	}

	static void _PrintNBooks(vector <clsBook>& vBooks, int N)
	{
		if (vBooks.size() < N)
		{
			N = vBooks.size();
		}

		for (int i = 0; i < N; i++)
		{
			_PrintBookInfo(vBooks[i], vBooks[i].Title);
			cout << "\n";
		}
	}

	static void _SortBooksByBestSelling(vector <clsBook> vBooks)
	{
		for (int i = 0; i < vBooks.size() - 1; i++)
		{
			for (int j = i + 1; j < vBooks.size(); j++)
			{
				if (vBooks[i].SoldQuantity < vBooks[j].SoldQuantity)
				{
					clsBook::Swap(vBooks[i], vBooks[j]);
				}
			}
		}
	}

	static void _PrintBestSellingBooksScreen()
	{
		DrawScreenHeader("\t\t\tBest Selling Books.");

		vector <clsBook> vBooks = clsBook::GetBooksList();
		_SortBooksByBestSelling(vBooks);

		_PrintNBooks(vBooks, 5);
	}

public: 
	static void PrintBestSellingBooksScreen()
	{
		_PrintBestSellingBooksScreen();
	}
};

