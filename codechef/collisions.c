/*

Once N boys and M girls attended a party. You are given a matrix A of N rows and M columns where Aij is 1 if the i-th boy likes the j-th girl,
otherwise it will be 0. Note that it is not necessary that if a boy x likes girl y, then girl y should like boy x.

You know that if there are two different boys x and y, who both like girl z, then there will be a collision.
Can you calculate the number of different collisions at this party? Note that order of boys in the collision doesn't matter.

*/

#include <stdio.h>

int
collision(int r, int c, int m[r][c])
{
	int i, j, n, s;

	n = 0;
	for (j = 0; j < c; j++) {
		s = 0;
		for (i = 0; i < r; i++)
			s += m[i][j];

		if (s > 1)
			n += (s == 2) ? 1 : s;
	}
	return n;
}

int
main(void)
{
	int a[4][3] = {
	    {1, 1, 1},
	    {1, 0, 0},
	    {1, 1, 0},
	    {0, 0, 0},
	};
	printf("%d\n", collision(4, 3, a));

	int b[2][2] = {
	    {1, 0},
	    {0, 1},
	};
	printf("%d\n", collision(2, 2, b));

	return 0;
}
