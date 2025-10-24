//Eldöntés. Van-e max pontszám
/*
Be: tomb[0..14] //int : i:=0 //int

Algoritmus
	Ciklus amíg (tomb[i] != 100)
		i:= i + 1
	Ciklus vége
	Ha (i < 15) akkor Kiir: "Van" különben Kiir: "Nincs"

Algoritmus vége
*/

#include <iostream>
using namespace std;

int tomb[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

void eldontes()
{
	cout << "Eldontes. Van-e 100 pontos ZH" << endl;
	int i = 0;
	while (tomb[i] != 100) { i++; }

	if (i < 15) { cout << "Van"; }
	else { cout << "Nincs"; }
}