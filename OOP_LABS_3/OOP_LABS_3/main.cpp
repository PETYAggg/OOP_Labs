#include "ticketsell.h"
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)
using namespace std;

int main()
{

	ofstream f("kek.txt");
	ticket a,b,c, *A;
	cin >> a;
	cin >> b;
	cin >> c;

	a.Sell();
	b.Sell();
	c.Sell();
	

	A = new ticket[3];
	A[0] = a;
	A[1] = b;
	A[2] = c;

	sortTickets(A, 3);


	cout << A[0];
	cout << A[1];
	cout << A[2];
	
	f.close();
	system("pause");
	
	return 0;

}