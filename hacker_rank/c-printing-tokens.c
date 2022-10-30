#include <stdio.h>

void
tokens(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] != ' ')
			putchar(s[i]);
		else
			printf("\n");
	}
	if (i > 0 && s[i - 1] != ' ')
		printf("\n");
	printf("\n");
}

int
main(void)
{
	tokens("This is C");
	tokens("Learning C is fun");
	tokens("How is that");
	return 0;
}
