/*
Bemenet : A[1..N] rendezett sorozat, Z //Keresendõ
Kimenet : Sorsz -> Z elem sorszáma, ha van
Algoritmus :
	AH := 1 //Alsó határ
	FH := N //Felsõ határ
	Ciklus
		i := egészrész((AH + FH) / 2)
		HA(A[i] < Z) AH := i + 1
		HA(A[i] > Z) AH := i - 1
	amíg (AH <= FH és A[i] <> Z)

	HA (AH <=FH) akkor Sorsz := i
Algoritmus vége
*/

#include <iostream>
using namespace std;

void log_kereses2();

int tomb7[15] = { 1, 4, 6, 12, 32, 33, 33, 34, 43, 45, 56, 57, 67, 99, 100 }; //Rendezettnek kell lenni
int nagytomb[10000] = { 0 };

void log_kereses()
{
	int AH = 0, FH = 19, Z = 12, lepes = 0, i;
	do
	{
		i = (AH + FH) / 2;
		if (tomb7[i] < Z) { AH = i + 1;  }
		if (tomb7[i] > Z) { FH = i - 1;  }
		lepes++;
	} while (AH <= FH && tomb7[i] != Z);

	if (AH <= FH) { cout << "A pozicio : " << i << " lepesszam : " << lepes << endl; }
	log_kereses2();
}

void log_kereses2()
{
	int i = 0, j = 3;
	int AH = 0, FH = 9999, Z = 8532, lepes = 0;

	do 
	{
		nagytomb[i] = j;
		i++; 
		j = j + 3;
	} while (i < 10000);

	do
	{
		i = (AH + FH) / 2;
		if (nagytomb[i] < Z) { AH = i + 1; }
		if (nagytomb[i] > Z) { FH = i - 1; }
		lepes++;
	} while (AH <= FH && nagytomb[i] != Z);

	if (AH <= FH) { cout << "A nagytomb pozicio : " << i << " lepesszam : " << lepes << endl; }
	else { cout << Z << " Nem talalhato." << endl; }

}