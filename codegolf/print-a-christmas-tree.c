/*

The Challenge

Print a nice Christmas tree with it's own star at the top using the shortest code possible.
The tree star is an asterisk (*) and the tree body is made out of 0 The tree must be 10 rows high. Every row should be properly indented in the way that the previous row are centered over the next one.
Any given row must have 2 more 0s than the previous, except for the first one that is the star and the second, which has only one 0. The result is something like this:

          *
          0
         000
        00000
       0000000
      000000000
     00000000000
    0000000000000
   000000000000000
  00000000000000000

Tie break for resizable height trees without software changes (except changing height parameter)

Please, paste the resulting tree of your code too! 

*/

#include <stdio.h>

void
tree(int n)
{
	int a, b, c;
	int i, j;

	a = 2 * n - 1;
	for (i = 0; i < n; i++) {
		if (i == 0) {
			b = 1;
			c = '*';
		} else {
			b = 2 * i - 1;
			c = '0';
		}

		for (j = 0; j < (a - b - 1) / 2; j++)
			printf(" ");
		for (j = 0; j < b; j++)
			printf("%c", c);
		printf("\n");
	}
}

int
main(void)
{
	tree(10);
	return 0;
}
