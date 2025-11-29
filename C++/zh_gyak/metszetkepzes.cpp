#include <iostream>
#include <string>
using namespace std;

void metszet()
{
	string A[8] = { "GIZI", "FERI", "PISTA", "JANI", "SANYI", "MANYI", "Leó", "TEÓ" };
	string N[6] = { "SAMU", "FERI", "PISTA", "JANI", "BELZEBUB", "TEÓ" };
	string M[6];

	int m_index = 0;

	for (int i = 0; i < 8; i++)
	{
		int j = 0;
		do {
			j++;
		} while (j <= 6 && A[i] != N[j]);
		if (j <= 6) { M[m_index] = A[i]; m_index++; }
	}

	for (int i = 0; i < 8; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << N[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << M[i] << " ";
	}
	cout << endl;
}