/*

Given an array of strings and an original string, write a function to output an array of boolean values - true if the word can be formed from the original word by swapping two letters only once and false otherwise.
Examples

validateSwaps(["BACDE", "EBCDA", "BCDEA", "ACBED"], "ABCDE")
➞ [true, true, false, false]

// Swap "A" and "B" from "ABCDE" to get "BACDE".
// Swap "A" and "E" from "ABCDE" to get "EBCDA".
// Both "BCDEA" and "ACBED" cannot be formed from "ABCDE" using only a single swap.

validateSwaps(["32145", "12354", "15342", "12543"], "12345")
➞ [true, true, true, true]

validateSwaps(["9786", "9788", "97865", "7689"], "9768")
➞ [true, false, false, false]

Notes

Original string will consist of unique characters.

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
validswaps(const char **s, size_t n, const char *t, bool *b)
{
	size_t i, j, k;
	char x[2], y[2];

	memset(b, 0, sizeof(*b) * n);
	for (i = 0; i < n; i++) {
		for (j = k = 0; s[i][j] && t[j]; j++) {
			if (s[i][j] == t[j])
				continue;

			if (k >= nelem(x)) {
				k++;
				break;
			}
			x[k] = s[i][j];
			y[k] = t[j];
			k++;
		}

		if (k != nelem(x) || s[i][j] != t[j])
			continue;

		b[i] = (x[0] == y[1] && x[1] == y[0]);
	}
}

void
test(const char **s, size_t n, const char *t, bool *r)
{
	bool b[n];

	validswaps(s, n, t, b);
	assert(memcmp(b, r, sizeof(b)) == 0);
}

int
main(void)
{
	const char *s1[] = { "BACDE", "EBCDA", "BCDEA", "ACBED" };
	const char *s2[] = { "32145", "12354", "15342", "12543" };
	const char *s3[] = { "9786", "9788", "97865", "7689" };
	const char *s4[] = { "123", "321", "132", "13", "12" };
	const char *s5[] = { "123", "1234", "1235" };
	const char *s6[] = { "123", "123", "123" };
	const char *s7[] = { "132", "321", "213" };

	bool b1[] = { true, true, false, false };
	bool b2[] = { true, true, true, true };
	bool b3[] = { true, false, false, false };
	bool b4[] = { true, false, false, false, false };
	bool b5[] = { false, false, false };
	bool b6[] = { false, false, false };
	bool b7[] = { true, true, true };

	test(s1, nelem(s1), "ABCDE", b1);
	test(s2, nelem(s2), "12345", b2);
	test(s3, nelem(s3), "9768", b3);
	test(s4, nelem(s4), "213", b4);
	test(s5, nelem(s5), "12", b5);
	test(s6, nelem(s6), "133", b6);
	test(s7, nelem(s7), "123", b7);

	return 0;
}
