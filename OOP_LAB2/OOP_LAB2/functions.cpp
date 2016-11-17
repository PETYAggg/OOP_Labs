#include <stdio.h>
#include "functions.h"
#include <fstream>


#pragma warning (disable : 4996)
using namespace std;



bool showMenu()
{
	WIN32_FIND_DATA FindDataFile;
	HANDLE hf;

	hf = FindFirstFile("D:\\TRY\\OOP_LABS\\lab2\\*.txt ", &FindDataFile);
	if (hf != INVALID_HANDLE_VALUE)
	{
	
		do
		{
			for (int i = 0; FindDataFile.cFileName[i]; ++i)
				cout << char(FindDataFile.cFileName[i]);
			cout << endl;
		} while (FindNextFile(hf, &FindDataFile));
		FindClose(hf);
		return true;
	}
	else
	{
		cout << "eror\n\a";
		system("pause");
		return false;
	}
}




void outputfromFile(ifstream &f1)
{
	char strichka[1000];

	while (!f1.eof()) {

		f1.get(strichka, 999, '\0');

		puts(strichka);

	}

	cout << endl;

}


void stekInput(ifstream &f1, stek *&p1)
{


	char temp[2];
	char *temper, *toCopy;
	int strSize = 0;
	int i = 0;

	while (!f1.eof())
	{

		if (f1.get(temp, 2, '\0'))
		{
			if (temp[strlen(temp) - 1] == '\n')
			{
				push(p1, temp, i);
				i++;
			}

			else
			{
				strSize += strlen(temp);
				toCopy = new char[strSize + 1];
				strcpy(toCopy, temp);
				do
				{
					f1.get(temp, 2, '\0');
					strSize += strlen(temp);
					temper = new char[strlen(toCopy) + 1];
					strcpy(temper, toCopy);
					delete toCopy;
					toCopy = new char[strSize + 1];
					strcpy(toCopy, temper);
					strcat(toCopy, temp);
				} while (temp[strlen(temp)-1 ] != '\n' && !f1.eof() && temp[strlen(temp) ] != '\n');

				push(p1, toCopy, i);
				i++;
				if (toCopy != 0)
					delete toCopy;
				if (temper != 0)
					delete temper;


			}

		}
	}
}



void push(stek *&p1, char *line, int position)
{
	stek	*temphead = p1, *temphelp, *input;


	input = new stek;
	input->line = new char[strlen(line) + 1];
	strcpy(input->line, line);



	if (position == 0) {

		temphelp = p1;

		p1 = input;
		p1->adr = temphelp;
		return;
	}
	for (int i = 1; i < position && temphead != NULL; i++) {
		temphead = temphead->adr;
		if (temphead == NULL) { cout << "error no head"; return; }
	}
	temphelp = new stek;
	temphelp = temphead->adr;
	temphead->adr = input;
	input->adr = temphelp;


}

void numberStek(stek *p1, int number)
{
	stek *temp = p1;
	char *reserve;
	int tempnumber = number, count = 0;


	while (p1)
	{

		count = 0;
		tempnumber = number;
		while (tempnumber)
		{
			tempnumber = tempnumber / 10;
			count++;
		}
		tempnumber = number;


		reserve = new char[strlen(p1->line) + tempnumber + 2];
		strcpy(reserve, p1->line);
		if (p1->line) delete p1->line;




		for (int i = 0; i < count + 1; i++)
			for (int j = strlen(reserve); j >= 0; j--)
				reserve[j + 1] = reserve[j];



		for (int i = count - 1; i >= 0; i--)
		{
			reserve[i] = (tempnumber % 10) + 48;
			tempnumber = tempnumber / 10;
		}
		reserve[count] = ':';
		number++;




		p1->line = new char[strlen(reserve) + 1];
		strcpy(p1->line, reserve);
		p1 = p1->adr;


		if (reserve != 0) delete reserve;

	}
	p1 = temp;


}

void pop(stek*& p1)
{
	if (p1 == NULL)
		return;

	stek *toDel = p1;
	p1 = p1->adr;

	if (toDel->line != 0)
		delete toDel->line;

	delete toDel;
}

void stekOutput(stek *&p1)
{
	while (p1 != NULL)
	{
		if (p1->line)	cout<<p1->line;

		if (p1->line[strlen(p1->line) - 1] != '\n')
			cout << endl;
		

		pop(p1);
	}
}