/*

Julia enjoys talking to her grandma, playing with legos, and inventing two-player card games where she has a winning strategy.
Recently however, she has not been able to talk to her grandma in person because of some kind of “pandemonium”.
Instead, they have resorted to texting, which is a very slow process since grandma types very slowly and often mistypes letters.
To make matters worse, grandma has started to write every word three times so that Julia can correct her mistypes.
For example, if grandma wants to write the word “hello”, she will instead write “hellohellohello”. If she mistypes one of those letters, it might instead be sent as “hellohrllohello’.’

Your task is to write a program that given a message sent by grandma, where possibly one letter has been changed to some other letter, finds the original word.

Input

The input consists of one string s containing lower case English letters (3≤|s|≤99). This is the message sent by grandma.
It is guaranteed that this string is the result of a word being written three times, where possibly one letter was changed to some other letter.

Output

Output one string t, the original word.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
word(const char *s, char *b)
{
	size_t c, i, j, l, n;

	n = strlen(s);
	if (n == 0 || n % 3)
		return NULL;

	l = n / 3;
	for (i = 0; i < 3; i++) {
		c = 0;
		for (j = i + 1; j < 3; j++) {
			if (!strncmp(s + i * l, s + j * l, l))
				c++;
		}
		if (c == 0)
			break;
	}

	j = (i == 0) ? i + 1 : i - 1;
	strncpy(b, s + j * l, l);
	b[l] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128], *p;

	p = word(s, b);
	if (p == NULL)
		assert(p == r);
	else {
		printf("%s\n", p);
		assert(!strcmp(p, r));
	}
}

int
main(void)
{
	test("hellohrllohello", "hello");
	test("hejhejhej", "hej");
	test("xehxehshe", "xeh");
	test("xorxoreax", "xor");
	return 0;
}
