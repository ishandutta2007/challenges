/*

Given a word, decide if it is an ambigram.

When rotated:

b > q
d > p
l > l
n > u
o > o
p > d
q > b
s > s
u > n
x > x
z > z
Assume only lowercase letters as input.

Test input:

this,
another,
lll,
lol,
dad,
dab,
dap,
wow,
ooi,
lollpopdodllol,
Ones That Should Return Truthy Values:

lll,
lol,
lollpopdodllol,

Note that input and output can be taken in any format (except for Standard Loopholes).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
map(int c)
{
	static const int tab[][2] = {
	    {'b', 'q'},
	    {'d', 'p'},
	    {'l', 'l'},
	    {'n', 'u'},
	    {'o', 'o'},
	    {'p', 'd'},
	    {'q', 'b'},
	    {'s', 's'},
	    {'u', 'n'},
	    {'x', 'x'},
	    {'z', 'z'},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (c == tab[i][0])
			return tab[i][1];
		if (c == tab[i][1])
			return tab[i][0];
	}
	return -1;
}

bool
ambigram(const char *s)
{
	size_t i, n;

	n = strlen(s);
	if (n == 0)
		return true;

	for (i = 0; i <= n / 2; i++) {
		if (map(s[i]) != s[n - i - 1])
			return false;
		if (s[i] != map(s[n - i - 1]))
			return false;
	}
	return true;
}

int
main(void)
{
	assert(ambigram("this") == false);
	assert(ambigram("another") == false);
	assert(ambigram("lll") == true);
	assert(ambigram("lol") == true);
	assert(ambigram("dad") == false);
	assert(ambigram("dab") == false);
	assert(ambigram("dap") == false);
	assert(ambigram("wow") == false);
	assert(ambigram("ooi") == false);
	assert(ambigram("lollpopdodllol") == true);
	assert(ambigram("a") == false);
	assert(ambigram("abc") == false);
	assert(ambigram("zz") == true);
	assert(ambigram("s") == true);

	return 0;
}
