/*

Given a string that is one of the directions on a 16-point compass rose

16-point compass rose

output the two directions that are immediately adjacent to the input direction, in clockwise order.

Specifically, you need to handle these (and only these) input/output pairs:

Input  Output
N      NNW NNE
NNE    N NE
NE     NNE ENE
ENE    NE E
E      ENE ESE
ESE    E SE
SE     ESE SSE
SSE    SE S
S      SSE SSW
SSW    S SW
SW     SSW WSW
WSW    SW W
W      WSW WNW
WNW    W NW
NW     WNW NNW
NNW    NW N

The output may be a string with some delimiter (not nothing) between the directions or a two-element list.
The direction immediately counterclockwise to the input must appear first.
You may use lowercase letters for the directions instead of uppercase but keep all input and output in one case or the other.

For example, for input N (or n if you're using lowercase) some valid outputs are:

NNW NNE
NNW-NNE
["NNW", "NNE"]
nnw-nne (if using lowercase)

Some invalid outputs are:

NNWNNE
NNE NNW
nnwNNE
NNw NNe

The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
compass(const char *s, char *b)
{
	static const char *tab[] = {
	    "N",
	    "NNE",
	    "NE",
	    "ENE",
	    "E",
	    "ESE",
	    "SE",
	    "SSE",
	    "S",
	    "SSW",
	    "SW",
	    "WSW",
	    "W",
	    "WNW",
	    "NW",
	    "NNW",
	};

	size_t i, j, k, n;

	n = nelem(tab);
	for (i = 0; i < n; i++) {
		if (!strcmp(s, tab[i]))
			break;
	}

	if (i < n) {
		j = (i > 0) ? i - 1 : n - 1;
		k = (i + 1) % n;
		sprintf(b, "%s %s", tab[j], tab[k]);
	} else
		b[0] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	compass(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("N", "NNW NNE");
	test("NNE", "N NE");
	test("NE", "NNE ENE");
	test("ENE", "NE E");
	test("E", "ENE ESE");
	test("ESE", "E SE");
	test("SE", "ESE SSE");
	test("SSE", "SE S");
	test("S", "SSE SSW");
	test("SSW", "S SW");
	test("SW", "SSW WSW");
	test("WSW", "SW W");
	test("W", "WSW WNW");
	test("WNW", "W NW");
	test("NW", "WNW NNW");
	test("NNW", "NW N");

	return 0;
}
