#include <iostream>
using namespace std;

void elm_feladat_1();
void elm_feladat_2();
void elm_feladat_3();
void elm_feladat_4();
void elm_feladat_5();
void elm_feladat_6();
void elm_feladat_7();
void elm_feladat_8();
void elm_feladat_9();
void elm_feladat_10();
void elm_feladat_11();
void elm_feladat_12();
void elm_feladat_13();
void elm_feladat_14();
void elm_feladat_15();
void elm_feladat_16();
void elm_feladat_17();
void elm_feladat_18();
void elm_feladat_19();
void elm_feladat_20();
void elm_feladat_21();
void elm_feladat_22();
void elm_feladat_23();
void elm_feladat_24();
void elm_feladat_25();


void elm_main()
{
	elm_feladat_25();
}

// Hányszor fut le a lenti ciklus?
void elm_feladat_1()
{
	int i = 2;
	while (i < 3) i++;

	cout << i;
	//Egyszer fut le
}

//Mi lesz a kimenete a lenti kifejezésnek?
void elm_feladat_2()
{
	int k = 5, b = 1;
	cout << 2 / k + b % 3;

	//		0 + 1 = 1
	//Az int miatt lesz 0 az osztás
}

//Mi lesz a kimenete a lenti kifejezésnek?
void elm_feladat_3()
{
	int a = 2, b = 6;
	cout << a % 2 + b % 3;
	//0 + 0 = 0
}

//Mi lesz a kimenete a lenti kifejezésnek?
void elm_feladat_4()
{
	int tomb[2][3] = { 1, 1, 2 }; // => [112][000]
	cout << tomb[1][1];
	//0 Mert az init során 0-val tölti ki azt, amit nem adtunk meg.
	//Az elsõ sor
	//112
	//A második sor
	//000 Ezt nem adtuk meg.
}

//Mi lesz az x értéke a ciklus lefutása után?
void elm_feladat_5()
{
	int x = 0, i = 0;
	for (i = 2; i < 4; i++)
	{
		x = x + 1;
		if (i == 2) break;
	}
	cout << x;
	//1
}

//Adjon meg egy C++ kifejezést, ami akkor igaz ha az x változó háromjegyû, pozitív, páratlan egész szám
void elm_feladat_6()
{
	int x = 999;
	if (x > 99 && x % 2 != 0 && x < 1000) { cout << "True"; }
	else
	{
		cout << "False";
	}
}

//Írjon egy olyan kifejezést C++ nyelven, ami akkor igaz, ha G egész szám belül esik, a 25 és 35 zárt intervallumon!
void elm_feladat_7()
{
	int G = 36;
	if (G >= 25 && G <= 35) { cout << "True"; }
	else
	{
		cout << "False";
	}
}

//Mennyi lesz az i ciklusváltozó és az x változó értéke a ciklus lefutása után?
void elm_feladat_8()
{
	int x = 2, i;
	for (i = 0; i < 1; i++)
	{
		x = x - 1;
	}
	cout << i << " " << x;
	// i = 1
	// x = 1
}

//A char szoveg[10]=”ZOLTAN” értékadás után mennyi lesz a szoveg[1] értéke?
void elm_feladat_9()
{
	char szoveg[10] = "ZOLTAN";
	cout << szoveg[1];
	//O
}

//Mit ír ki a programrészlet?
void elm_feladat_10()
{
	int b = 10, z[3] = { 2,4,3 };
	switch (z[2])
	{
	case 1: b = b + 5;
	case 2: b = b + 10; break;
	case 3: b = b + 15;
	}

	cout << b; //25
}

//Mit ír ki a mprogram?
float Fx(int* t, int x);

void elm_feladat_11()
{
	int szam = 2;
	int tmb[2] = { 4.3,3.5 };
	cout << Fx(tmb, szam);
}

float Fx(int* t, int x)
{
	float seged = 0;
	for (int i = 0; i < x; i++)
		seged = seged + t[i];

	if (seged > 7) return 1;
	return 0;

}

//Mit ír ki a mprogram?
void elm_feladat_12()
{
	int a = 5, b = 2, c = 10, er;
	er = a % b * c;						// 5%2 = 1 *10 = 10
	cout << "\n eredmeny= " << er;		//......................2 pont 

	b = 2;
	double val_er = 1 / 2 * 2 + 12;		//13 -> 12 Az 1 / 2 egész osztas, ezért a double-n 0.
	cout << "\n eredmeny=" << val_er;  	//.....................2 pont 

	int i = 0, tmb[5] = { 1,2,3,4,5 };
	do {
		tmb[i] = 3 * i;
		i++;
	} while (i < 3);					//6
	cout << "\n tmb[2]= " << tmb[2];	//......................2 pont 
	cout << endl;

	a = 2; b = 15;
	switch (a)
	{
	case 0: b = b + 1;
	case 1: b = 3;
	case 2: b = 100;
	case 3: b = 350;
	}									//350
	cout << " b= " << b;				//......................2 pont 	
}

