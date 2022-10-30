/*

Mubashir was testing how atoms can react in their ionic state during nuclear fusion.
He observed that atoms can introduce different elements with Hydrogen at high temperatures and inside a pressurized chamber.
During his experiment, elements started precipitating inside the chamber.
Help him find the total number of molecules of Water H2O, Carbon Dioxide CO2 and Methane CH4 generated during this process.

Given the number of atoms of carbon, hydrogen and oxygen, calculate the molecules in the following order:

1. Hydrogen reacts with Oxygen = H2O
2. Carbon reacts with Oxygen   = CO2
3. Carbon reacts with Hydrogen = CH4

Examples

chemicalReactions(45, 11, 100) ➞ [5, 45, 0]
// 10 atoms of hydrogen + 5 atoms of oxygen = 5 molecules of H2O
// 45 atoms of carbon + 90 atoms of oxygen = 45 molecules of CO2
// 1 hydrogen atom + 0 carbon atoms = 0 molecules of CH4

chemicalReactions(113, 0, 52) ➞ [0, 26, 0]

chemicalReactions(939, 3, 694) ➞ [1, 346, 0]

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef unsigned long ulong;

void
reactions(ulong c, ulong h, ulong o, ulong r[3])
{
	r[0] = min(h / 2, o);
	h -= 2 * r[0];
	o -= r[0];

	r[1] = min(c, o / 2);
	c -= r[1];
	o -= 2 * r[1];

	r[2] = min(c, h / 4);
}

void
test(ulong c, ulong h, ulong o, ulong r[3])
{
	ulong p[3];

	reactions(c, h, o, p);
	printf("%lu %lu %lu\n", p[0], p[1], p[2]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	test(45, 11, 100, (ulong[]){5, 45, 0});
	test(354, 1023230ull, 0, (ulong[]){0, 0, 354});
	test(939, 3, 694, (ulong[]){1, 346, 0});
	test(215, 41, 82100ul, (ulong[]){20, 215, 0});
	test(113, 0, 52, (ulong[]){0, 26, 0});

	return 0;
}
