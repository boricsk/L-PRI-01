//Példaprogram struktúra tip. változó létrehozására, értékadásra, képernyõtörlésre és formátumozott kiírásra.
//Tároljuk egy tanuló nevét, matematika jegyét és az érte kapott kreditet!
//Írjuk ki az adatokat formátumozottan a képernyõre! 
#include <iostream>
#include <iomanip>
using namespace std;

struct tanulo
{
	char nev[25];
	int matek;
	int kredit;
}t;

int konz7_feladat1()
{
	t.matek = 5;
	t.kredit = 20;
	cout << "Kerem a nevet : "; cin.getline(t.nev, 25); cout << endl;

	system("cls");
	cin.setf(ios::left);
	cout << "Adatok" << endl;
	cout << setw(10) << "Nev\t" << "Matek\t" << "Kredit" << endl;
	cout << setw(10) << t.nev << "\t" <<t.matek <<"\t" << t.kredit << endl;

	return 0;
}