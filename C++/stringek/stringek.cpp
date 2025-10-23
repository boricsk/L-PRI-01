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
	// Csak 14 karaktert tesz bele, mert a 15. a lez�r� karakter
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

void chartomb()
{
	char nev[15];
	cout << "Kerem a nevet szokozzel elvalasztva."; cin >> nev;
	cout << "A neved :" << nev << endl; //cin csak a sz�k�zig olvas, ez�rt csak a csal�dn�v lesz benne.
	//--------------------
	//A cin.getline megoldja a probl�m�t.
	char nev2[15];
	cout << "Kerem a nevet szokozzel elvalasztva." << endl; 
	cin.getline(nev2,15);
	cout << "A neved :" << nev2;
}

/// <summary>
/// // Vers bek�r�se soronk�nt max 60 karakter --- 
// K�rj�k be egy v�ltoz�ba, hogy (max. 4) h�ny soros verset akarunk beolvastatni!
// A feladat p�lda billenty�zet puffer �r�t�s�re is.
// A bek�rt vers ki�rat�sa nagybet�sen, sz�moljuk meg h�ny sz� van a versben!
/// </summary>
void vers()
{
	int dbszo= 0, sorszam = 0;
	char vers[4][60];
	do
	{
		cout << "Hany soros a vers (max 4) "; cin >> sorszam;
	} while (sorszam < 1 || sorszam > 4);

	cin.ignore();

	for (int i = 0; i < sorszam; i++)
	{
		cout << "A vers " << i + 1 << " sora :"; cin.getline(vers[i], 60);
	}

	for (int i = 0; i < sorszam; i++)
	{
		cout << vers[i] << endl;
	}

	cout << endl;
	for (int i = 0; i < sorszam; i++)
	{
		for (int j = 0; j < strlen(vers[i]); j++) {
			cout << (char)toupper(vers[i][j]);
			if (vers[i][j] == ' ') { dbszo++; }
		}
		cout << endl;
	}
	cout << "A szavak szama : " << dbszo + sorszam << endl;
}


int main()
{
	vers();

	//compare();
	return 0;
}