#include "ticket.h"
#include "trainticket.h"
#include "abstract_class.h"
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)
using namespace std;


void Output(Stringtoobject *A)
{
	cout<<A->getStringFromObject();
}






int main()
{
	NumberOfObjects * a[3];
	
	ticket *q = new ticket;
	q->Sell("Kek", 11, 12, 2016);
	a[0] = q;
	
	ticket *w = new ticket;
	w = new trainticket;
	
	a[1] = w;
	
	ticket *e = new ticket;
	e = new ticket;
	e->Sell("Kok", 11, 12, 2016);
	w->Sell("Kik", 11, 12, 2016);
	a[2] = e;
	for (int i = 0; i <= 2; i++)cout << (ticket *)a[i] << endl;

	sortTickets( a, 3);

	for (int i = 0; i <= 2; i++)cout << (ticket *) a[i]<< endl;

	int x;
	cin >> x;




	//vector<NumberOfObjects*> array;

	//ticket* a1 = new ticket;
	//a1->Sell("first", 11, 22, 2222);
	//array.push_back(a1);

	//ticket* a2 = new ticket;
	//a2->Sell("second", 11, 22, 2222);
	//

	//ticket* a3 = new ticket;
	//a3->Sell("third", 11, 22, 2222);
	//array.push_back(a3);
	//array.push_back(a2);

	//trainticket* a4 = new trainticket;
	//a4->Sell("lol", 11, 23, 2313);
	//array.push_back(a4);
	//Sort(array);
	//
	//for (int i = 0; i <= 3; i++)
	//{
	//	cout << (ticket *)array[i] << endl;
	//	
	//}
	
	
	ticket *aka=new ticket("rofler", 11 ,12 ,2016);

	string str = aka->getStringFromObject();
	cout << str<<endl;
	aka->Sell("keker",30,12,2016);
	cout << aka << endl << endl;
	aka->getObjectFromRow(str);
	cout << aka << endl;
	
	

	system("pause");
	return 0;
}













