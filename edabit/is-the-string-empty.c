/*

Create a function that returns true if a string is empty and false otherwise.
Examples

isEmpty("") ➞ true

isEmpty(" ") ➞ false

isEmpty("a") ➞ false

Notes

    A string containing only whitespaces " " does not count as empty.
    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>

int
isempty(const char *s)
{
	return *s == '\0';
}

int
main(void)
{
	assert(isempty("") == 1);
	assert(isempty(" ") == 0);
	assert(isempty("            ") == 0);
	assert(isempty("38215") == 0);
	assert(isempty("afjabsdf") == 0);
	assert(isempty("!?@&") == 0);

	return 0;
}
