/*

(Easy): The Button can be pressed but once...

The 1st of April brought the Button to Reddit - if you've not heard of it, read the blog post on it here.
The value of the countdown at the instant that someone presses the button determines the flair that they obtain on the subreddit.
For example, if the counter is at 53.04 seconds, then I would obtain a 53 flair, as that is the number of seconds (rounded down).
After a person presses the button, the countdown resets from 60.00 seconds.
Today's challenge is simple - you'll be given a list of users in no particular order, and told at which time each user pressed the button; you'll need to work out which flair each user gets.

You can assume that the countdown never runs to zero for this challenge, and that no two users will press the button at exactly the same moment.
Formal Inputs and Outputs
Input Description

At a time of 0.00 seconds, the countdown starts from 60.00 seconds, counting down. So at a time of 27.34 seconds, the countdown will read 32.66 assuming no-one has pressed the button;
all times are given in this format, with a number of seconds and a number of hundredths of a second. The list of users will be given in this format:

7
UserA: 41.04
UserB: 7.06
UserC: 20.63
UserD: 54.28
UserE: 12.59
UserF: 31.17
UserG: 63.04

The number on the first line is the number of users in the input string; after that, the username of each user, followed by the number of seconds since the beginning of the countdown.
Output Description

Output the numerical flair that each user will receive, in the order in which the users click the buttons - for example:

UserB: 52
UserE: 54
UserC: 51
UserF: 49
UserA: 50
UserD: 46
UserG: 51

UserG clicked the button last, and so they are printed last - when they clicked the button, the countdown was at 51.24, so they receive the 51 flair.
Sample Inputs and Outputs
Sample Input

8
Coder_d00d: 3.14
Cosmologicon: 22.15
Elite6809: 17.25
jnazario: 33.81
nint22: 10.13
rya11111: 36.29
professorlamp: 31.60
XenophonOfAthens: 28.74

Sample Output

Coder_d00d: 56
nint22: 53
Elite6809: 52
Cosmologicon: 55
XenophonOfAthens: 53
professorlamp: 57
jnazario: 57
rya11111: 57

Sample Input

7
bholzer: 101.09
Cosmologicon: 27.45
nint22: 13.76
nooodl: 7.29
nottoobadguy: 74.56
oskar_s: 39.90
Steve132: 61.82

Sample Output

nooodl: 52
nint22: 53
Cosmologicon: 46
oskar_s: 47
Steve132: 38
nottoobadguy: 47
bholzer: 33

Notes

Got any cool ideas for a challenge? Head on over to r/DailyProgrammer_Ideas and tell us what you've got!

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	char name[32];
	double instant;
} Presser;

int
cmp(const void *a, const void *b)
{
	const Presser *p, *q;

	p = a;
	q = b;
	if (p->instant < q->instant)
		return -1;
	if (p->instant > q->instant)
		return 1;
	return 0;
}

void
flair(Presser *p, size_t n)
{
	Presser *q;
	size_t i;
	double t;
	int f;

	qsort(p, n, sizeof(*p), cmp);

	t = 0;
	for (i = 0; i < n; i++) {
		q = p + i;
		f = max(60 - (q->instant - t), 0);
		t = q->instant;
		printf("%s: %d\n", q->name, f);
	}
	printf("\n");
}

int
main(void)
{
	Presser p1[] = {
	    {"UserA", 41.04},
	    {"UserB", 7.06},
	    {"UserC", 20.63},
	    {"UserD", 54.28},
	    {"UserE", 12.59},
	    {"UserF", 31.17},
	    {"UserG", 63.04},
	};

	Presser p2[] = {
	    {"Coder_d00d", 3.14},
	    {"Cosmologicon", 22.15},
	    {"Elite6809", 17.25},
	    {"jnazario", 33.81},
	    {"nint22", 10.13},
	    {"rya11111", 36.29},
	    {"professorlamp", 31.60},
	    {"XenophonOfAthens", 28.74},
	};

	Presser p3[] = {
	    {"bholzer", 101.09},
	    {"Cosmologicon", 27.45},
	    {"nint22", 13.76},
	    {"nooodl", 7.29},
	    {"nottoobadguy", 74.56},
	    {"oskar_s", 39.90},
	    {"Steve132", 61.82},
	};

	flair(p1, nelem(p1));
	flair(p2, nelem(p2));
	flair(p3, nelem(p3));

	return 0;
}
