/*

Create a function which validates whether a bridge is safe to walk on (i.e. has no gaps in it to fall through).
Examples

isSafeBridge("####") ➞ true

isSafeBridge("## ####") ➞ false

isSafeBridge("#") ➞ true

Notes

You can expect the bridge's ends connecting it to its surrounding.

*/

#include <assert.h>
#include <stdio.h>

int
safebridge(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] != '#')
			return 0;
	}
	return i > 0;
}

int
main(void)
{
	assert(safebridge("####") == 1);
	assert(safebridge("## ####") == 0);
	assert(safebridge("#") == 1);
	assert(safebridge("# #") == 0);
	return 0;
}
