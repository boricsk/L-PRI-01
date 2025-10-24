/*
Be: tomb[0..14] //int
Ki: megfelelt := 0 //int

Algoritmus
	Ciklus 0 tól 14-ig
		Ha (tomb[i] > 50) akkor megfelelt := megfelelt + 1
		Elágazás vége
	Ciklus vége
	Kiir: megfelelt
Algoritmus vége
*/

#include <iostream>
using namespace std;

int tomb4[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

void megszamlalas()
{
	cout << "Megszamlalas. Hanyan feleltek meg? (50-nel nagyobb)" << endl;
	int megfelelt = 0;
	for (int i = 0; i < 15; i++)
	{
		if (tomb4[i] > 50) megfelelt++;
	}
	cout << "Megfelelt: " << megfelelt << " db" << endl;
}