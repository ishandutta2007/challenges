/*

Recently, an electrical engineer studying traffic light timings was fined $500 by the state of Oregon for referring to himself as an engineer.

Given a 2 letter string as input, representing a US state, output:

    I am not an engineer if the state is Oregon (OR)
    I am an engineer if the state is any other US state
    What is an engineer? given any other input

Output may not contain any leading whitespace, but may contain as much trailing whitespace as you wish.

You can assume the input will always be 2 uppercase letters.

Here is a list of all 50 US state abbreviations:

AL, AK, AZ, AR, CA, CO, CT, DE, FL, GA, HI, ID, IL, IN, IA, KS, KY, LA, ME,
MD, MA, MI, MN, MS, MO, MT, NE, NV, NH, NJ, NM, NY, NC, ND, OH, OK, OR, PA,
RI, SC, SD, TN, TX, UT, VT, VA, WA, WV, WI, WY

Scoring

This is code-golf, so fewest bytes in each language wins!

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const char *const *s;
	const char *const *t;

	s = a;
	t = b;
	return strcmp(*s, *t);
}

const char *
isengineer(const char *s)
{
	static const char *tab[] = {
	    "AK",
	    "AL",
	    "AR",
	    "AZ",
	    "CA",
	    "CO",
	    "CT",
	    "DE",
	    "FL",
	    "GA",
	    "HI",
	    "IA",
	    "ID",
	    "IL",
	    "IN",
	    "KS",
	    "KY",
	    "LA",
	    "MA",
	    "MD",
	    "ME",
	    "MI",
	    "MN",
	    "MO",
	    "MS",
	    "MT",
	    "NC",
	    "ND",
	    "NE",
	    "NH",
	    "NJ",
	    "NM",
	    "NV",
	    "NV",
	    "NY",
	    "OH",
	    "OK",
	    "OR",
	    "PA",
	    "RI",
	    "SC",
	    "SD",
	    "TN",
	    "TX",
	    "UT",
	    "VA",
	    "VT",
	    "WA",
	    "WI",
	    "WV",
	    "WY",
	};
	const char **p;

	p = bsearch(&s, tab, nelem(tab), sizeof(*tab), cmp);
	if (!p)
		return "What is an engineer?";
	if (strcmp(*p, "OR"))
		return "I am an engineer";
	return "I am not an engineer";
}

int
main(void)
{
	char b[3];
	int i, j;

	for (i = 'A'; i <= 'Z'; i++) {
		for (j = 'A'; j <= 'Z'; j++) {
			sprintf(b, "%c%c", i, j);
			printf("%s: %s\n", b, isengineer(b));
		}
	}
	return 0;
}
