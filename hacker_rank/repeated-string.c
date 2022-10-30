/*
Lilah has a string, s, of lowercase English letters that she repeated infinitely many times.

Given an integer, n, find and print the number of letter a's in the first n letters of Lilah's infinite string.

For example, if the string s=abcac and n=10, the substring we consider is abcacabcac, the first 10 characters of her infinite string.
There are 4 occurrences of a in the substring.
*/
#include <stdio.h>
#include <inttypes.h>

size_t
repeat(const char *s, size_t n)
{
	size_t i, c;

	c = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (i >= n)
			return c;

		if (s[i] == 'a')
			c++;
	}
	if (i == 0)
		return c;

	c = (n / i) * c;
	for (i = n % i; i != 0 && s[i] != '\0'; i++) {
		if (s[i] == 'a')
			c++;
	}
	return c;
}

int
main(void)
{
	printf("%zu\n", repeat("abcac", 10));
	printf("%zu\n", repeat("aba", 10));
	printf("%zu\n", repeat("a", 1000000000000ULL));
	printf("%zu\n", repeat("aa", 1000000000000ULL));
	printf("%zu\n", repeat("", SIZE_MAX));
	return 0;
}
