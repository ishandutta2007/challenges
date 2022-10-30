/*

Create a function that takes an array of items and checks if the last item matches the rest of the array.

Notes

The array is always filled with items.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mli(const char **s, size_t n)
{
	size_t i, j, k;

	if (n < 2)
		return 0;

	for (i = k = 0; i < n - 1; i++) {
		for (j = 0; s[i][j]; j++, k++) {
			if (s[i][j] != s[n - 1][k])
				return 0;
		}
	}
	return 1;
}

int
main(void)
{
	const char *s1[] = { "rsq", "6hi", "g", "rsq6hig" };
	const char *s2[] = { "0", "1", "2", "3", "4", "5", "12345" };
	const char *s3[] = { "for", "mi", "da", "bel", "formidable" };
	const char *s4[] = { "8", "thunder", "true", "8thundertrue" };
	const char *s5[] = { "1", "1", "1", "11" };
	const char *s6[] = { "tocto", "G8G", "xtohkgc", "3V8", "ctyghrs", "100.88", "fyuo", "Q", "toctoG8Gxtohkgc3V8ctyghrs100.88fyuoQ" };

	assert(mli(s1, nelem(s1)) == 1);
	assert(mli(s2, nelem(s2)) == 0);
	assert(mli(s3, nelem(s3)) == 0);
	assert(mli(s4, nelem(s4)) == 1);
	assert(mli(s5, nelem(s5)) == 0);
	assert(mli(s6, nelem(s6)) == 1);

	return 0;
}
