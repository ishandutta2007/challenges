/*

Create a function that converts dates from one of five string formats:

    "January 9, 2019" (MM D, YYYY)
    "Jan 9, 2019" (MM D, YYYY)
    "01/09/2019" (MM/DD/YYYY)
    "01-09-2019" (MM-DD-YYYY)
    "01.09.2019" (MM.DD.YYYY)

The return value will be an array formatted like: [MM, DD, YYYY], where MM, DD, and YYYY are all integers. Using the examples above:
Examples

convertDate("January 9, 2019") ➞ [1, 9, 2019]

convertDate("Jan 9, 2019") ➞ [1, 9, 2019]

convertDate("01/09/2019") ➞ [1, 9, 2019]

convertDate("01-09-2019") ➞ [1, 9, 2019]

convertDate("01.09.2019") ➞ [1, 9, 2019]

Notes

You can solve this any number of ways, but using JavaScript's new Date() method is probably the easiest. Check the Resources tab for documentation.

*/

#define _XOPEN_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int
convdate(const char *s, int t[3])
{
	static const char *fmts[] = {
		"%b %d, %Y",
		"%m/%d/%Y",
		"%m-%d-%Y",
		"%m.%d.%Y",
		NULL
	};

	struct tm tm;
	size_t i;
	char *p;

	for (i = 0; fmts[i]; i++) {
		p = strptime(s, fmts[i], &tm);
		if (p && *p == '\0')
			break;
	}
	if (fmts[i] == NULL)
		return -1;

	t[0] = tm.tm_mon + 1;
	t[1] = tm.tm_mday;
	t[2] = tm.tm_year + 1900;
	return 0;
}

void
test(const char *s, int *r)
{
	int t[3];

	assert(convdate(s, t) == 0);
	assert(memcmp(t, r, sizeof(t)) == 0);
}

int
main(void)
{
	test("January 9, 2019", (int[]){ 1, 9, 2019 });
	test("Jan 9, 2019", (int[]){ 1, 9, 2019 });
	test("01/09/2019", (int[]){ 1, 9, 2019 });
	test("01-09-2019", (int[]){ 1, 9, 2019 });
	test("01.09.2019", (int[]){ 1, 9, 2019 });
	test("March 3, 1901", (int[]){ 3, 3, 1901 });
	test("Mar 3, 1901", (int[]){ 3, 3, 1901 });
	test("03/03/1901", (int[]){ 3, 3, 1901 });
	test("03-03-1901", (int[]){ 3, 3, 1901 });
	test("03.03.1901", (int[]){ 3, 3, 1901 });
	test("August 8, 1666", (int[]){ 8, 8, 1666 });
	test("Nov 13, 1533", (int[]){ 11, 13, 1533 });
	test("04/15/1789", (int[]){ 4, 15, 1789 });
	test("12-23-1111", (int[]){ 12, 23, 1111 });
	test("02.28.1832", (int[]){ 2, 28, 1832 });

	return 0;
}
