/*

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	int start, end;
} Interval;

int
cmp(const void *a, const void *b)
{
	const Interval *p, *q;

	p = a;
	q = b;
	if (p->start < q->start)
		return -1;
	if (p->start == q->start)
		return 0;
	return 1;
}

size_t
mergeinterval(Interval *v, size_t n)
{
	size_t i, j;

	qsort(v, n, sizeof(*v), cmp);
	for (i = j = 0; i < n; i++) {
		if (j == 0 || v[j - 1].end < v[i].start)
			v[j++] = v[i];
		else
			v[j - 1].end = max(v[j - 1].end, v[i].end);
	}

	return j;
}

void
printinterval(Interval *v, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("[%d,%d]", v[i].start, v[i].end);
		if (i + 1 < n)
			printf(",");
	}
	printf("]\n");
}

void
test(Interval *v, size_t n)
{
	printinterval(v, n);
	n = mergeinterval(v, n);
	printinterval(v, n);
	printf("\n");
}

int
main(void)
{
	Interval i1[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	Interval i2[] = {{1, 4}, {1, 5}};
	Interval i3[] = {{1, 1}, {1, 1}, {1, 1}};
	Interval i4[] = {{1, 1}, {1, 1}, {1, 1}, {-2, 1000}};

	test(i1, nelem(i1));
	test(i2, nelem(i2));
	test(i3, nelem(i3));
	test(i4, nelem(i4));

	srand(time(NULL));
	Interval i5[10];
	for (size_t i = 0; i < nelem(i5); i++) {
		i5[i].start = rand() & 0xfff;
		i5[i].end = i5[i].start + (rand() & 0xff);
	}
	test(i5, nelem(i5));

	return 0;
}
