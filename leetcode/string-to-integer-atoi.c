/*

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.

*/

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int
xatoi(const char *s)
{
	size_t i;
	long sgn, v;

	i = 0;
	while (s[i] == ' ')
		i++;

	sgn = 1;
	switch (s[i]) {
	case '-':
		sgn = -1;
		// fallthrough
	case '+':
		i++;
		break;
	}

	v = 0;
	for (; isdigit(s[i]); i++) {
		v = (v * 10) + (s[i] - '0');
		if (v * sgn >= INT_MAX)
			return INT_MAX;
		if (v * sgn <= INT_MIN)
			return INT_MIN;
	}

	return v * sgn;
}

int
main(void)
{
	printf("%d\n", xatoi("42"));
	printf("%d\n", xatoi("   -42"));
	printf("%d\n", xatoi("4193 with words"));
	printf("%d\n", xatoi("words and 987"));
	printf("%d\n", xatoi("-91283472332"));
	printf("%d\n", xatoi("991283472332"));
	return 0;
}
