/*

Create functions for the Calculator class that can do the following:

    Add two numbers.
    Subtract two numbers.
    Multiply two numbers.
    Divide two numbers.

Notes

The functions should return the result of the calculation.

*/

#include <iostream>

using namespace std;

template <typename T>
struct Calculator
{
	T add(T a, T b)
	{
		return a + b;
	}

	T subtract(T a, T b)
	{
		return a - b;
	}

	T multiply(T a, T b)
	{
		return a * b;
	}

	T divide(T a, T b)
	{
		if (b == 0)
			return 0;
		return a / b;
	}
};

int main()
{
	Calculator<int> calc;
	cout << calc.add(10, 5) << endl;
	cout << calc.subtract(10, 5) << endl;
	cout << calc.multiply(10, 5) << endl;
	cout << calc.divide(10, 5) << endl;
	cout << calc.add(5, 5) << endl;
	cout << calc.add(20, 5) << endl;
	cout << calc.subtract(30, 5) << endl;
	cout << calc.subtract(100, 5) << endl;
	cout << calc.multiply(5, 5) << endl;
	cout << calc.multiply(100, 5) << endl;
	cout << calc.divide(10, 5) << endl;
	cout << calc.divide(100, 5) << endl;
	return 0;
}
