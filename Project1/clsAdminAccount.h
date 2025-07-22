#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include "clsUtil.h"
#include "clsInput.h"
using namespace std; 

static const string AdminFileName = "Admin.txt";

class clsAdminAccount
{
public: 

	struct stAdmin
	{
		string _Id; 
		string _Password; 

		stAdmin(string Id, string Password)
		{
			this->_Id = Id; 
			this->_Password = Password; 
		}
	};

	static stAdmin GetAdminAccount()
	{
		fstream File; 
		File.open(::AdminFileName, ios::in);
		string AdminRecord; 
		getline(File, AdminRecord);

		vector <string> vAdmin = clsUtil::SplitString(AdminRecord, "#//#");

		return stAdmin(vAdmin[0], vAdmin[1]);
	}

};

