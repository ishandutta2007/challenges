/*

Create a function that takes a string (IPv4 address in standard dot-decimal format) and returns true if the IP is valid or false if it's not.
For information on IPv4 formatting, please refer to the resources in the Resources tab.

Notes

    IPv6 addresses are not valid.
    Leading zeros are not valid ("123.045.067.089" should return false).
    You can expect a single string for every test case.
    Numbers may only be between 1 and 255.
    The last digit may not be zero, but any other might.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int
isvalidip(const char *s)
{
	long v;
	char *sp;
	int i;

	for (i = 0; i < 5 && *s != '\0'; i++) {
		if (s[0] == '0' && (s[1] != '.' && s[1] != '\0'))
			return 0;
		if (!isdigit(s[0]))
			return 0;

		v = strtol(s, &sp, 10);
		if (v < 0 || v > 255)
			return 0;

		s = sp;
		if (*s == '.')
			s++;
		else if (*s != '\0')
			return 0;
	}
	return i == 4;
}

int
main(void)
{
	printf("%d\n", isvalidip("12.255.56.1"));
	printf("%d\n", isvalidip("1.2.3.4"));
	printf("%d\n", isvalidip("123.45.67.89"));
	printf("%d\n", isvalidip("0.232.47.227"));

	printf("%d\n", isvalidip("1.2.3"));
	printf("%d\n", isvalidip("12.34.56"));
	printf("%d\n", isvalidip("1.2.3.4.5"));
	printf("%d\n", isvalidip(""));

	printf("%d\n", isvalidip("123.456.78.90"));
	printf("%d\n", isvalidip("123.045.067.089"));
	printf("%d\n", isvalidip("123.456.789.0"));
	printf("%d\n", isvalidip("123.045.067.089"));
	printf("%d\n", isvalidip("1e0.1e0.1e0.1e0"));

	printf("%d\n", isvalidip("abc.def.ghi.jkl"));
	printf("%d\n", isvalidip("12.34.56.-1"));

	printf("%d\n", isvalidip("12.34.56 .1"));
	printf("%d\n", isvalidip("192.168.1.1  "));
	printf("%d\n", isvalidip("  192.168.1.1"));

	return 0;
}
