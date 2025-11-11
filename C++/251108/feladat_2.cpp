/*
Irjunk progit, ami a szöveg.txt-t beolvassa és kiirja a képernyõre egy int Beolvas(char fnev[]) használatával
Számoljuk meg a sorok számát

int Szamol(char fnev[], char betu)
Kérjük be a betu karaktert és számoljuk meg hányszor szerepel

void Titkosít(char fnev[], char betu)
Az elõbb bekért karaktereket cseréljük ki * ra

Minden függvény esetén olvassuk be a filet
*/

#include <fstream>
#include <istream>
#include <iostream>

using namespace std;

int Beolvas(char fnev[]);
int Szamol(char fnev[], char betu);
void Titkosit(char fnev[], char betu);
int Feladat2Main();

int Feladat2Main()
{
	char filename[] = "szoveg.txt";
	char szamolando;
	cout << "A sorok szama : " << Beolvas(filename) << endl;
	cout << "Kerek egy karaktert :";  cin >> szamolando; cout << endl;
	cout << "A(z) " << szamolando << " karakterek szama : " << Szamol(filename, szamolando) << endl;
	Titkosit(filename, szamolando);
	return 0;
}

int Beolvas(char fnev[]) 
{
	int db = 0;
	char sor[100];
	ifstream be(fnev);
	if (be.fail()) { cout << "Hiba"; system("pause"); exit(-1); }
	while (!be.eof())
	{
		be.getline(sor, 100);
		cout << sor << endl;
		db++;
	}
	be.close();
	return db;
}

int Szamol(char fnev[], char betu) 
{
	ifstream be(fnev);
	if (be.fail()) { cout << "Hiba"; system("pause"); exit(-1); }
	char karakter;
	int db = 0;
	while (!be.eof())
	{
		be.get(karakter);
		if (karakter == betu) { db++; }
	}
	be.close();
	return db;
}

void Titkosit(char fnev[], char betu) 
{
	ifstream be(fnev);
	if (be.fail()) { cout << "Hiba"; system("pause"); exit(-1); }
	char karakter;
	while (!be.eof())
	{
		be.get(karakter);
		if (karakter == betu) { karakter = '*'; }
		cout << karakter;
	}
	be.close();
	
}
