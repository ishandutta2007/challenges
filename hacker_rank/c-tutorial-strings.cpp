#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void process(const string &a, const string &b)
{
	cout << a.length() << " " << b.length() << endl;
	
	auto c = a + b;
	cout << c << endl;

	auto x = a;
	auto y = b;
	swap(x[0], y[0]);
	cout << x << " " << y << endl;
}

int main()
{
	process("abcd", "ef");
	return 0;
}
