// Write a function expand(s, t) that expands shorthand notations like a-z in the string s into the equivalent complete list abc ... xyz in t.
// Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
// Arrange that a leading or trailing - is  taken literally.

#include <stdio.h>

char *
expand(const char *s, char *t)
{
	size_t i, j;
	char c;

	i = j = 0;
	while ((c = s[i++])) {
		if (s[i] == '-' && s[i + 1] >= c) {
			i++;
			while (c < s[i])
				t[j++] = c++;
		} else
			t[j++] = c;
	}
	t[j] = '\0';
	return t;
}

int
main(void)
{
	char buf[80];
	printf("%s\n", expand("a-c-p-u-v-z", buf));
	printf("%s\n", expand("test-the-world", buf));
	printf("%s\n", expand("n-y-p-d", buf));
	printf("%s\n", expand("-a-z0-9-", buf));
	return 0;
}
