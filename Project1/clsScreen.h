#pragma once

#include <iostream>
#include <iomanip>
using namespace std; 

class clsScreen
{
public: 
	static string Setw(short Length = 35)
	{
		cout << left << setw(Length) << "";
		return "";
	}

	static void DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << Setw() << "_____________________________________________________________\n";
		cout << Setw() << Title << "\n";
		if (SubTitle != "") cout << Setw() << SubTitle << "\n";
		cout << Setw() << "_____________________________________________________________\n";
	}

};
