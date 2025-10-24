/*
Bemenet: tomb[0..14] //int : i //int : min := 1 // int
Kimenet: tomb[min]
Algoritmus
Ciklus i := 0 t�l 14-ig 1-ess�vel
	ha (tomb[i] < t�mb[min]) akkor min :=i
	el�gaz�s v�ge
ciklus v�ge
Ki: tomb[min] : Ki: min
Algoritmus v�ge
*/

#include <iostream>
using namespace std;

int tomb5[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

void min_max_kivalasztas()
{	
	cout << "Minimum maximum kivalasztas" << endl;

	int i, min = 0;
	for (i = 0; i < 15; i++) {
		if (tomb5[i] < tomb5[min]) min = i;
	}

	cout << "Minimum: " << tomb5[min] << " helye: " << min << endl;
}