#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void ref_3_main();
void ref_3();
void dynamic_array();

void ref_3_main()
{
	dynamic_array();
}

void ref_3()
{
	//Mutató típus
	int hossz = 15;
	int* hossz_mut;
	hossz_mut = &hossz;
	cout << "hossz => " << hossz << " *hossz_mut => " << *hossz_mut << endl;
	cout << "hossz => " << hossz << " hossz_mut => " << hossz_mut << endl;
	cout << "hossz => " << hossz << " &hossz => " << &hossz << endl;

	*hossz_mut = 20;
	cout << "hossz => " << hossz << " *hossz_mut => " << *hossz_mut << endl;
	cout << "hossz => " << hossz << " hossz_mut => " << hossz_mut << endl;
	cout << "hossz => " << hossz << " &hossz => " << &hossz << endl;

	hossz = 30;
	cout << "hossz => " << hossz << " *hossz_mut => " << *hossz_mut << endl;
	cout << "hossz => " << hossz << " hossz_mut => " << hossz_mut << endl;
	cout << "hossz => " << hossz << " &hossz => " << &hossz << endl;

	//Referencia típus. Ez gyakorlatilag azt csinálja, hogy egy meglévõ változóhoz aliast rendel
	int hossz2 = 50;
	int& hiv = hossz2; // A hossz2-re a hiv névvel is lehet hivatkozni.
	
	hiv = 30;
	cout << "hossz2 " << hossz2 << " hiv " << hiv << endl;
	
	hossz2 = 100;
	cout << "hossz2 " << hossz2 << " hiv " << hiv << endl;

	//Példa

	int x = 10;
	int* p;
	int& h = x; //x re h val is hivatkozhatunk
	p = &x; //p x cime lesz
	
	cout << x << " " << *p << " " << h << endl; // 10 10 10
	h = x * *p;                                 // 10*10
	cout << x << " " << *p << " " << h << endl; // 100 100 100
	
}

/*
Írjunk egy programot, amelyben egy labdarúgó csapat játékosainak neveit és mezeinek a 
számait tároljuk. Egy mérkõzésre 20 játékos nevezhetõ, de nem biztos, hogy a csapat 
rendelkezésére áll ennyi játékos, mert vírusos idõszak van. Ebben a bajnokságban minimum 
9 emberrel lehet egy mérkõzést elkezdeni. Tároljuk a játékosok neveit és mezszámait egy dinamikus tömbben!
*/

struct jatekos
{
	string nev;
	int mezszam;
};

void dynamic_array()
{
	jatekos* csapat; //mutató létrehozása a tömbhöz
	int letszam = 0;
	while (letszam < 9 || letszam > 20)
	{
		cout << "Kerem a csapat letszamat : "; cin >> letszam;	
		cin.ignore();
	}
		
	csapat = new jatekos[letszam]; //a csapat tömb letrehozasa

	for (int i = 0; i < letszam; i++)
	{
		cout << "Kerem a " << i + 1 << " jatekos nevet "; getline(cin, csapat[i].nev);
		cout << "Kerem a " << i + 1 << " jatekos mezszámát "; cin >> csapat[i].mezszam;
		cin.ignore();
	}

	system("cls");
	cout.setf(ios::left);

	for (int i = 0; i < letszam; i++)
	{
		csapat; cout << setw(25) << csapat[i].nev << csapat[i].mezszam << endl;
	}

	delete[] csapat;
}