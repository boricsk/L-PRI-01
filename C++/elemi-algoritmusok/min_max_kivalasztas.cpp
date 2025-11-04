/*
Bemenet: tomb[0..14] //int : i //int : min := 1 // int
Kimenet: tomb[min]
Algoritmus
Ciklus i := 0 tól 14-ig 1-essével
	ha (tomb[i] < tömb[min]) akkor min :=i
	elágazás vége
ciklus vége
Ki: tomb[min] : Ki: min
Algoritmus vége
*/

#include <iostream>
using namespace std;

int tomb5[15] = { 10,34,56,4,57,45,67,6,43,32,33,99,33,100,21 };

void min_max_kivalasztas()
{	
	cout << "Minimum maximum kivalasztas" << endl;

	int i, min = 0;
	for (i = 0; i < 15; i++) {
		if (tomb5[i] < tomb5[min]) min = i;
	}

	cout << "Minimum: " << tomb5[min] << " helye: " << min << endl;
}