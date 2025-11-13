/* Egy max 12 fõs kosárlabda csapat adatait tároljuk egy struktúra tömbben.
* Tároljuk a játékosok nevét, magasságát, és dobott pontjait.
* 1, Kérjük be ellenõrzötten a csapat létszámát (5-12)!
* 2, Töltsük fel a struktúratömböt adatokkal úgy, hogy a nevet billentyûzetrõl kérjük be,
* a magasságot és pontokat véletlengenerátorral állítsuk elõ. A magasság 170- 220 cm, a dobott pontok
* 0-100 között lehetnek.
* 3,Írassuk ki az adatokat táblázatosan!
* 4, Számítsuk ki a csapat pont átlagát!
* 5, Ki a legmagasabb (adjuk meg a nevét)!
* 6, Számoljuk meg hányan dobtak 50 pont felett!
* 7, Kik dobtak 50 felett?
*/

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct kosaras
{
	string nev;
	int mag;
	int pont;
};

int konz7_feladat4()
{
	int letszam = 0, atlag = 0, max_i = 0, db50 = 0, db50_index = 0;
	kosaras csapat[12];
	kosaras csapat50[12];

	while (letszam < 5 || letszam > 12)
	{
		cout << "Kerem a letszamot : "; cin >> letszam;
		cin.ignore();
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < letszam; i++)
	{
		cout << "Adja meg a " << i + 1 << " jatekos nevet "; getline(cin, csapat[i].nev);
		csapat[i].mag = rand() % 51 + 170;
		csapat[i].pont = rand() % 101;
		atlag += csapat[i].pont;
		if (csapat[i].mag > csapat[max_i].mag) { max_i = i; }
		if (csapat[i].pont > 50) 
		{ 
			csapat50[db50_index].mag = csapat[i].mag;
			csapat50[db50_index].nev = csapat[i].nev;
			csapat50[db50_index].pont = csapat[i].pont;
			db50_index++;
			db50++; 
		}
	}

	system("cls");
	for (int i = 0; i < letszam; i++)
	{
		cout << csapat[i].nev << "\t" << csapat[i].mag << "\t" << csapat[i].pont << endl;
	}

	cout << "A pontatlag : " << atlag / (float)letszam << endl;
	cout << "A legmagasabb jatekos : " << csapat[max_i].nev << endl;
	cout << "50 pont feletti jatekosok szama : " << db50 <<". Ezek: " << endl;
	for (int i = 0; i < db50_index; i++)
	{
		cout << csapat50[i].nev << "\t" << csapat50[i].mag << "\t" << csapat50[i].pont << endl;
	}
	return 0;
}
