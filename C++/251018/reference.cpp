#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void reference_main();
void replace(int x, int y);

void reference_main()
{
	int szam1, szam2;
	cout << "Kerek egy szamot "; cin >> szam1; cout << endl;
	cout << "Kerek egy masik szamot "; cin >> szam2; cout << endl;

	cout << "A csere elott " << szam1 << " " << szam2 << endl;
	replace(szam1, szam2);
	cout << "A csere utan " << szam1 << " " << szam2 << endl;

}

void replace(int x, int y)
{
	int temp = 0;
	temp = x;
	x = y;
	y = temp;
}
/*
A csere nem történt meg, mert a main scope nem ugyanaz mint a replace scope
*/