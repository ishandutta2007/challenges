/*

The challenge today is very simple. The task is to determine the TI calculator for which the submitted datafile was made.

The datafiles always start with a string **TI, the version (described below), and other data you can ignore.

Now, the versions you need to recognize are:

95* => TI-95
92P => TI-92+
92* => TI-92
89* => TI-89
86* => TI-86
85* => TI-85
84P => TI-84+
84* => TI-84
83* => TI-83
83P => TI-83+
82* => TI-82
81* => TI-81
74* => TI-74
73P => TI-73+
Examples
**TI95*   => TI-95
**TI83P   => TI-83+
**TI73P   => TI-73+
**TI85*   => TI-85
**TI83PGG => TI-83+
**TI86*asdf*9**TI92Pasd => TI-86
Rules
You can assume the input is always correct, is at least 7 characters long, and has been crafted for one of the TI calculators listed above.

This is code golf, so the shortest answer wins.

I/O rules and loopholes apply.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
version(const char *s, char *b)
{
	unsigned long n;
	char *ep;

	if (strncmp(s, "**TI", 4)) {
		sprintf(b, "UNK");
		return b;
	}

	n = strtoul(s + 4, &ep, 10);
	sprintf(b, "TI-%lu%s", n, (*ep == 'P') ? "+" : "");
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	version(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("**TI95*", "TI-95");
	test("**TI83P", "TI-83+");
	test("**TI73P", "TI-73+");
	test("**TI85*", "TI-85");
	test("**TI83PGG", "TI-83+");
	test("**TI86*asdf*9**TI92Pasd", "TI-86");

	return 0;
}
