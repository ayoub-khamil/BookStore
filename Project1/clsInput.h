#pragma once

#include <iostream>
#include <string>
using namespace std;

class clsInput
{
public:

	// number range validation
private: template <typename T> static bool isNumberInRange(T number, T from, T to)
{
	return (number >= from && number <= to);
}

public:
	static bool isIntNumberInRange(int number, int from, int to)
	{
		return isNumberInRange<int>(number, from, to);
	}
	static bool isFloatNumberInRange(float number, float from, float to)
	{
		return isNumberInRange<float>(number, from, to);
	}
	static bool isDoubleNumberInRange(double number, double from, double to)
	{
		return isNumberInRange<double>(number, from, to);
	}

	// number readers 
private: template <typename T> static T readNum(string invalidInputMessage = "")
{
	T num = 0;
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << invalidInputMessage << "\n";
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return num;
}

public:
	static int readIntNumber(string invalidInputMessage = "")
	{
		return readNum<int>(invalidInputMessage);
	}
	static float readFloatNumber(string invalidInputMessage = "")
	{
		return readNum<float>(invalidInputMessage);
	}
	static double readDoubleNumber(string invalidInputMessage = "")
	{
		return readNum<double>(invalidInputMessage);
	}

private: template <typename T> static T readNumInRange(T from, T to, string invalidInputMessage = "")
{
	T number = 0;
	do
	{
		number = readNum<T>(invalidInputMessage);

	} while (!(isNumberInRange(number, from, to)));

	return number;
}

public:
	static int readIntInRange(int from, int to, string invalidInputMessage = "")
	{
		return readNumInRange<int>(from, to, invalidInputMessage);
	}
	static float readFloatInRange(float from, float to, string invalidInputMessage = "")
	{
		return readNumInRange<float>(from, to, invalidInputMessage);
	}
	static double readDoubleInRange(double from, double to, string invalidInputMessage = "")
	{
		return readNumInRange<double>(from, to, invalidInputMessage);
	}

	// char type readers 
	static string ReadString(string Message = "")
	{
		string Str = "";
		cout << Message;
		getline(cin >> ws, Str);
		return Str;
	}
	static char ReadChar(string Message = "")
	{
		char Char = ' ';
		cout << Message;
		cin >> ws >> Char;
		return Char;
	}
	
};