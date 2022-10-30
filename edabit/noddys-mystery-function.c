/*

Noddy has written a mysterious function which takes in a word and returns true if it's passed a specific test. Solve the riddle of what Noddy's function is by having a look at some of the examples below.
Examples

noddy_function("FANTASTIC") ➞ true

noddy_function("wonderful") ➞ false

noddy_function("NODDY") ➞ false

Notes

    Check the Tests tab for more examples.
    This isn't really a coding challenge, more of a fun riddle ;)

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const char *s, const char *t)
{
	size_t i;
	int x, y;

	for (i = 0;; i++) {
		x = tolower(s[i]);
		y = tolower(t[i]);
		if (x != y)
			return x - y;
		if (x == '\0' || y == '\0')
			break;
	}
	return 0;
}

bool
noddy(const char *w)
{
	static const char *tab[] = {
		"fantastic",
		"waterfall",
		"nature",
		"benevolent",
		"courageous",
		"virtue",
		"creature",
		"planet",
		"possibility",
		"inspiration",
		"hope",
		"nurture",
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (cmp(tab[i], w) == 0)
			return true;
	}
	return false;
}

int
main(void)
{
	assert(noddy("FANTASTIC") == true);
	assert(noddy("wonderfall") == false);
	assert(noddy("NODDY") == false);
	assert(noddy("fantastic") == true);
	assert(noddy("wonderful") == false);
	assert(noddy("noddy") == false);
	assert(noddy("blessed") == false);
	assert(noddy("Wonder") == false);
	assert(noddy("waterfall") == true);
	assert(noddy("nature") == true);
	assert(noddy("ADVENTUROUS") == false);
	assert(noddy("Benevolent") == true);
	assert(noddy("courageous") == true);
	assert(noddy("End") == false);
	assert(noddy("virtue") == true);
	assert(noddy("Kindness") == false);
	assert(noddy("CREATURE") == true);
	assert(noddy("Planet") == true);
	assert(noddy("disaster") == false);
	assert(noddy("possibility") == true);
	assert(noddy("Inspiration") == true);
	assert(noddy("Hope") == true);
	assert(noddy("nurture") == true);
	assert(noddy("UNDERSTANDING") == false);
	assert(noddy("Edabit") == false);

	return 0;
}
