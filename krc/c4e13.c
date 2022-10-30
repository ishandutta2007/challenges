// Write a recursive version of the function reverse(s),
// which reverses the string s in place.

#include <stdio.h>
#include <string.h>

void
reverser(char *s, size_t i, size_t len)
{
	size_t j;
	char c;

	if (i >= len)
		return;

	j = len - (i + 1);
	if (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}
}

char *
reverse(char *s)
{
	reverser(s, 0, strlen(s));
	return s;
}

void
test(char *s)
{
	int i;
	for (i = 0; i < 4; i++) {
		reverse(s);
		printf("%s\n", s);
	}
	printf("--------\n");
}

int
main(void)
{
	char a[] = "ritchie tensor manifold";
	test(a);

	char b[] = "exofield over transmission lines";
	test(b);

	char c[] = "";
	test(c);

	char d[] = "quantum foliage";
	test(d);

	return 0;
}
