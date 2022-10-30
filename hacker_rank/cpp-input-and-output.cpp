#include <iostream>
#include <string>

using namespace std;

int read_value(const string &nth)
{
	int value;
	cout << "input the " << nth << " value: ";
	cin >> value;
	return value;
}

int read_and_sum_3()
{
	auto a = read_value("first");
	auto b = read_value("second");
	auto c = read_value("third");
	auto s = a + b + c;
	cout << "the sum is: " << s << endl;
	return s;
}

int main()
{
	read_and_sum_3();
	return 0;
}
