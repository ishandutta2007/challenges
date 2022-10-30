// overload + and << operator for complex numbers
#include <iostream>

using namespace std;

class Complex
{
public:
	int a, b;

	Complex operator+(Complex const &c)
	{
		return Complex{a + c.a, b + c.b};
	}

	friend ostream& operator<<(ostream &s, const Complex &c)
	{
		s << c.a << "+i" << c.b;
		return s;
	}
};

int main()
{
	auto a = Complex{3, 4};
	auto b = Complex{5, 6};
	cout << a + b << endl;
	return 0;
}
