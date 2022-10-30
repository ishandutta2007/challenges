/*

The naming conventions for games in the Super Mario series is very strange, and don't match up between regions.

| Japanese Name       | American Name                      |
|---------------------|------------------------------------|
| Super Mario Bros.   | Super Mario Bros.                  |
| Super Mario Bros. 2 | Super Mario Bros.: The Lost Levels |
| Super Mario USA     | Super Mario Bros. 2                |
| Super Mario Bros. 3 | Super Mario Bros. 3                |
| Super Mario Bros. 4 | Super Mario World                  |
What a mess!

Challenge:

Given a string consisting of the Japanese name of a Super Mario game, output the corresponding American name.
You may input the Japanese string through any reasonable method, and output the American string (with an optional newline) through any reasonable method.

You must use the exact strings shown above. Standard loopholes are forbidden!

The shortest code (in bytes) is the winner.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
smb(const char *s)
{
	static const char *tab[][2] = {
	    {"Super Mario Bros.", "Super Mario Bros."},
	    {"Super Mario Bros. 2", "Super Mario Bros.: The Lost Levels"},
	    {"Super Mario USA", "Super Mario Bros. 2"},
	    {"Super Mario Bros. 3", "Super Mario Bros. 3"},
	    {"Super Mario Bros. 4", "Super Mario World"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i][0]))
			return tab[i][1];
	}
	return s;
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = smb(s);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("Super Mario Bros.", "Super Mario Bros.");
	test("Super Mario Bros. 4", "Super Mario World");

	return 0;
}
