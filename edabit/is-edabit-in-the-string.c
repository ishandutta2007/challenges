/*

A string contains the word "edabit" if a subsequence of its characters spell "edabit".

Write a function that accepts a string and returns “YES” if the string contains a subsequence of the word edabit or "NO" if it does not.

*/

#include <stdio.h>

const char *
hasedabit(const char *s)
{
	static const char *tab = "edabit";
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (s[i] == tab[j] && tab[++j] == '\0')
			return "YES";
	}
	return "NO";
}

int
main(void)
{
	printf("%s\n", hasedabit("eddaaabt"));
	printf("%s\n", hasedabit("edwardisabletodoittoo"));
	printf("%s\n", hasedabit("abecdfghijklmnopqrstuvwxyz"));
	printf("%s\n", hasedabit("edisthebestatthis"));
	printf("%s\n", hasedabit("teachandlearnbitbybit"));
	printf("%s\n", hasedabit("fjkdlkskkkkkdkkdkdedaaakkjkkdkkdklqiieuirooeizooziiciibiiiiifooiioiiuuyeyttgguoosooodiifiufiiodikkjkls"));
	return 0;
}
