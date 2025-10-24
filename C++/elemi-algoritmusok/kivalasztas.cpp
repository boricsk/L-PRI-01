//Kiválasztás. Melyik helyen van az 57 pontos dolgozat
/*
Be: tomb[0..14] //int : i:=0 //int
Ki i
Algoritmus
	Ciklus amíg (tomb[i] != 57)
		i:= i + 1
	Ciklus vége
	Kiir: i + 1
Algoritmus vége
*/

#include <iostream>
using namespace std;

int tomb1[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

void kivalasztas()
{
	cout << "Kivalasztas. Hol van az 57 ertek" << endl;
	int i = 0;
	while (tomb1[i] != 57) { i++; }
	cout << "Az 57. pont a " << i + 1 << "helyen van." << endl;
}