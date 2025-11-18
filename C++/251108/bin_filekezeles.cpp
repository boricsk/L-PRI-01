#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <iomanip>

using namespace std;

void bin_file_handling_main();
void bin_file_write();

void bin_file_handling_main()
{
	bin_file_write();
}

struct tanulo
{
	char nev[25];
	float atlag;
	int szul_ev;
};

void bin_file_write()
{
	ofstream ki("osztaly.dat", ios::binary);
	tanulo x;
	if (ki.fail()) { cout << "Hiba"; exit(1); }

	for (int i = 0; i < 5; i++)
	{
		cout << "Adja meg az " << i + 1 << " tanulo nevet"; cin.getline(x.nev, 25);
		cout << "Adja meg az " << i + 1 << " tanulo atlagat"; cin >> x.atlag;
		cout << "Adja meg az " << i + 1 << " tanulo szuletesi evet"; cin >> x.szul_ev;
		ki.write((char*)&x, sizeof(x));
		cin.ignore();
	}
	ki.close();
}