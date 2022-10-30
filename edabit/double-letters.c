// Create a function that takes a word and returns true if the word has two consecutive identical letters.

#include <stdio.h>

int
doubleletters(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == s[i + 1])
			return 1;
	}
	return 0;
}

int
main(void)
{
	printf("%d\n", doubleletters("loop"));
	printf("%d\n", doubleletters("meeting"));
	printf("%d\n", doubleletters("yummy"));
	printf("%d\n", doubleletters("moo"));
	printf("%d\n", doubleletters("toodles"));
	printf("%d\n", doubleletters("droop"));
	printf("%d\n", doubleletters("loot"));

	printf("%d\n", doubleletters("orange"));
	printf("%d\n", doubleletters("munchkin"));
	printf("%d\n", doubleletters("forestry"));
	printf("%d\n", doubleletters("raindrops"));
	printf("%d\n", doubleletters("gold"));
	printf("%d\n", doubleletters("paradise"));

	return 0;
}
