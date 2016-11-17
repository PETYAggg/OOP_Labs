#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

struct stek {
	char* line;
	stek *adr;
};


void outputfromFile(FILE *f1); //Вивід з файла на екран

void stekInput(FILE *&f1, stek *&p1);  //Ф-ція, що щитує файл у стек, приймає у параметри вершину стеку який потрібно заповнити


void stekOutput(stek *&p1); //Виводить стек і видаляє його


void numberStek(stek *p1, int number);//Нумерує стек за заданою вершиною і числом з якого починати рахунок


void push(stek *&p1, char* line, int position); //Вставляє елемент у стек . Приймає у параметри елемент що потрібно вставити і позицію на яку вставити

void pop(stek*& p1);   //видаляє елемент ща вказаним вказівником


