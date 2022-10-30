/*

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
Note that the third maximum here means the third maximum distinct number.

*/

#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
max3rd(int *a, size_t n)
{
	size_t i, c;
	int m[3];

	if (n == 0)
		return 0;
	if (n == 1)
		return a[0];
	if (n == 2)
		return max(a[0], a[1]);

	m[0] = INT_MIN;
	m[1] = INT_MIN;
	m[2] = a[0];
	c = 0;
	for (i = 1; i < n; i++) {
		if (a[i] > m[2]) {
			m[0] = m[1];
			m[1] = m[2];
			m[2] = a[i];
			c += (c < 2) ? 1 : 0;
		} else if (m[2] > a[i] && a[i] > m[1]) {
			m[0] = m[1];
			m[1] = a[i];
			c += (c < 2) ? 2 : 0;
		} else if (m[1] > a[i] && a[i] > m[0]) {
			m[0] = a[i];
			c += (c < 2) ? 3 : 0;
		}
	}
	if (c < 1)
		m[1] = m[2];
	if (c < 2)
		m[0] = m[1];

	return m[0];
}

int
main(void)
{
	int a[] = {3, 2, 1};
	printf("%d\n", max3rd(a, nelem(a)));

	int b[] = {1, 2};
	printf("%d\n", max3rd(b, nelem(b)));

	int c[] = {2, 2, 3, 1};
	printf("%d\n", max3rd(c, nelem(c)));
	printf("%d\n", max3rd(c, 3));

	int d[] = {4, 6, 7, 8, 8, 9, 9};
	printf("%d\n", max3rd(d, nelem(d)));

	int e[] = {1, 4, 5, 6, 52, 3, 5, 35, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65, 7, 88, 88, 88, 88, 88, 88, 88, 6, 9, 5, 2, 11, 1, 1, 1, 1, 1, 1};
	printf("%d\n", max3rd(e, nelem(e)));

	int f[] = {10, 4, 3, 50, 23, 90};
	printf("%d\n", max3rd(f, nelem(f)));

	int g[] = {12, 13, 1, 10, 34, 1};
	printf("%d\n", max3rd(g, nelem(g)));

	int h[] = {1, 14, 2, 16, 10, 20};
	printf("%d\n", max3rd(h, nelem(h)));

	int i[] = {19, -10, 20, 14, 2, 16, 10};
	printf("%d\n", max3rd(i, nelem(i)));

	int j[] = {10, 5, 15, 5, 15, 10, 1, 1};
	printf("%d\n", max3rd(j, nelem(j)));

	int k[] = {INT_MIN, 1, 2};
	printf("%d\n", max3rd(k, nelem(k)));

	int l[] = {INT_MIN, INT_MIN, INT_MIN, 4};
	printf("%d\n", max3rd(l, nelem(l)));

	int m[] = {INT_MIN, 10, 3, 4};
	printf("%d\n", max3rd(m, nelem(m)));
	
	int n[] = {1, 1, 1};
	printf("%d\n", max3rd(n, nelem(n)));

	return 0;
}
