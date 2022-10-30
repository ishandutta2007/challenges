/*

There are N workers; each worker is of one of the following three types:

A translator translates some text from Chef's language to another langague.
An author writes some text in Chef's language.
An author-translator can both write a text in Chef's language and translate it to another language.
Chef wants to have some text written and translated into some language (different from Chef's language). Chef can't do either of those tasks, but he can hire workers. For each i (1≤i≤N), if he hires the i-th worker, he must pay that worker ci coins.

Help Chef find the minimum total number of coins he needs to pay to have a text written and translated. It is guaranteed that it is possible to write and translate a text.

Input

The first line of the input contains a single integer N denoting the number of workers.
The second line contins N space-separated integers c1,c2,...,cN denoting the numbers of coins Chef has to pay each hired worker.
The third line contains N space-separated integers t1,t2,...,tN denoting the types of workers. For each valid i, the i-th worker is a translator if ti=1, an author if ti=2 or an author-translator if ti=3.

Output

Print a single line containing one integer — the minimum number of coins Chef has to pay.

Constraints
1≤N≤1,000
1≤ci≤100,000 for each valid i
1≤ti≤3 for each valid i

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
payment(int *c, int *t, size_t n)
{
	int x, y, z;
	size_t i;

	x = y = z = INT_MAX;
	for (i = 0; i < n; i++) {
		switch (t[i]) {
		case 1:
			x = min(x, c[i]);
			break;
		case 2:
			y = min(y, c[i]);
			break;
		case 3:
			z = min(z, c[i]);
			break;
		}
	}
	return min(x + y, z);
}

int
main(void)
{
	int c1[] = {1, 3, 4, 6, 8};
	int t1[] = {1, 2, 1, 2, 3};

	assert(payment(c1, t1, nelem(c1)) == 4);

	return 0;
}
