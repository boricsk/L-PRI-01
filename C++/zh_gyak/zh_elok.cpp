/*Feladat :
Egy vegyesbolt adatait kell tárolni. Tároljuk az áruk neveit (string),  árát,
és a raktáron lévõ darabszámot!
Hozzunk létre egy az elõbbiek tárolására szolgáló struktúra típusú változót!
Maximum 15 db különféle árúnk lehet (15 elemû a struktúra tömb)!
1. Kérjük  be az árúk számát ellenõrzötten!
2. Kérjük be az áruk neveit! (pl. fekete ribizli szörp)
3. Kérjük be az áruk árát ellenõrzötten(nem lehet 5000 Ft nál nagyobb és 100 Ft- nál kisebb!)
4. Kérjük be az árúk darabszámát véletlengenerátorral (az árúk száma 1 és 10 db között lehet)
5. Írja ki az adatokat táblázatosan!
6. Határozza meg, és írja ki, mennyi az egész árukészlet értéke!
7. Számolja ki az átlagos árat és írja ki a képernyõre !
8. Számolja meg hány áruból van több mint öt raktárkészleten!
9. Írja ki a legdrágább áru nevét és árát!
10. Emelje az árakat 20 %-kal majd írja ki az áruk nevét és új árát!
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

struct aru
{
	string nev;
	int menny;
	int ar;
};

int zh_elok()
{
	aru aruk[15];
	int aru_szama = 0, aru_osszertek = 0, max_index = 0, tobb5 = 0;
	while (aru_szama <= 0 || aru_szama > 15)
	{
		cout << "Kerem az aruk szamat (1-15): "; cin >> aru_szama;
		if (aru_szama < 0 || aru_szama > 15) { cout << "Hibas! 1 es 15 kozotti szamot kerek!" << endl; }
		cin.ignore();
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < aru_szama; i++)
	{
		cout << "Kerem az " << i + 1 << " aru nevet : "; getline(cin, aruk[i].nev);
		aruk[i].menny = rand() % 10 + 1;
		while (aruk[i].ar < 100 || aruk[i].ar > 5000)
		{
			cout << "Kerem az " << i + 1 << " arat : "; cin >> aruk[i].ar;
			if (aruk[i].ar < 100 || aruk[i].ar > 5000) { cout << "A megadott ar hibas! 100-5000 kozott kell lenni!" << endl; }
			aru_osszertek += aruk[i].ar;
			if (aruk[i].ar > aruk[max_index].ar) { max_index = i; }
			if (aruk[i].menny > 5) { tobb5++; }
			cin.ignore();
		}
	}

	system("cls");
	for (int i = 0; i < aru_szama; i++)
	{
		cout << aruk[i].nev << "\t" << aruk[i].menny << "\t" << aruk[i].ar << endl;
	}

	cout << "Az osszertek : " << aru_osszertek << endl;
	cout << "Az atlagar : " << aru_osszertek / float(aru_szama) << endl;
	cout << "5-nel tobb keszlet " << tobb5 << " arubol van." << endl;
	cout << "A legdrababb : " << aruk[max_index].nev << "\t" << aruk[max_index].ar << endl;

	cout << "20% emelés után :" << endl;
	for (int i = 0; i < aru_szama; i++)
	{
		aruk[i].ar = aruk[i].ar * 1.2;
		cout << aruk[i].nev << "\t" << aruk[i].menny << "\t" << aruk[i].ar << endl;
	}

	return 0;
}