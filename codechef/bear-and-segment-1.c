/*

Bear Limak has a string S. Each character of S is a digit '0' or '1'.

Help Limak and check if all the '1' digits form a single non-empty segment (consecutive subsequence) in the string. For each test case, print "YES" or "NO" accordingly.

*/

#include <stdio.h>

const char *
consecutive(const char *s)
{
	size_t i;
	int f;

	f = 0x0;
	for (i = 0; s[i]; i++) {
		if (s[i] != '1')
			f &= ~0x1;
		else if (f == 0x0)
			f |= 0x7;
		else if ((f & 0x3) != 0x3)
			return "NO";
	}
	return (f & 0x4) ? "YES" : "NO";
}

int
main(void)
{
	printf("%s\n", consecutive("001111110"));
	printf("%s\n", consecutive("00110011"));
	printf("%s\n", consecutive("000"));
	printf("%s\n", consecutive("1111"));
	printf("%s\n", consecutive("101010101"));
	printf("%s\n", consecutive("101111111111"));
	printf("%s\n", consecutive("11111111111"));
	printf("%s\n", consecutive("001"));
	printf("%s\n", consecutive("0"));
	printf("%s\n", consecutive("1"));
	return 0;
}
