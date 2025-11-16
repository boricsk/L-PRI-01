/*
Bemenet A[1..N] rendezetlen
Kimenet A[1..N] rendezett
Algoritmus
	ciklus 1 tõl N-ig
		ciklus i+1 tõl N-ig
			ha (A[j] < A[i]) akkor
				seged := A[j]
				A[j] = A[i]
				A[i] = seged
			elágazás vége
		ciklus vége
	ciklus vége
Algoritmus vége
*/

#include <iostream>

using namespace std;

void rend_kozv_kiv()
{
	int A[16] = { 70,61,10,44,5,12,16,40,3,31,47,22,24,33,7,46 };
	int N = 16 - 1;
	int seged = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (A[j] < A[i]) {
				seged = A[j];
				A[j] = A[i];
				A[i] = seged;
			}
		}

		for (int k = 0; k < 16; k++)
		{
			cout << A[k] << " ";
		}
		cout << endl;
	}
}