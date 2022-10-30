/*

Given a rod of length n inches and a list of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8
-------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
The input will be given in this form: The prices will be in ascending order, index starting at 1 to n separated by a space.

{price of length 1} {price of length 2}.... {price of length N}

The output should be the maximum Obtainable Value

{maxVal}

a Non-Golfed solution to this, in Python is:

INT_MIN = -32767
def cutRod(price, n):
    val = [0 for x in range(n+1)]
    val[0] = 0
    for i in range(1, n+1):
        max_val = INT_MIN
        for j in range(i):
             max_val = max(max_val, price[j] + val[i-j-1])
        val[i] = max_val

    return val[n]

arr = [1,2,3,4,5,6,7,8,9,10]
size = len(arr)
print(cutRod(arr, size))
Test cases:

|                                      Input                                     | Output |
|:------------------------------------------------------------------------------:|:------:|
|                              `1 5 8 9 10 17 17 20`                             |  `22`  |
|                                `1 3 2 5 6 7 4 8`                               |  `12`  |
|                     `5 6 3 2 4 6 8 7 3 4 6 2 12 4 5 7 4 3`                     |  `90`  |
| `23 2 3 45 34 23 3143 13 13 213 1321 3123 12 312 312 31 3 213 432 41 3 123 43` | `9475` |

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
cutrod(int *p, size_t n)
{
	size_t i, j;
	int m, r;
	int *v;

	v = calloc(n + 1, sizeof(*v));
	if (!v)
		return -1;

	for (i = 1; i < n + 1; i++) {
		m = INT_MIN;
		for (j = 0; j < i; j++)
			m = max(m, p[j] + v[i - j - 1]);
		v[i] = m;
	}
	r = v[n];

	free(v);
	return r;
}

int
main(void)
{
	int p1[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int p2[] = {1, 3, 2, 5, 6, 7, 4, 8};
	int p3[] = {5, 6, 3, 2, 4, 6, 8, 7, 3, 4, 6, 2, 12, 4, 5, 7, 4, 3};
	int p4[] = {23, 2, 3, 45, 34, 23, 3143, 13, 13, 213, 1321, 3123, 12, 312, 312, 31, 3, 213, 432, 41, 3, 123, 43};

	assert(cutrod(p1, nelem(p1)) == 22);
	assert(cutrod(p2, nelem(p2)) == 12);
	assert(cutrod(p3, nelem(p3)) == 90);
	assert(cutrod(p4, nelem(p4)) == 9475);

	return 0;
}
