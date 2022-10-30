/*

Luke Skywalker has family and friends. Help him remind them who is who.
Given a string with a name, return the relation of that person to Luke.

Person	Relation
Darth Vader	father
Leia	sister
Han	brother in law
R2D2	droid
Examples

relation_to_luke("Darth Vader") ➞ "Luke, I am your father."

relation_to_luke("Leia") ➞ "Luke, I am your sister."

relation_to_luke("Han") ➞ "Luke, I am your brother in law."

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
relation(const char *s, char *b, size_t n)
{
	static const char tab[][2][128] = {
	    {"Darth Vader", "father"},
	    {"Leia", "sister"},
	    {"Han", "brother in law"},
	    {"R2D2", "droid"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i][0])) {
			snprintf(b, n, "Luke, I am your %s.", tab[i][1]);
			return b;
		}
	}

	return NULL;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(!strcmp(relation(s, b, sizeof(b)), r));
}

int
main(void)
{
	test("Darth Vader", "Luke, I am your father.");
	test("Leia", "Luke, I am your sister.");
	test("Han", "Luke, I am your brother in law.");
	test("R2D2", "Luke, I am your droid.");

	return 0;
}
