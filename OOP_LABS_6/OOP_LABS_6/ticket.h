#pragma once
#include "abstract_class.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;



class ticket : public NumberOfObjects, public Stringtoobject
 {
protected:
	static int number[7];
	int Pnumber[7];
	bool sold;
	void numbering();
	char control;
	
public:

	string name;
	struct date_struct
	{
		int day;
		int month;
		int year;
	};
	date_struct date;

	ticket();
	ticket(string a);
	ticket(string your_name, int day, int month, int year);
	ticket(ticket & a);
	ticket(ifstream &a);

	bool isSold();
	string getNumbering();
	string getGlobalCount();
	string getName();
	string getDate();


	void getFromFile(ifstream &k);
	void inputInfo();


	void Annulate();


	void Sell();
	void Sell(string Name);
	void Sell(string Name, int day, int month, int year);


	bool operator<(ticket &a)
	{
		if (date.year < a.date.year)return true;
		else
			if (date.month < a.date.month)return true;
			else
				if (date.day < a.date.day)return true;
				else return false;
	}
	bool operator>(ticket &a)
	{
		if (date.year > a.date.year)return true;
		else
			if (date.month > a.date.month)return true;
			else
				if (date.day > a.date.day)return true;
				else return false;
	}
	bool operator==(ticket &a)
	{
		if (name == a.name && date.day == a.date.day && date.month == a.date.month && date.year == a.date.year) return true;
		else return false;
	}

	friend ostream& operator<<(ostream& a, ticket & b)
	{
		a << b.name << endl;
		a << b.getDate() << endl;
		a << b.getNumbering() << endl;
		b.isSold() ? a << "sold" << endl : a << "not sold" << endl;
		return a;

	}

	friend ostream& operator<<(ostream& a, ticket * b)
	{
		a << b->name << endl;
		a << b->getDate() << endl;
		a << b->getNumbering() << endl;
		b->isSold() ? a << "sold" << endl : a << "not sold" << endl;
		return a;

	}
	friend istream& operator >> (istream& a, ticket &b)
	{
		a >> b.name;
		a >> b.date.day;
		a >> b.date.month;
		a >> b.date.year;
		return a;

	}
	friend istream& operator >> (istream& a, ticket *b)
	{
		a >> b->name;
		a >> b->date.day;
		a >> b->date.month;
		a >> b->date.year;
		return a;

	}

	friend ofstream& operator<<(ofstream& a, ticket &b)
	{
		a << b.name << endl;
		a << b.getDate() << endl;
		a << b.getNumbering() << endl;
		b.isSold() ? a << "sold" << endl : a << "not sold" << endl;
		return a;
	}
	friend ifstream& operator >> (ifstream& a, ticket &b)
	{
		a >> b.name;
		a >> b.date.day;
		a >> b.date.month;
		a >> b.date.year;
		return a;

	}



	int getNumber()
	{
		int sum = 0;
		int in = 0;
		string s = getNumbering();

		for (in = 0; in <= 6; in++)
			if (s[in] != 48) break;


		for (int k = in; k <= 6; k++)
		{

			int t = 7 - k;
			int temp = (s[k] - 48);

			for (int i = 1; i < t; i++)
			{

				temp = temp * 10;

			}
			sum += temp;

		}
		return sum;

	}
	
	int getQuantity()
	{


		string s = getGlobalCount();
		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int t = s.length() - i;
			int temp = (s[i] - 48);

			for (int i = 1; i < t; i++)
			{

				temp = temp * 10;

			}
			sum += temp;
		}
		return sum;
	}

	string getStringFromObject()
	{
		stringstream a;
		a <<name<<" ";
		a <<getDate();
		a << getNumbering()<<" ";
		isSold() ? a << "sold"<<" " : a << "notsold"<<" " ;
		return a.str();
	}

	void getObjectFromRow(string row)
	{
		stringstream a;
	a<<row;
	a >>  name;
	a>>date.day;
	a>>date.month;
	a>>date.year;
	}
	
	~ticket() { }
};

void outputTicket(ticket a);

void sortTickets(NumberOfObjects  **A, int n);

void Sort(vector<NumberOfObjects*> &);



istream& operator >> (std::istream &stream, Stringtoobject* obj);
ostream& operator << (std::ostream &stream, Stringtoobject* obj);


//int ticket::number[] = { 0 };