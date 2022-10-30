/*

We all know that passwords are not very secure unless users are disciplined enough to use passwords that are difficult to guess.
But most users are not so careful, and happily use passwords such as “123456”. In fact, there are lists of commonly used passwords that hackers can use for breaking into systems, and these passwords often work.

You have done a lot of hacking using such lists, and you have a good idea of how likely each password in the list is the correct one (you are very surprised by the number of people using “123456” as their passwords).
You have a new account to hack, and you have decided to try each of the passwords in the list one at a time, until the correct one is found. You are absolutely sure that the account you want to hack uses a password in the given list.

What is the expected number of attempts to find the correct passwords, assuming that you try these passwords in the optimal order?

Input

The first line of input contains a positive integer N, the number of passwords in the list. Each of the next N lines gives the password, followed by a space, followed by the probability that the password is the correct one.
Each password consists only of alphanumeric characters and is 1 to 12 characters long. Each probability is a real number with 4 decimal places.
You may assume that there are at most 500 passwords in the list, and that the sum of all probabilities equals 1. No two passwords in the list are the same.

Output

Output on a single line the expected number of attempts to find the correct passwords using the optimal order. Answers within 10^-4 of the correct answer will be accepted.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char val[32];
	double prob;
} Password;

int
cmp(const void *a, const void *b)
{
	const Password *p, *q;

	p = a;
	q = b;
	if (p->prob > q->prob)
		return -1;
	if (p->prob < q->prob)
		return 1;
	return 0;
}

double
expectation(Password *p, size_t n)
{
	double e;
	size_t i;

	qsort(p, n, sizeof(*p), cmp);

	e = 0;
	for (i = 0; i < n; i++)
		e += p[i].prob * (i + 1);
	return e;
}

void
test(Password *p, size_t n, double r)
{
	double e;

	e = expectation(p, n);
	printf("%f\n", e);
	assert(fabs(e - r) < 1e-4);
}

int
main(void)
{
	Password p1[] = {
	    {"123456", 0.6666},
	    {"qwerty", 0.3334},
	};
	Password p2[] = {
	    {"qwerty", 0.5432},
	    {"123456", 0.3334},
	    {"password", 0.1234},
	};

	test(p1, nelem(p1), 1.3334);
	test(p2, nelem(p2), 1.5802);
	return 0;
}
