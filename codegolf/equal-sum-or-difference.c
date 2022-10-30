/*

Write shortest possible code that will return true if the two given integer values are equal or their sum or absolute difference is 5.

Example test cases:

4 1 => True
10 10 => True
1 3 => False
6 2 => False
1 6 => True
-256 -251 => True
6 1 => True
-5 5 => False
The shortest I could come up with in python2 is 56 characters long:

x=input();y=input();print all([x-y,x+y-5,abs(x-y)-5])<1
-9, thanks @ElPedro. It takes input in format x,y:

x,y=input();print all([x-y,x+y-5,abs(x-y)-5])<1

*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool
eq(int a, int b)
{
	return (a == b) || (a + b == 5) || (abs(a - b) == 5);
}

int
main(void)
{
	assert(eq(4, 1) == true);
	assert(eq(10, 10) == true);
	assert(eq(1, 3) == false);
	assert(eq(6, 2) == false);
	assert(eq(1, 6) == true);
	assert(eq(-256, -251) == true);
	assert(eq(6, 1) == true);
	assert(eq(-5, 5) == false);

	return 0;
}
