/*

Something which is not true is false, but something which is not not true is true! Create a function where given n number of "not", evaluate whether it's true or false.

Notes

Even though this challenge can be easily solved through the use of an if | else block, you might want to solve it through the use of a Boolean Logic Operator or a Bitwise Operator,
taking the opportunity to become acquainted with these methods (check the Resources tab to find specific links).

*/

#include <stdio.h>
#include <stdbool.h>

bool
notnotnot(unsigned n, bool v)
{
	return (n & 1) ? !v : v;
}

int
main(void)
{
	printf("%d\n", notnotnot(1, true));
	printf("%d\n", notnotnot(2, false));
	printf("%d\n", notnotnot(7, true));
	printf("%d\n", notnotnot(7, false));
	printf("%d\n", notnotnot(3, true));
	printf("%d\n", notnotnot(13, true));
	printf("%d\n", notnotnot(24, false));
	printf("%d\n", notnotnot(6, false));
	return 0;
}
