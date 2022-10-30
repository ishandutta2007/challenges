/*

Create a function that takes two numbers and a mathematical operator + - / * and will perform a calculation with the given numbers.

Notes

If the input tries to divide by 0, return: "Can't divide by 0!"

*/

#include <stdio.h>
#include <string.h>

int
calc(int x, const char *op, int y, int *z)
{
	if (!strcmp(op, "+"))
		*z = x + y;
	else if (!strcmp(op, "-"))
		*z = x - y;
	else if (!strcmp(op, "*"))
		*z = x * y;
	else if (!strcmp(op, "/")) {
		if (y == 0)
			return -1;
		*z = x / y;
	} else
		return -2;
	return 0;
}

void
test(int x, const char *op, int y)
{
	int rv, z;

	rv = calc(x, op, y, &z);
	if (rv == -1)
		printf("Can't divide by 0!\n");
	else if (rv == -2)
		printf("Invalid operator!\n");
	else
		printf("%d\n", z);
}

int
main(void)
{
	test(2, "/", 2);
	test(10, "-", 7);
	test(2, "*", 16);
	test(2, "-", 2);
	test(15, "+", 26);
	test(2, "+", 2);
	test(2, "/", 0);
	return 0;
}
