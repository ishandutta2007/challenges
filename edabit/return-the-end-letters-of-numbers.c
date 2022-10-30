/*

Create a function that takes an integer and returns it as an ordinal number. An Ordinal Number is a number that tells the position of something in a list, such as 1st, 2nd, 3rd, 4th, 5th etc.

*/

#include <stdio.h>
#include <stdlib.h>

char *
endnum(int x, char *b, size_t n)
{
	static const char *tab[] = {
		"TH",
		"ST",
		"ND",
		"RD",
		"TH",
		"TH",
		"TH",
		"TH",
		"TH",
		"TH",
	};
	snprintf(b, n, "%d-%s", x, tab[abs(x) % 10]);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", endnum(334, b, sizeof(b)));
	printf("%s\n", endnum(12341, b, sizeof(b)));
	printf("%s\n", endnum(1, b, sizeof(b)));
	printf("%s\n", endnum(3222, b, sizeof(b)));
	printf("%s\n", endnum(563, b, sizeof(b)));
	printf("%s\n", endnum(553, b, sizeof(b)));
	printf("%s\n", endnum(34, b, sizeof(b)));
	printf("%s\n", endnum(1231, b, sizeof(b)));
	printf("%s\n", endnum(22, b, sizeof(b)));
	return 0;
}
