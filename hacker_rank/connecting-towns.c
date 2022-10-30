/*

Gandalf is travelling from Rohan to Rivendell to meet Frodo but there is no direct route from Rohan (T1) to Rivendell (Tn).

But there are towns T2,T3,T4...Tn-1 such that there are N1 routes from Town T1 to T2, and in general,
Ni routes from Ti to Ti+1 for i=1 to n-1 and 0 routes for any other Ti to Tj for j ≠ i+1

Find the total number of routes Gandalf can take to reach Rivendell from Rohan.

Output total number of routes from T1 to Tn modulo 1234567 

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
routes(int *a, size_t n)
{
	size_t i;
	int v, m;

	if (n == 0)
		return 0;

	m = 1234567;
	v = 1;
	for (i = 0; i < n; i++)
		v = ((v % m) * (a[i] % m)) % m;
	return v;
}

int
main(void)
{
	int a[] = {1, 3};
	printf("%d\n", routes(a, nelem(a)));

	int b[] = {2, 2, 2};
	printf("%d\n", routes(b, nelem(b)));

	return 0;
}
