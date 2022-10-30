/*

John has collected various rocks. Each rock has various minerals embeded in it. Each type of mineral is designated by a lowercase letter in the range ascii[a-z]. 
There may be multiple occurrences of a mineral in a rock. A mineral is called a gemstone if it occurs at least once in each of the rocks in John's collection.
Given a list of minerals embedded in each of John's rocks, display the number of types of gemstones he has in his collection.

For example, the array of mineral composition strings arr=[abc, abc, bc].
The minerals b and c appear in each composite, so there are 2 gemstones.

*/
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
gems(const char **s, size_t n)
{
	size_t h[26], i, j;
	char f[sizeof(h)];
	int c, k;

	memset(h, 0, sizeof(h));
	k = 0;
	for (i = 0; i < n; i++) {
		memset(f, 0, sizeof(f));
		for (j = 0; s[i][j]; j++) {
			c = (s[i][j] & 0xff) - 'a';
			if (!(0 <= c && c < nelem(h)) || f[c])
				continue;

			if (h[c] <= n)
				h[c]++;
			if (h[c] == n)
				k++;
			f[c] = 1;
		}
	}
	return k;
}

int
main(void)
{
	const char *a[] = {
	    "abc",
	    "abc",
	    "bc",
	};
	printf("%d\n", gems(a, nelem(a)));

	const char *b[] = {
	    "abcdde",
	    "baccd",
	    "eeabg",
	};
	printf("%d\n", gems(b, nelem(b)));

	const char *c[] = {
	    "abcdefghijklmnopqrstuvwxyz",
	    "abcdefghijklmnopqrstuvwxy",
	};
	printf("%d\n", gems(c, 1));
	printf("%d\n", gems(c, nelem(c)));

	return 0;
}
