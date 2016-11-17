#include <stdio.h>
#include "functions.h"

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)


using namespace std;

int main()
{
	FILE * file = fopen("rofl.txt", "r");

	if (!file) {
		cout << "can't open file ";
		system("pause");
		return 0;

	}

	stek *p1;

	p1 = new stek;
	p1 = NULL;
	//Створення змінних для тесту функцій







	stekInput(file, p1);


	numberStek(p1, 1);



	stekOutput(p1);

	fclose(file);



	system("pause");






	delete p1;
	return 0;

}