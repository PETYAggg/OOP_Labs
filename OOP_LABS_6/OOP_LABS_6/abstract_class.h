#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



class NumberOfObjects {
public:
	virtual int getNumber() = 0;
	virtual int getQuantity() = 0;
	
	
};


class Stringtoobject
{
public:
	virtual void getObjectFromRow(string row) = 0;
	virtual string getStringFromObject() = 0;

};
