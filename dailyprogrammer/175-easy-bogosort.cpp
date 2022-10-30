/*

Description

A bogo sort is a purposefully inefficient algorithm for sorting a sequence. Today we will be using this for strings to test for equality.

Here is wikipedias entry for a Bogo-Sort

Inputs & Outputs

Given a scrambled string N and another string M. You must sort N so that it matches M. After it has been sorted, it must output how many iterations it took to complete the sorting.

Sample Inputs & Outputs

Input:

Bogo("lolhe","Hello")

Output:

1456 iterations

Bonus

For a bit of fun, the LEAST efficient algorithm wins. Check out the bogo-bogo sort, an algorithm that's designed not to succeed before the heat death of the universe

http://www.dangermouse.net/esoteric/bogobogosort.html

If you have designed an algorithm but it still hasn't finished sorting, if you can prove it WILL sort, you may post your proof.
Notes

Have an idea for a challenge?

Consider submitting it to /r/dailyprogrammer_ideas

*/

#include <cstdio>
#include <cctype>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

bool equal(const vector<char> &dst, const vector<char> &src)
{
	if (dst.size() != src.size())
		return false;
	for (auto i = 0ull; i < dst.size(); i++)
	{
		if (tolower(dst[i]) != tolower(src[i]))
			return false;
	}
	return true;
}

int bogosort(vector<char> &dst, const vector<char> &src)
{
	random_device rd;
	mt19937 g(rd());

	auto tries = 0;
	for (; !equal(dst, src); tries++)
		shuffle(dst.begin(), dst.end(), g);
	return tries;
}

void test(vector<char> &dst, const vector<char> &src)
{
	printf("%d iterations\n", bogosort(dst, src));
	for (auto c : dst)
		printf("%c", c);
	printf("\n");
}

int main()
{
	vector<char> s1 = { 'l', 'o', 'l', 'h', 'e' };
	vector<char> r1 = { 'H', 'e', 'l', 'l', 'o' };

	test(s1, r1);

	return 0;
}
