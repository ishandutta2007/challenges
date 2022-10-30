/*

I need a UUID. Your job is to generate one.

The canonical UUID (Universally Unique IDentifier) is a 32 digit hexadecimal number with hyphens inserted in certain points.
The program should output 32 hex digits (128 bits), in the form of xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx (8-4-4-4-12 digits), where x is a random hexadecimal number.
Assuming that your language's PRNG is perfect, all valid outputs must have the same probability of being generated.
TL;DR

Generate 32 random hexadecimal digits in the form 8-4-4-4-12 digits. Shortest code wins.

EDIT: Must be hexadecimal. Always generating decimal only is invalid. EDIT 2: No built-ins. These aren't GUIDs, just generic hex digits.
Example output:

ab13901d-5e93-1c7d-49c7-f1d67ef09198
7f7314ca-3504-3860-236b-cface7891277
dbf88932-70c7-9ae7-b9a4-f3df1740fc9c
c3f5e449-6d8c-afe3-acc9-47ef50e7e7ae
e9a77b51-6e20-79bd-3ee9-1566a95d9ef7
7b10e43c-3c57-48ed-a72a-f2b838d8374b

Input, and standard loopholes are disallowed.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char *
uuid(char *b)
{
	static const char *fmt = "8-4-4-4-12";
	size_t i, j, k, l;
	char *ep;

	l = 0;
	for (i = 0; fmt[i]; i++) {
		if (!isdigit(fmt[i])) {
			l += sprintf(b + l, "%c", fmt[i]);
			continue;
		}

		k = strtoul(fmt + i, &ep, 10);
		i = ep - fmt - 1;
		for (j = 0; j < k; j++)
			l += sprintf(b + l, "%x", rand() & 15);
	}

	return b;
}

int
main(void)
{
	char b[80];
	int i;

	srand(time(NULL));
	for (i = 0; i < 16; i++)
		printf("%s\n", uuid(b));
	return 0;
}
