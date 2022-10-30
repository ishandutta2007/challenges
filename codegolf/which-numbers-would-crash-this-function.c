/*

Which values of x and y will cause a crash with some C compilers?

int f(int x, int y) {
    return (y==0) ? 0 : (x/y);
}

*/

#include <limits.h>

int
f(int x, int y)
{
	return (y == 0) ? 0 : x / y;
}

int
main(void)
{
	f(INT_MIN, -1);
	return 0;
}
