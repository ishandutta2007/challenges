/*

Try finding your ancestors and offspring with code.

Create a function that takes a number x and a character y ("m" for male, "f" for female), and returns the name of an ancestor (m/f) or descendant (m/f).

    If the number is negative, return the related ancestor.
    If positive, return the related descendant.
    You are generation 0. In the case of 0 (male or female), return "me!".

Examples

generation(2, "f") ➞ "granddaughter"

generation(-3, "m") ➞ "great grandfather"

generation(1, "f") ➞ "daughter"

Notes

Check the Resources tab for helpful hints.
Generation	Male	Female
-3	great grandfather	great grandmother
-2	grandfather	grandmother
-1	father	mother
0	me!	me!
1	son	daughter
2	grandson	granddaughter
3	great grandson	great granddaughter

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
generation(int x, int y)
{
	static const struct {
		int generation;
		const char *male;
		const char *female;
	} tab[] = {
	    {-3, "great grandfather", "great grandmother"},
	    {-2, "grandfather", "grandmother"},
	    {-1, "father", "mother"},
	    {0, "me!", "me!"},
	    {1, "son", "daughter"},
	    {2, "grandson", "granddaughter"},
	    {3, "great grandson", "great granddaughter"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (x != tab[i].generation)
			continue;
		if (y == 'm')
			return tab[i].male;
		if (y == 'f')
			return tab[i].female;
	}
	return NULL;
}

void
test(int x, int y, const char *r)
{
	assert(!strcmp(generation(x, y), r));
}

int
main(void)
{
	test(-3, 'm', "great grandfather");
	test(1, 'f', "daughter");
	test(-3, 'f', "great grandmother");
	test(-2, 'm', "grandfather");
	test(-2, 'f', "grandmother");
	test(-1, 'm', "father");
	test(-1, 'f', "mother");
	test(0, 'f', "me!");
	test(1, 'm', "son");
	test(1, 'f', "daughter");
	test(2, 'm', "grandson");
	test(2, 'f', "granddaughter");
	test(3, 'm', "great grandson");
	test(3, 'f', "great granddaughter");

	return 0;
}
