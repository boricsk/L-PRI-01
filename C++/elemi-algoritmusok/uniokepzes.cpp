/*
Bemenet A[1..N], B[1..M]
Kimenet C[1..cdb]

Algoritmus
	Ciklus i:= 1 tõl N-ig
		C[i] := A[i]
	ciklus vége

	cdb := N

	ciklus j := 1 tõl M-ig
		i := 1
		ciklus amíg i <= N és A[i] <> B[j]
			i:= i + 1
		ciklus vége

		ha (i>N) akkor 
			cdb := cdb + 1 : C[cdb] := B[j]		
		elágazás vége

	ciklus vége
Algoritmus vége
*/
#include <iostream>

using namespace std;

void uniokepzes()
{
	int A[5] = { 1,2,3,4,8 };
	int B[4] = { 7,5,9,6 };
	int C[(sizeof(A) + sizeof(B)) / sizeof(int)] = { 0 };
	int cdb = 0, i = 0, j = 0;
	int N = 5 - 1; //0-tól kezdett index miatt
	int M = 4 - 1; //0-tól kezdett index miatt
	
	for (i = 0; i < 5; i++)
	{
		C[i] = A[i];
	}

	cdb = N; //A C pozíciót beállítjuk a 4-ra, innen folytatjuk.

	for (j = 0; j < 4; j++)
	{
		i = 1;
		while (i <= N && A[i] != B[j])
		{
			i = i + 1;
		}
		if (i > N) { cdb = cdb + 1; C[cdb] = B[j]; }
	}

	for (int k = 0; k < 9; k++)
	{
		cout << C[k] << " ";
	}

}