#pragma once
#pragma warning(disable:4996)

#include "clsUtil.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsDate
{
private: 
	short _Year = 1; 
	short _Month = 1;
	short _Day = 1;

	static clsDate _GetSystemDate()
	{
		time_t TimeInSeconds = time(0);
		tm* stTime = localtime(&TimeInSeconds);

		short Year = stTime->tm_year + 1900;
		short Month = stTime->tm_mon + 1;
		short Day = stTime->tm_mday;

		return clsDate(Year, Month, Day);
	}

public: 
	clsDate(short Year, short Month, short Day)
	{
		this->_Year = Year; 
		this->_Month = Month;
		this->_Day = Day;
	}
	clsDate(string sDate)
	{
		vector <string> vDate;
		vDate = clsUtil::SplitString(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}
	clsDate()
	{
		*this = _GetSystemDate();
	}

	string GetFormat()
	{
		return to_string(_Year) + "/" + to_string(_Month) + "/" + to_string(_Day);
	}
};
