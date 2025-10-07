#include <iostream>

using namespace std;

void test();

int practice() {
	int a = 3;
	cout << a * 2 << endl;

	a = 5;
	cout << a / 2.0 << endl;

	a = 10;
	a++;
	cout << a << endl;

	a = 5;
	int b = ++a; //Els� k�rben n�vel, majd �rt�ket ad. a++ eset�n 5 lenne mert a hozz�rendel�s ut�n n�vekszik.
	cout << b << endl;

	cout << (3 > 2 || 2 > 1) << endl;

	a = 4;
	cout << a % 2 << endl; //Marad�kos oszt�s

	double d = 5 / 2;
	cout << d << endl; //2.0

	d = 5.0 / 2;
	cout << d << endl; //2.0

	int i = 0;
	while (i < 3) {
		cout << i << " ";
		i++;
	}
	cout << endl;

	for (int q = 1; i <= 3; i++) {
		cout << q * 2 << " ";
	} //2 4 6
	cout << endl;

	a = 5;
	if (a > 3) cout << "OK";
	cout << endl;

	if (a < 3) cout << "NO"; else cout << "YES";
	cout << endl;

	a = 10;
	if (a == 10) cout << "1";
	else cout << "0";
	cout << endl;

	cout << (true || false) << endl;

	cout << (true && false) << endl;

	cout << 7 / 2 << endl;

	cout << 7 / 2.0 << endl;

	i = 3;
	cout << i++ + 1 << endl; //4

	i = 3;
	cout << ++i + 1 << endl; //5

	cout << (3 * 2 + 4) << endl; //10

	cout << 3 * (2 + 4) << endl; //18

	cout << (5 > 3) << endl;

	cout << (5 < 3 && 2 < 1) << endl;//0

	d = 5 / 2;
	cout << d << endl; //2.0

	d = 5.0 / 2;
	cout << d << endl; //2.5

	cout << (int)5.8 << endl; //5

	a = 2;
	b = 3;
	cout << (a == b) << endl; //0

	a += 3;
	cout << a << endl; //5



	return 0;
}

//Adjuk �ssze az eg�sz sz�mokat 1-t�l a bek�rt sz�mig.
void osszead()
{
	int n, sum = 0;
	cout << "Kerem a szamot: "; cin >> n; cout << endl;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	cout << "Az osszeg: " << sum << endl;
}

void osszead2()
{
	int n, sum = 0;
	cout << "Kerem a szamot: "; cin >> n; cout << endl;
	int i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	cout << "Az osszeg: " << sum << endl;
}

//K�rj�nk be egy szamot a billenty�r�l �s d�nts�k el, hogy prim-e?
void prime()
{
	int iter = 2, szam, osztokszama = 0;
	cout << "Kerem a szamot :"; cin >> szam; cout << endl;
	int szamfele = szam / 2;
	while (iter <= szamfele && osztokszama == 0)
	{
		if (szam % iter == 0)
		{
			osztokszama++;
		}
		iter++;
	}
	if (osztokszama > 0) { cout << "Nem prim" << endl; }
	else { cout << "Prim" << endl; }
}

//�rjunk programot, amely bek�r a billenty�zetr�l egy pontsz�mot 0 �s 100 k�z�tt, ha a pont 51 pont alatt van, ki�rja, hogy megbukott ellenkez� esetben megfelelt az eredm�ny!

void ertekel()
{
	int pont = 0;
	do
	{
		cout << "Kerem a pontszamot :"; cin >> pont; cout << endl;
		if (pont > 100 || pont < 0) { cout << "Hibas ertek" << endl; }
	} while (pont < 0 || pont > 100); //Az && nem is logikus ide, mert egy sz�m nem lehet kisebb 0 �s nagyobb 100-n�l egyszerre.
	if (pont > 51) { cout << "Megfelelt" << endl; }
	else { cout << "Bukta" << endl; }
}

//Egy csoportba max 15-en j�rhatnak. K�rj�k be egyenk�nt a csoport mat jegyeit(1-5)  
//�s t�roljuk egy JEGY[] t�mbben! Minden bek�r�s ut�n k�rdezz�k meg van-e m�g adat (Y)?!
// �rassuk ki t�bl�zatos form�ban a jegyeket egy �j ciklussal
// �s sz�m�tsuk ki a csoport �tlag�t! 
int jegy()
{
	int jegy[15], i, atlag = 0, letszam = 0;
	char betu;

	do
	{
		do
		{
			cout << "Adja meg a " << letszam + 1 << ". tanulo jegyet :";
			cin >> jegy[letszam];
		} while (jegy[letszam] < 1 || jegy[letszam] > 5);
		cout << "Van m�g ? (y)"; cin >> betu;
		letszam++;

	} while (betu == 'y' && letszam < 15);
	system("cls");

	for (i = 0; i < letszam; i++) {
		cout << "A(z) " << i + 1 << " tanulo jegye :" << jegy[i] << endl;
		atlag = atlag + jegy[i];
	}

	cout << "Az atlag :" << (float)atlag / letszam << endl;

	return 0;
}

void switchcase()
{
	int jegy;
	cout << "Adja meg a jegyet :"; cin >> jegy; cout << endl;
	switch (jegy)
	{
	case 1: cout << "Elegtelen" << endl; break;
	case 2: cout << "Elegseges" << endl; break;
	case 3: cout << "Kozepes" << endl; break;
	case 4: cout << "Jo" << endl; break;
	case 5: cout << "Kivalo" << endl; break;
	default:
		cout << "Nincs ilyen jegy" << endl;
		break;
	}
}
/* FELADAT 1
// T�lts�nk fel egy max. 15 elem� t�mb�t ellen�rz�tten (0-100) majd
// �rassuk ki az elemeket t�bl�zatosan. Keress�k meg a max elem index�t, �rt�k�t!
//cser�lj�k meg a t�mbben a max elemet az els� elemmel
// �rassuk ki �jra a t�mb�t!
*/

void feladat1()
{
	int tomb[15], maxindex = 0, i, db, maxIndex = 0, max = 0, seged;

	do
	{
		cout << "Kerem a tomb elemszamat :"; cin >> db; cout << endl;
	} while (db < 1 || db > 15);

	for (i = 0; i < db; i++) {
		do
		{
			cout << "Kerem a tomb " << i + 1 << ". elemet "; cin >> tomb[i]; cout << endl;
		} while (tomb[i] < 0 || tomb[i] > 100);
	}

	cout << endl << "Kiiratas" << endl;
	for (i = 0; i < db; i++) {
		cout << "A(z) " << i + 1 << ". elem :" << tomb[i] << endl;
	}

	cout << endl << "Max index" << endl;
	for (i = 0; i < db; i++) {
		if (tomb[i] > max) { max = tomb[i]; maxindex = i; }
	}
	cout << "A legnagyobb szam index : " << maxindex << endl;

	cout << "0 es a max elem csereje" << endl;
	seged = tomb[0];
	tomb[0] = tomb[maxindex];
	tomb[maxindex] = seged;

	for (i = 0; i < db; i++) {
		cout << "A(z) " << i + 1 << ". elem :" << tomb[i] << endl;
	}
}





int main() {
	//practice();
	//test();
	//osszead();
	//osszead2();
	feladat1();
	return 0;
}