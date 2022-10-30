/*

There are N students living in the dormitory of Berland State University. Each of them sometimes wants to use the kitchen, so the head of the dormitory came up with a timetable for kitchen's usage in order to avoid the conflicts:

The first student starts to use the kitchen at the time 0 and should finish the cooking not later than at the time A1.
The second student starts to use the kitchen at the time A1 and should finish the cooking not later than at the time A2.
And so on.
The N-th student starts to use the kitchen at the time AN-1 and should finish the cooking not later than at the time AN
The holidays in Berland are approaching, so today each of these N students wants to cook some pancakes. The i-th student needs Bi units of time to cook.

The students have understood that probably not all of them will be able to cook everything they want. How many students will be able to cook without violating the schedule?

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of students.

The second line contains N space-separated integers A1, A2, ..., AN denoting the moments of time by when the corresponding student should finish cooking.

The third line contains N space-separated integers B1, B2, ..., BN denoting the time required for each of the students to cook.

Output

For each test case, output a single line containing the number of students that will be able to finish the cooking.

Constraints

Should contain all the constraints on the input data that you may have. Format it like:

1 ≤ T ≤ 10
1 ≤ N ≤ 10^4
0 < A1 < A2 < ... < AN < 10^9
1 ≤ Bi ≤ 10^9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
students(int *a, int *b, size_t n)
{
	size_t i;
	int c, p;

	c = 0;
	p = 0;
	for (i = 0; i < n; i++) {
		if (a[i] - p >= b[i])
			c++;

		p = a[i];
	}
	return c;
}

int
main(void)
{
	int a1[] = {1, 10, 15};
	int b1[] = {1, 10, 3};

	int a2[] = {10, 20, 30};
	int b2[] = {15, 5, 20};

	assert(students(a1, b1, nelem(a1)) == 2);
	assert(students(a2, b2, nelem(a2)) == 1);

	return 0;
}
