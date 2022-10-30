/*

Challenge

Given the high resolution molecular mass of an organic molecule, output the molecule's molecular formula.

Explanation

The input will be a single number to three decimal places of precision, the relative molecular mass of the molecule.

Here, the molecular mass is defined as the sum of the masses of the atoms in the compound. Since you only are finding the molecular formulae of organic compounds, the atomic masses you need to know are:

    C, Carbon: 12.011
    H, Hydrogen: 1.008
    O, Oxygen: 15.999
    N, Nitrogen: 14.007

Your formula should only ever contain carbon, hydrogen, oxygen or nitrogen.

When writing the formula, it should take the form:

CaHbOcNd

Where the elements must be in that order (C -> H -> O -> N, so C2O8N4H6 should be C2H6O8N4) and a, b, c and d are numbers of the preceding element in the molecule (i.e. C2 means that there are two carbon atoms in the molecule).

If a, b, c or d are zero, that element should not be included in the formula (e.g. C2H6O2N0 should be C2H6O2). Finally, if a, b, c or d are one, you should not include the number in the formula (e.g. C1H4 should be CH4).

The input will always be valid (i.e. there will be a molecule with that mass). If the input is ambiguous (multiple molecules have the same mass), you must only output one of the molecules. How you choose this molecule is up to you.
Worked Example

Suppose the input is 180.156, there is only one combination of the elements which can have this molecular mass:

12.011*6 + 1.008*12 + 15.999*6 + 14.007*0 = 180.156

So there are:

    6 Carbons
    12 Hydrogens
    6 Oxygens
    0 Nitrogens

Therefore, your output should be:

C6H12O6

More Examples

Input -> Output

28.054 -> C2H4
74.079 -> C3H6O2
75.067 -> C2H5O2N
18.015 -> H2O

Winning

Shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char sym;
	double mass;
} Compound;

int
cmp(const void *a, const void *b)
{
	const Compound *x, *y;

	x = a;
	y = b;
	if (x->sym < y->sym)
		return -1;
	if (x->sym > y->sym)
		return 1;
	return 0;
}

double
weight(const char *s)
{
	static const Compound tab[] = {
	    {'C', 12.011},
	    {'H', 1.008},
	    {'N', 14.007},
	    {'O', 15.999},
	};

	Compound c, *p;
	char *ep;
	double r;
	size_t i;
	long n;

	memset(&c, 0, sizeof(c));

	r = 0;
	for (i = 0; s[i];) {
		c.sym = s[i++];

		p = bsearch(&c, tab, nelem(tab), sizeof(*tab), cmp);
		if (!p)
			return -1;

		n = 1;
		if (isdigit(s[i])) {
			n = strtol(s + i, &ep, 0);
			i = ep - s;
		}

		r += p->mass * n;
	}
	return r;
}

void
test(const char *s, double r)
{
	double w;

	w = weight(s);
	printf("%f\n", w);
	assert(fabs(w - r) < 1e-3);
}

int
main(void)
{
	test("C6H12O6", 180.156);
	test("C2H4", 28.054);
	test("C3H6O2", 74.079);
	test("C2H5O2N", 75.067);
	test("H2O", 18.015);

	return 0;
}
