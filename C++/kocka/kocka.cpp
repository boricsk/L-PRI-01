#include <iostream>
#include <ctime>

using namespace std;

int kocka()
{
	int kocka[1000], TAR[6] = { 0 }, i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 1000; i++) {
		kocka[i] = rand() % 6 + 1;
		cout << kocka[i] << " ";
	}
	cout << endl;

	int dbparos = 0;
	for (i = 0; i < 1000; i++) {
		if (kocka[i] % 2 == 0) { dbparos++; }
		switch (kocka[i])
		{
		case 1: TAR[0]++; break;
		case 2: TAR[1]++; break;
		case 3: TAR[2]++; break;
		case 4: TAR[3]++; break;
		case 5: TAR[4]++; break;
		case 6: TAR[5]++; break;
		}
	}
	cout << endl;
	for (i = 0; i < 6; i++) {
		cout << "A(z)" << i + 1 << " dobasok szama: " << TAR[i] << endl;
	}
	cout << "A paros dobasok szama : " << dbparos << endl;
	cout << "A paratlan dobasok szama : " << 1000 - dbparos << endl;

	return 0;
}



int main()
{
	kocka();
	

	return 0;
}