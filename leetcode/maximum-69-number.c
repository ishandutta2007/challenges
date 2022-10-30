/*

Given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Constraints:

    1 <= num <= 10^4
    num's digits are 6 or 9.

Hint 1
Convert the number in an array of its digits.

Hint 2
Brute force on every digit to get the maximum number.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned
max69(unsigned n)
{
	char b[sizeof(n) * 8], *p;

	snprintf(b, sizeof(b), "%u", n);
	if ((p = strchr(b, '6')))
		*p = '9';
	return strtoul(b, NULL, 10);
}

int
main(void)
{
	printf("%u\n", max69(9669));
	printf("%u\n", max69(9996));
	printf("%u\n", max69(9999));
	return 0;
}
