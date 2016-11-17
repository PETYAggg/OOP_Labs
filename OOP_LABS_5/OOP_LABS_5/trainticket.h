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

	
	void Druk() {
		cout << "****************************************" << endl;

		int k = name.size();
		cout << "**" << "  " << name << "  " << setw(34 - k); cout << "**" << endl;

		cout << "**" << "  Date: " << date.day << "." << date.month << "." << date.year << "  " << setw(18) << "**" << endl;
		cout << "**" << " Postil: "; postil ? cout << "yes" : cout << "no"; cout << "  " << setw(24) << "**" << endl;
		cout << "**" << " Vagon: " << vagon << " " << setw(25) << "**" << endl;
		cout << "**" << " Personal number: " << getNumbering() << " " << setw(12) << "**" << endl;
		cout << "****************************************" << endl;
	}
};
