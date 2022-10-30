/*

You are given an array of integers, marks, denoting the marks scored by students in a class.
The alternating elements marks_0, marks_2, marks_4 and so on denote the marks of boys.
Similarly, marks_1, marks_3, marks_5 and so on denote the marks of girls.

The array name marks, works as a pointer which stores the base address of that array.
In other words, marks contains the address where marks_0  is stored in the memory.


Complete the function, marks_summation(int* marks, char gender, int number_of_students) which returns the total sum of:
marks of boys if gender=b
marks of girls if gender=g

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
grade(int *a, size_t n, int g)
{
	size_t i, s;

	if (g == 'b')
		i = 0;
	else if (g == 'g')
		i = 1;
	else
		return -1;

	s = 0;
	for (; i < n; i += 2)
		s += a[i];
	return s;
}

int
main(void)
{
	int a[] = {3, 2, 5};
	printf("%d\n", grade(a, nelem(a), 'b'));

	int b[] = {1, 2, 3, 4, 5};
	printf("%d\n", grade(b, nelem(b), 'g'));

	int c[] = {5};
	printf("%d\n", grade(c, nelem(c), 'g'));

	return 0;
}
