/*

For this challenge, forget how to add two numbers together. The best explanation on what to do for this function is this meme:

Alternative Text
Examples

meme_sum(26, 39) ➞ 515
# 2+3 = 5, 6+9 = 15
# 26 + 39 = 515

meme_sum(122, 81) ➞ 1103
# 1+0 = 1, 2+8 = 10, 2+1 = 3
# 122 + 81 = 1103

meme_sum(1222, 30277) ➞ 31499

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
memesum(uvlong a, uvlong b)
{
	uvlong v, r, p;

	r = 0;
	p = 1;
	for (;;) {
		v = (a % 10) + (b % 10);
		r += v * p;

		a /= 10;
		b /= 10;
		if (!a && !b)
			break;

		p *= (v >= 10) ? 100 : 10;
	}
	return r;
}

int
main(void)
{
	assert(memesum(2, 11) == 13);
	assert(memesum(0, 1) == 1);
	assert(memesum(0, 0) == 0);
	assert(memesum(16, 18) == 214);
	assert(memesum(26, 39) == 515);
	assert(memesum(122, 81) == 1103);
	assert(memesum(1222ull, 30277ull) == 31499ull);
	assert(memesum(38810ull, 1383ull) == 391193ull);
	assert(memesum(1236ull, 30977ull) == 31111013ull);
	assert(memesum(49999ull, 49999ull) == 818181818ull);

	return 0;
}
