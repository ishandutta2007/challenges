/*

The middle-square method is a method of generating pseudorandom numbers.
In practice, it's not a good method, since its period is usually very short and it has some severe weaknesses.
The defects associated with the original middle-square generator can be rectified by running the middle square with a Weyl sequence, which prevents convergence to zero.

Write a function msws(seed, n) that can generate the n-th random 16-bit long number.
The implementation should result in fast performance.

Algorithm description:

    raise r to the power of 2
    update weyl number by adding marsaglia
    add weyl to r
    drop 8 bits from the right, extract 16 bits from the right to get new random r

marsaglia = 362437
r, weyl = seed, 0

# repeat n times to get n-th random number r:
r = r ** 2
weyl = (weyl + marsaglia) % 2 ** 32
r = (r + weyl) % 2 ** 32
r = (r // 2 ** 8) % 2 ** 16

Examples

Notes

    The function should be efficient to handle large n (be inventive).
    For comparison, my submitted solution takes less than a second to complete all tests.
    Hint: a compiled program can run up to 200 times faster than a mathematically identical script in the Python interpreter.
    The code in Tests makes a temporary directory that will exist only during the execution of the tests.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
msws(uvlong s, uvlong n)
{
	static const uvlong m = 362437ull;
	uvlong i, r, w;

	r = s;
	w = 0;
	for (i = 0; i < n; i++) {
		r *= r;
		w = (w + m) & 0xffffffffull;
		r = (r + w) & 0xffffffffull;
		r = (r >> 8) & 0xffffull;
	}
	return r;
}

int
main(void)
{
	static const uvlong tab[][3] = {
	    {0ull, 1ull, 1415ull},
	    {512ull, 2ull, 26068ull},
	    {99991ull, 1000000ull, 51359ull},
	    {900037ull, 2097152ull, 26164ull},
	    {67777ull, 4194304ull, 24998ull},
	    {4096ull, 8388608ull, 30362ull},
	    {16033ull, 10000000ull, 41556ull},
	    {366ull, 11223300ull, 1738ull},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(msws(tab[i][0], tab[i][1]) == tab[i][2]);

	return 0;
}
