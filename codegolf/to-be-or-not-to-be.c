/*

In the fewest bytes possible, determine whether the two values given each match one of the following:

First value

2      string or integer - whichever you prefer
to     case insensitive
too    case insensitive
two    case insensitive
t0     case insensitive (t zero)
Second value

b      case insensitive
be     case insensitive
bee    case insensitive
b3     case insensitive
Examples
2          'Bee'            true
'2'        'b'              true
'not to'   'be'             false
'that is'  'the question'   false

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>

bool
exists(const char **s, const char *t)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (!strcasecmp(s[i], t))
			return true;
	}
	return false;
}

bool
be(const char *a, const char *b)
{
	static const char *w1[] = {"2", "to", "too", "two", "t0", NULL};
	static const char *w2[] = {"b", "be", "bee", "b3", NULL};

	return exists(w1, a) && exists(w2, b);
}

int
main(void)
{
	assert(be("2", "Bee") == true);
	assert(be("2", "b") == true);
	assert(be("not to", "be") == false);
	assert(be("that is", "the question") == false);

	return 0;
}
