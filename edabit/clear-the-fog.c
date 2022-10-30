/*

Create a function which returns the word in the string, but with all the fog letters removed. However, if the string is clear from fog, return "It's a clear day!".
Examples

clearFog("sky") ➞ "It's a clear day!"

clearFog("fogfogfffoooofftreesggfoogfog") ➞ "trees"

clearFog("fogFogFogffffooobirdsandthebeesGGGfogFog") ➞ "birdsandthebees"

Notes

    There won't be any fog inside of any of the actual words (won't include the letters f, o or g).
    Hidden words are always in lowercase.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
clearfog(char *s)
{
	size_t i, j, c;

	c = 0;
	for (i = j = 0; s[i]; i++) {
		if (strchr("fog", tolower(s[i])))
			c++;
		else
			s[j++] = s[i];
	}
	s[j] = '\0';

	if (c == 0)
		sprintf(s, "It's a clear day!");
	return s;
}

int
main(void)
{
	static char tab[][2][80] = {
		{ "fogfogfffoooofftreesggfoogfog", "trees" },
		{ "fooofffgggofoogfoskygfogfogfoooggg", "sky" },
		{ "ffogfogoggofobirdsandthebeesfogfoggofgoffog", "birdsandthebees" },
		{ "fogfoofgfogfgplanefogofgoffgo", "plane" },
		{ "fogofogoofgfffogthesaurusfogfogfogfgofg", "thesaurus" },
		{ "fogfgofofsunfogfgoogfogofgff", "sun" },
		{ "city", "It's a clear day!" },
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(strcmp(clearfog(tab[i][0]), tab[i][1]) == 0);

	return 0;
}
