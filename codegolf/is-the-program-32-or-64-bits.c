/*

Assignment is simple to explain: write the shortest code you need to determine whether an executable binary program supplied as parameter is 32 or 64 bits.

If there is a different kind of bitness, you can also do for it, but is not mandatory.

What I really don't want is telling me you support other bitnesses and after I get 32 or 64 as a result.

Valid outputs for 32:

32
32bit
32bits
32 bit
32 bits

The same pattern for 64.

*/

#include <stdio.h>
#include <limits.h>

int
main(void)
{
	printf("%zu bits\n", sizeof(void *) * CHAR_BIT);
	return 0;
}
