/*
In mathematics, the Golomb sequence is a non-decreasing integer sequence where n-th term is equal to number of times n appears in the sequence.

The first few values are
1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, ……

Explanation of few terms:
Third term is 2, note that three appears 2 times.
Second term is 2, note that two appears 2 times.
Fourth term is 3, note that four appears 3 times.

Given a positive integer n. The task is to find the first n terms of Golomb sequence.
*/

#include <cstdio>
#include <map>

std::map<int, int> cache;

int golomb(int n)
{
	if (n <= 1)
		return 1;

	auto it = cache.find(n);
	if (it != cache.end())
		return it->second;

	cache[n] = 1 + golomb(n - golomb(golomb(n - 1)));
	return cache[n];
}

int main()
{
	for (int i = 1; i <= 1000; i++)
		printf("%d %d\n", i, golomb(i));
	return 0;
}
