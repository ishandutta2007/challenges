/*

Create a function that checks if the box is completely filled with the asterisk symbol *.

Examples

completely_filled([
  "#####",
  "#***#",
  "#***#",
  "#***#",
  "#####"
]) ➞ true

completely_filled([
  "#####",
  "#* *#",
  "#***#",
  "#***#",
  "#####"
]) ➞ false

completely_filled([
  "###",
  "#*#",
  "###"
]) ➞ true

completely_filled([
  "##",
  "##"
]) ➞ true

Notes

    Boxes of size n <= 2 are considered automatically filled (see example #4).
    Empty space will always be a space character (" ").

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
filled(const char **s, size_t n)
{
	size_t i, j;

	if (n <= 2)
		return true;

	for (i = 1; i < n - 1; i++) {
		for (j = 1; j < n - 1; j++) {
			if (s[i][j] != '*')
				return false;
		}
	}

	return true;
}

int
main(void)
{
	const char *s1[] = {
	    "#",
	};
	const char *s2[] = {
	    "##",
	    "##",
	};
	const char *s3[] = {
	    "###",
	    "#*#",
	    "###",
	};
	const char *s4[] = {
	    "######",
	    "#****#",
	    "#****#",
	    "#****#",
	    "#****#",
	    "######",
	};
	const char *s5[] = {
	    "#####",
	    "#***#",
	    "#***#",
	    "#***#",
	    "#####",
	};
	const char *s6[] = {
	    "#####",
	    "#* *#",
	    "#***#",
	    "#***#",
	    "#####",
	};
	const char *s7[] = {
	    "######",
	    "#* **#",
	    "#****#",
	    "#* **#",
	    "#*** #",
	    "######",
	};
	const char *s8[] = {
	    "######",
	    "#* **#",
	    "#* **#",
	    "#* **#",
	    "#* **#",
	    "######",
	};

	assert(filled(s1, nelem(s1)) == true);
	assert(filled(s2, nelem(s2)) == true);
	assert(filled(s3, nelem(s3)) == true);
	assert(filled(s4, nelem(s4)) == true);
	assert(filled(s5, nelem(s5)) == true);
	assert(filled(s6, nelem(s6)) == false);
	assert(filled(s7, nelem(s7)) == false);
	assert(filled(s8, nelem(s8)) == false);

	return 0;
}
