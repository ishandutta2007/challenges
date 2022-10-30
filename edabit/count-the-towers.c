/*

Create a function that counts the number of towers.
Examples

count_towers([
  ["     ##         "],
  ["##   ##        ##"],
  ["##   ##   ##   ##"],
  ["##   ##   ##   ##"]
]) ➞ 4

count_towers([
  ["                         ##"],
  ["##             ##   ##   ##"],
  ["##        ##   ##   ##   ##"],
  ["##   ##   ##   ##   ##   ##"]
]) ➞ 6

count_towers([
  ["##"],
  ["##"]
]) ➞ 1

Notes

    You are given a 2D matrix.
    Towers are two characters in length.
    Towers are made only of the character #.
    Some tests have no towers, return 0.

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
towers(const char **s, size_t n)
{
	const char *p;
	size_t t;

	if (n == 0)
		return 0;

	t = 0;
	p = s[n - 1];
	while ((p = strstr(p, "##"))) {
		p += 2;
		t += 1;
	}

	return t;
}

int
main(void)
{
	const char *s1[] = {
		"     ##         ",
		"##   ##        ##",
		"##   ##   ##   ##",
		"##   ##   ##   ##",
	};
	const char *s2[] = {
		"                         ##",
		"##             ##   ##   ##",
		"##        ##   ##   ##   ##",
		"##   ##   ##   ##   ##   ##",
	};
	const char *s3[] = {
		"##",
		"##",
	};
	const char *s4[] = {
		"",
	};
	const char *s5[] = {
		"                                              ",
		"##   ##   ##   ##   ##   ##   ##   ##   ##   ##",
		"##   ##   ##   ##   ##   ##   ##   ##   ##   ##",
		"##   ##   ##   ##   ##   ##   ##   ##   ##   ##",
	};
	const char *s6[] = {
		"##   ##          ",
		"##   ##          ",
		"##   ##   ##   ##",
	};

	assert(towers(s1, nelem(s1)) == 4);
	assert(towers(s2, nelem(s2)) == 6);
	assert(towers(s3, nelem(s3)) == 1);
	assert(towers(s4, nelem(s4)) == 0);
	assert(towers(s5, nelem(s5)) == 10);
	assert(towers(s6, nelem(s6)) == 4);

	return 0;
}
