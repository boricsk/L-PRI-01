#include <iostream>
using namespace std;

void compare()
{
	char nev1[15], nev2[15];
	cout << "Kerem az elso nevet "; cin.getline(nev1, 15);
	cout << "Kerem a masodik nevet "; cin.getline(nev2, 15);

	cout << endl;
	cout << nev1 << " " << nev2 << " " << strcmp(nev1, nev2);
}

void strings()
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
}

int main()
{


	compare();
	return 0;
}