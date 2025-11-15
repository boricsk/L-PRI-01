/*
Egy maximum 12 fõs jéghoki csapat adatait tároljuk egy struktúra tömbben.
Tároljuk a játékosok nevét, játékidejét, és lõtt góljait.

Feladat:

 1, Kérje be ellenõrzötten a csapat létszámát (5-12)										4 pont

 2, Hozzon létre egy megfelelõ struktúrát és tömböt az adatok tárolására!					4 pont
  Töltse fel a struktúratömböt adatokkal úgy, hogy a nevet billentyûzetrõl kérje be!		5 pont
  A név vezeték és keresztnevet is tartalmazhat szóközzel elválasztva!
  A játékidõt véletlengenerátorral állítsa elõ (0-60 perc)!									3 pont
  A lõtt gólokat is billentyûzetrõl kérje be ellenõrzötten, az értékük 0-5 között lehet!	2 pont

3, Írassa ki az adatokat táblázatosan!														4 pont
4, Számítsa ki hány gólt lõtt a csapat összesen!											6 pont
5, Ki játszott a legtöbbet (adja meg a nevét és góljainak számát)!							8 pont
6, Számolja meg hányan lõttek legalább egy gólt?											7 pont
7, Írassa ki azoknak a nevét és játékidejét, akik legalább 20 percet a pályán töltöttek!	7 pont

A kiíratás mintája:
1. Kiss Beno	56 perc	0 gól
2. Samu Oszkar	 7 perc	3 gól
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

struct hoki
{
	string nev;
	int jatekido;
	int gol;
};

int konz7_feladat5()
{
	hoki csapat[12];
	hoki csapat20perc[12];
	int letszam = 0, osszgol = 0, legaktivabbIndex = 0, min1GolDb = 0, csapat20percIndex = 0;
	srand((unsigned int)time(NULL));

	while (letszam < 5 || letszam > 12)
	{
		cout << "Kerem a latszamot "; cin >> letszam;
		if (letszam < 5 || letszam > 12) { cout << "Hibas bevitel!" << endl; }
		cin.ignore();
	}

	for (int i = 0; i < letszam; i++)
	{
		cout << "Kerem a(z) " << i + 1 << " jatekos nevet :"; getline(cin, csapat[i].nev);
		while (csapat[i].gol < 0 || csapat[i].gol > 5) {
			cout << "Kerem a(z) " << i + 1 << " jatekos goljait :"; cin >> csapat[i].gol;
			if (csapat[i].gol < 0 || csapat[i].gol > 5) { cout << "Hibas bevitel!" << endl; }
			cin.ignore();
		}
		csapat[i].jatekido = rand() % 61;

		osszgol += csapat[i].gol;
		if (csapat[i].jatekido > csapat[legaktivabbIndex].jatekido) { legaktivabbIndex = i; }
		if (csapat[i].gol >= 1) { min1GolDb++; }
		if (csapat[i].jatekido >= 20)
		{
			csapat20perc[csapat20percIndex].nev = csapat[i].nev;
			csapat20perc[csapat20percIndex].gol = csapat[i].gol;
			csapat20perc[csapat20percIndex].jatekido = csapat[i].jatekido;
			csapat20percIndex++;
		}
	}

	system("cls");
	cout.setf(ios::left);

	for (int i = 0; i < letszam; i++)
	{
		cout << "Nev :" << setw(20) << csapat[i].nev << setw(4) << csapat[i].jatekido << " perc " << setw(2) << csapat[i].gol << " gol." << endl;
	}

	cout << "A csapat osszes goljainak szama : " << osszgol << endl;
	cout << "A legtobbet " << csapat[legaktivabbIndex].nev << " jatszott es " << csapat[legaktivabbIndex].gol << "-t lott." << endl;
	cout << "Legalabb 1 golt " << min1GolDb << " jatekos lott." << endl;

	cout << "Legalabb 20 percet a lenti jatekosok jatszottak: " << endl;
	for (int i = 0; i < csapat20percIndex; i++)
	{
		cout << "Nev :" << setw(20) << csapat20perc[i].nev << setw(4) << csapat20perc[i].jatekido << " perc " << setw(2) << csapat20perc[i].gol << " gol." << endl;
	}

	return 0;
}