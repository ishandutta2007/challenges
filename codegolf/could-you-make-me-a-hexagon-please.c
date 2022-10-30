/*

Today, we're going to make an ASCII hexagon. You must write a program or function that takes a positive integer n, and outputs a hexagon grid of size n, made up of asterisks. For example, a hexagon of size 2 looks like this:

 * *
* * *
 * *
While a hexagon of size 3 looks like this:

  * * *
 * * * *
* * * * *
 * * * *
  * * *
You may use any of the default input and output methods, for example STDIO/STDOUT, function arguments and return values or reading/writing a file.

You may assume that input is always valid, so if it's not a positive integer, your program may do whatever you want. You do however have to handle the special case of a size 1 hexagon, which happens to be a single asterisk:

*
Leading and trailing whitespace is allowed as long as the output is visually the same.

Examples:
1:
*

2:
 * *
* * *
 * *

3:
  * * *
 * * * *
* * * * *
 * * * *
  * * *

4:
   * * * *
  * * * * *
 * * * * * *
* * * * * * *
 * * * * * *
  * * * * *
   * * * *

5:
    * * * * *
   * * * * * *
  * * * * * * *
 * * * * * * * *
* * * * * * * * *
 * * * * * * * *
  * * * * * * *
   * * * * * *
    * * * * *

6:
     * * * * * *
    * * * * * * *
   * * * * * * * *
  * * * * * * * * *
 * * * * * * * * * *
* * * * * * * * * * *
 * * * * * * * * * *
  * * * * * * * * *
   * * * * * * * *
    * * * * * * *
     * * * * * *

12:
           * * * * * * * * * * * *
          * * * * * * * * * * * * *
         * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
       * * * * * * * * * * * * * * * *
      * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * *
    * * * * * * * * * * * * * * * * * * *
   * * * * * * * * * * * * * * * * * * * *
  * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * *
  * * * * * * * * * * * * * * * * * * * * *
   * * * * * * * * * * * * * * * * * * * *
    * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * *
      * * * * * * * * * * * * * * * * *
       * * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
         * * * * * * * * * * * * * *
          * * * * * * * * * * * * *
           * * * * * * * * * * * *
As usual, this is code-golf, so standard loopholes apply, and you should try to write the shortest possible program measured in bytes.
Of course, some languages are inherently shorter or longer than others, so remember that the goal is not necessarily to have the shortest overall byte count, but to beat submissions in the same or similar languages.

May the best golfer win!

*/

#include <stdio.h>
#include <stdlib.h>

void
hexagon(int n)
{
	int i, j, m;

	printf("n=%d\n", n);
	m = (2 * n) - 1;
	for (; m > 0; m--) {
		j = abs(n - m);
		for (i = 0; i < j; i++)
			printf(" ");
		for (i = 0; i < (2 * n) - (j + 1); i++)
			printf("* ");
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	hexagon(1);
	hexagon(2);
	hexagon(3);
	hexagon(4);
	hexagon(5);
	hexagon(6);
	hexagon(12);

	return 0;
}
