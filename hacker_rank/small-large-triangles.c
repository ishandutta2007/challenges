/*

You are given  triangles, specifically, their sides a, b, and c. 
Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different.

The best way to calculate a volume of the triangle with sides a, b, and c is Heron's formula.
S = sqrt(p*(p-a)*(p-b)*(p-c)) where p = (a+b+c)/2

Sample Input 0

3
7 24 25
5 12 13
3 4 5

Sample Output 0

3 4 5
5 12 13
7 24 25

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int a, b, c;
} triangle;

double
heron(const triangle *t)
{
	double p;

	p = (t->a + t->b + t->c) / 2;
	return sqrt(p * (p - t->a) * (p - t->b) * (p - t->c));
}

int
compare(const void *a, const void *b)
{
	int sa, sb;

	sa = heron(a);
	sb = heron(b);
	if (sa == sb)
		return 0;
	if (sa < sb)
		return -1;
	return 1;
}

void
sort(triangle t[], size_t n)
{
	qsort(t, n, sizeof(*t), compare);
}

void
print(triangle t[], size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d %d %d\n", t[i].a, t[i].b, t[i].c);
	printf("\n");
}

int
main(void)
{
	triangle t[] = {
	    {7, 24, 25},
	    {5, 12, 13},
	    {3, 4, 5},
	};

	print(t, nelem(t));
	sort(t, nelem(t));
	print(t, nelem(t));
	return 0;
}
