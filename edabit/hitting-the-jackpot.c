/*

Create a function that takes in an array (slot machine outcome) and returns true if all elements in the array are identical, and false otherwise.
The array will contain 4 elements.

Notes

The elements must be exactly identical for there to be a jackpot.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isjackpot(const char *s[], size_t n)
{
	size_t i;

	if (n == 0)
		return 0;

	for (i = 0; i < n - 1; i++) {
		if (strcmp(s[i], s[i + 1]))
			return 0;
	}
	return 1;
}

int
main(void)
{
	const char *s1[] = {"@", "@", "@", "@"};
	const char *s2[] = {"!", "!", "!", "!"};
	const char *s3[] = {"abc", "abc", "abc", "abc"};
	const char *s4[] = {"karaoke", "karaoke", "karaoke", "karaoke"};
	const char *s5[] = {"SS", "SS", "SS", "SS"};
	const char *s6[] = {":(", ":)", ":|", ":"};
	const char *s7[] = {"&&", "&", "&&&", "&&&&"};
	const char *s8[] = {"hee", "heh", "heh", "heh"};
	const char *s9[] = {"SS", "SS", "SS", "Ss"};
	const char *s10[] = {"SS", "SS", "Ss", "Ss"};

	printf("%d\n", isjackpot(s1, nelem(s1)));
	printf("%d\n", isjackpot(s2, nelem(s2)));
	printf("%d\n", isjackpot(s3, nelem(s3)));
	printf("%d\n", isjackpot(s4, nelem(s4)));
	printf("%d\n", isjackpot(s5, nelem(s5)));
	printf("%d\n", isjackpot(s6, nelem(s6)));
	printf("%d\n", isjackpot(s7, nelem(s7)));
	printf("%d\n", isjackpot(s8, nelem(s8)));
	printf("%d\n", isjackpot(s9, nelem(s9)));
	printf("%d\n", isjackpot(s10, nelem(s10)));
	return 0;
}
