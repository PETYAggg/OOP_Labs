#pragma once
#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "stackclass.h"
using namespace std;


class Fileoperations : public Stackoperations

{
public:


	void renumber()
	{
		Stackoperations help;

		if (this->size() == 0)
			cout << "Стек пустий!\n";
		else
		{

			size_t i = this->size();
			while (!this->empty())
			{

				string last_row;
				last_row = this->top();
				this->pop();
				stringstream ss;
				ss << i-- << ": " << last_row;
				help.push(ss.str());
			}
		

		}

		while (!help.empty())
		{

			this->push(help.top());
			help.pop();
		}

	}



	void getFromFile(string name)
	{
		fstream file(name, ios_base::in);
		if (!file.is_open())
			cout << "Error opening file:  " << name << endl;
		else
			while (!file.eof()) push_s(file);

		file.close();
	}

	void outputInFile(string name)
	{
		fstream file(name, ios_base::out);
		if (!file.is_open())
			cout << "Error opening file: " << name << endl;
		else
			while (!this->empty())
			{
				file << this->top()<<endl;
				this->pop();
			}
		file.close();

	}

	void outputInConsole()
	{
		ostream_iterator<string> oss(cout, "\n");
		while (!this->empty())
		{

			*oss = this->top();
			this->pop();
		}
	}

	void makeNumberedCopy(string name)
	{

		fstream file(name, ios_base::in);
		if (!file.is_open())
			cout << "Error opening file:  " << name << endl;
		else
			while (!file.eof()) push_s(file);
				
		file.close();

		this->renumber();
		this->reverse();


		string addr = name.substr(0, name.find(".txt"));
		addr += "_copy.txt";
		file.open(addr, ios::out);
		ostream_iterator<string> oss(file, "\n");
		stack temp = (*this);
		while (!temp.empty())
			{
				
				*oss= temp.top();
				temp.pop();
				//if (!temp.empty())	file << endl;
			}
		file.close();
	}







	~Fileoperations()
	{
		while (!this->empty())
		{
			this->pop();
		}
	}
};