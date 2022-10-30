/*

Given the following matrix :

            [1   1   0 ]
      A =   [0   1   0 ]
            [0   0   1 ]

We compute that

A^100 =

    [A B 0]
    [0 C 0]
    [0 D E]


*/
#include <stdio.h>
#include <string.h>

void
zero(int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			m[i][j] = 0;
	}
}

void
copy(int p[3][3], int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			p[i][j] = m[i][j];
	}
}

void
mul(int c[3][3], int a[3][3], int b[3][3])
{
	int i, j, k, t[3][3];
	zero(t);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++)
				t[i][j] += a[i][k] * b[k][j];
		}
	}
	copy(c, t);
}

void
mexp(int m[3][3], int n)
{
	int p[3][3], i;
	copy(p, m);
	for (i = 1; i < n; i++)
		mul(p, p, m);
	copy(m, p);
}

void
print(int m[3][3])
{
	printf("%d\n", m[0][0]);
	printf("%d\n", m[0][1]);
	printf("%d\n", m[1][1]);
	printf("%d\n", m[2][1]);
	printf("%d\n", m[2][2]);
}

int
main(void)
{
	int a[3][3] = {
	    {1, 1, 0},
	    {0, 1, 0},
	    {0, 0, 1},
	};
	mexp(a, 100);
	print(a);
	return 0;
}
