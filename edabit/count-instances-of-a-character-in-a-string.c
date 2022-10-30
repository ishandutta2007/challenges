/*

Create a function that takes two strings as arguments and returns the number of times the first string (the single character) is found in the second string.

Notes

Your output must be case-sensitive (see second example).

*/

#include <stdio.h>

size_t
charcount(char c, const char *s)
{
	size_t i, n;

	for (i = n = 0; s[i]; i++)
		n += (s[i] == c);
	return n;
}

int
main(void)
{
	printf("%zu\n", charcount('a', "edabit"));
	printf("%zu\n", charcount('b', "big fat bubble"));
	printf("%zu\n", charcount('c', "Chamber of secrets"));
	printf("%zu\n", charcount('f', "frank and his friends have offered five foxes for sale"));
	printf("%zu\n", charcount('x', "edabit"));
	printf("%zu\n", charcount('a', "Adam and Eve bit the apple and found a snake"));
	printf("%zu\n", charcount('s', "sssssssssssssssssssssssss"));
	printf("%zu\n", charcount('7', "10795426697"));
	return 0;
}
