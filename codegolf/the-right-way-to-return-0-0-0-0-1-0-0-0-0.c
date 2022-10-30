/*

Here is the program to return [[0, 0, 0], [0, 1, 0], [0, 0, 0]]

[[0]*3,[0,1,0],[0]*3]

*/

#include <stdio.h>
#include <string.h>

void
dump(int m[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
}

void
assign(int m[3][3])
{
	memset(m, 0, sizeof(*m) * 3);
	m[1][1] = 1;
}

int
main(void)
{
	int m[3][3];

	assign(m);
	dump(m);

	return 0;
}
