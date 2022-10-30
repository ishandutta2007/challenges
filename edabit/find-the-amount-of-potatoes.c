/*

Create a function to return the amount of potatoes there are in a string.

Examples

Potatoes("potato") ➞ 1

Potatoes("potatopotato") ➞ 2

Potatoes("potatoapple") ➞ 1

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
potatoes(const char *s)
{
	const char *p;
	size_t n;

	n = 0;
	for (p = s; (p = strstr(p, "potato")); p += 6)
		n++;
	return n;
}

int
main(void)
{
	assert(potatoes("potato") == 1);
	assert(potatoes("potatopotato") == 2);
	assert(potatoes("potatoatoapple") == 1);
	assert(potatoes("potatopotatocherry") == 2);
	assert(potatoes("potatopotatopotatoorange") == 3);
	assert(potatoes("potatopotatobananapotatopotato") == 4);
	assert(potatoes("potatopotatomangopotatopotatopotato") == 5);
	assert(potatoes("potatocucumberpotatopotatopotatopotatopotato") == 6);

	return 0;
}
