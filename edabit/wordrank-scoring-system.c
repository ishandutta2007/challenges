/*

Create a function that takes a string of words and returns the highest scoring word. Each letter of a word scores points according to it's position in the alphabet: a = 1, b = 2, c = 3, etc.

*/

#include <stdio.h>
#include <ctype.h>

char *
wordrank(const char *s, char *b, size_t n)
{
	const char *p, *q;
	unsigned long w, m;
	size_t i, j, l;
	int c;

	if (n == 0)
		return b;

	p = q = s;
	w = m = 0;
	for (i = j = l = 0;; i++, j++) {
		c = s[i] & 0xff;
		if (c == '\0' || isspace(c)) {
			if (m < w) {
				p = q;
				l = j;
				m = w;
			}
			q = &s[i + 1];
			w = 0;
			j = 0;
			if (c == '\0')
				break;
			continue;
		}

		c = tolower(c);
		if ('a' < c && c <= 'z')
			w += c - 'a' + 1;
	}

	for (i = j = 0; i < l && i < n - 1; i++) {
		if (isalpha(p[i]))
			b[j++] = p[i];
	}
	b[j] = '\0';

	return b;
}

int
main(void)
{
	char b[80];
	printf("%s\n", wordrank("The quick brown fox.", b, sizeof(b)));
	printf("%s\n", wordrank("Nancy is very pretty.", b, sizeof(b)));
	printf("%s\n", wordrank("Check back tomorrow, man!", b, sizeof(b)));
	printf("%s\n", wordrank("Wednesday is hump day.", b, sizeof(b)));
	printf("%s\n", wordrank("If the Easter Bunny and the Tooth Fairy had babies would they take your teeth and leave chocolate for you?", b, sizeof(b)));
	printf("%s\n", wordrank("The memory we used to share is no longer coherent.", b, sizeof(b)));
	printf("%s\n", wordrank("He didn’t want to go to the dentist, yet he went anyway.", b, sizeof(b)));
	printf("%s\n", wordrank("What was the person thinking when they discovered cow’s milk was fine for human consumption... and why did they do it in the first place!?", b, sizeof(b)));
	printf("%s\n", wordrank("Mary plays the piano.", b, sizeof(b)));
	printf("%s\n", wordrank("I hear that Nancy is very pretty.", b, sizeof(b)));
	printf("%s\n", wordrank("If you like tuna and tomato sauce- try combining the two. It’s really not as bad as it sounds.", b, sizeof(b)));
	printf("%s\n", wordrank("She works two jobs to make ends meet; at least, that was her reason for not having time to join us.", b, sizeof(b)));
	printf("%s\n", wordrank("Wednesday is hump day, but has anyone asked the camel if he’s happy about it?", b, sizeof(b)));
	printf("%s\n", wordrank("The body may perhaps compensates for the loss of a true metaphysics.", b, sizeof(b)));
	printf("%s\n", wordrank("The clock within this blog and the clock on my laptop are 1 hour different from each other.", b, sizeof(b)));
	printf("%s\n", wordrank("Check back tomorrow; I will see if the book has arrived.", b, sizeof(b)));

	return 0;
}
