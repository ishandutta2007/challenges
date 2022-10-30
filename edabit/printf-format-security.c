/*

printf is a standard C function that's a great way to easily print data to the console using format specifiers.
That being said, it's common knowledge that you should NEVER give a user the ability to directly set the first parameter of a function that can take format specifiers.

To pass this challenge, you need to find out why users shouldn't be given full control of printf.
A vulnerable function will take a string you provide and pass it to printf along with a value you need to modify.

Examples

// No examples! The fun is finding the exploit yourself!

Notes

A format specifier is a character set like %s or %f. Look for one that writes to memory.

*/

#include <assert.h>
#include <stdio.h>

int
vulnerability(const char *s)
{
	int v;

	v = 0;
	printf(s, &v);
	return v > 0;
}

int
main(void)
{
	assert(vulnerability("\n%n") == 1);
	return 0;
}
