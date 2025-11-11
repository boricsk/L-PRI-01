/*
Be : A[1..N], B[1..M]
Ki : C[]

Algoritmus:
	Cdb = 0
	Ciklus i = 1 tõl N-ig
		j:=1
		Ciklus amíg j<=M és A[i] <> B[j]
			j:= j + 1
		Ciklus vége
		Ha (j <= M) akkor Cdb := Cdb + 1 : C[Cdb] := A[i]
	Ciklus vége
Algoritmus vége
*/

#include <iostream>

using namespace std;

void metszetkepzes()
{
	int A[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };
	int B[10] = { 1,36,2,45,87,22,8,13,43,7 };
	int C[15] = { 0 };
	int cdb = 0, j = 0;
	
	cout << "A ";
	for (int i = 0; i < 15; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "B ";
	for (int i = 0; i < 10; i++) {
		cout << B[i] << " ";
	}

	for (int i = 0; i < 15; i++)
	{
		j = 0;
		while (j <= 10 && A[i] != B[j])
		{
			j = j + 1;
		}
		if (j <= 10) { C[cdb] = A[i]; cdb = cdb + 1;  }
	}

	cout << endl;
	cout << "C ";
	for (int i = 0; i < 15; i++) {
		cout << C[i] << " ";
	}
}