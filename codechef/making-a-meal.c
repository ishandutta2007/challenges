/*

Today, Chef decided to cook some delicious meals from the ingredients in his kitchen.
There are N ingredients, represented by strings S1,S2,…,SN.
Chef took all the ingredients, put them into a cauldron and mixed them up.

In the cauldron, the letters of the strings representing the ingredients completely mixed, so each letter appears in the cauldron as many times as it appeared in all the strings in total;
now, any number of times, Chef can take one letter out of the cauldron (if this letter appears in the cauldron multiple times, it can be taken out that many times) and use it in a meal.
A complete meal is the string "codechef". Help Chef find the maximum number of complete meals he can make!

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains a single string Si.

Output

For each test case, print a single line containing one integer — the maximum number of complete meals Chef can create.

Constraints
1≤T≤100
1≤N≤100
|S1|+|S2|+…+|SN|≤1,000
each string contains only lowercase English letters

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

void
frequency(const char *s, size_t h[256])
{
	size_t i;

	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;
}

size_t
meals(const char **s, size_t n)
{
	size_t a[256], b[256];
	size_t i, r;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	frequency("codechef", a);
	for (i = 0; i < n; i++)
		frequency(s[i], b);

	r = SIZE_MAX;
	for (i = 0; i < nelem(a); i++) {
		if (a[i])
			r = min(r, b[i] / a[i]);
	}
	return r;
}

int
main(void)
{
	const char *s1[] = {
	    "cplusplus",
	    "oscar",
	    "deck",
	    "fee",
	    "hat",
	    "near",
	};

	const char *s2[] = {
	    "code",
	    "hacker",
	    "chef",
	    "chaby",
	    "dumbofe",
	};

	const char *s3[] = {
	    "codechef",
	    "chefcode",
	    "fehcedoc",
	    "cceeohfd",
	    "codechef",
	};

	assert(meals(s1, nelem(s1)) == 1);
	assert(meals(s2, nelem(s2)) == 2);
	assert(meals(s3, nelem(s3)) == 5);

	return 0;
}
