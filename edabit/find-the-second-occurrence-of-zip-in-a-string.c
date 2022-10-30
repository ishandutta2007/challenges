/*

Write a function that returns the position of the second occurrence of "zip" in a string, or -1 if it does not occur at least twice.
Your code should be general enough to pass every possible case where "zip" can occur in a string.

Notes

Uppercase "Zip" is not the same as lowercase "zip".

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

ssize_t
findzip(const char *s)
{
	const char *p;

	if (!(p = strstr(s, "zip")))
		return -1;
	if (!(p = strstr(p + 3, "zip")))
		return -1;
	return p - s;
}

int
main(void)
{
	assert(findzip("all zip files are zipped") == 18);
	assert(findzip("all zip files are compressed") == -1);
	assert(findzip("We believe university-level zip education can be both high quality and low cost. Using the economics of the Internet, we've connected some of the greatest teachers to hundreds of thousands of students all over the world.") == -1);
	assert(findzip("Zip is a file format used for data compression and archiving. A zip file contains one or more files that have been compressed, to reduce file size, or stored as is. The zip file format permits a number of compression algorithms.") == 169);
	return 0;
}
