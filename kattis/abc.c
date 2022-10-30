/*

You will be given three integers A, B and C. The numbers will not be given in that exact order, but we do know that A is less than B and B less than C.
In order to make for a more pleasant viewing, we want to rearrange them in a given order.

Input

The first line contains the three positive integers A, B and C, not necessarily in that order. The three numbers will be less than or equal to 100.

The second line contains three uppercase letters ’A’, ’B’ and ’C’ (with no spaces between them) representing the desired order.

Output

Output A, B and C in the desired order on a single line, separated by single spaces.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define mid(a, b, c) max(min(a, b), min(max(a, b), c))

int
abc(int x, int y, int z, const char s[3], int r[3])
{
	int a, b, c;
	int i;

	a = min(x, min(y, z));
	b = mid(x, y, z);
	c = max(x, max(y, z));
	for (i = 0; i < 3; i++) {
		switch (s[i]) {
		case 'A':
			r[i] = a;
			break;
		case 'B':
			r[i] = b;
			break;
		case 'C':
			r[i] = c;
			break;
		default:
			return -1;
		}
	}

	return 0;
}

void
test(int x, int y, int z, const char s[3], int r[3])
{
	int p[3];

	assert(abc(x, y, z, s, p) >= 0);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	test(1, 5, 3, "ABC", (int[3]){1, 3, 5});
	test(6, 4, 2, "CAB", (int[3]){6, 2, 4});
	return 0;
}
