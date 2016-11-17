#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

struct stek {
	char* line;
	stek *adr;
};

void outputfromFile(ifstream &f1);
void pop(stek*& p1);
void stekOutput(stek *&p1);
void numberStek(stek *p1, int number);
void stekInput(ifstream &f1, stek *&p1); 
void push(stek *&p1, char *line, int position);

bool showMenu();
