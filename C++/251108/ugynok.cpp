#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <iomanip>

using namespace std;

struct ugynok
{
	string varos;
	int tav;
};

int UgynokMain();

int UgynokMain()
{
	ifstream be("vartav.txt");
	if (be.fail()) { cout << "Hiba"; system("pause"); exit(1); }

	ugynok A[20];
	int i = 0, j = 0, db = 0;
	cout.setf(ios::left);
	while (!be.eof())
	{
		be >> A[i].varos; //Mert a space-ig olvas!!
		be >> A[i].tav;
		cout << setw(6) << "Varos " << setw(10) << A[i].varos << setw(7) << " tav :" << setw(10) << A[i].tav << endl;
		i++;
	}
	db = i;
	cout << "Az ugynok " << i << " varosban volt." << endl;
	
	//Hány kilómétert utazott az ugynok
	int km = 0;
	for (j = 0; j < db; j++)
	{
		km += A[j].tav * 2;
	}
	cout << "Az ugynok " << km << " km-t utazott." << endl;

	//Melyik a legtávolabbi város. A város nevét a varos.txt-be írja
	int max_tav_index = 0;

	for (j = 0; j < db; j++) {
		if (A[max_tav_index].tav < A[j].tav) { max_tav_index = j; }
	}
	cout << "A legtavolabbi varos : " << A[max_tav_index].varos << endl;

	ofstream ki("varos.txt");
	if (ki.fail()) { cout << "Hiba"; system("pause"); exit(1); }
	ki << A[max_tav_index].varos << " " << A[max_tav_index].tav << endl;

	return 0;
}