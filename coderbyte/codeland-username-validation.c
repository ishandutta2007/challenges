/*

Codeland Username Validation

Have the function CodelandUsernameValidation(str) take the str parameter being passed and determine if the string is a valid username according to the following rules:

1. The username is between 4 and 25 characters.
2. It must start with a letter.
3. It can only contain letters, numbers, and the underscore character.
4. It cannot end with an underscore character.

If the username is valid then your program should return the string true, otherwise return the string false.

Examples
Input: "aa_"
Output: false
Input: "u__hello_world123"
Output: true

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
valid(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_')
			return false;
	}

	if (i < 4 || i > 25 || !isalpha(s[0]) || s[i - 1] == '_')
		return false;

	return true;
}

int
main(void)
{
	assert(valid("aa_") == false);
	assert(valid("u__hello_world123") == true);

	return 0;
}
