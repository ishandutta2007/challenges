/*

Sami's spaceship crashed on Mars! She sends a series of SOS messages to Earth for help.

Letters in some of the SOS messages are altered by cosmic radiation during transmission.
Given the signal received by Earth as a string s,
determine how many letters of Sami's SOS have been changed by radiation.

For example, Earth receives SOSTOT. Sami's original message was SOSSOS. Two of the message characters were changed in transit.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
corrupted(const char *s)
{
	static const char m[] = "SOS";
	size_t i, j, l, c;

	l = nelem(m) - 1;
	c = 0;
	for (i = 0; s[i] != '\0'; i++) {
		j = i % l;
		if (s[i] != m[j])
			c++;
	}

	j = i % l;
	if (j != 0)
		c += l - j;
	return c;
}

int
main(void)
{
	printf("%zu\n", corrupted("SOSTOT"));
	printf("%zu\n", corrupted("SOSSPSSQSSOR"));
	printf("%zu\n", corrupted("SOSSOT"));
	printf("%zu\n", corrupted("SOSSOSSOS"));
	printf("%zu\n", corrupted("SO"));
	printf("%zu\n", corrupted("S"));
	printf("%zu\n", corrupted("T"));
	printf("%zu\n", corrupted(""));
	return 0;
}
