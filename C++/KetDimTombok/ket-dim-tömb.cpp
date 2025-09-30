#include <iostream>
using namespace std;

void hom()
{
	float HOM[4][7], atlag = 0;
	int i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 7; j++)
		{
			cout << "Kerem a homersekletet " << i + 1 << ". het " << j + 1 << ". nap." << endl;
			cin >> HOM[i][j];
			atlag = atlag + HOM[i][j];
		}
	}
	cout << "Havi atlag : " << atlag / (i * j) << endl;

	for (i = 0; i < 4; i++)
	{
		cout << "A(z) " << i + 1 << ". heten mert homersekletek: ";
		for (j = 0; j < 7; j++)
		{
			cout << HOM[i][j] << " ";
		}
		cout << endl;
	}
}
/*
Adott egy 8 f�s t�volugr� verseny d�nt�j�nek v�geredm�nye (a versenyz�k ugr�sai) egy t�mbben t�rolva. �rjunk programot amely v�laszt ad az al�bbi k�rd�sekre:
1, Mekkora volt az ugr�sok �tlaga?
2, H�nyan ugrottak az �tlag felett?
3, H�nyan teljes�tett�k a nemzetk�zi szintet( >= 800cm)
4, Mekkora volt a gy�ztes eredm�ny ?
*/
void verseny()
{
	int tavol[8] = { 650, 0, 827, 820, 799, 850, 798, 770 };
	float atlag = 0.0;
	int i = 0;
	//�tlag

	for (i = 0; i < 8; i++)
	{
		atlag = atlag + tavol[i];
	}
	cout << "Az atlag : " << atlag / 8 << endl;	
	
	
	atlag = atlag / 8;
	int count = 0;
	//�tlag felett ugr�k sz�ma
	for (i = 0; i < 8; i++) {
		if (tavol[i] > atlag) { count++; }
	}
	cout << "Atlag feletti ugrasok szama: " << count << endl;

	//Hanyan teljesitettek a nemzetkozi szintet?
	count = 0;
	int level = 800;
	for (i = 0; i < 8; i++) {
		if (tavol[i] > level) { count++; }
	}
	cout << "A nemzetkozi szintet teljesitok szama :" << count << endl;

	//Mekkora volt a gyoztes eredmeny?
	int max = 0;
	for (i = 0; i < 8; i++) {
		if (tavol[i] > max) { max = tavol[i]; }
	}
	cout << "A legnagyobb ugras :" << max << endl;
}


void main()
{
	//hom();
	verseny();
}