/*
Be: tomb[0..14] //int : tombhossz := 0 // int
Ki: i:=0 //int
Algoritmus
	tömbhossz := szizeof(tomb) / sizeof(tomb[0])
	Be: keresendo //int
	Ciklus amíg ( i <= tombhossz és tomb[i] != keresendo)
		i := i + 1
	Ciklus vége
	Ha (i != tombhossz) akkor Kiir keresendo: Kiir i
		különben Kiir "Nincs találat"
Algoritmus vége
*/

#include <iostream>
using namespace std;

int tomb3[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

void lin_keres()
{
	int keresendo, tombhossz = 0;
	int i = 0;
	tombhossz = sizeof(tomb3) / sizeof(tomb3[0]);

	cout << "Linearis kereses. " << endl;
	cout << "Kerek egy szamot: "; cin >> keresendo;

	while (i <= tombhossz && tomb3[i] != keresendo) { i++; }

	if (i <= tombhossz) {
		cout << "A keresett pontszam : " << keresendo << " hely :" << i + 1 << endl;
	}
	else {
		cout << "Nincs ilyen pontszam!" << endl;
	}
}