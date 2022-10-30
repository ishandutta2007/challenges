/*

Time sheets
In a work place you often have to complete time sheets. This task is write code to help this.

Input
Two times in a slightly non- standard 12 hour clock signifying the start and end of the day separated by a space. A third number represents the number of minutes taken for lunch. For example

9:14 5:12 30
This means you started work at 9:14am, finished work at 5:12pm and took 30 minutes for lunch.

You can assume that

Any time in the first column is from 00:00 (midnight) up to but not including 1pm and any time in the second column is 1pm at the earliest up until 11:59pm.
The lunch break is no longer than the working day!
The input format must be as in the examples given.

Task
Your code should read in a file (or standard input) of these triples, and for each one output how long you worked. This output should indicate the number of hours. For the example above this is:

7hr and 58min minus 30 minutes which is 7hr 28min.

Output
Your output must specify the (whole) number of hours and minutes and must not list more than 59 minutes. That is you can't output 2hr 123min. Apart from that, your code can output in any easily human read format that is convenient for you.

Examples
10:00 1:00 30    --> 2hr 30min
12:59 1:00 0     --> 0hr 1min
00:00 11:59 0    --> 23hr 59min
10:00 2:03 123   --> 2hr 0min

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
convf(const char *s, int f)
{
	int h, m;

	if (sscanf(s, "%d:%d", &h, &m) != 2)
		return -1;

	if (f && h < 12)
		h += 12;

	return (h * 60) + m;
}

char *
convt(int t, char *b)
{
	sprintf(b, "%dhr %dmin", t / 60, t % 60);
	return b;
}

char *
timesheet(const char *t0, const char *t1, const char *tl, char *b)
{
	int s, e, l;

	s = convf(t0, 0);
	e = convf(t1, 1);
	l = atoi(tl);
	if (s < 0 || e < 0 || l < 0)
		return NULL;
	return convt(abs(s - e + l), b);
}

void
test(const char *t0, const char *t1, const char *tl, const char *r)
{
	char b[64], *p;

	p = timesheet(t0, t1, tl, b);
	assert(p);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("10:00", "1:00", "30", "2hr 30min");
	test("12:59", "1:00", "0", "0hr 1min");
	test("00:00", "11:59", "0", "23hr 59min");
	test("10:00", "2:03", "123", "2hr 0min");

	return 0;
}
