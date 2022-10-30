/*

For my CS class, my instructor has given us the assignment of creating a rectangle made of asterisks with diagonal lines drawn through it in Java.

He also told us to write it in as few bytes as possible. I've gotten it down to 190 bytes, but I need to find a few to simplify this code even more to decrease bytes. Can anyone help me with this?

This code is functional:

interface d{static void main(String[]a){for(int z=0,w=new Byte(a[0]),h=new Byte(a[1]);z<h*w;){int y=z/w,x=z++%w;System.out.print((x>w-2)?"*\n":(y%(h-1)*x*((y-x)%3)==0)?"*":" ");}}}

Input is 10 10.

Output:

**********
**  *  * *
* *  *  **
*  *  *  *
**  *  * *
* *  *  **
*  *  *  *
**  *  * *
* *  *  **

*/

#include <stdio.h>

void
asterisk(int w, int h)
{
	int x, y;

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			if (x == 0 || y == 0 || y == h - 1 || x + y == w - 1 || x == w - 1 || x == y)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

int
main(void)
{
	asterisk(10, 10);
	asterisk(50, 50);
	return 0;
}
