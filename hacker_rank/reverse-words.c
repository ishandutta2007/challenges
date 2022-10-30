// reverse word in a sentence
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
rev(char *s, size_t n)
{
	size_t i;
	char c;

	for (i = 0; i < n / 2; i++) {
		c = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
	return s;
}

char *
revwords(char *s)
{
	size_t i, j, n;
	char c;

	if (s == NULL)
		return NULL;

	n = strlen(s);
	if (n == 0)
		return s;

	rev(s, n);
	for (c = j = 0, i = n - 1;; i--) {
		if (isspace(s[i]) && !isspace(c)) {
			rev(s + i + 1, j);
			j = 0;
		} else if (i == 0) {
			rev(s, j + 1);
			break;
		} else if (!isspace(s[i]))
			j++;
		c = s[i];
	}
	return s;
}

int
main(void)
{
	char str[][80] = {
	    "walk the dog",
	    "cat the mat",
	    "tar   and         outline seed",
	    "hello\tworld\tgoodbye",
	    "abc123",
	};
	size_t i;

	for (i = 0; i < nelem(str); i++) {
		printf("%s\n", str[i]);
		revwords(str[i]);
		printf("%s\n", str[i]);
	}
	return 0;
}
