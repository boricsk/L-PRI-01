//Összegzés. Csoportátlag
/*
Be: tomb[0..14] //int : i:=0 //int
Ki: sum
Algoritmus
	Ciklus i = 0 tól 14-ig
		szum := szum + tomb[i]
	Ciklus vége
	Kiir: sum / i //float

Algoritmus vége
*/
#include <iostream>
using namespace std;

int tomb6[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

void osszegzes()
{
	cout << "Osszegzes. Csoportatlag" << endl;
	int i = 0;
	int sum = 0;
	for (i = 0; i < 15; i++)
	{
		sum = sum + tomb6[i];
	}

	cout << "Az atlag " << (float)sum / i;
}