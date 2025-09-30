#include <iostream>
using namespace std;

int main()
{
	int tomb[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

	//----------------------------------------------
	cout << "Minimum maximum kiv�laszt�s" << endl;
	/*
	Bemenet: tomb[0..14] //int : i //int : min := 1 // int
	Kimenet: tomb[min]
	Algoritmus
	Ciklus i := 0 t�l 14-ig 1-ess�vel
		ha (tomb[i] < t�mb[min]) akkor min :=i
		el�gaz�s v�ge
	ciklus v�ge
	Ki: tomb[min] : Ki: min
	Algoritmus v�ge
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
		Ciklus i:= 0-t�l 14-ig
			Ha (tomb[i] > 75) akkor segedindex := segedindex + 1 : seged[segedindex] := i + 1
			El�gaz�s v�ge
		Ciklus v�ge
		KI: segedindex
		Ciklus i := 0-t�l segedindex-ig
			Ki: seged[i]
		Ciklus v�ge
	Algoritmus v�ge
	*/
	cout << "Kiv�logat�s. Mennyi 4-es vagy jobb (75-n�l nagyobb) van?" << endl;
	int segedIndex = 0, seged[15];
	i = 0;
	for (i = 0; i < 15; i++)
	{
		if (tomb[i] > 75)
		{
			seged[segedIndex++] = i + 1;
		}
	}
	cout << "N�gyes vagy jobb jegy: " << segedIndex << " db, helye(i): " << endl;
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
		Ciklus 0 t�l 14-ig
			Ha (tomb[i] > 50) akkor megfelelt := megfelelt + 1
			El�gaz�s v�ge
		Ciklus v�ge
		Kiir: megfelelt
	Algoritmus v�ge
	*/
	cout << "Megsz�ml�l�s. H�nyan feleltek meg? (50-n�l nagyobb)" << endl;
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
		t�mbhossz := szizeof(tomb) / sizeof(tomb[0])
		Be: keresendo //int
		Ciklus am�g ( i < tombhossz �s tomb[i] != keresendo)
			i := i + 1
		Ciklus v�ge
		Ha (i != tombhossz) akkor Kiir keresendo: Kiir i
			k�l�nben Kiir "Nincs tal�lat"
	Algoritmus v�ge
	*/

	int keresendo, tombhossz = 0;
	i = 0;
	tombhossz = sizeof(tomb) / sizeof(tomb[0]);

	cout << "Linearis kereses. " << endl;
	cout << "K�rek egy sz�mot: "; cin >> keresendo;

	while (i < tombhossz && tomb[i] != keresendo) { i++; }

	if (i != tombhossz) {
		cout << "A keresett pontszam : " << keresendo << " index :" << i + 1 << endl;
	}
	else {
		cout << "Nincs ilyen pontsz�m!" << endl;
	}

	//----------------------------------------------
	//Kiv�laszt�s. Melyik helyen van az 57 pontos dolgozat
	/*
	Be: tomb[0..14] //int : i:=0 //int
	Ki i
	Algoritmus
		Ciklus am�g (tomb[i] != 57)
			i:= i + 1
		Ciklus v�ge
		Kiir: i + 1
	Algoritmus v�ge
	*/
	cout << "Kiv�laszt�s. Hol van az 57 �rt�k" << endl;
	i = 0;
	while (tomb[i] != 57) { i++; }
	cout << "Az 57. pont a " << i + 1 << "helyen van." << endl;

	//----------------------------------------------
	//Eld�nt�s. Van-e max pontsz�m
	/*
	Be: tomb[0..14] //int : i:=0 //int
	
	Algoritmus
		Ciklus am�g (tomb[i] != 100)
			i:= i + 1
		Ciklus v�ge
		Ha (i < 15) akkor Kiir: "Van" k�l�nben Kiir: "Nincs"

	Algoritmus v�ge
	*/
	cout << "Eld�nt�s. Van-e 100 pontos ZH" << endl;
	i = 0;
	while (tomb[i] != 100) { i++; }

	if (i < 15) { cout << "Van"; }
	else { cout << "Nincs"; }


	//----------------------------------------------
	//�sszegz�s. Csoport�tlag
	/*
	Be: tomb[0..14] //int : i:=0 //int
	Ki: sum 
	Algoritmus
		Ciklus i = 0 t�l 14-ig
			szum := szum + tomb[i]
		Ciklus v�ge
		Kiir: sum / i //float

	Algoritmus v�ge
	*/

	cout << "�sszegz�s. Csoport�tlag" << endl;
	i = 0;
	int sum = 0;
	for (i = 0; i< 15; i++)
	{
		sum = sum + tomb[i];
	}

	cout << "Az �tlag " << (float)sum / i; 
	
	return 0;

}