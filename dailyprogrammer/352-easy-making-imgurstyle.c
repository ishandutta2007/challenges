/*

Description

Short links have been all the rage for several years now, spurred in part by Twitter's character limits.
Imgur - Reddit's go-to image hosting site - uses a similar style for their links. Monotonically increasing IDs represented in Base62.

Your task today is to convert a number to its Base62 representation.
Input Description

You'll be given one number per line. Assume this is your alphabet:

0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 

Example input:

15674
7026425611433322325

Output Description

Your program should emit the number represented in Base62 notation. Examples:

O44
bDcRfbr63n8

Challenge Input

187621
237860461
2187521
18752

Challenge Output

9OM
3n26g
B4b9
sS4    

Note

Oops, I have the resulting strings backwards as noted in this thread. Solve it either way, but if you wish make a note as many are doing. Sorry about that.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

char *
base62(uvlong n, char *b)
{
	static const char sym[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static const size_t symlen = sizeof(sym) - 1;

	size_t i;

	i = 0;
	do {
		b[i++] = sym[n % symlen];
	} while (n /= symlen);
	b[i] = '\0';

	return b;
}

void
test(uvlong n, const char *r)
{
	char b[512];

	base62(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(15674ull, "O44");
	test(7026425611433322325ull, "bDcRfbr63n8");
	test(187621ull, "9OM");
	test(237860461ull, "3n26g");
	test(2187521ull, "B4b9");
	test(18752ull, "sS4");

	return 0;
}
