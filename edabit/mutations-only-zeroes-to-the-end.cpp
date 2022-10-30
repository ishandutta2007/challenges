/*

Write a function that moves all the zeroes to the end of an array. Do this without returning a copy of the input array.

Examples

zeroesToEnd([1, 2, 0, 0, 4, 0, 5]) ➞ [1, 2, 4, 5, 0, 0, 0]

zeroesToEnd([0, 0, 2, 0, 5]) ➞ [2, 5, 0, 0, 0]

zeroesToEnd([4, 4, 5]) ➞ [4, 4, 5]

zeroesToEnd([0, 0]) ➞ [0, 0]

Notes

    You must mutate the original array.
    Keep the relative order of the non-zero elements the same.

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void zeroes_to_end(vector<int> &a)
{
	auto compare = [](auto x, auto y) { return x != 0 && y == 0; };
	stable_sort(a.begin(), a.end(), compare);
}

void test(vector<int> &a, vector<int> &b)
{
	zeroes_to_end(a);
	assert(a == b);
}

int main()
{
	auto a1 = vector<int>{ 1, 2, 0, 0, 4, 0, 5 };
	auto b1 = vector<int>{ 1, 2, 4, 5, 0, 0, 0 };

	auto a2 = vector<int>{ 0, 0, 1, 3 };
	auto b2 = vector<int>{ 1, 3, 0, 0 };

	auto a3 = vector<int>{ 0, 0, 2, 0, 5 };
	auto b3 = vector<int>{ 2, 5, 0, 0, 0 };

	auto a4 = vector<int>{ 4, 4, 5 };
	auto b4 = vector<int>{ 4, 4, 5 };

	auto a5 = vector<int>{ 0, 0 };
	auto b5 = vector<int>{ 0, 0 };

	test(a1, b1);
	test(a2, b2);
	test(a3, b3);
	test(a4, b4);
	test(a5, b5);

	return 0;
}
