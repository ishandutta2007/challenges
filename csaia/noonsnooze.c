/*

Write a program NoonSnooze.java that takes an integer command-line argument representing the number of minutes, snooze, that have elapsed since 12:00pm (noon) and prints the resulting time.
Assume a 12-hour clock (with ‘am’ and ‘pm’). You must not use loops. You may assume that the value of snooze is a non-negative integer.

Hints!
Use integer division (/) and integer remainder (%) operators to help compute the new values for the hours and minutes.
Use the integer remainder (%) operator to determine if the clock should read am or pm.
Use conditionals (if) to help format the output.


Exercises!
Try solving this problem by hand, e.g., using the following values: 0, 9, 15, 60, 719, 720, 721, 1440, 1441, ..., 5039, 5040, 5041, … Use only integer division (/) and integer remainder (%).


Examples:

> java-introcs NoonSnooze 50
12:50pm

> java-introcs NoonSnooze 100
1:40pm

> java-introcs NoonSnooze 721
12:01am

> java-introcs NoonSnooze 11111
5:11am

*/

#include <stdio.h>
#include <stdlib.h>

char *
snooze(int t, char *b)
{
	const char *p;
	int h, m, i;

	if (t < 0) {
		sprintf(b, "invalid input");
		return b;
	}

	h = t / 60;
	m = t % 60;

	i = (12 + h) % 12;
	if (i == 0)
		i += 12;
	p = (h < 12) ? "pm" : "am";

	sprintf(b, "%d:%02d %s", i, m, p);
	return b;
}

int
main(int argc, char *argv[])
{
	char b[128];
	int i;

	if (argc < 2) {
		fprintf(stderr, "usage: minutes ...\n");
		return 1;
	}

	for (i = 1; i < argc; i++)
		printf("%s\n", snooze(atoi(argv[i]), b));

	return 0;
}
