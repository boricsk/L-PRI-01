#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void reference2_main();
void replace(int *x, int *y);
void pointer_type();

void pointer_type()
{
	int len = 15;
	int *len_pointer;		//Pointer dekl. * => indirekciós operátor
	len_pointer = &len;		//A pointerben a len memóriacíme van
	*len_pointer = 13;		// a len értéke 13
}

void reference2_main()
{
	int szam1, szam2;
	cout << "Kerek egy szamot "; cin >> szam1; cout << endl;
	cout << "Kerek egy masik szamot "; cin >> szam2; cout << endl;

	cout << "A csere elott " << szam1 << " " << szam2 << endl;
	replace(&szam1, &szam2);
	cout << "A csere utan " << szam1 << " " << szam2 << endl;

}

void replace(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}
/*
& -> Pointer átadása (címképző operátor)

Előtte:

szam1 (cím pl. 0x100) értéke = 3
szam2 (cím pl. 0x104) értéke = 7
Hívás: replace(&szam1, &szam2) -> a függvény paraméterei:

x = 0x100 (mutat szam1-re)
y = 0x104 (mutat szam2-re)

A replace belsejében:
temp = *x; → temp = 3
*x = *y; → a cím 0x100-on (szam1) most 7
*y = temp; → a cím 0x104-en (szam2) most 3

Utána:
szam1 = 7, szam2 = 3
*/