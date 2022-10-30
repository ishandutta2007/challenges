/*

You are given the length of a video in minutes. The format is mm:ss (e.g.: "02:54").
Create a function that takes the video length and return it in seconds.

Notes

    The video length is given as a string.
    If the number of seconds is 60 or over, return false (see example #3).
    You may get a number of minutes over 99 (e.g. "121:49" is perfectly valid).

*/

#include <stdio.h>

long
mintosec(const char *s)
{
	unsigned x, y;

	if (sscanf(s, "%u:%u", &x, &y) != 2)
		return -1;
	if (y >= 60)
		return -1;
	return 60 * x + y;
}

int
main(void)
{
	printf("%ld\n", mintosec("01:00"));
	printf("%ld\n", mintosec("13:56"));
	printf("%ld\n", mintosec("10:60"));
	printf("%ld\n", mintosec("132:21"));
	printf("%ld\n", mintosec("132:271"));
	printf("%ld\n", mintosec("01:30"));
	printf("%ld\n", mintosec("10:00"));
	return 0;
}
