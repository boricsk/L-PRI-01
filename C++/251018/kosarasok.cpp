#include <iostream>

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

kosaras csapat[15];

void kmain()
{
	srand((unsigned int)time(NULL));

	cout << "Hihi";
}