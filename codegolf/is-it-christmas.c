/*

Challenge
Given that Christmas is:

December
Month 12
Day 25
Every year, determine today's date, and whether or not today is Christmas.
If it is Christmas, you must print "It's Christmas".
If it is not Christmas, you must somehow wait until Christmas and then print "It's Christmas".

Example
From this Stack Overflow Question

import time
while time.strftime("%b, %d", time.localtime()) != "Dec, 25":
    time.sleep(60)
print "It's Christmas"
Python in 115 Characters

Rules
Here are the rules:

Assume that the computer's clock is always right.
Your code must be able to be started at any time.
Your code must print "It's Christmas" on Christmas.
Looping is certainly not necessary, but once started your code should not stop until it has printed.
Shortest code wins.

*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>

void
christmas(void)
{
	struct tm tm;
	time_t t;

	for (;;) {
		t = time(NULL);
		localtime_r(&t, &tm);
		if (tm.tm_mon == 11 && tm.tm_mday == 25)
			break;
		sleep(60);
	}
	printf("It's Christmas\n");
}

int
main(void)
{
	christmas();
	return 0;
}
