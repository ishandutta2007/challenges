/*

Create a function that takes an array of numbers and return "Boom!" if the number 7 appears in the array.
Otherwise, return "there is no 7 in the array".

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
sevenboom(int *a, size_t n)
{
	char s[80];
	size_t i;

	for (i = 0; i < n; i++) {
		snprintf(s, sizeof(s), "%d", a[i]);
		if (strchr(s, '7'))
			return "Boom!";
	}
	return "there is no 7 in the array";
}

int
main(void)
{
	int a1[] = {2, 6, 7, 9, 3};
	int a2[] = {33, 68, 400, 5};
	int a3[] = {86, 48, 100, 66};
	int a4[] = {76, 55, 44, 32};
	int a5[] = {35, 4, 9, 37};
	int a6[] = {1, 2, 3, 4, 5, 6, 7};
	int a7[] = {8, 6, 33, 100};
	int a8[] = {2, 55, 60, 97, 86};

	printf("%s\n", sevenboom(a1, nelem(a1)));
	printf("%s\n", sevenboom(a2, nelem(a2)));
	printf("%s\n", sevenboom(a3, nelem(a3)));
	printf("%s\n", sevenboom(a4, nelem(a4)));
	printf("%s\n", sevenboom(a5, nelem(a5)));
	printf("%s\n", sevenboom(a6, nelem(a6)));
	printf("%s\n", sevenboom(a7, nelem(a7)));
	printf("%s\n", sevenboom(a8, nelem(a8)));

	return 0;
}
