/*

Given one line that consists of only letters, process as following:

You maintain a string that's empty at the beginning.
If the next input character is in the string, remove it from the string.
If the next input character isn't in the string, append it to the string.
Output the final state of the string.

You can safely assume the input consists at least one character (i.e. non-empty), but there's no guarantee that the output isn't empty.

Pseudocode (Feel free to golf this):

str = EMPTY
for each character ch in input
  if ch exists in str
    remove all ch from str
  else
    append ch to str
print str
The input matches the regular expression ^[A-Za-z]+$.

Sample test cases:

ABCDBCCBE -> ADCBE
ABCXYZCABXAYZ -> A
aAABBbAbbB -> aAbB
GG -> (empty)
The input can be given in any applicable way, but it must be treated as a string, and the same for output. The program should not exit with an error.

The shortest program in each language wins!

Extra (Optional): Please explain how your program works. Thank you.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const size_t *x, *y;

	x = a;
	y = b;
	if (x[1] < y[1])
		return -1;
	if (x[1] > y[1])
		return 1;
	return 0;
}

char *
appenderase(const char *s, char *b)
{
	size_t h[256][2];
	size_t i, j;
	int c;

	for (i = 0; i < nelem(h); i++) {
		h[i][0] = i;
		h[i][1] = 0;
	}
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		h[c][1] = (h[c][1]) ? 0 : i + 1;
	}

	qsort(h, nelem(h), sizeof(*h), cmp);

	for (i = j = 0; i < nelem(h); i++) {
		if (h[i][1])
			b[j++] = h[i][0];
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	appenderase(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("ABCDBCCBE", "ADCBE");
	test("ABCXYZCABXAYZ", "A");
	test("aAABBbAbbB", "aAbB");
	test("GG", "");

	return 0;
}
