#include <iostream>
#include <stack>
#include <string>
#include "stackclass.h"
#include <iterator>
#include <fstream>
#include "Fileoperations.h"
using namespace std;



	int main()
	{ 
		
		Fileoperations b;
		b.push("Some text");
		b.push("text text text text");
		b.push("Hello");
		b.renumber();
		b.reverse();			//���� ������ reverse
		b.outputInConsole();

		cout << endl << endl;

		Fileoperations c;
		ifstream kek("kek.txt");
		c.push_s(kek);						//���� ������ push_s
		c.push_s(kek);
		c.push_s(kek);

		c.outputInConsole();
		c.outputInFile("out.txt");
		
		c.makeNumberedCopy("kek.txt");		//���� ��������� ������������� ��ﳿ �����
		cout << endl << endl;

	
		
		system("pause");
		return 0;
	}