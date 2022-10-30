/*

This seems almost trivial, but since after some effort I was not able to beat the literal solution in J, I thought it might make a decent challenge (though, to be clear, this is not a J-specific challenge).

Title says it all. You simply need to write a program, or function (taking no arguments) that returns or prints:

N NE E SE S SW W NW
You may use newlines in place of spaces.

A no-argument function returning an array of strings such as

['N', 'NE', 'E', 'SE', 'S', 'SW', 'W', 'NW']
is also acceptable.

The letters may be upper or lower case, but may not be mixed.

*/

#include <stdio.h>

int
main(void)
{
	printf("N NE E SE S SW W NW\n");
	return 0;
}
