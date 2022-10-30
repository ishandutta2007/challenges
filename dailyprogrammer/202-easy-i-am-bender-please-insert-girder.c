/*

Description

Poor Mr.Tinkles is having some troubles. Similar to The Loneliest Whale In The World, no one can hear his cries. Or in this case, understand them.

He talks in a sequence of on's and off's. 0's and 1's, it's binary. Obviously as a mere human you can't possibly translate what he's saying as he says it. Looks like you'll have to think of a way around this....
Formal Inputs & Outputs
Input description

On console input you will be given a variable number of 0's and 1's that correspond to letters in the alphabet [a-z] and whitespace ' '. These will be integers coming in, it's your job to cast them however you need.
Output description

The program should output the english translation (or other languages if you feel so inclined!) of the binary phrase
Samples

Input

010010000110010101101100011011000110111100100
0000101011101101111011100100110110001100100

Output

Hello World

Test Input
1

011100000110110001100101011000

010111001101100101001000000111

010001100001011011000110101100

100000011101000110111100100000

0110110101100101
2

011011000110100101100110011001

010010000001110010011010010110

011101101000011101000010000001

101110011011110111011100100000

011010010111001100100000011011

000110111101101110011001010110

110001111001
Finally

Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
translate(const char *s, char *b)
{
	size_t i, j;
	char t[16];

	memset(t, 0, sizeof(t));
	for (i = j = 0; s[i]; i++) {
		if ((i & 7) == 7) {
			memcpy(t, s + i - 7, 8);
			b[j++] = strtol(t, NULL, 2);
		}
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	translate(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	const char *s1 = "010010000110010101101100011011000110111100100"
	                 "0000101011101101111011100100110110001100100";
	const char *s2 = "011100000110110001100101011000"
	                 "010111001101100101001000000111"
	                 "010001100001011011000110101100"
	                 "100000011101000110111100100000"
	                 "0110110101100101";
	const char *s3 = "011011000110100101100110011001"
	                 "010010000001110010011010010110"
	                 "011101101000011101000010000001"
	                 "101110011011110111011100100000"
	                 "011010010111001100100000011011"
	                 "000110111101101110011001010110"
	                 "110001111001";

	test(s1, "Hello World");
	test(s2, "please talk to me");
	test(s3, "life right now is lonely");

	return 0;
}
