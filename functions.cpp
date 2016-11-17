

#include <stdio.h>
#include "functions.h"

#pragma warning (disable : 4996)
using namespace std;



void outputfromFile(FILE *f1)
{
	char strichka[1000];

	while (!feof(f1)) {

		fgets(strichka, 999, f1);

		puts(strichka);

	}

	printf("%s \n", " ");

}

void stekInput(FILE *&f1, stek *&p1)
{


	char temp[3];
	char *temper, *toCopy;
	int strSize = 0;
	int i = 0;

	while (!feof(f1))
	{

		if (fgets(temp, 3, f1))
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
					fgets(temp, 3, f1);
					strSize += strlen(temp);
					temper = new char[strlen(toCopy) + 1];
					strcpy(temper, toCopy);
					delete toCopy;
					toCopy = new char[strSize + 1];
					strcpy(toCopy, temper);
					strcat(toCopy, temp);
				} while (temp[strlen(temp) - 1] != '\n' && !feof(f1));

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
		if (temphead == NULL) { printf("%s %s \n", "error "); return; }
	}
	temphelp = new stek;
	temphelp = temphead->adr;
	temphead->adr = input;
	input->adr = temphelp;


}


void pop(stek*& List)
{
	if (List == NULL)
		return;

	stek *toDel = List;
	List = List->adr;

	if (toDel->line != 0)
		delete toDel->line;

	delete toDel;
}

void stekOutput(stek *&List)
{
	while (List != NULL)
	{
		if (List->line)	printf(List->line);

		if (List->line[strlen(List->line) - 1] != '\n')
			printf("\n");

		pop(List);
	}
}

