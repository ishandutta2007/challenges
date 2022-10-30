/*

Write a program that accepts a year as input and outputs the century the year belongs in (e.g. 18th century's year ranges are 1701 to 1800) and whether or not the year is a leap year. Pseudocode for leap year can be found here.

Sample run:

Enter Year: 1996

Century: 20

Leap Year: Yes

Enter Year: 1900

Century: 19

Leap Year: No

*/

#include <stdio.h>

int
isleap(unsigned y)
{
	if (y % 4)
		return 0;

	if (!(y % 100) && y % 400)
		return 0;

	return 1;
}

unsigned
century(unsigned y)
{
	return (!y) ? 0 : (y - 1) / 100 + 1;
}

void
classify(unsigned y)
{
	printf("Century: %d\n", century(y));
	printf("Leap Year: %s\n", isleap(y) ? "Yes" : "No");
}

int
main(void)
{
	classify(1996);
	classify(1900);
	classify(1701);
	classify(1800);
	classify(1801);
	classify(2000);
	classify(2001);

	return 0;
}
