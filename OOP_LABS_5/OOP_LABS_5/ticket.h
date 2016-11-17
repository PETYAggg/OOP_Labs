#pragma once
#include "abstract_class.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;



 class ticket : public abstract_clas
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
	friend istream& operator >> (istream& a, ticket &b)
	{
		a >> b.name;
		a >> b.date.day;
		a >> b.date.month;
		a >> b.date.year;
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

	void Druk() {
		cout << "///////////////////////////////////////" << endl;
		int k = name.size();
		cout << "//" << "  " << name << "  " << setw(34 - k); cout << "//" << endl;
		cout << "//" << "  Date: " << date.day << "." << date.month << "." << date.year << "  " << setw(18) << "//" << endl;
		cout << "//" << " Personal number: " << getNumbering() << " " << setw(12) << "//" << endl;
		cout << "///////////////////////////////////////" << endl;
	}
	

	~ticket() { }
};

void outputTicket(ticket a);

void sortTickets(ticket *& A, int n);



//int ticket::number[] = { 0 };