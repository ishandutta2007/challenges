/*

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

    You may assume that the array does not change.
    There are many calls to sumRange function.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int *s;
	size_t n;
} rq_t;

int
rqinit(rq_t *rq, int *a, size_t n)
{
	size_t i;

	rq->n = 0;
	rq->s = calloc(n, sizeof(*rq->s));
	if (!rq->s)
		return -1;
	rq->n = n;

	if (n == 0)
		return 0;

	rq->s[0] = a[0];
	for (i = 1; i < n; i++)
		rq->s[i] = rq->s[i - 1] + a[i];

	return 0;
}

int
rqsumrange(rq_t *rq, size_t i, size_t j)
{
	if (i >= rq->n || j >= rq->n)
		return INT_MIN;
	if (i == 0)
		return rq->s[j];
	return rq->s[j] - rq->s[i - 1];
}

void
rqfree(rq_t *rq)
{
	if (!rq)
		return;
	free(rq->s);
}

int
main(void)
{
	rq_t rq;
	int n1[] = {-2, 0, 3, -5, 2, -1};

	rqinit(&rq, n1, nelem(n1));
	printf("%d\n", rqsumrange(&rq, 0, 2));
	printf("%d\n", rqsumrange(&rq, 2, 5));
	printf("%d\n", rqsumrange(&rq, 0, 5));
	rqfree(&rq);

	return 0;
}
