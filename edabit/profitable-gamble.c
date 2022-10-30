// Create a function that takes in three arguments (prob, prize, pay)
// and returns true if prob * prize > pay; otherwise return false.
#include <stdio.h>
#include <stdbool.h>

bool
profitable(double prob, double prize, double pay)
{
	return prob * prize > pay;
}

int
main(void)
{
	printf("%d\n", profitable(0.2, 50, 9));
	printf("%d\n", profitable(0.9, 1, 2));
	printf("%d\n", profitable(0.9, 3, 2));
	printf("%d\n", profitable(0.33, 10, 3.30));
	printf("%d\n", profitable(0, 1000, 0.1));
	printf("%d\n", profitable(0.1, 1000, 7));
	printf("%d\n", profitable(0, 0, 0));
	return 0;
}
