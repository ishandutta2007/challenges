/*

Given a list of digits 1 through 9, output whether each digit is grouped together as a single contiguous block. In other words, no two of the same digit are separated by different digits. It's OK if a digit doesn't appear at all. Fewest bytes wins.

Input: A non-empty list of digits 1 through 9. This can be as a decimal number, string, list, or similar sequence.

Output: A consistent Truthy value if all the digits are grouped in contiguous blocks, and a consistent Falsey value if they are not.

True cases:

3
51
44999911
123456789
222222222222222222222
False cases:

818
8884443334
4545
554553
1234567891

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
grouped(const char *s)
{
	size_t i, j;
	char h[256];
	int c;

	memset(h, 0, sizeof(h));
	for (i = j = 0; s[i]; i = j) {
		j = i + 1;
		while (s[i] == s[j])
			j++;

		c = s[i] & 0xff;
		if (h[c])
			return false;
		h[c] = 1;
	}
	return true;
}

int
main(void)
{
	assert(grouped("3") == true);
	assert(grouped("51") == true);
	assert(grouped("44999911") == true);
	assert(grouped("123456789") == true);
	assert(grouped("222222222222222222222") == true);

	assert(grouped("818") == false);
	assert(grouped("8884443334") == false);
	assert(grouped("4545") == false);
	assert(grouped("554553") == false);
	assert(grouped("1234567891") == false);

	return 0;
}
