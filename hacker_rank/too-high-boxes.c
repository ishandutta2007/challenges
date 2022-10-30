/*

You are transporting some boxes through a tunnel, where each box is a parallelepiped,
and is characterized by its length, width and height.

The height of the tunnel is 41 feet and the width can be assumed to be infinite.
A box can be carried through the tunnel only if its height is strictly less than the tunnel's height.
Find the volume of each box that can be successfully transported to the other end of the tunnel.
Note: Boxes cannot be rotated.

*/
#include <stdio.h>

void
tunnelsnake(int l, int w, int h)
{
	if (h >= 41)
		return;

	printf("%d\n", l * w * h);
}

int
main(void)
{
	tunnelsnake(5, 5, 5);
	tunnelsnake(1, 2, 40);
	tunnelsnake(10, 5, 41);
	tunnelsnake(7, 2, 42);
	return 0;
}
