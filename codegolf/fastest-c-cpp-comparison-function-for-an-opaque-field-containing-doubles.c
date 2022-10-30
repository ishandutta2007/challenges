/*

Description:

Write the fastest comparison function for an opaque field containing a double. Here is my example:

// Three-way comparison function:
//   if a < b: negative result
//   if a > b: positive result
//   else: zero result
inline int Compare(const unsigned char* a, const unsigned char* b) const
{
    if (*(double*)a < *(double*)b) return -1;
    if (*(double*)a > *(double*)b) return +1;
    return 0;
}
Size: 188 characters (excluding the comments)
Speed: N/A

Background:

Google's LevelDB stores keys as opaque fields (i.e. bytes) and it requires the use of a comparator when the keys cannot be compared as bytes, such as the case with doubles.
You can read this article to see why Floating-Point binary comparison is tricky, so when LevelDB stores key-value pairs on disk it has to properly compare the opaque keys in order to achieve good data locality.

Correct Submission:

The submission must be written in C/C++.
The submission must correctly compare the opaque fields as doubles.
Given that 1 and 2 are satisfied, the winner should be selected based on the minimum CPU operations ticks (i.e. the fastest comparison).
If there is a tie, then the shortest correct submission will be awarded.

P.S. This is my first time posting, so please let me know if I should correct/improve something in the competition.

*/

#include <stdio.h>

int
cmp(const void *a, const void *b)
{
	double x, y;

	x = *(double *)a;
	y = *(double *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int
main(void)
{
	double a, b;

	a = 10;
	b = 30;
	printf("%d\n", cmp(&a, &b));

	a = 40;
	b = 10;
	printf("%d\n", cmp(&a, &b));

	return 0;
}
