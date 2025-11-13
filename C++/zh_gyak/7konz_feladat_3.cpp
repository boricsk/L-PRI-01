// Egy hallgatói csoportba max. 15-en járnak.Tároljuk a hallgatók nevét, jegyét és a születési évét!
//Kérjük be a valós csoportlétszámot ellenõrzötten, majd a hallgatói adatokat!
//Írassuk ki az adatokat táblázatosan, számítsuk ki a csoport átlagát, majd írassuk ki a legöregebb hallgató nevét!

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct tanulo
{
	string nev;
	int jegy;
	int szul;
};

int konz7_feladat3()
{
	tanulo csoport[15];
	int letszam = 0, atlag = 0;
	while (letszam < 1 || letszam > 15)
	{
		cout << "Kerem a letszamot "; cin >> letszam;
		cin.ignore(); // Ha van még getline akkor kell!!
	}
	
	for (int i = 0; i < letszam; i++)
	{
		cout << "Kerem a " << i + 1 << " tanulo nevet"; getline(cin, csoport[i].nev);
		cout << "Kerem a " << i + 1 << " tanulo szuletesi evet :"; cin >> csoport[i].szul;

		while (csoport[i].jegy < 1 || csoport[i].jegy > 5)
		{
			cout << "Kerem a jegyet (1-5) "; cin >> csoport[i].jegy;
			cin.ignore();
		} 
		
	}

	system("cls");
	cout.setf(ios::left);
	for (int i = 0; i < letszam; i++)
	{
		cout << setw(10) << "Nev : " << csoport[i].nev << "\t" << "Szuletes " << csoport[i].szul << "\t" << "Jegy :" << csoport[i].jegy << endl;
		atlag += csoport[i].jegy;
	}

	cout << "A csoport atlag : " << atlag / (float)letszam << endl;

	int min_index = 0;
	for (int i = 0; i < letszam; i++)
	{
		if (csoport[i].szul < csoport[min_index].szul) { min_index = 1; }
	}

	cout << "A legidõsebb : " << csoport[min_index].nev << endl;

	return 0;
}