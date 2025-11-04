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

#include <iostream>
using namespace std;

int tomb2[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

void kivalogatas()
{
	cout << "Kivalogatas. Mennyi 4-es vagy jobb (75-nel nagyobb) van?" << endl;
	int segedIndex = 0, seged[15];
	int i = 0;
	for (i = 0; i < 15; i++)
	{
		if (tomb2[i] > 75)
		{
			seged[segedIndex++] = i + 1;
		}
	}
	cout << "Negyes vagy jobb jegy: " << segedIndex << " db, helye(i): " << endl;
	for (i = 0; i < segedIndex; i++)
	{
		cout << seged[i] << " ";
	}
}