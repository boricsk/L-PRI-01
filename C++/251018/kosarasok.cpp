#include <iostream>
#include <iomanip>

using namespace std;
/// <summary>
/// Egy max. 12 f�s kos�rcsapat adatait t�roljuk egy struct-ban.
/// T�roljuk a j�t�kosok nev�t,magass�g�t �s a dobott pontokat.
/// Feladatok
/// Bek�ri a l�tsz�mot elle�rz�tten (5-12 f�)
/// Bek�ri a neveket
/// A t�bbi adathoz v�letlensz�m gener�tort haszn�ljunk. Mag 170-220 a pontok 0-100 k�z�tt legyenek
/// Irassuk ki az adatokat t�bl�zatosan
/// Sz�m�tsuk ki a pont�tlagot
/// Adjuk meg a legmagasabb j�t�kos nev�t
/// Sz�moljuk meg h�nyan dobtat 50p felett.
/// </summary>

struct kosaras
{
	string nev;
	int mag;
	int pont;
};

void kiirat(kosaras csapat[15], int letszam);
float atlagotszamol(kosaras csapat[15], int letszam);
string legmagasabb(kosaras csapat[15], int letszam);
int db50pontfelett(kosaras csapat[15], int letszam);

kosaras csapat[15];

void kmain()
{
	int letszam = 0;
	srand((unsigned int)time(NULL));
	do {
		cout << "Kerem a csapat letszamot :"; cin >> letszam;
		cin.ignore();
	} while (letszam < 5 || letszam > 12);
	
	cout << endl;

	for (int i = 0; i < letszam; i++)
	{
		cout << "Kerem a(z) " << i + 1 << " jatekos nevet ";
		cin >> csapat[i].nev;
		csapat[i].pont = rand() % 101;
		csapat[i].mag = rand() % (220 - 170) + 170;
	}

	kiirat(csapat, letszam);
	cout << endl;
	cout << "A pontatlag :" << atlagotszamol(csapat, letszam) << endl;
	cout << "A legmagasabb jatekos :" << legmagasabb(csapat, letszam) << endl;
	cout << "50 pont felettiek szama :" << db50pontfelett(csapat, letszam) << endl;


	cout << "Hihi";
}

void kiirat(kosaras csapat[15], int letszam)
{
	system("cls");
	cout.setf(ios::left);
	for (int i = 0; i < letszam; i++)
	{
		cout << setw(25) << "Nev : " << csapat[i].nev << setw(10) << " Mag. : " << csapat[i].mag << setw(10) << " Pont : " << csapat[i].pont << endl;
	}
}

float atlagotszamol(kosaras csapat[15], int letszam)
{
	int atlag = 0;
	for (int i = 0; i < letszam; i++)
	{
		atlag = atlag + csapat[i].pont;
	}
	return (float)atlag / letszam;
}

string legmagasabb(kosaras csapat[15], int letszam)
{
	int maxindex = 0;
	for (int i = 0; i < letszam; i++)
	{
		if (csapat[maxindex].mag < csapat[i].mag) { maxindex = i; }
	}
	return csapat[maxindex].nev;
}

int db50pontfelett(kosaras csapat[15], int letszam)
{
	int db = 0;
	for (int i = 0; i < letszam; i++)
	{
		if (csapat[i].pont > 50) { db++; }
	}
	return db;
}
