/*

Unfair hurdles are hurdles which are either too high, or way too close together.

Create a function which takes in an array of strings, representing hurdles, and returns whether or not they are unfair. For the purposes of this challenge, unfair hurdles are:

    At least 4 characters tall.
    Strictly less than 4 spaces apart.

Examples

// Hurdle are good distance apart but are way too tall.

isUnfairHurdle([
  "#    #    #    #",
  "#    #    #    #",
  "#    #    #    #",
  "#    #    #    #"
]) ➞ true


// Hurdles are a fine height but are way too close together.

isUnfairHurdle([
  "#  #  #  #",
  "#  #  #  #",
  "#  #  #  #"
]) ➞ true


// These hurdles are mighty splendid.

isUnfairHurdle([
  "#      #      #      #",
  "#      #      #      #"
]) ➞ false

Notes

    Hurdles will be represented with a hashtag "#".
    There will be the same spacing between hurdles.
    Hurdles are always as high as the length of the array.
    Hurdles are always evenly spaced.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
findhurdle(const char **s, size_t n, size_t c, size_t *sp)
{
	const char *p, *q;
	size_t i, o;

	p = s[0] + c;
	q = strchr(p, '#');
	if (!q)
		return 1;

	o = q - p;
	for (i = 0; i < n; i++) {
		if (s[i][c + o] != '#')
			return -1;
	}

	*sp = o;
	return 0;
}

int
unfairhurdle(const char **s, size_t n)
{
	size_t c, lsp, sp;
	int rv;

	if (n == 0)
		return 0;

	lsp = 0;
	c = 0;
	for (;;) {
		rv = findhurdle(s, n, c, &sp);
		if (rv < 0)
			return -1;
		if (rv == 1)
			break;

		if (lsp == 0)
			lsp = sp;
		if (lsp != sp || (sp > 0 && sp < 4) || n >= 4)
			return 1;

		c += sp + 1;
	}

	return 0;
}

int
main(void)
{
	const char *s1[] = {
		"#    #    #    #",
		"#    #    #    #",
		"#    #    #    #",
		"#    #    #    #",
	};
	const char *s2[] = {
		"#  #  #  #",
		"#  #  #  #",
		"#  #  #  #",
	};
	const char *s3[] = {
		"#    #    #    #",
		"#    #    #    #",
		"#    #    #    #"
	};
	const char *s4[] = {
		"#    #    #    #",
		"#    #    #    #",
	};
	const char *s5[] = {
		"#      #      #      #",
		"#      #      #      #",
	};
	const char *s6[] = {
		"########",
		"########",
		"########",
		"########",
		"########",
	};
	const char *s7[] = {
		"#    #",
		"#    #",
	};
	const char *s8[] = {
		"#    #",
		"#    #",
		"#    #",
	};
	const char *s9[] = {
		"#    #    #",
		"#    #    #",
		"#    #    #",
	};
	const char *s10[] = {
		"#    #    #    #    #",
		"#    #    #    #    #",
		"#    #    #    #    #",
	};
	const char *s11[] = {
		"#    #    #    #    #",
		"#    #    #    #    #",
		"#    #    #    #    #",
		"#    #    #    #    #",
		"#    #    #    #    #",
	};
	const char *s12[] = {
		"#    #",
		"#    #",
		"#    #",
		"#    #",
		"#    #",
	};

	assert(unfairhurdle(s1, nelem(s1)) == 1);
	assert(unfairhurdle(s2, nelem(s2)) == 1);
	assert(unfairhurdle(s3, nelem(s3)) == 0);
	assert(unfairhurdle(s4, nelem(s4)) == 0);
	assert(unfairhurdle(s5, nelem(s5)) == 0);
	assert(unfairhurdle(s6, nelem(s6)) == 1);
	assert(unfairhurdle(s7, nelem(s7)) == 0);
	assert(unfairhurdle(s8, nelem(s8)) == 0);
	assert(unfairhurdle(s9, nelem(s9)) == 0);
	assert(unfairhurdle(s10, nelem(s10)) == 0);
	assert(unfairhurdle(s11, nelem(s11)) == 1);
	assert(unfairhurdle(s12, nelem(s12)) == 1);

	return 0;
}
