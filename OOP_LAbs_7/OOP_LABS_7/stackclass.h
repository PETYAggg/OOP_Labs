#pragma once
#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Stackoperations : public stack<string>
{

public:
	string row;

	void reverse()
	{
		vector<string> temp;

		while (!this->empty())
		{
			temp.push_back(this->top());
			this->pop();
		}
		for (int i = 0; i < temp.size(); i++)
			this->push(temp[i]);
	}
	string peek(int k)
	{
		stack help = (*this);
		
		for (int i = 1; i < k; i++)
		{
			help.pop();
		}
		row = help.top();
		return row;
	}
	void push_s(istream& file)
	{	if(!file.eof())
		file >> *this;
		else return;
		if (row != "\0")
			this->push(row);
	}

	friend istream& operator >> (istream&is, Stackoperations&a)
	{
		a.row;
		getline(is,a.row,'\n');

		return is;
	}
	friend ostream& operator <<(ostream &os, Stackoperations &a)
	{
		os << a.row << endl;
		return os;
	}

	~Stackoperations()
	{
		while (!this->empty())
		{
			this->pop();
		}
	}
};



