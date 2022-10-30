/*

Create a function that takes a string and returns true or false, depending on whether the characters are in order or not.
Examples

isInOrder("abc") ➞ true

isInOrder("edabit") ➞ false

isInOrder("123") ➞ true

isInOrder("xyzz") ➞ true

Notes

You don't have to handle empty strings.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
inorder(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i++) {
		if (s[i] > s[i + 1])
			return false;
	}
	return true;
}

int
main(void)
{
	assert(inorder("abc") == true);
	assert(inorder("edabit") == false);
	assert(inorder("xyz") == true);
	assert(inorder("xyzz") == true);
	assert(inorder("123") == true);
	assert(inorder("321") == false);
	assert(inorder("") == true);

	return 0;
}
