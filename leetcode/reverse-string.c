#include <stdio.h>
#include <string.h>

char *
rev(char *s)
{
	size_t i, n;
	char c;

	n = strlen(s);
	for (i = 0; i < n / 2; i++) {
		c = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
	return s;
}

int
main(void)
{
	char s1[] = "hello";
	char s2[] = "Hannah";
	printf("%s\n", rev(s1));
	printf("%s\n", rev(s2));
	return 0;
}
