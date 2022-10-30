/*

The insurance guy laughs, he's just kidding. He just needs an updated list. You just need one of those Rammstein Vodka bottles.

Given an object with alcoholic drinks and a number, return a string with the name of the Rammstein bottle that matches the given number.
Examples

{ whiskey: 100, "Rammstein A": 100, "Rammstein B": 50 } ➞ "Rammstein A"
// number = 100

{ whiskey: 100, "Rammstein A": 100, "Rammstein B": 50 } ➞ "Rammstein B"
// number = 50

{ whiskey: 100, "Rammstein A": 100, "Rammstein D": 70, beer: 70 } ➞ "Rammstein D"
// number = 70

Notes

    There will always be a corresponding Rammstein bottle for the number given.
    There will never be 2 Rammstein bottles with the same number.
    You always return one Rammstein bottle.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *name;
	int value;
} Bottle;

const char *
vodka(Bottle *b, size_t n, int w)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (b[i].value == w)
			return b[i].name;
	}
	return NULL;
}

void
test(Bottle *b, size_t n, int w, const char *r)
{
	const char *p;

	p = vodka(b, n, w);
	if (!p)
		assert(!r);
	else
		assert(!strcmp(p, r));
}

int
main(void)
{
	Bottle bottles[] = {
	    {"Rammstein A", 100},
	    {"Rammstein B", 50},
	    {"Rammstein C", 1},
	};

	test(bottles, nelem(bottles), 100, "Rammstein A");
	test(bottles, nelem(bottles), 50, "Rammstein B");
	test(bottles, nelem(bottles), 1, "Rammstein C");

	return 0;
}
