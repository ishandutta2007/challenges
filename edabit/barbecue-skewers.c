/*

You are in charge of the barbecue grill. A vegetarian skewer is a skewer that has only vegetables (-o). A non-vegetarian skewer is a skewer with at least one piece of meat (-x).

For example, the grill below has 4 non-vegetarian skewers and 1 vegetarian skewer (the one in the middle).

["--xo--x--ox--",
"--xx--x--xx--",
"--oo--o--oo--",
"--xx--x--ox--",
"--xx--x--ox--"]

Given a BBQ grill, write a function that returns [# vegetarian skewers, # non-vegetarian skewers]. For example above, the function should return [1, 4].
Examples

bbqSkewers( [
  "--oooo-ooo--",
  "--xx--x--xx--",
  "--o---o--oo--",
  "--xx--x--ox--",
  "--xx--x--ox--"
]) ➞ [2, 3]

bbqSkewers([
  "--oooo-ooo--",
  "--xxxxxxxx--",
  "--o---",
  "-o-----o---x--",
  "--o---o-----"
]) ➞ [3, 2]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
bbqskewers(const char **s, size_t n, size_t r[2])
{
	size_t i;

	r[0] = r[1] = 0;
	for (i = 0; i < n; i++) {
		if (strstr(s[i], "-x"))
			r[1]++;
		else if (strstr(s[i], "-o"))
			r[0]++;
	}
}

void
test(const char **s, size_t n, size_t v, size_t m)
{
	size_t r[2];

	bbqskewers(s, n, r);
	assert(r[0] == v && r[1] == m);
}

int
main(void)
{
	const char *s1[] = {
		"--oooo-ooo--",
		"--xx--x--xx--",
		"--o---o--oo--",
		"--xx--x--ox--",
		"--xx--x--ox--",
	};
	const char *s2[] = {
		"--oooo-ooo--",
		"--xxxxxxxx--",
		"--o---",
		"-o-----o---x--",
		"--o---o-----",
	};
	const char *s3[] = {
		"--oooo-ooo--",
		"--ooooooo--",
		"--o---",
		"-o-----o---x--",
		"--o-oooo-----",
	};
	const char *s4[] = {
		"--xo--x--ox--",
		"--xx--x--xx--",
		"--oo--o--oo--",
		"--xx--x--ox--",
		"--xx--x--ox--",
	};
	const char *s5[] = {
		"--------",
		"--------",
	};

	test(s1, nelem(s1), 2, 3);
	test(s2, nelem(s2), 3, 2);
	test(s3, nelem(s3), 4, 1);
	test(s4, nelem(s4), 1, 4);
	test(s5, nelem(s5), 0, 0);

	return 0;
}
