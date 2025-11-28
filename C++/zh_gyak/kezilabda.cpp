/*
Feladat: A kezilabda.txt állományban tároljuk egy kézilabda csapat egyik mérkõzésének statisztikáját.
Tárolják a játékos nevét, dobott góljait és a mérkõzés alatt a pályán töltött idõt percben.
(Csak ékezetmentes betûket írtak)

Pl.
Kovacs 13 40
Fekete 2 23

Minden játékos adata új sorban van és a nevek, pontok, eltöltött idõ szóközökkel elválasztva.
Tudjuk, hogy legfeljebb 10 játékos adatai vannak az állományban (nem biztos, hogy van 10)

1, Olvassa be a fájlt egy olyan adatszerkezetbe, amit az alábbi kérdésekhez fel tud használni! (struktúra))
(Ha nem tudja beolvasni az állományból az adatokat, akkor kérje be õket billentyûzetrõl!)		5 pont

2, Hány gólt dobott a csapat összesen a mérkõzésen?												5 pont

3, Melyik játékos dobta a legtöbb gólt? ( Ha több van elég az elsõ)								7 pont

4, Döntse el dobott-e valaki 6 gól felett!		 (igen/nem)										7 pont

5, Kérjen be egy nevet billentyûzetrõl és döntse el, hogy játszott –e							8 pont
 és ha igen akkor hány percet ?

6, Válogassa ki azoknak a játékosoknak az adatait egy új tömbbe, akik kevesebb
idõt  játszottak, mint az átlag! Írja ki az adatokat a képernyõre!								9 pont

7, Írja ki a képernyõre a játékosok nevét névsor szerint csökkenõ sorrendben!

(bármely rendezést használhatja!)																9 pont

Az egyes feladatokat nem kell függvénnyel megoldani! A forráskódot C++ vagy
C#  nyelven készítse el! Az egyes feladatokat külön-külön oldja meg és a
forráskódban jelölje kommenttel!

PL.
// 2. Hány gólt dobott a csapat összesen - megszámlálás
//4. Döntse el dobott-e valaki 6 gól felett! _Eldöntés
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

struct kezilabda
{
	string nev;
	int gol;
	int jatekido;
};

int kezi()
{
	kezilabda* csapat;
	kezilabda* atlagonAluliCsapat;
	string* jatekosNevek;
	string fileName = "kezilabda.txt";
	string seged;
	int db = 0, i = 0, osszGolok = 0, golkiralyIndex = 0, dbHatGolFelett = 0, jatekosEllenorzesIndex = 0, atlagIndex = 0;
	float atlag = 0;
	string jatekosnev;

	ifstream be(fileName);
	if (be.fail()) { cout << "Hibas fileolvasas!"; exit(1); }

	while (!be.eof())
	{
		getline(be, seged);
		db++;
	}
	be.seekg(0, ios::beg);

	csapat = new kezilabda[db];
	atlagonAluliCsapat = new kezilabda[db];
	jatekosNevek = new string[db];

	while (!be.eof())
	{
		be >> csapat[i].nev >> csapat[i].gol >> csapat[i].jatekido;
		osszGolok += csapat[i].gol;
		if (csapat[i].gol > csapat[golkiralyIndex].gol) { golkiralyIndex = i; }
		if (csapat[i].gol > 6) { dbHatGolFelett++; }
		atlag += csapat[i].jatekido;
		jatekosNevek[i] = csapat[i].nev;
		i++;
	}
	atlag = atlag / db;
	be.close();

	cout << "Az osszgol szam : " << osszGolok << endl;
	cout << "A legtobb golt " << csapat[golkiralyIndex].nev << " dobta." << endl;
	if (dbHatGolFelett > 0) { cout << "Igen" << endl; }
	else { cout << "Nem" << endl; }

	cout << "Kerek egy nevet "; cin >> jatekosnev;

	for (int i = 0; i < db; i++)
	{
		if (csapat[i].nev == jatekosnev) { jatekosEllenorzesIndex = i; }
		if (csapat[i].jatekido < atlag)
		{
			atlagonAluliCsapat[atlagIndex].nev = csapat[i].nev;
			atlagonAluliCsapat[atlagIndex].gol = csapat[i].gol;
			atlagonAluliCsapat[atlagIndex].jatekido = csapat[i].jatekido;
			atlagIndex++;
		}
	}

	if (jatekosEllenorzesIndex != 0) {
		cout << "A " << jatekosnev << " " << csapat[jatekosEllenorzesIndex].jatekido << " percet játszott" << endl;
	}
	else { cout << "A jatekos nincs az adatbázisban." << endl; }

	seged.empty();

	for (int i = 0; i < db - 1; i++)
	{
		for (int j = i + 1; j < db; j++)
		{
			if (jatekosNevek[j] > jatekosNevek[i]) {
				seged = jatekosNevek[j];
				jatekosNevek[j] = jatekosNevek[i];
				jatekosNevek[i] = seged;
			}
		}
	}

	for (int k = 0; k < db; k++)
	{
		cout << jatekosNevek[k] << endl;
	}	

	return 0;
}