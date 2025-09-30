#include <iostream>
using namespace std;

int main()
{
	int i;
	char nev1[15], nev2[15];
	// Csak 14 karaktert tesz bele, mert a 15. a lezáró karakter
	cout << "Kerem a nevet :"; cin.getline(nev1, 15);
	strcpy_s(nev2, nev1);
	cout << "A neved : " << nev2 << endl;
	cout << "A nev 2 hossza :" << strlen(nev2) << endl;

	for (i = 0; i < strlen(nev2); i++)
	{
		cout << (char)tolower(nev2[i]);
	}

	cout << endl;

	for (i = 0; i < strlen(nev2); i++)
	{
		cout << (char)toupper(nev2[i]);
	}

	cout << endl;

	if (strcmp(nev1, nev2) == 0) { cout << "Egyformak"; }

	return 0;
}