/*

Inspired by a now deleted StackOverflow question. Can you come up with a way to get a particular method executed, without explicitly calling it? The more indirect it is, the better.

Here's what I mean, exactly (C used just for exemplification, all languages accepted):

// Call this.
void the_function(void)
{
    printf("Hi there!\n");
}

int main(int argc, char** argv)
{
    the_function(); // NO! Bad! This is a direct call.
    return 0;
}

*/

#include <stdio.h>

// compilers will optimize printf to puts if there is no format characters in the string
// override the standard lib puts so it will call us
int
puts(const char *s)
{
	(void)s;

	return fputs("Hello, World!\n", stdout);
}

int
main(void)
{
	printf("Goodbye!\n");
	return 0;
}
