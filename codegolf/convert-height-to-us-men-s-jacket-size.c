/*

In the US, clothing size sometimes has rough designations like M, L, XXL, etc. The US designation of the "men's jacket" category depends on the height of the person.
So, in this challenge, you should implement this conversion, which is defined by the following table, taken from this site:

US size Body height (cm)
XXXS    160 - 164
XXS     162 - 166
XS      166 - 170
S       168 - 173
M       171 - 176
L       174 - 182
XL      180 - 186
XXL     184 - 189
3XL     187 - 193
4XL     191 - 194
5XL     193 - 198
6XL     197 - 200
* I chose the "men's jacket" category from there because it has the most variability

Input
Body height, in cm. As a number or a string.

Output
Size designation - as a return value or printed.

Additional rules
For some sizes, designation is uncertain (e.g. 174, 175 and 176 correspond to both M and L) - your converter should return one of these, deterministically or not
If it's easier, output fully spelled versions like XXXXL instead of 4XL; however, 2XL and 2XS are invalid (apparently they are used in real life, but I decided to forbid them because I thought they weren't)
Assume the input is valid, i.e. a whole number between 160 and 200

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
clothsize(int n)
{
	static const struct {
		char sym[8];
		int lo;
		int hi;
	} js[] = {
	    {"XXXS", 160, 164},
	    {"XXS", 162, 166},
	    {"XS", 166, 170},
	    {"S", 168, 173},
	    {"M", 171, 176},
	    {"L", 174, 182},
	    {"XL", 180, 186},
	    {"XXL", 184, 189},
	    {"3XL", 187, 193},
	    {"4XL", 191, 194},
	    {"5XL", 193, 198},
	    {"6XL", 197, 200},
	};

	size_t i;

	for (i = 0; i < nelem(js); i++) {
		if (js[i].lo <= n && n <= js[i].hi)
			return js[i].sym;
	}
	return NULL;
}

void
test(int n, const char *r)
{
	const char *p;

	p = clothsize(n);
	printf("%s %s\n", p, r);
	if (!p)
		assert(p == r);
	else
		assert(!strcmp(p, r));
}

int
main(void)
{
	test(160, "XXXS");
	test(197, "5XL");
	test(200, "6XL");

	return 0;
}
