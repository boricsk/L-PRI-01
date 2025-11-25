/*
Feladat:

A Helsinkiben rendezett nyári olimpián a magyar sportolók által elért helyezéseket a
Helsinki.txt állományban tároljuk a következő módon. Az állomány soronként tartalmazza
az 1952-es nyári olimpián elért pontszerző helyezéseket (1−6. hely). Az első három
helyezés egyben azt is jelentette, hogy arany-, ezüst- vagy bronzérmet szerzett a
sportoló vagy a csapat. Az adatokat egy ; választja el egymástól.

Például:
1;1;atletika;kalapacsvetes   ez azt jelenti, :
− első adat az elért helyezés, jelen esetben "1"
− második adat a helyezést elérő sportoló vagy csapat esetén sportolók száma, jelen esetben: "1" .
− a harmadik adat a sportág neve, jelen esetben "atletika” .
− a negyedik adat a sportágon belül a versenyszám neve, jelen esetben "kalapacsvetes" .

Írjunk egy C++ nyelvű programot amely végrehajtja az alábbi feladatokat! Az egyes részfeladatokat
függvényekkel oldja meg, melyek neveit megadjuk, ill. az adatok tárolásához lehetőség szerint
dinamikus tömböt használjunk ahol lehet!

1. Olvassa be a Helsinki.txt állományban lévő adatokat és tárolja el egy olyan adatszerkezetbe,
amely a további feladatok megoldására alkalmas!  Nem tudjuk, hány sor van az állományban. ( Beolvas() függvény)
2. Határozza meg és írja ki a képernyőre, hogy hány pontszerző helyezést értek el a magyar versenyzők! (Pontszerzok())
3. Készítsen statisztikát a megszerzett érmek számáról, majd összesítse az érmek számát ! (Ermek() )
4. Az olimpián az országokat az elért eredményeik alapján rangsorolják. Az 1−6. helyezéseket olimpiai
pontokra váltják, és ezt összegzik. Határozza meg és írja ki a minta szerint az elért olimpiai pontok
összegét az alábbi táblázat segítségével! ( Ossz_pont() ).

Helyezés Olimpiai pont
1.                         7
2.                         5
3.                         4
4.                         3
5.                          2
6.                          1

5. Az úszás és a vívás sportágakban világversenyeken mindig jól szerepeltek a magyar versenyzők. Határozza
meg és írja ki melyik sportágban szereztek több érmet a sportolók! Ha az érmek száma egyenlő, akkor az
"Egyenlő volt az érmek száma” felirat jelenjen meg! (Tobb_erem()).
6. Hozzon létre egy eredmeny.txt szöveges állományt amelybe kiírja azokat a sportágakat ahol aranyérmet
szereztünk. Minden sportág neve új sorba kerüljön és a nevek csak egyszer szerepeljenek. (Kiir() ).

Megjegyzések:

Először az adatok tárolására deklaráljunk egy négy adattaggal rendelkező struktúra típust. Mivel a feladatban dinamikus
tömböt kell alkalmazni a programban az adatok tárolására, de a tömb méretét még nem ismerjük,  célszerű a Pontszerzok()
és a Beolvas() függvények sorrendjét felcserélni. Először a Pontszerzok() függvényben az állomány megnyitása után
megszámoljuk a sorok( helyezések ) számát és a függvény ezt az értéket adja vissza. Így válaszolni tudunk a 2. feladat
kérdésére, ill. azt is megtudjuk, hogy mekkora tömböt kell lefoglalni az adatok számára.
Az Ermek() függvényben egyszerűen megszámoljuk a 4-nél kisebb(1-3) helyezések számát egy 3 elemű tömböt felhasználva.
Az Ossz_pont() függvényben hozzunk létre egy segédtömböt int pont[6] = { 7,5,4,3,2,1 }; ahol a helyezésekért járó pontokat
tároljuk. Ezután menjünk végig az adatokon és összegezzük a helyezésekért járó pontokat.
A Tobb_erem() függvényben számoljuk meg egy két elemű tömb segítségével a két sportág előfordulás számát az állományban
(használhatunk e tömb helyett két változót is), majd hasonlítsuk össze melyikből volt több. A függvény vagy a sportág
nevét vagy az "Egyenlo volt az ermek szama” stringet adja vissza.
Végül a Kiir() függvényben hozzunk létre egy tömböt az első helyezést elért sportágak tárolására. Mivel nem ismerjük
ennek a számát ugyan akkorát kell létrehoznunk mint az eredeti tömb. Válogassuk ki az első helyezett sportágakat
ebbe a tömbbe, de figyeljünk arra, ha már a nevek között szerepel a sportágnév akkor ne tegyük oda.
Végük írjuk ki a sportágak neveit az eredmeny.txt állományba.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct helsinki
{
	int helyezes;
	int sportolok_szama;
	string sportag;
	string versenynev;
};

struct statistika
{
	int helyezesek;
	int aranyerem;
	int ezusterem;
	int bronzerem;
	int osszpont;
	string tobb_erem;
};

int beolvas(string filenev, helsinki* tomb, int db);
int pontszerzok(string filenev);
void ermek(helsinki* tmb, int helyezes, statistika* stat);
void ossz_pont(helsinki* tmb, int helyezes, statistika* stat);
void tobb_erem(helsinki* tmb, int helyezes, string sportag0, string sportag1, statistika* stat);

void helsinki_main()
{
	statistika* stat;
	stat = new statistika;
	string file = "Helsinki.txt";
	int helyezes_szam = pontszerzok(file);
	cout << "A helyezes szam " << helyezes_szam << endl;
	stat->helyezesek = helyezes_szam;

	helsinki* tmb;
	tmb = new helsinki[helyezes_szam];

	beolvas(file, tmb, helyezes_szam);
	ermek(tmb, helyezes_szam, stat);
	ossz_pont(tmb, helyezes_szam, stat);
	tobb_erem(tmb, helyezes_szam, "uszas", "vivas", stat);
}

void tobb_erem(helsinki* tmb, int helyezes, string sportag0, string sportag1, statistika* stat)
{
	int db[2] = { 0 };
	string result;
	for (int i = 0; i < helyezes; i++)
	{
		if (tmb[i].helyezes < 4)
		{
			if (tmb[i].sportag == sportag0) { db[0]++; }
			if (tmb[i].sportag == sportag1) { db[1]++; }
		}
	}
	result = "Mibol volt tobb erem " + sportag0 + " vagy " + sportag1 + " : ";

	if (db[0] > db[1]) { result += sportag0 + "\n"; }
	else if (db[0] == db[1]) { result += sportag1 + "\n"; }
	else { result += "ugyanannyi ermet szereztek.\n"; }
	stat->tobb_erem = result;
	cout << result << endl;
}

void ossz_pont(helsinki* tmb, int helyezes, statistika* stat)
{
	int pont[6] = { 7,5,4,3,2,1 };
	int osszpont = 0;

	for (int i = 0; i < helyezes; i++)
	{
		osszpont += pont[tmb[i].helyezes - 1];
	}
	cout << "Az osszpontszam : " << osszpont << endl;
	stat->osszpont = osszpont;
}

void ermek(helsinki* tmb, int helyezes, statistika* stat)
{
	int ermek[3] = { 0 };
	for (int i = 0; i < helyezes; i++)
	{
		if (tmb[i].helyezes < 4) { ermek[tmb[i].helyezes - 1]++; }
	}
	cout << "Aranyerem : " << ermek[0] << endl;
	cout << "Ezusterem : " << ermek[1] << endl;
	cout << "Bronzerem : " << ermek[2] << endl;
	stat->aranyerem = ermek[0];
	stat->ezusterem = ermek[1];
	stat->bronzerem = ermek[2];
}

int pontszerzok(string filenev)
{
	ifstream be(filenev);
	if (be.fail()) { cout << "File olvasasi hiba!"; exit(1); }
	string seged;
	int i = 0;

	while (!be.eof())
	{
		getline(be, seged);
		i++;
	}
	be.close();
	return i;
}

int beolvas(string filenev, helsinki* tomb, int db)
{
	ifstream be(filenev);
	if (be.fail()) { cout << "File olvasasi hiba!"; exit(1); }
	string seged;
	int i = 0;
	while (!be.eof())
	{
		getline(be, seged);
		int pos1 = seged.find(' ');
		int pos2 = seged.find(' ', pos1 + 1);
		int pos3 = seged.find(' ', pos2 + 1);

		tomb[i].helyezes = stoi(seged.substr(0, pos1));
		tomb[i].sportolok_szama = stoi(seged.substr(pos1 + 1, pos2 - pos1));
		tomb[i].sportag = seged.substr(pos2 + 1, pos3 - (pos1 + pos2));
		tomb[i].versenynev = seged.substr(pos3 + 1, seged.length() - pos3);

		//getline(be, seged,' ');
		//tomb[i].helyezes = stoi(seged);
		//getline(be, seged, ' ');
		//tomb[i].sportolok_szama = stoi(seged);
		//getline(be, tomb[i].sportag, ' ');
		//getline(be, tomb[i].versenynev, ' ');
		i++;
	}
	be.close();
	return 0;
}