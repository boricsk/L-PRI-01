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
Adott egy 8 fõs távolugró verseny döntõjének végeredménye (a versenyzõk ugrásai) egy tömbben tárolva. Írjunk programot amely választ ad az alábbi kérdésekre:
1, Mekkora volt az ugrások átlaga?
2, Hányan ugrottak az átlag felett?
3, Hányan teljesítették a nemzetközi szintet( >= 800cm)
4, Mekkora volt a gyõztes eredmény ?
*/
void verseny()
{
	int tavol[8] = { 650, 0, 827, 820, 799, 850, 798, 770 };
	float atlag = 0.0;
	int i = 0;
	//Átlag

	for (i = 0; i < 8; i++)
	{
		atlag = atlag + tavol[i];
	}
	cout << "Az atlag : " << atlag / 8 << endl;	
	
	
	atlag = atlag / 8;
	int count = 0;
	//Átlag felett ugrók száma
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