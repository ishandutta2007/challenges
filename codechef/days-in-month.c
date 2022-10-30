/*

RJ is a very curious observer. On the first day of every month, he tries to figure out, for each of the seven days of the week, how many times that day occurs in the current month.

RJ got confused so badly doing this that he asks for your help! He asks several queries; in each query, he gives you the number of days in the current month and which day of the week is on the 1st of the current month.

For each query, you should tell him how many times each day of the week occurs.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains an integer W and a string S, separated by a space.
W denotes the number of days in the current month.
S is one of the strings "mon", "tues", "wed", "thurs", "fri", "sat" or "sun", denoting the day of the week on the 1st of the current month.

Output

For each query, print seven space-separated integers denoting the number of occurrences of Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday.

Constraints
1 ≤ T ≤ 10^3
28 ≤ W ≤ 31

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
days(unsigned w, const char *s, unsigned d[7])
{
	static const char *tab[] = {
	    "mon",
	    "tues",
	    "wed",
	    "thurs",
	    "fri",
	    "sat",
	    "sun",
	};

	unsigned i, n;

	memset(d, 0, sizeof(*d) * 7);

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i])) {
			n = i;
			break;
		}
	}
	if (i == nelem(tab))
		return -1;

	for (i = 0; i < w; i++)
		d[(i + n) % 7]++;

	return 0;
}

void
test(unsigned w, const char *s, unsigned r[7])
{
	unsigned d[7];

	assert(days(w, s, d) >= 0);
	assert(!memcmp(r, d, sizeof(d)));
}

int
main(void)
{
	test(28, "mon", (unsigned[]){4, 4, 4, 4, 4, 4, 4});
	test(31, "wed", (unsigned[]){4, 4, 5, 5, 5, 4, 4});

	return 0;
}
