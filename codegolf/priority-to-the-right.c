/*

Your task is to regulate traffic on a crossroads. There are 4 roads coming from north, east, south and west.

The input is a string representing the upcoming traffic on each road. For example, NNNWS indicates there is a total of 5 cars: three at the north, one at the west and one at the south. The order of characters has no importance here, NNNWS is equivalent to WNNSN.

You must output the order in which the cars should go, using the priority to the right rule: cars coming from the south must let cars coming from east go first, east gives way to north, north gives way to west and west gives way to south.

For example, with the input NNNWS, the south car should go first, then the west car, then the 3 north cars. The output should thus be SWNNN.

There are some indecidable cases, for example NS or NNWSE : you should then output the string stuck.

Test cases

N => N
NW => WN
NWS => SWN
SNW => SWN
SSSSS => SSSSS
ENNNNES => NNNNEES
NS => stuck
NNWSE => stuck

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
count(const char *s, size_t c[4])
{
	size_t i;

	c[0] = c[1] = c[2] = c[3] = 0;
	for (i = 0; s[i]; i++) {
		c[0] += (s[i] == 'S');
		c[1] += (s[i] == 'E');
		c[2] += (s[i] == 'N');
		c[3] += (s[i] == 'W');
	}
}

int
slot(size_t c[4])
{
	size_t i;
	int n, z;

	n = -1;
	z = 0;
	for (i = 0; i < 4; i++) {
		if (c[i] && !c[(i + 1) & 3]) {
			if (n != -1)
				return -1;
			n = i;
		}
		z += (c[i] == 0);
	}
	return (z == 4) ? 0 : n;
}

void
output(char *b, size_t c[4], int n)
{
	static const char dir[] = "SENW";
	size_t l;
	int i;

	l = 0;
	for (i = 0; i < 4; i++) {
		while (c[n]) {
			b[l++] = dir[n];
			c[n]--;
		}
		n = (n == 0) ? 3 : n - 1;
	}
	b[l] = '\0';
}

char *
order(const char *s, char *b)
{
	size_t c[4];
	int n;

	count(s, c);
	n = slot(c);
	if (n < 0)
		strcpy(b, "stuck");
	else
		output(b, c, n);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	order(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("N", "N");
	test("NW", "WN");
	test("NWS", "SWN");
	test("SNW", "SWN");
	test("SSSSS", "SSSSS");
	test("ENNNNES", "NNNNEES");
	test("NS", "stuck");
	test("NNWSE", "stuck");
	test("", "");

	return 0;
}
