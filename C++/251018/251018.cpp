#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

//Struktúra típus
struct dolgozo
{
	string nev;
	int fiz;
};

struct tanulo
{
	string nev;
	int jegy;
	int szul;
};

void bevitel();
void tablazatosKiiras();
void tanulok();


int main()
{
	tanulok();
	return 0;
}

void tanulok()
{
	tanulo hallg[15];
	int letszam, i, atlag = 0;
	do
	{
		cout << "Kerem a csoport letszamot ";
		cin >> letszam;
		cin.ignore();
	} while (letszam < 1 || letszam > 15);

	for (i = 0; i < letszam; i++)
	{
		cout << "Adja meg a " << i + 1 << " tanulo nevet :";
		getline(cin, hallg[i].nev);

		cout << "Adja meg a " << i + 1 << " tanulo szuletesi evet :";
		cin >> hallg[i].szul;

		do
		{
			cout << "Kerem a jegyet ";
			cin >> hallg[i].jegy;
			cin.ignore();
		} while (hallg[i].jegy < 1 || hallg[i].jegy > 5);
	}
		system("cls");

		cout.setf(ios::left);
		cout << "Az adatok :" << endl;		
		for (i = 0; i < letszam; i++)
		{
			cout << setw(10) << "Nev : " << hallg[i].nev << " Jegy :" << hallg[i].jegy << " Szul : " << hallg[i].szul << endl;
			atlag = atlag + hallg[i].jegy;
		}
		cout << endl;
		cout << "Az atlag :" << (double)atlag / letszam << endl;

		//Ki a legidõsebb
		int idIndex = 0;
		for (i = 1; i < letszam; i++)
		{
			if (hallg[idIndex].szul > hallg[i].szul) { idIndex = i; }
		}

		cout << "A legidosebb tanulo : " << endl;
		cout << setw(10) << "Nev : " << hallg[idIndex].nev << " Jegy :" << hallg[idIndex].jegy << " Szul : " << hallg[idIndex].szul << endl;
	
}

void tablazatosKiiras()
{
	dolgozo csop[5];
	int i, ossz = 0;
	for (i = 0; i < 5; i++)
	{
		cout << "Adja meg a " << i + 1 << " dolgozo nevet. ";
		getline(cin, csop[i].nev);
		cout << "Adja meg a fizut ";
		cin >> csop[i].fiz;
		cin.ignore();
	}

	system("cls");
	cout.setf(ios::left); //balra igazítás beáll.

	for (i = 0; i < 5; i++)
	{
		cout << setw(25) << csop[i].nev << "\t" << csop[i].fiz << endl;
		ossz = ossz + csop[i].fiz;
	}
	cout << "Az osszfizu : " << ossz << endl;
}

void bevitel()
{
	dolgozo csop[5];
	int i, ossz = 0;
	for (i = 0; i < 5; i++)
	{
		cout << "Adja meg a " << i + 1 << " dolgozo nevet. ";
		getline(cin, csop[i].nev);

		cout << "Adja meg a fizut ";
		cin >> csop[i].fiz;
		//Ha a getlinet használod akkor a bill. pufferben benne marad egy enter.
		//a cin meg csak az enterig olvasna. Az ignorral ki lehet szedni a bent
		//maradt értéket.
		cin.ignore();
	}
}