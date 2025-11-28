/*
Egy 16 csapatos labdarúgó bajnokság egyik fordulójának eredményeit tároljuk a merkozes.txt állományban.
Ebben a fordulóban nem biztos, hogy 8 mérkõzés volt, néhány meccs elmaradt a rossz idõjárás miatt.
Minden mérkõzés eredménye új sorban van és a gólok v. mint a csapatok száma szóközzel elválasztva. (3 2 ute vac)

Olvassa be a fájlt egy olyan adatszerkezetbe, amit az alábbi kérdésekhez fel tud használni (struktúra))!

1, Írassa ki hány mérkõzés volt a fordulóban!
2, Hány csapat nyert otthon?
3, Melyik csapat rúgta a legtöbb gólt?
4, Volt -e döntetlen?
5 Hány gólt lõtt az ute? ( nem biztos, hogy játszott)
6, Rendezze a csapatokat névsor szerint növekvõ sorrendben és írja ki a csapatok.txt állományba!

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct futball
{
	int csapat1gol;
	int csapat2gol;
	string csapat1nev;
	string csapat2nev;
};

struct futballStat
{
	string nev;
	int gol;
};

void foci()
{
	string befileNev = "merkozes.txt";
	string kifileNev = "csapatok.txt";
	futball* csapat;
	futballStat* statisztika;
	string* csapatok;
	string seged;
	int db = 0, i = 0, otthoniGyozelemDb = 0, dontetlenDb = 0, uteGolok = 0, csapatokIndex = 0, statisztikaIndex = 0, golkiralyIndex = 0;
	ifstream be(befileNev);
	if (be.fail()) { cout << "Hiba!"; exit(1); }

	do
	{
		getline(be, seged);
		db++;
	} while (!be.eof());

	cout << "A forduloban " << db << " merkozes volt." << endl;

	csapat = new futball[db];
	csapatok = new string[db * 2];
	statisztika = new futballStat[db * 2];

	be.seekg(0, ios::beg);

	do
	{
		be >> csapat[i].csapat1gol >> csapat[i].csapat2gol >> csapat[i].csapat1nev >> csapat[i].csapat2nev;
		if (csapat[i].csapat1gol > csapat[i].csapat2gol) { otthoniGyozelemDb++; }
		if (csapat[i].csapat1gol == csapat[i].csapat2gol) { dontetlenDb++; }
		if (csapat[i].csapat1nev == "ute") { uteGolok += csapat[i].csapat1gol; }
		if (csapat[i].csapat2nev == "ute") { uteGolok += csapat[i].csapat2gol; }
		
		csapatok[csapatokIndex] = csapat[i].csapat1nev;
		csapatok[csapatokIndex + 1] = csapat[i].csapat2nev;
		csapatokIndex += 2;

		statisztika[statisztikaIndex].nev = csapat[i].csapat1nev;
		statisztika[statisztikaIndex].gol = csapat[i].csapat1gol;
		statisztika[statisztikaIndex + 1].nev = csapat[i].csapat2nev;
		statisztika[statisztikaIndex + 1].gol = csapat[i].csapat2gol;
		statisztikaIndex += 2;
		i++;
	} while (!be.eof());

	be.close();

	cout << "Otthoni gyozott " << otthoniGyozelemDb << " csapat." << endl;
	cout << "UTE golok szama " << uteGolok << endl;
	if (dontetlenDb > 0) { cout << "Volt dontetlen." << endl; }
	else { cout << "Nem volt dontetlen." << endl; }

	for (int i = 0; i < db * 2; i++)
	{
		//cout << statisztika[i].nev << endl;
		if (statisztika[golkiralyIndex].gol < statisztika[i].gol) { golkiralyIndex = i; }
	}

	cout << "A legtobb golt " << statisztika[golkiralyIndex].nev << " szerezte." << endl;

	seged.empty();

	for (int i = 0; i < db * 2 - 1; i++)
	{
		for (int j = i + 1; j < db * 2; j++)
		{
			if (csapatok[j] < csapatok[i]) {
				seged = csapatok[j];
				csapatok[j] = csapatok[i];
				csapatok[i] = seged;
			}
		}
	}

	ofstream ki(kifileNev);
	if (ki.fail()) { cout << "Hiba a file irasa alatt"; exit(1); }

	for (int k = 0; k < db * 2; k++)
	{
		ki << csapatok[k] << endl;
	}

	ki.close();
	delete[] csapat;
	delete[] csapatok;
	delete[] statisztika;

}