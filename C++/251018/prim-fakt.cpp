#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void prim_fakt_main();
double fakt(int n);
bool isPrime(int x);

int szam = 0;

void prim_fakt_main()
{
	cout << "Kerek egy szamot :"; cin >> szam; cout << endl;
	cout << "szam! :" << fakt(szam) << endl;
	if (isPrime(szam)) { cout << "A szam prim." << endl; } else { cout << "A szam nem prim." << endl; }
}

double fakt(int n)
{
	double ret = 1;
	for (int i = 2; i <= n; i++) { ret *= i; }
	return ret;
}

bool isPrime(int x)
{
	int gyok = sqrt(x);
	int i = 2;
	while (i < gyok && x % i != 0) { i++; }

	if (i <= gyok) { return false; }
	else { return true; }
	
}