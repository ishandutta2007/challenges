/*

You will be given a string. It will contain 9 unique integers from 0-9. You must return the missing integer. The string will look like this:

123456789
 > 0

134567890
  > 2

867953120
   > 4

*/

#include <stdio.h>

int
missing(const char *s)
{
	size_t i;
	int n;

	n = 0;
	for (i = 0; s[i]; i++)
		n += s[i];
	return 477 - n;
}

int
main(void)
{
	printf("%d\n", missing("123456789"));
	printf("%d\n", missing("134567890"));
	printf("%d\n", missing("867953120"));
	printf("%d\n", missing("867453120"));
	printf("%d\n", missing("967453120"));
	return 0;
}
