/*

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
sheet2num(const char *s)
{
	size_t i, n;
	int c, v, p;

	n = strlen(s);
	if (n == 0)
		return 0;

	v = 0;
	p = 1;
	for (i = n - 1;; i--) {
		c = tolower(s[i]);
		if (!('a' <= c && c <= 'z'))
			return -1;

		v += p * (c - 'a' + 1);
		p *= 26;

		if (i == 0)
			break;
	}
	return v;
}

int
main(void)
{
	printf("%d\n", sheet2num("A"));
	printf("%d\n", sheet2num("Z"));
	printf("%d\n", sheet2num("AA"));
	printf("%d\n", sheet2num("AB"));
	printf("%d\n", sheet2num("ZY"));
	return 0;
}
