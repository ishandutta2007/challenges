#include <iostream>
#include <iomanip>

using namespace std;

void print(double a, double b, double c)
{
	cout << "0x" << hex << (int)a << endl;
	cout << right << setw(15) << setfill('-') << showpos << b << endl;
	cout << noshowpos << scientific << setprecision(9) << c << endl;
}

int main()
{
	print(100.345, 2006.008, 2331.41592653498);
	return 0;
}