//Mit ír ki a mprogram?
void elm_feladat_13()
{
	int f = 20, *mut;
	int& fi = f;
	
	mut = &f;
	cout << "f=" << f << " *mut= " << *mut << endl;		//20-------------	2pont 

	fi = f * *mut;
	cout << "fi=" << fi << " *mut= " << *mut << endl;   //400-------------	2pont 
}

/*
Mi a hiba az alábbi programrészekben
1./	
int i , k=10;				//---------------	2pont
for(i=0, i<12, ++i )
{ k+=i;}
, helyett ; kell a forba

2./	
int tomb[3]={2};
cin<<  tomb[1]; 				//---------------	2pont
<< helyett >> kell

3./	
int main
{
	int j=1, i=2;
	j = j+2;
}								//---------------	2pont
Main-nál nincs ()

4./	
int *szam, hosz=5;
szam = hossz;
cout << hossz << endl; 			//---------------	2pont
Hiányzik az & cimképzõ operátor. Nem lehet pointernek értéket adni.
*/

/*
5, A C++ nyelv szabályait figyelembe véve mely függvénydeklarációk szabályosak az alábbiak közül?

int* FV(int a, int b);				->OK
int (int a, int *);					->* nem lehet név
float H(int &, *k);					->*k nak nincs típusa
double C (int a, c, float x);		->c nek nincs tipusa


a, Mind a 4 jó
b, egyik sem jó
c, Az 1, 2, 4 a jó
d, 1, 2 a jó
e, 2,3,4 a jó
f, az 1, 3 a jó
g, az 1 a jó						//---------------	2pont

A válaszom : g
*/

//Hányszor fut le a ciklus?
void elm_feladat_14()
{
	int i = 1;
	while (i < 3) { i++; cout << "X"; }
	
	//2x
}

//Mi lesz az értéke a kifejezésnek?
void elm_feladat_15()
{
	int k = 4, b = 2;
	cout << 2 / k + b % 3;
	//0 + 2 = > 2
}

//Mi lesz az értéke a kifejezésnek?
void elm_feladat_16()
{
	int a = 2, b = 6;
	cout << a % 2 + b % 3;
	//0 + 0 = > 0
}

//Mit ír ki?
void elm_feladat_17()
{
	int Tomb[2][3] = { 1,1,2,3,4 };
	cout << Tomb[1][1];
	//4
}

//Mi lesz az x értéke?
void elm_feladat_18()
{
	int x = 1, i;
	for (i = 0; i < 4; i++)
	{		
		x = x + 1;
		if (i == 2) break;
	}
	cout << x;
	//4
}

//Adjon meg egy C++ kiejezéstamely akkor igaz, ha x változó 10 nél kisebb páratlan egész
void elm_feladat_19()
{
	int x = -2;
	if (x < 10 && x % 2 != 0) { cout << "T"; }
	else { cout << "F"; }
}

//Írjon egy olyan kifejezést C++ nyelven: ami akkor igaz, ha G egész szám kívül esik, a 25 és 35 zárt intervallumon!
void elm_feladat_20()
{
	int G = 25;
	if (G < 25 || G > 35) { cout << "T"; }
	else { cout << "F"; }
}

//Mennyi lesz az i ciklusváltozó és az x változó értéke a ciklus lefutása után?
void elm_feladat_21()
{
	int x = 2, i;
	for (i = 0; i < 1; i++)
	{
		x = x + 1;
	}
	cout << i << " " << x;
	//i 1 x 3
}

//A char szoveg[15]=”SAMUKA” értékadás után mennyi lesz a szoveg[3] értéke?
void elm_feladat_22()
{
	char szoveg[15] = "SAMUKA";
	cout << szoveg[3];
	//U
}

//Mit ír ki?
void elm_feladat_23()
{
	int b = 10, z[3] = { 2,4,3 };
	switch (z[2])
	{
	case 1:b = b + 5; break;
	case 3:b = b + 10;
	case 5:b = b + 15;
	}
	cout << b; //35
}

//Mit ír ki?
void elm_feladat_24()
{
	int valt = 10;					//sima int 10 értékkel
	int* m;							//egy ponter ami int-re fog majd mutatni
	m = &valt;						//m (pointer) értéke legyen az a memóriacím, ami a valt-ra mutat
	valt = *m * valt;				//valt legyen egyenlõ az m pointerben tárolt címre mutató érték szorozva valt-ban lévõ értékkel
	cout << valt << "\t" << *m;		//100 100 mert a valt erteke változott a szorzással
}

//Mit ír ki?
int FGV(int, int);

int FGV(int x, int y)
{
	return 2 * y / x;
}

void elm_feladat_25()
{
	float sz1 = 3.5, sz2 = 4;
	cout << FGV(sz1, sz2); // 2 * 4 / 3 => 2 az int miatt nem 2.6 
}