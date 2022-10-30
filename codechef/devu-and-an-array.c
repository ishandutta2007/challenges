/*

Devu has an array A consisting of N positive integers. He would like to perform following operation on array.

Pick some two elements a, b in the array (a could be same as b, but their corresponding indices in the array should not be same).
Remove both the elements a and b and instead add a number x such that x lies between min(a, b) and max(a, b), both inclusive, (i.e. min(a, b) ≤ x ≤ max(a, b)). 

Now, as you know after applying the above operation N - 1 times, Devu will end up with a single number in the array. He is wondering whether it is possible to do the operations in such a way that he ends up a number t.

He asks your help in answering Q such queries, each of them will contain an integer t and you have to tell whether it is possible to end up t. 

*/
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	return x - y;
}

const char *
possible(int *a, size_t n, int t)
{
	if (n == 0)
		return "No";
	qsort(a, n, sizeof(*a), cmp);
	return (a[0] <= t && t <= a[n - 1]) ? "Yes" : "No";
}

int
main(void)
{
	int a[] = {1};
	printf("%s\n", possible(a, nelem(a), 1));
	printf("%s\n", possible(a, nelem(a), 2));

	int b[] = {1, 3};
	printf("%s\n", possible(b, nelem(b), 1));
	printf("%s\n", possible(b, nelem(b), 2));
	printf("%s\n", possible(b, nelem(b), 3));
	printf("%s\n", possible(b, nelem(b), 4));

	return 0;
}
