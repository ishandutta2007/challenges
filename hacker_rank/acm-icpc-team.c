/*

There are a number of people who will be attending ACM-ICPC World Finals.
Each of them may be well versed in a number of topics.
Given a list of topics known by each attendee, you must determine the maximum number of topics a 2-person team can know.
Also find out how many ways a team can be formed to know that many topics.
Lists will be in the form of bit strings, where each string represents an attendee and each position
in that string represents a field of knowledge, 1 if its a known field or 0 if not.

For example, given three attendees' data as follows:

10101
11110
00010

These are all possible teams that can be formed:

Members Subjects
(1,2)   [1,2,3,4,5]
(1,3)   [1,3,4,5]
(2,3)   [1,2,3,4]

In this case, the first team will know all 5 subjects. They are the only team that can be created knowing that many subjects.

Complete the acmTeam function in the editor below.
It should return an integer array with two elements:
the maximum number of topics any team can know and the number of teams that can be formed that know that maximum number of topics.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
cor(const char *a, const char *b)
{
	size_t c, i;

	c = 0;
	for (i = 0; a[i] && b[i]; i++) {
		if ((a[i] - '0') | (b[i] - '0'))
			c++;
	}
	return c;
}

void
know(const char **p, size_t n)
{
	size_t b, c, i, j, m;

	m = c = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			b = cor(p[i], p[j]);
			if (m < b) {
				m = b;
				c = 1;
			} else if (m == b)
				c++;
		}
	}
	printf("%zu %zu\n", m, c);
}

int
main(void)
{
	const char *a[] = {
	    "10101",
	    "11110",
	    "00010",
	};
	know(a, nelem(a));

	const char *b[] = {
	    "10101",
	    "11100",
	    "11010",
	    "00101",
	};
	know(b, nelem(b));

	const char *c[] = {
	    "11101",
	    "10101",
	    "11001",
	    "10111",
	    "10000",
	    "01110",
	};
	know(c, nelem(c));

	return 0;
}
