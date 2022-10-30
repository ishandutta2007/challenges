/*

You are given four integers a, b, c and d. Determine if there's a rectangle such that the lengths of its sides are a, b, c and d (in any order).

*/

#include <stdio.h>
#include <stdlib.h>

const char *
isrect(int a, int b, int c, int d)
{
	if (a == b && c == d)
		return "YES";
	if (a == c && b == d)
		return "YES";
	if (a == d && b == c)
		return "YES";
	return "NO";
}

int
main(void)
{
	printf("%s\n", isrect(1, 1, 2, 2));
	printf("%s\n", isrect(3, 2, 2, 3));
	printf("%s\n", isrect(1, 2, 2, 2));
	printf("%s\n", isrect(1, 2, 20, 2));
	printf("%s\n", isrect(20, 20, 20, 20));
	printf("%s\n", isrect(5, 5, 5, 1));
	printf("%s\n", isrect(6, 8, 8, 6));
	return 0;
}
