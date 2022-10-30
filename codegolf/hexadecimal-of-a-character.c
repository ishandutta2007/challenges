/*

Given a unicode character C (or the first character of a string input), output that character's hex representation. Case does not matter. The output ranges from \u0000 to \u9999.

Test cases

A => 41  (65_10 === 41_16)
ʣ => 2A3 (675_10 === 2A3_16)
Ω => 3A9 (937_10 === 3A9_16)
7 => 37  (55_10 === 37_16)
(null byte) => 0 (0_10 === 0_16)

-50% byte bonus if you output the javascript escape character \uXXXX of the character C, e.g. g => \u0067 and ~ => \u007E

*/

#include <stdio.h>

void
printchar(unsigned long r)
{
	printf("%lX\n", r);
}

int
main(void)
{
	printchar(U'A');
	printchar(U'ʣ');
	printchar(U'Ω');
	printchar(U'7');

	return 0;
}
