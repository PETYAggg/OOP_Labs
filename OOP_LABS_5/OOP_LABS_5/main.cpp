#include "ticket.h"
#include "trainticket.h"
#include "abstract_class.h"
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)
using namespace std;








void Abstract_Output(abstract_clas *A) {
	A->Druk();																//Поліморфна функція
}












int main()
{

	trainticket A("PEtro_keker", 11, 12, 2016, true,"kupe");
	ticket B("Petro_Andr", 11, 12, 2016);
	A.Sell();
	B.Sell();

	Abstract_Output(&A);
	cout << endl;
	Abstract_Output(&B);
	cout << endl;

	
	system("pause");

	return 0;

}