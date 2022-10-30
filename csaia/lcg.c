// https://www.cs.princeton.edu/courses/archive/spring03/cs126/assignments/cycle.html

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int a, b, m;
	int x;
} lcg_t;

int
lcgstep(lcg_t *l)
{
	l->x = (l->a * l->x + l->b) % l->m;
	return l->x;
}

/*

 Floyd's algorithm. The second part of this assignment is to implement a method known as Floyd's algorithm for finding the cycle length or period. Floyd's algorithm consists of two phases: (i) find a point on the cycle, and (ii) compute the cycle length.

    Phase I. To find a point on the cycle, we use the following clever idea: run two versions of the generator concurrently, one iterating twice as fast as the other, until both versions have the same value. At some point, both of them are on the cycle and we have a race on the cycle, with the gap between the faster one and the slower one shrinking by one on each iteration. Eventually, the faster one catches up to the slower one, and the two generators are at the same point on the cycle.

Above is an example of the process with a = 22, b = 1, c = 0, and M = 72. In this example, the cycle is 3-67-35-51-43-11-27-19-59-3, and its length is 9. Somewhat coincidentally, this happens to be equal to the number of steps until the fast and slow generators first meet, but this will not be true in general. The fast generator happens to be at 51 when the slow one first hits the cycle at 3. The fast one is six steps behind the slow one, and catches up, one step at a time.

Phase II. Once we know a value on the cycle, one more trip around the cycle (back to that same value) will give us the cycle length. Continuing the example above, we discovered from Phase I that 27 is in the cycle. After another 9 iterations we are back at 27, so we conclude the cycle length is 9.

*/

void
lcgcycle(lcg_t *l, int *c, int *n)
{
	lcg_t u, v;

	u = *l;
	v = *l;
	for (;;) {
		lcgstep(&u);

		lcgstep(&v);
		lcgstep(&v);

		if (u.x == v.x)
			break;
	}

	*c = u.x;
	*n = 0;
	for (;;) {
		lcgstep(&u);
		*n += 1;

		if (*c == u.x)
			break;
	}
}

void
testbasic(void)
{
	static const int tab[][4] = {
		{ 1, 3, 0, 10 },
		{ 2, 1, 0, 10 },
		{ 22, 1, 0, 72 },
		{ 11, 37, 1, 100 },
		{ 8, 20, 10, 100 },
	};

	size_t i, j;
	lcg_t l;

	printf("%4s %4s %4s %4s ", "a", "b", "c", "M");
	for (j = 0; j <= 12; j++)
		printf("x%-3zu ", j);
	printf("\n");
	for (i = 0; i < nelem(tab); i++) {
		l = (lcg_t){
			.a = tab[i][0],
			.b = tab[i][1],
			.m = tab[i][3],
			.x = tab[i][2],
		};
		printf("%4d %4d %4d %4d ", tab[i][0], tab[i][1], tab[i][2], tab[i][3]);
		for (j = 0; j <= 12; j++) {
			printf("%-4d ", l.x);
			lcgstep(&l);
		}
		printf("\n");
	}
	printf("\n");
}

void
testiter(void)
{
	lcg_t l = { 11, 37, 100, 1 };
	int i;

	for (i = 0; i < 100; i++) {
		printf("%3d ", l.x);
		if ((i & 15) == 15)
			printf("\n");
		lcgstep(&l);
	}
	printf("\n\n");
}

void
testcycle(void)
{
	static const int tab[][4] = {
		{ 22, 1, 0, 72 },
		{ 123, 456, 789, 1000000 },
		{ 124, 456, 789, 1000000 },
		{ 78, 60, 89, 129024 },
	};

	lcg_t l;
	size_t i;
	int c, n;

	for (i = 0; i < nelem(tab); i++) {
		l = (lcg_t){
			.a = tab[i][0],
			.b = tab[i][1],
			.m = tab[i][3],
			.x = tab[i][2],
		};
		lcgcycle(&l, &c, &n);
		printf("value %d length %d\n", c, n);
	}
}

int
main(void)
{
	testbasic();
	testiter();
	testcycle();
	return 0;
}
