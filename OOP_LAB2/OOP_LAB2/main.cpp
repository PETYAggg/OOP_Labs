#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include "functions.h"

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)



using namespace std;
int main()
{
	ifstream f1;

	if (!showMenu()) return 0;


	string name; 
	cout << "Enter name of file -> ";
	getline(cin, name);
	system("cls");


	f1.open(name);
	if (!f1.is_open())
	{
		std::cout << "\aCould not open file " << name;
		exit(EXIT_FAILURE);
	}

	stek *p1;
	p1 = new stek;
	p1 = NULL;
	/*outputfromFile(f1);*/
	stekInput(f1, p1);
	numberStek(p1, 1);
	stekOutput(p1);

	system("pause");

	return 0;
}