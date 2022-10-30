/*

Check if a string title is a title string or not. A title string is one which has all the words in the string start with a upper case letter.

Examples

checkTitle("A Mind Boggling Achievement") ➞ true

checkTitle("A Simple C++ Program!") ➞ true

checkTitle("Water is transparent") ➞ false

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
title(const char *s)
{
	size_t i;

	for (i = 0; s[i];) {
		while (isspace(s[i]))
			i++;

		if (isalpha(s[i]) && islower(s[i]))
			return false;

		while (s[i] && !isspace(s[i]))
			i++;
	}
	return true;
}

int
main(void)
{
	assert(title("A Mind Boggling Achievement") == true);
	assert(title("A Simple C++ Program!") == true);
	assert(title("Water is transparent") == false);

	return 0;
}
