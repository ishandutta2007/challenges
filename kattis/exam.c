/*

Your friend and you took the same true/false exam. You know your answers, your friend’s answers, and the number of your friend’s answers that were correct.

Compute the maximum possible score you could have gotten.

Input

The first line contains a single integer k, the number of correct answers on your friend’s exam.

The second line contains a string of characters, the answers you wrote down. Each letter is either a ‘T’ or an ‘F’. The length of the string is the number n of exam questions.

The third line also contains a string of n characters, the answers your friend wrote down. Each letter is either a ‘T’ or an ‘F’.

Bounds are 0≤k≤n≤1000;1≤n.

Output

The output is one line containing the maximum number of questions you could have gotten correct.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
maxscore(size_t k, const char *s, const char *t)
{
	size_t a, b, c, i;

	a = b = 0;
	for (i = 0; s[i] && t[i]; i++) {
		a += (s[i] == t[i]);
		b += (s[i] != t[i]);
	}
	c = i - min(k, i);

	return a + (2 * min(b, c)) - c;
}

int
main(void)
{
	assert(maxscore(3, "FTFFF", "TFTTT") == 2);
	assert(maxscore(6, "TTFTFFTFTF", "TTTTFFTTTT") == 9);

	return 0;
}
