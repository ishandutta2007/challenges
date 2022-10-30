/*

When I was a kid, there was a "really cool" shortcut to count to 100:

1, 2, miss a few, 99, 100

Output the exact string above, in the fewest characters possible, without using these characters: 0, 1, 2, 9

*/

#include <stdio.h>

int
main(void)
{
	printf("%d, %d, %s, %d, %d\n", 4 - 3, 5 - 3, "miss a few", 33 * 3, 5 * 5 * 4);

	return 0;
}
