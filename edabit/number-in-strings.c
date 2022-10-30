/*

Create a function that takes an array of strings and returns an array with only the strings that have numbers in them.
If there are no strings containing numbers, return an empty array.

Notes

The strings can contain white spaces or any type of characters.
Bonus: Try solving this without regex.

*/

#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
numinstr(const char **l, size_t n)
{
	size_t i, j, k;

	for (i = j = 0; i < n; i++) {
		for (k = 0; l[i][k]; k++) {
			if (isdigit(l[i][k])) {
				l[j++] = l[i];
				break;
			}
		}
	}
	return j;
}

void
test(const char **l, size_t n)
{
	size_t i;

	n = numinstr(l, n);
	printf("[");
	for (i = 0; i < n; i++) {
		printf("\"%s\"", l[i]);
		if (i + 1 < n)
			printf(",");
	}
	printf("]\n");
}

int
main(void)
{
	const char *s1[] = {"1a", "a", "2b", "b"};
	const char *s2[] = {"abc", "abc10"};
	const char *s3[] = {"abc", "ab10c", "a10bc", "bcd"};
	const char *s4[] = {"this is a test", "test1"};
	const char *s5[] = {"1", "a", " ", "b"};
	const char *s6[] = {"rct", "ABC", "Test", "xYz"};
	const char *s7[] = {"this IS", "10xYZ", "xy2K77", "Z1K2W0", "xYz"};
	const char *s8[] = {"-/>", "10bc", "abc"};

	test(s1, nelem(s1));
	test(s2, nelem(s2));
	test(s3, nelem(s3));
	test(s4, nelem(s4));
	test(s5, nelem(s5));
	test(s6, nelem(s6));
	test(s7, nelem(s7));
	test(s8, nelem(s8));

	return 0;
}
