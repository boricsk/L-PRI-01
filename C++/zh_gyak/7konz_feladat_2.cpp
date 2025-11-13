// Adott egy 5 dolgozóból álló brigad. Tároljuk a dolgozók nevét és fizetését!
// Kérjük be az adatokat írjuk ki táblázatosan és számoljuk ki az össz fizetést!
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct dolgozo {
	string nev;
	int fizu;
};

int konz7_feladat2()
{
	dolgozo csapat[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Kerem a " << i + 1 << " dolgozo nevet "; getline(cin, csapat[i].nev); 
		cout << "Kerem a " << i + 1 << " dolgozo fizetesset "; cin >> csapat[i].fizu;
		cin.ignore(); //Mivel ciklusban van a bekérés törölni kell a buffert ha a köv. getline lesz.
	}

	system("cls");
	cout.setf(ios::left);
	int fizu_summ = 0;
	for (int i = 0; i < 5; i++) {
		cout << setw(10) << csapat[i].nev << "\t" << csapat[i].fizu << endl;
		fizu_summ += csapat[i].fizu;
	}
	cout << "Az ossz fizu : " << fizu_summ << endl;
	return 0;
}