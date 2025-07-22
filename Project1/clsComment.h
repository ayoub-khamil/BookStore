#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std; 

class clsComment
{
private: 
	string _BookId;
	string _CommentText; 
	clsDate _CreationDate; 

public: 
	static clsComment _CommentRecordToObject(string Record, string Delim)
	{
		vector <string> RecordTokens = clsUtil::SplitString(Record, Delim);

		if (RecordTokens.size() < 3)
		{
			throw std::runtime_error("Invalid Comment record format!");
		}

		string Id = RecordTokens[0];
		string Text = RecordTokens[1];
		clsDate Date(RecordTokens[2]);

		return clsComment(Text, Id, Date);
	}
	string _CommentObjectToRecord(string Delim = "#//#")
	{
		string CommentRecord = "";
		CommentRecord += this->_BookId + Delim;
		CommentRecord += this->_CommentText + Delim;
		CommentRecord += this->_CreationDate.GetFormat();
		return CommentRecord;
	}


public: 
	clsComment(string CommentText, string CommenterId, clsDate CreationDate)
	{
		this->_CommentText = CommentText;
		this->_BookId = CommenterId;
		this->_CreationDate = CreationDate; 
	}
	clsComment()
	{

	}

	string GetId()
	{
		return _BookId;
	}
	_declspec(property(get = GetId)) string Id; 

	string GetCommentText()
	{
		return _CommentText; 
	}
	_declspec(property(get = GetCommentText)) string Text; 

	string GetCreationDate()
	{
		return _CreationDate.GetFormat(); 
	}
	_declspec(property(get = GetCreationDate)) string Date; 

	void Read(string CommentText, string BookId)
	{		
		this->_CreationDate = clsDate();
		this->_CommentText = CommentText; 
		this->_BookId = BookId;

	}
};
