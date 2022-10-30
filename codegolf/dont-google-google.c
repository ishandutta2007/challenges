/*

We all know that if you google the word "google" it will break the internet.

Your task is to create a function that accepts one string and returns its length, in the fewest possible Unicode characters.

However, if the given string is google (lowercase), it will cause an error.

For example, g('bing') will return 4 but g('google') will cause an error.

Please provide an example of usage, and the error if possible.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
search(const char *s)
{
	assert(strcmp(s, "google"));
	return strlen(s);
}

int
main(void)
{
	assert(search("bing") == 4);
	search("google");

	return 0;
}
