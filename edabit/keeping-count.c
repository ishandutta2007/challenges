/*

Given a number, create a function which returns a new number based on the following rules:

    For each digit, replace it by the number of times it appears in the number.
    The final instance of the number will be an integer, not a string.

The following is a working example:

digitCount(136116) ➞ 312332
// The number 1 appears thrice, so replace all 1s with 3s.
// The number 3 appears only once, so replace all 3s with 1s.
// The number 6 appears twice, so replace all 6s with 2s.

Examples

digitCount(221333) ➞ 221333

digitCount(136116) ➞ 312332

digitCount(2) ➞ 1

Notes

Each test will have a positive whole number in its parameter.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
count(uvlong x)
{
	uvlong d[sizeof(x) * CHAR_BIT], h[10];
	uvlong n, r, v;

	memset(h, 0, sizeof(h));
	n = 0;
	do {
		v = x % 10;
		h[v]++;
		d[n++] = v;
		x /= 10;
	} while (x);

	for (r = 0; n > 0; n--)
		r = (r * 10) + h[d[n - 1]];
	return r;
}

int
main(void)
{
	assert(count(221333ull) == 221333ull);
	assert(count(136116ull) == 312332ull);
	assert(count(2ull) == 1ull);
	assert(count(3410515780ull) == 1122222112ull);
	assert(count(24677734541ull) == 13133313131ull);
	assert(count(79825929634ull) == 13121323111ull);
	assert(count(36123594675ull) == 22112211212ull);
	assert(count(62849835970ull) == 11212211211ull);
	assert(count(29081455325ull) == 21111133123ull);
	assert(count(94717270184ull) == 12323131212ull);
	assert(count(72017589759ull) == 31113212322ull);
	assert(count(53569357419ull) == 32312231112ull);
	assert(count(33879999825ull) == 22214444211ull);
	assert(count(33600360627ull) == 33333333311ull);
	assert(count(12594580129ull) == 22221211222ull);
	assert(count(36852564216ull) == 13122231213ull);
	assert(count(34415793631ull) == 32221113132ull);
	assert(count(76384607724ull) == 32112213312ull);
	assert(count(8604519582ull) == 2111211221ull);
	assert(count(70209476552ull) == 22221121222ull);
	assert(count(20036302062ull) == 34422243423ull);
	assert(count(77674727011ull) == 55151515122ull);
	assert(count(17597066090ull) == 12122322323ull);
	assert(count(79082080537ull) == 21321323112ull);
	assert(count(30187177000ull) == 14213233444ull);
	assert(count(72916170033ull) == 21121222222ull);
	assert(count(11314637247ull) == 33232122122ull);
	assert(count(69095956141ull) == 23132322212ull);
	assert(count(66117263379ull) == 33222132221ull);
	assert(count(30491133624ull) == 31212233112ull);

	return 0;
}
