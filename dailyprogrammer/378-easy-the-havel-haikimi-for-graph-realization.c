/*

[2019-05-20] Challenge #378 [Easy] The Havel-Hakimi algorithm for graph realization

It was a dark and stormy night. Detective Havel and Detective Hakimi arrived at the scene of the crime.

Other than the detectives, there were 10 people present. They asked the first person, "out of the 9 other people here, how many had you already met before tonight?" The person answered "5". They asked the same question of the second person, who answered "3". And so on. The 10 answers they got from the 10 people were:

5 3 0 2 6 2 0 7 2 5

The detectives looked at the answers carefully and deduced that there was an inconsistency, and that somebody must be lying. (For the purpose of this challenge, assume that nobody makes mistakes or forgets, and if X has met Y, that means Y has also met X.)

Your challenge for today is, given a sequence of answers to the question "how many of the others had you met before tonight?", apply the Havel-Hakimi algorithm to determine whether or not it's possible that everyone was telling the truth.

If you're feeling up to it, skip ahead to the Challenge section below. Otherwise, try as many of the optional warmup questions as you want first, before attempting the full challenge.
Optional Warmup 1: eliminating 0's.

Given a sequence of answers, return the same set of answers with all the 0's removed.

warmup1([5, 3, 0, 2, 6, 2, 0, 7, 2, 5]) => [5, 3, 2, 6, 2, 7, 2, 5]
warmup1([4, 0, 0, 1, 3]) => [4, 1, 3]
warmup1([1, 2, 3]) => [1, 2, 3]
warmup1([0, 0, 0]) => []
warmup1([]) => []

If you want to reorder the sequence as you do this, that's fine. For instance, given [4, 0, 0, 1, 3], then you may return [4, 1, 3] or [1, 3, 4] or [4, 3, 1] or any other ordering of these numbers.
Optional Warmup 2: descending sort

Given a sequence of answers, return the sequence sorted in descending order, so that the first number is the largest and the last number is the smallest.

warmup2([5, 1, 3, 4, 2]) => [5, 4, 3, 2, 1]
warmup2([0, 0, 0, 4, 0]) => [4, 0, 0, 0, 0]
warmup2([1]) => [1]
warmup2([]) => []

Optional Warmup 3: length check

Given a number N and a sequence of answers, return true if N is greater than the number of answers (i.e. the length of the sequence), and false if N is less than or equal to the number of answers. For instance, given 7 and [6, 5, 5, 3, 2, 2, 2], you would return false, because 7 is less than or equal to 7.

warmup3(7, [6, 5, 5, 3, 2, 2, 2]) => false
warmup3(5, [5, 5, 5, 5, 5]) => false
warmup3(5, [5, 5, 5, 5]) => true
warmup3(3, [1, 1]) => true
warmup3(1, []) => true
warmup3(0, []) => false

Optional Warmup 4: front elimination

Given a number N and a sequence in descending order, subtract 1 from each of the first N answers in the sequence, and return the result. For instance, given N = 4 and the sequence [5, 4, 3, 2, 1], you would subtract 1 from each of the first 4 answers (5, 4, 3, and 2) to get 4, 3, 2, and 1. The rest of the sequence (1) would not be affected:

warmup4(4, [5, 4, 3, 2, 1]) => [4, 3, 2, 1, 1]
warmup4(11, [14, 13, 13, 13, 12, 10, 8, 8, 7, 7, 6, 6, 4, 4, 2]) => [13, 12, 12, 12, 11, 9, 7, 7, 6, 6, 5, 6, 4, 4, 2]
warmup4(1, [10, 10, 10]) => [9, 10, 10]
warmup4(3, [10, 10, 10]) => [9, 9, 9]
warmup4(1, [1]) => [0]

You may assume that N is greater than 0, and no greater than the length of the sequence. Like in warmup 1, it's okay if you want to reorder the answers in your result.
Challenge: the Havel-Hakimi algorithm

Perform the Havel-Hakimi algorithm on a given sequence of answers. This algorithm will return true if the answers are consistent (i.e. it's possible that everyone is telling the truth) and false if the answers are inconsistent (i.e. someone must be lying):

    Remove all 0's from the sequence (i.e. warmup1).

    If the sequence is now empty (no elements left), stop and return true.

    Sort the sequence in descending order (i.e. warmup2).

    Remove the first answer (which is also the largest answer, or tied for the largest) from the sequence and call it N. The sequence is now 1 shorter than it was after the previous step.

    If N is greater than the length of this new sequence (i.e. warmup3), stop and return false.

    Subtract 1 from each of the first N elements of the new sequence (i.e. warmup4).

    Continue from step 1 using the sequence from the previous step.

Eventually you'll either return true in step 2, or false in step 5.

You don't have to follow these steps exactly: as long as you return the right answer, that's fine. Also, if you answered the warmup questions, you may use your warmup solutions to build your challenge solution, but you don't have to.

hh([5, 3, 0, 2, 6, 2, 0, 7, 2, 5]) => false
hh([4, 2, 0, 1, 5, 0]) => false
hh([3, 1, 2, 3, 1, 0]) => true
hh([16, 9, 9, 15, 9, 7, 9, 11, 17, 11, 4, 9, 12, 14, 14, 12, 17, 0, 3, 16]) => true
hh([14, 10, 17, 13, 4, 8, 6, 7, 13, 13, 17, 18, 8, 17, 2, 14, 6, 4, 7, 12]) => true
hh([15, 18, 6, 13, 12, 4, 4, 14, 1, 6, 18, 2, 6, 16, 0, 9, 10, 7, 12, 3]) => false
hh([6, 0, 10, 10, 10, 5, 8, 3, 0, 14, 16, 2, 13, 1, 2, 13, 6, 15, 5, 1]) => false
hh([2, 2, 0]) => false
hh([3, 2, 1]) => false
hh([1, 1]) => true
hh([1]) => false
hh([]) => true

Detailed example

Here's the first pass through the algorithm using the original example:

    [5, 3, 0, 2, 6, 2, 0, 7, 2, 5] - Starting sequence

    [5, 3, 2, 6, 2, 7, 2, 5] - After step 1, removing 0's.

    Step 2: This sequence is not empty, so go on to step 3.

    [7, 6, 5, 5, 3, 2, 2, 2] - After step 3, sorting in descending order.

    [6, 5, 5, 3, 2, 2, 2] - After step 4, removing the first answer N = 7.

    Step 5: N (7) is less than or equal to the number of answers remaining in the sequence (7), so go on to step 6.

    [5, 4, 4, 2, 1, 1, 1] - After step 6, subtracting 1 from each of the first 7 answers (which is all of them in this case).

At this point you would start over at step 1 with the sequence [5, 4, 4, 2, 1, 1, 1]. After your second pass through the algorithm, your sequence will be [3, 3, 1, 0, 0, 1], so start back at step 1 with this sequence. After your third pass you'll have [2, 0, 0]. On your fourth pass, you'll stop at step 5, because you'll have N = 2 and an empty sequence ([]), and 2 > 0, so you will return false.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

size_t
warmup1(int *a, size_t n)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		if (a[i] != 0)
			a[j++] = a[i];
	}
	return j;
}

int
cmp2(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return 1;
	if (x == y)
		return 0;
	return -1;
}

void
warmup2(int *a, size_t n)
{
	qsort(a, n, sizeof(*a), cmp2);
}

bool
warmup3(size_t l, int *a, size_t n)
{
	(void)a;
	return l > n;
}

void
warmup4(size_t l, int *a, size_t n)
{
	size_t i;
	for (i = 0; i < n && i < l; i++)
		a[i]--;
}

void
test1(int *a, size_t n)
{
	size_t m;

	printf("warmup1: ");
	m = warmup1(a, n);
	print(a, m);
}

void
test2(int *a, size_t n)
{
	printf("warmup2: ");
	warmup2(a, n);
	print(a, n);
}

void
test3(size_t l, int *a, size_t n)
{
	printf("warmup3: ");
	printf("%s\n", warmup3(l, a, n) ? "true" : "false");
}

void
test4(size_t l, int *a, size_t n)
{
	printf("warmup4: ");
	warmup4(l, a, n);
	print(a, n);
}

bool
hh(int *a, size_t n)
{
	for (;;) {
		n = warmup1(a, n);
		if (n == 0)
			return true;

		warmup2(a, n);

		if (warmup3(a[0], &a[1], n - 1))
			return false;

		warmup4(a[0], &a[1], n - 1);

		a++;
		n--;
	}
}

int
main(void)
{
	int a1[] = {5, 3, 0, 2, 6, 2, 0, 7, 2, 5};
	test1(a1, nelem(a1));

	int a2[] = {4, 0, 0, 1, 3};
	test1(a2, nelem(a2));

	int a3[] = {1, 2, 3};
	test1(a3, nelem(a3));

	int a4[] = {0, 0, 0};
	test1(a4, nelem(a4));
	test1(a4, 0);

	int a5[] = {5, 1, 3, 4, 2};
	test2(a5, nelem(a5));

	int a6[] = {0, 0, 0, 4, 0};
	test2(a6, nelem(a6));

	int a7[] = {1};
	test2(a7, nelem(a7));
	test2(a7, 0);

	int a8[] = {6, 5, 5, 3, 2, 2, 2};
	test3(7, a8, nelem(a8));

	int a9[] = {5, 5, 5, 5, 5};
	test3(5, a9, nelem(a9));

	int a10[] = {5, 5, 5, 5};
	test3(5, a10, nelem(a10));

	int a11[] = {1, 1};
	test3(5, a11, nelem(a11));
	test3(1, a11, 0);
	test3(0, a11, 0);

	int a12[] = {5, 4, 3, 2, 1};
	test4(4, a12, nelem(a12));

	int a13[] = {14, 13, 13, 13, 12, 10, 8, 8, 7, 7, 6, 6, 4, 4, 2};
	test4(11, a13, nelem(a13));

	int a14[] = {10, 10, 10};
	test4(1, a14, nelem(a14));

	int a15[] = {10, 10, 10};
	test4(3, a15, nelem(a15));

	int a16[] = {1};
	test4(1, a16, nelem(a16));

	int a17[] = {5, 3, 0, 2, 6, 2, 0, 7, 2, 5};
	printf("%d\n", hh(a17, nelem(a17)));

	int a18[] = {4, 2, 0, 1, 5, 0};
	printf("%d\n", hh(a18, nelem(a18)));

	int a19[] = {3, 1, 2, 3, 1, 0};
	printf("%d\n", hh(a19, nelem(a19)));

	int a20[] = {16, 9, 9, 15, 9, 7, 9, 11, 17, 11, 4, 9, 12, 14, 14, 12, 17, 0, 3, 16};
	printf("%d\n", hh(a20, nelem(a20)));

	int a21[] = {14, 10, 17, 13, 4, 8, 6, 7, 13, 13, 17, 18, 8, 17, 2, 14, 6, 4, 7, 12};
	printf("%d\n", hh(a21, nelem(a21)));

	int a22[] = {15, 18, 6, 13, 12, 4, 4, 14, 1, 6, 18, 2, 6, 16, 0, 9, 10, 7, 12, 3};
	printf("%d\n", hh(a22, nelem(a22)));

	int a23[] = {6, 0, 10, 10, 10, 5, 8, 3, 0, 14, 16, 2, 13, 1, 2, 13, 6, 15, 5, 1};
	printf("%d\n", hh(a23, nelem(a23)));

	int a24[] = {2, 2, 0};
	printf("%d\n", hh(a24, nelem(a24)));

	int a25[] = {3, 2, 1};
	printf("%d\n", hh(a25, nelem(a25)));

	int a26[] = {1, 1};
	printf("%d\n", hh(a26, nelem(a26)));

	int a27[] = {1};
	printf("%d\n", hh(a27, nelem(a27)));
	printf("%d\n", hh(a27, 0));

	return 0;
}
