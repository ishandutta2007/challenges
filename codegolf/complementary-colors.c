/*

Given an input of a color in #rrggbb hex format, output its RGB complement in the same format.

The RGB complement R2G2B2 of any color R1G1B1 is defined as the color with R2 value 255 - R1, B2 value 255 - B1, and G2 value 255 - G1.

Hex digits may be either in uppercase (#FFAA20) or lowercase (#ffaa20). The case of the input and output need not be consistent (so you may take input in lowercase but output in uppercase, and vice versa).

Since this is code-golf, the shortest code in bytes wins.

Test cases (note that since giving your program/function its own output should result in the original input (it is involutory), the test cases should work in both directions):

In/Out   Out/In
----------------
#ffffff  #000000
#abcdef  #543210
#badcab  #452354
#133742  #ecc8bd
#a1b2c3  #5e4d3c
#7f7f80  #80807f

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
complement(const char *s, char *b)
{
	unsigned R, G, B;

	if (sscanf(s, "#%02x%02x%02x", &R, &G, &B) != 3)
		return NULL;
	sprintf(b, "#%02x%02x%02x", 255 - R, 255 - G, 255 - B);
	return b;
}

void
test(const char *s, const char *t)
{
	char a[128], b[128];

	complement(s, a);
	complement(a, b);
	printf("%s %s\n", a, b);
	assert(!strcmp(t, a));
	assert(!strcmp(s, b));
}

int
main(void)
{
	test("#ffffff", "#000000");
	test("#abcdef", "#543210");
	test("#badcab", "#452354");
	test("#133742", "#ecc8bd");
	test("#a1b2c3", "#5e4d3c");
	test("#7f7f80", "#80807f");

	return 0;
}
