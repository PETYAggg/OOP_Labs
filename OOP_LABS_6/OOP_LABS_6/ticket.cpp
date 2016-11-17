#pragma once
#include <iostream>
#include "ticket.h"
#include "abstract_class.h"
#include <string>
#pragma warning (disable : 4996)
using namespace std;
int ticket::number[] = { 0 };

ticket::ticket()
{

	name = "default";
	date.day = 0;
	date.month = 0;
	date.year = 0;
	sold = false;

	for (int i = 0; i <= 6; i++)Pnumber[i] = 0;
}




ticket::ticket(string a) {


	name = a;
	date.day = 0;
	date.month = 0;
	date.year = 0;
	for (int i = 0; i <= 6; i++)Pnumber[i] = 0;
	sold = false;
}

ticket::ticket(string your_name, int day, int month, int year)
{
	name = your_name;
	date.day = day;
	date.month = month;
	date.year = year;
	for (int i = 0; i <= 6; i++)Pnumber[i] = 0;
	sold = false;
}

ticket::ticket(ticket & a)
{
	name = a.name;
	for (int i = 0; i <= 6; i++)
		Pnumber[i] = a.Pnumber[i];
	date.day = a.date.day;
	date.month = a.date.month;
	date.year = a.date.year;

}

ticket::ticket(ifstream &a)
{
	a >> name;
	a >> date.day;
	a >> date.month;
	a >> date.year;
	sold = false;
	for (int i = 0; i <= 6; i++)Pnumber[i] = 0;
}

void ticket::getFromFile(ifstream &k)
{
	k >> name;

}

string ticket::getGlobalCount()
{
	string k;

	/*for (int i = 0; i <= 6; i++)
	{
		k += number[i] + 48;
	}

	return k;*/

	for (int i = 0; i <= 6; i++)
	{
		if (number[i] != 0) k += number[i] + 48;
		
	}
	return k;
}

string ticket::getNumbering()
{
	string k;

	for (int i = 0; i <= 6; i++)
	{
		k += Pnumber[i] + 48;
	}

	return k;
}

void ticket::numbering()
{
	number[6]++;
	for (int i = 6; i >= 0; i--)
	{
		if ((number[i] / 10) != 0)
		{
			number[i - 1]++;
			number[i] = number[i] % 10;
		}
	}

}

string ticket::getName()
{

	return name;

}

string ticket::getDate()
{
	/*char day[3], month[3], year[5];
	string temp1, temp2, temp3;
	sprintf(day, "%d", date.day);
	temp1 = day;
	temp1 += " ";
	sprintf(month, "%d", date.month);
	temp2 = month;
	temp2 += " ";
	temp1 += temp2;
	sprintf(year, "%d", date.year);
	temp3 = year;
	temp3 += " ";
	temp1 += temp3;*/
	stringstream a;
	a << to_string(date.day) << " ";
	a << to_string(date.month) << " ";
	a << to_string(date.year) << " ";

	return a.str();



}

void ticket::Annulate() {
	name = "_annulated";
	sold = false;
}

void ticket::inputInfo() {
	cout << "Input name-> " << endl;
	cin >> name;
	cout << "Input day " << endl;
	cin >> date.day;
	cout << "input month " << endl;
	cin >> date.month;
	cout << "input year " << endl;
	cin >> date.year;

}


void ticket::Sell(string Name)
{
	if (sold)  return;
	if (name == "_annulated")
	{
		name = Name;
		sold = true;
	}
	else
	{
		name = Name;
		sold = true;
		numbering();
		for (int i = 0; i <= 6; i++)Pnumber[i] = number[i];
	}

}

void ticket::Sell()
{
	if (sold) return;
	numbering();

	for (int i = 0; i <= 6; i++)Pnumber[i] = number[i];
	sold = true;

}

void ticket::Sell(string Name, int day, int month, int year)
{

	if (name == "_annulated")
	{
		name = Name;
		sold = true;
		date.day = day;
		date.month = month;
		date.year = year;
	}
	else
	{
		name = Name;
		sold = true;
		date.day = day;
		date.month = month;
		date.year = year;
		numbering();
		for (int i = 0; i <= 6; i++)Pnumber[i] = number[i];
	}
}

bool ticket::isSold()
{
	return sold;
}



void outputTicket(ticket a)
{
	cout << a.getName();
	cout << endl;
	cout << a.getDate();
	cout << endl;
	cout << a.getNumbering();
	cout << endl;
	a.isSold() ? cout << "sold" : cout << "not sold";
	cout << endl;
}



void sortTickets(NumberOfObjects ** A, int n)
{
	bool temp = true;
	
	while (temp)
	{
		temp = false;
		for (int i = 1; i <n; i++)
		{	
			if (A[i - 1]->getNumber() > A[i]->getNumber())
			{
				NumberOfObjects *temper = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temper;
				temp = true;
				
			}
		}

	}


}




void Sort(vector<NumberOfObjects*> & array)
{
	

	for (int i = 0; i < array.size(); i++)
	{
		for (int j = array.size() - 1; j > i; j--)
		{

			if (array[j-1]->getNumber() > array[j]->getNumber())
			{
				NumberOfObjects *tmp = array[j-1];
				array[j-1] = array[j];
				array[j] = tmp;
			}
		}
	}


	

}




ostream& operator << (ostream &stream, Stringtoobject* obj)
{
	cout << "kek";
	return stream << obj->getStringFromObject();
}
istream& operator >> (istream &stream, Stringtoobject* obj)
{
	string temp;
	stream >> temp;
	obj->getObjectFromRow(temp);
	return stream;
}