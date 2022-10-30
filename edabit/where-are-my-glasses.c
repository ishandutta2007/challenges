/*

Oh no! I've lost my glasses, but paradoxically, I need glasses to find my glasses!

Please help me out by showing me the index in the list which contains my glasses. They look like two capital Os, with any number of dashes in between!

    This means that both O--O and O------------O are valid glasses, but not O----#--O for example!
    Search thoroughly, maybe you'll find my glasses in places such as 'dustO-Odust'

Examples

findGlasses(["phone", "O-O", "coins", "keys"]) ➞ 1

findGlasses(["OO", "wallet", "O##O", "O----O"]) ➞ 3

findGlasses(["O--#--O", "dustO---Odust", "more dust"]) ➞ 1

Notes

    All lists will include one valid pair of glasses because I swear I dropped them around here somewhere ...
    All elements in the list are strings.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
find(const char **s, ssize_t n)
{
	ssize_t i, j, t, u;

	for (i = 0; i < n; i++) {
		t = u = 0;
		for (j = 0; s[i][j]; j++) {
			switch (t) {
			case 0:
				if (s[i][j] == 'O') {
					t = 1;
					u = 0;
				}
				break;

			case 1:
				if (s[i][j] == '-')
					u++;
				else if (s[i][j] == 'O') {
					if (u)
						return i;
					u = 0;
				} else
					t = u = 0;
				break;
			}
		}
	}
	return -1;
}

int
main(void)
{
	const char *s1[] = {"phone", "O-O", "coins", "keys"};
	const char *s2[] = {"OO", "wallet", "O##O", "O----O"};
	const char *s3[] = {"O_O", "O-O", "OwO"};
	const char *s4[] = {"O--#--O", "dustO---Odust", "more dust"};
	const char *s5[] = {"floor", "the floor again", "pockets", "bed", "cabinet", "the top of my head O-O"};
	const char *s6[] = {"OOOO----~OOO", "-------", "OOOOOOO", "OO-OO-OO-O"};

	assert(find(s1, nelem(s1)) == 1);
	assert(find(s2, nelem(s2)) == 3);
	assert(find(s3, nelem(s3)) == 1);
	assert(find(s4, nelem(s4)) == 1);
	assert(find(s5, nelem(s5)) == 5);
	assert(find(s6, nelem(s6)) == 3);

	return 0;
}
