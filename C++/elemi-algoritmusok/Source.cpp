#include <iostream>
using namespace std;

int main()
{
	int tomb[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

	//----------------------------------------------
	cout << "Minimum maximum kiválasztás" << endl;
	/*
	Bemenet: tomb[0..14] //int : i //int : min := 1 // int
	Kimenet: tomb[min]
	Algoritmus
	Ciklus i := 0 tól 14-ig 1-essével
		ha (tomb[i] < tömb[min]) akkor min :=i
		elágazás vége
	ciklus vége
	Ki: tomb[min] : Ki: min
	Algoritmus vége
	*/
	int i, min = 0;
	for (i = 0; i < 15; i++) {
		if (tomb[i] < tomb[min]) min = i;
	}

	cout << "Minimum: " << tomb[min] << " helye: " << min << endl;
	cout << endl;

	//----------------------------------------------
	/*
	Bemenet: tomb[0..14] //int : segedIndex := 0 //int
	Kimenet: seged[0..14] //int
	Algoritmus
		Ciklus i:= 0-tõl 14-ig
			Ha (tomb[i] > 75) akkor segedindex := segedindex + 1 : seged[segedindex] := i + 1
			Elágazás vége
		Ciklus vége
		KI: segedindex
		Ciklus i := 0-tól segedindex-ig
			Ki: seged[i]
		Ciklus vége
	Algoritmus vége
	*/
	cout << "Kiválogatás. Mennyi 4-es vagy jobb (75-nél nagyobb) van?" << endl;
	int segedIndex = 0, seged[15];
	i = 0;
	for (i = 0; i < 15; i++)
	{
		if (tomb[i] > 75)
		{
			seged[segedIndex++] = i + 1;
		}
	}
	cout << "Négyes vagy jobb jegy: " << segedIndex << " db, helye(i): " << endl;
	for (i = 0; i < segedIndex; i++)
	{
		cout << seged[i] << " ";
	}
	cout << endl;

	//----------------------------------------------
	/*
	Be: tomb[0..14] //int
	Ki: megfelelt := 0 //int

	Algoritmus
		Ciklus 0 tól 14-ig
			Ha (tomb[i] > 50) akkor megfelelt := megfelelt + 1
			Elágazás vége
		Ciklus vége
		Kiir: megfelelt
	Algoritmus vége
	*/
	cout << "Megszámlálás. Hányan feleltek meg? (50-nél nagyobb)" << endl;
	int megfelelt = 0;
	for (i = 0; i < 15; i++)
	{
		if (tomb[i] > 50) megfelelt++;
	}
	cout << "Megfelelt: " << megfelelt << " db" << endl;
	cout << endl;

	//----------------------------------------------
	/*
	Be: tomb[0..14] //int : tombhossz := 0 // int
	Ki: i:=0 //int
	Algoritmus
		tömbhossz := szizeof(tomb) / sizeof(tomb[0])
		Be: keresendo //int
		Ciklus amíg ( i < tombhossz és tomb[i] != keresendo)
			i := i + 1
		Ciklus vége
		Ha (i != tombhossz) akkor Kiir keresendo: Kiir i
			különben Kiir "Nincs találat"
	Algoritmus vége
	*/

	int keresendo, tombhossz = 0;
	i = 0;
	tombhossz = sizeof(tomb) / sizeof(tomb[0]);

	cout << "Linearis kereses. " << endl;
	cout << "Kérek egy számot: "; cin >> keresendo;

	while (i < tombhossz && tomb[i] != keresendo) { i++; }

	if (i != tombhossz) {
		cout << "A keresett pontszam : " << keresendo << " index :" << i + 1 << endl;
	}
	else {
		cout << "Nincs ilyen pontszám!" << endl;
	}

	//----------------------------------------------
	//Kiválasztás. Melyik helyen van az 57 pontos dolgozat
	/*
	Be: tomb[0..14] //int : i:=0 //int
	Ki i
	Algoritmus
		Ciklus amíg (tomb[i] != 57)
			i:= i + 1
		Ciklus vége
		Kiir: i + 1
	Algoritmus vége
	*/
	cout << "Kiválasztás. Hol van az 57 érték" << endl;
	i = 0;
	while (tomb[i] != 57) { i++; }
	cout << "Az 57. pont a " << i + 1 << "helyen van." << endl;

	//----------------------------------------------
	//Eldöntés. Van-e max pontszám
	/*
	Be: tomb[0..14] //int : i:=0 //int
	
	Algoritmus
		Ciklus amíg (tomb[i] != 100)
			i:= i + 1
		Ciklus vége
		Ha (i < 15) akkor Kiir: "Van" különben Kiir: "Nincs"

	Algoritmus vége
	*/
	cout << "Eldöntés. Van-e 100 pontos ZH" << endl;
	i = 0;
	while (tomb[i] != 100) { i++; }

	if (i < 15) { cout << "Van"; }
	else { cout << "Nincs"; }


	//----------------------------------------------
	//Összegzés. Csoportátlag
	/*
	Be: tomb[0..14] //int : i:=0 //int
	Ki: sum 
	Algoritmus
		Ciklus i = 0 tól 14-ig
			szum := szum + tomb[i]
		Ciklus vége
		Kiir: sum / i //float

	Algoritmus vége
	*/

	cout << "Összegzés. Csoportátlag" << endl;
	i = 0;
	int sum = 0;
	for (i = 0; i< 15; i++)
	{
		sum = sum + tomb[i];
	}

	cout << "Az átlag " << (float)sum / i; 
	
	return 0;

}