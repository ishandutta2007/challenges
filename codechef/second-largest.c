// Three numbers A, B and C are the inputs. Write a program to find second largest among three numbers.
#include <stdio.h>

void
swap(int *x, int *y)
{
	int t;
	t = *y;
	*y = *x;
	*x = t;
}

int
max2(int a, int b, int c)
{
	if (a > c)
		swap(&a, &c);
	if (a > b)
		swap(&a, &b);
	if (b > c)
		swap(&b, &c);
	return b;
}

int
main(void)
{
	printf("%d\n", max2(120, 11, 400));
	printf("%d\n", max2(10213, 312, 10));
	printf("%d\n", max2(10, 3, 450));
	printf("%d\n", max2(6, 3, 450));
	printf("%d\n", max2(6, 300, 40));
	return 0;
}
