#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

struct stek {
	char* line;
	stek *adr;
};


void outputfromFile(FILE *f1); //���� � ����� �� �����

void stekInput(FILE *&f1, stek *&p1);  //�-���, �� ���� ���� � ����, ������ � ��������� ������� ����� ���� ������� ���������


void stekOutput(stek *&p1); //�������� ���� � ������� ����


void numberStek(stek *p1, int number);//������ ���� �� ������� �������� � ������ � ����� �������� �������


void push(stek *&p1, char* line, int position); //�������� ������� � ���� . ������ � ��������� ������� �� ������� �������� � ������� �� ��� ��������

void pop(stek*& p1);   //������� ������� �� �������� ����������


