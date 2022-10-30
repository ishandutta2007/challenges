// write a recursive function to compute length of string

#include <stdio.h>

size_t
length(const char *s)
{
	if (*s == '\0')
		return 0;
	return 1 + length(s + 1);
}

int
main(void)
{
	printf("%zu\n", length("shipment"));
	printf("%zu\n", length("apple"));
	printf("%zu\n", length("make"));
	printf("%zu\n", length("a"));
	printf("%zu\n", length(""));
	return 0;
}
