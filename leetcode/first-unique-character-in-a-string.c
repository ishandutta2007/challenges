/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
funiqch(const char *s)
{
	size_t i, f[256];
	ssize_t l[256], r;
	int c;

	memset(f, 0, sizeof(f));
	for (i = 0; i < nelem(l); i++)
		l[i] = -1;
	for (i = 0; (c = s[i] & 0xff); i++) {
		f[c]++;
		if (l[c] < 0)
			l[c] = i;
	}
	r = -1;
	for (i = 0; i < nelem(l); i++) {
		if ((r < 0 || r > l[i]) && f[i] == 1)
			r = l[i];
	}

	return r;
}

int
main(void)
{
	printf("%zd\n", funiqch("leetcode"));
	printf("%zd\n", funiqch("loveleetcode"));
	printf("%zd\n", funiqch("aabbcc"));
	printf("%zd\n", funiqch("vvax"));
	return 0;
}
