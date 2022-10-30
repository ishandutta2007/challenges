// Given a string s consisting of alphabets and digits 
// find the frequency of each digit in the given string.
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
freq(const char *s)
{
	size_t f[10] = {0};
	size_t i;

	for (i = 0; s[i] != '\0'; i++) {
		if ('0' <= s[i] && s[i] <= '9')
			f[s[i] - '0']++;
	}
	for (i = 0; i < nelem(f); i++)
		printf("%zu ", f[i]);
	printf("\n");
}

int
main(void)
{
	freq("a11472o5t6");
	freq("lw4n88j12n1");
	freq("1v88886l256338ar0ekk");
	return 0;
}
