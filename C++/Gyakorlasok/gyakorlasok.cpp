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
	int b = ++a; //Elsõ körben növel, majd értéket ad. a++ esetén 5 lenne mert a hozzárendelés után nõvekszik.
	cout << b << endl;

	cout << (3 > 2 || 2 > 1) << endl;

	a = 4;
	cout << a % 2 << endl; //Maradékos osztás

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

int main() {
	//practice();
	test();
	return 0;
}