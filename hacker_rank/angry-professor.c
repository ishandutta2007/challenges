/*

A Discrete Mathematics professor has a class of students. Frustrated with their lack of discipline,
he decides to cancel class if fewer than some number of students are present when class starts.
Arrival times go from on time (a <= 0) to arrived late (a > 0).

Given the arrival time of each student and a threshhold number of attendees, determine if the class is canceled.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
cancel(int *a, size_t n, size_t k)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		if (a[i] <= 0 && j++ >= k)
			break;
	}
	return (j < k) ? "YES" : "NO";
}

int
main(void)
{
	int a[] = {-1, -3, 4, 2};
	printf("%s\n", cancel(a, nelem(a), 3));

	int b[] = {0, -1, 2, 1};
	printf("%s\n", cancel(b, nelem(b), 2));

	int c[] = {-1, -1, 0, 0, 1, 1};
	printf("%s\n", cancel(c, nelem(c), 4));
	printf("%s\n", cancel(c, nelem(c), 5));

	return 0;
}
