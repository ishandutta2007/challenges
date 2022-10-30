/*

Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn't contain the substring "010".
In one step, Alice can change a 0 to a 1 or vice versa.
Count and print the minimum number of steps needed to make Alice see the string as beautiful.

For example, if Alice's string is b=010 she can change any one element and have a beautiful string.

*/

#include <stdio.h>
#include <string.h>

size_t
beautify(const char *s)
{
	const char *p;
	size_t n;

	n = 0;
	for (p = s; (p = strstr(p, "010")); p += 3)
		n++;
	return n;
}

int
main(void)
{
	printf("%zu\n", beautify("010"));
	printf("%zu\n", beautify("0101010"));
	printf("%zu\n", beautify("01100"));
	printf("%zu\n", beautify("0100101010"));
	printf("%zu\n", beautify("01"));
	return 0;
}
