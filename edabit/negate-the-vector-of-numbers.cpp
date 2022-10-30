/*

Given a vector of numbers, negate all elements contained within.

    Negating a positive value -+n will return -n, because all +'s are removed.
    Negating a negative value --n will return n, because the first - turns the second minus into a +.

Examples

negate({1, 2, 3, 4}) ➞ {-1, -2, -3, -4}

negate({-1, 2, -3, 4}) ➞ {1, -2, 3, -4}

negate({}) ➞ {}

Notes

If you get an empty vector, return an empty vector: {}

*/

#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> negate(vector<int> p)
{
	for (auto &v : p)
		v = -v;
	return p;
}

int main()
{
	assert(negate({1, 2, 3, 4}) == vector<int>({-1, -2, -3, -4}));
	assert(negate({-1, 2, 3, 4}) == vector<int>({1, -2, -3, -4}));
	assert(negate({-1, -2, -3, -4}) == vector<int>({1, 2, 3, 4}));
	assert(negate({}) == vector<int>({}));
	return 0;
}
