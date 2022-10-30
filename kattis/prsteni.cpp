/*

After an exhausting morning, Mirko fell asleep. His brother Stanko, however, just awoke and, like his brother, is all about excitement.
Stanko found N rings of varying radii in the garage. He arranged them on the floor so that each ring (except the first and last) touches the ones before and after it.

He started turning the first ring and noticed that the other rings turned as well; some faster, some slower!

Thrilled with his discovery, he decided to count how many times the other rings turn while the first ring turns once. He gave up after noticing that this number is not always an integer and not knowing what to do.

Write a program that determines how many times each ring turns while the first turns once.

Input

The first line of input contains an integer N(3≤N≤100), the number of rings.

The next line contains N integers between 1 and 1000, the radii of Stanko’s rings, in the order they are laid out on the floor.

Output

The output must contain N−1 lines. For every ring other than the first, in the order they are given in the input, output a fraction A/B, meaning that the respective ring turns A/B times while the first ring turns once.
The fractions must be in reduced form (the numerator and denominator must not have a common divisor larger than 1).

*/

#include <iostream>
#include <boost/format.hpp>

using namespace boost;
using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		auto t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void ringworld(const vector<int> &a)
{
	auto n = a.size();
	if (n < 1)
		return;

	auto x = a[0];
	for (auto i = 1u; i < n; i++)
	{
		auto y = a[i];
		auto z = gcd(x, y);
		cout << format("%1%/%2%") % (x / z) % (y / z) << endl;
	}
	cout << endl;
}

int main()
{
	ringworld({ 8, 4, 2 });
	ringworld({ 12, 3, 8, 4 });
	ringworld({ 300, 1, 1, 300 });
	return 0;
}
