#include <iostream>

using namespace std;
/// <summary>
/// Egy max. 12 fõs kosárcsapat adatait tároljuk egy struct-ban.
/// Tároljuk a játékosok nevét,magasságát és a dobott pontokat.
/// Feladatok
/// Bekéri a létszámot elleõrzötten (5-12 fõ)
/// Bekéri a neveket
/// A többi adathoz véletlenszám generátort használjunk. Mag 170-220 a pontok 0-100 között legyenek
/// Irassuk ki az adatokat táblázatosan
/// Számítsuk ki a pontátlagot
/// Adjuk meg a legmagasabb játékos nevét
/// Számoljuk meg hányan dobtat 50p felett.
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