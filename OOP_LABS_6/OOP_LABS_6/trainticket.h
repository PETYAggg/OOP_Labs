#pragma once
#include <iomanip>
#include "ticket.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



class trainticket : public ticket
{
private:
	bool postil;
	
public:

	string vagon;

	
	trainticket()
	{
		ticket();
		vagon = "ekonom";
		postil = false;

	}
	trainticket(string name) : ticket(name)
	{
		
		vagon = "ekonom";
		postil = false;
	}
	trainticket(string your_name, int day, int month, int year) :ticket(your_name, day, month, year)
	{
		
		vagon = " ekonom";
		postil = false;
	}
	trainticket(string your_name, int day, int month, int year, bool Postil, string Vagon): ticket(your_name, day, month, year)
	{
		
		vagon = Vagon;
		postil = Postil;
	}

	/*void  getStringFromObject(trainticket b)
	{
		string a;
		a += b.name;
		a += b.getDate() + " ";
		a += b.getNumbering();
		b.isSold() ? a += "sold" : a += "not sold";
		cout << a;
	}*/

	
};
