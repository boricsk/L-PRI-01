/*
Egy 7 fõs korárcsapatról statisztika készült, amely a játékosok nevét, játékidejét
és a dobott pontokat tartalmazta. A statiszika megsérült csak a név maradt meg.
Állítsuk vissza az adatokat, a játékídõ random (0-60) a pontokat (0-12) kérjük
be ellenõrzötten a felhasználótól a névhaz használjuk a jegyzokonyv.txt.t

Irassuk ki táblázatosan
Hány gólt dobott a csapat
Ki dobta a legtöbbet név, pont
Hányan dobtak 6 gól felett
Kik játszottak legalább 20 percet
A helyreállított adatokat mentsük el az uj_jegyzokonyv.txt-be
*/

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int KeziMain();
void DataRepair();

struct jatekos
{
	string nev;
	int jatekido;
	int gol;
};


int KeziMain()
{
	int golok = 0;
	jatekos csapat[7];
	ifstream be("jegyzokonyv.txt");
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 7; i++)
	{
		getline(be, csapat[i].nev);
		csapat[i].jatekido = rand() % 61;
		do {
			cout << "Kerem a(z) " << i + 1 << " jatekos pontjat : "; cin >> csapat[i].gol;
		} while (csapat[i].gol > 12 || csapat[i].gol < 0);
		golok += csapat[i].gol;
	}
	be.close();

	//Táblázatos kiirás
	cout.setf(ios::left);
	for (int i = 0; i < 7; i++)
	{
		cout << "Nev :" << setw(25)<<csapat[i].nev << " Pont :" << setw(5) <<csapat[i].gol << "Jatekido :" << csapat[i].jatekido << endl;
	}

	//Hány gólt dobtak összesen
	cout << "A csapat " << golok << " pontot szerzett." << endl;

	//Ki dobta a legtöbb gólt
	int max_gol_index = 0;
	for (int i = 0; i < 7; i++)
	{
		if (csapat[i].gol > csapat[max_gol_index].gol) { max_gol_index = i; }
	}
	cout << "A legtobb golt " << csapat[max_gol_index].nev << " szerezte" << endl;

	//Hányan dobtak 6 gól felett
	int hat_felett = 0;
	for (int i = 0; i < 7; i++)
	{
		if (csapat[i].gol > 6) { hat_felett++; }
	}

	cout << "6 gol felett " <<hat_felett << " jatekos dobott." << endl;

	//Legalább 20 percet játszottak
	for (int i = 0; i < 7; i++)
	{
		if (csapat[i].jatekido >= 20) 
		{ 
			cout << "Nev :" << setw(25) << csapat[i].nev << "Jatekido :" << csapat[i].jatekido << endl;
		}
	}

	ofstream ki("uj_jegyzokonyv.txt");
	if (ki.fail()) { cout << "Hiba"; system("pause"); exit(-1); }
	for (int i = 0; i < 7; i++)
	{
		ki << csapat[i].nev << " " << csapat[i].gol << " " << csapat[i].jatekido << endl;
	}

	return 0;
}