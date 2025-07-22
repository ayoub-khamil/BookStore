#pragma once

#include <iostream>
using namespace std; 

class clsDocument
{
private: 
	string _Id; 
	string _Title; 
	string _Author; 
	string _Category; 
	float _Price; 
	int _Quantity; 
	int _SoldQuantity; 

	bool _MarkForDeletion = false; 

public: 
	clsDocument(string Id, string Title, string Author, string Category,
		float Price, int Quantity, int SoldQuantity)
	{
		this->_Id = Id; 
		this->_Title = Title; 
		this->_Author = Author;
		this->_Category = Category;
		this->_Price = Price;
		this->_Quantity = Quantity; 
		this->_SoldQuantity = SoldQuantity;
	}

	string GetId()
	{
		return _Id; 
	}
	_declspec(property(get = GetId)) string Id; 

	void SetTitle(string Title)
	{
		this->_Title = Title; 
	}
	string GetTitle()
	{
		return _Title; 
	}
	_declspec(property(get = GetTitle, put = SetTitle)) string Title; 

	void SetAuthor(string Author)
	{
		this->_Author = Author;
	}
	string GetAuthor()
	{
		return _Author;
	}
	_declspec(property(get = GetAuthor, put = SetAuthor)) string Author;

	void SetCategory(string Category)
	{
		this->_Category = Category;
	}
	string GetCategory()
	{
		return _Category;
	}
	_declspec(property(get = GetCategory, put = SetCategory)) string Category;

	void SetPrice(float Price)
	{
		this->_Price = Price;
	}
	float GetPrice()
	{
		return _Price;
	}
	_declspec(property(get = GetPrice, put = SetPrice)) float Price;

	void SetQuantity(int Quantity)
	{
		this->_Quantity = Quantity;
	}
	int GetQuantity()
	{
		return _Quantity;
	}
	_declspec(property(get = GetQuantity, put = SetQuantity)) int Quantity;

	void SetSoldQuantity(int SoldQuantity)
	{
		this->_SoldQuantity = SoldQuantity;
	}
	int GetSoldQuantity()
	{
		return _SoldQuantity;
	}
	_declspec(property(get = GetSoldQuantity, put = SetSoldQuantity)) int SoldQuantity;

	void SetMarkForDeletion(bool MarkForDeletion)
	{
		this->_MarkForDeletion = MarkForDeletion;
	}
	bool GetMarkForDeletion()
	{
		return _MarkForDeletion;
	}
	_declspec(property(get = GetMarkForDeletion, put = SetMarkForDeletion)) bool MarkForDeletion;

};
