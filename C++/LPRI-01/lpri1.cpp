#include <iostream>
using namespace std;

const double pi = 3.14159;

int circle()
{
	int radius;
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	cout << "The area of the circle is: " << pi * radius * radius << endl;
	cout << "The circumference of the circle is: " << 2 * pi * radius << endl;
	return 0;
}

int precedence()
{
	char bet = 'A';
	int a, b = 5;
	a = 2 * (b + bet);
	cout << a << endl; //140
	cout << 1 / b * 100 << endl; //0
	cout << 100 * 1 / b << endl; //20
	float x;
	x = 1 / b * 100;
	cout << x << endl; //0
	return 0;
}

int increment()
{
	int a = 1, b = 1;
	a = ++a * 3;
	b = b++ * 3;
	cout << a << " " << b << endl; //2 11 1
	return 0;
}

int test1()
{
	int a = 1, b = 10, c = 0;
	c = (b < a) && ++c;
	cout << c << endl; //0
	return 0;
}

int main() {

	increment();
	return 0;
}