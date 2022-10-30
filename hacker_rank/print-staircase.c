// prints ascii staircase art
#include <stdio.h>
#include <stdlib.h>

void
printstair(size_t n)
{
	size_t i, j;

	printf("staircase=%zu\n", n);
	for (i = 1; i < n + 1; i++) {
		for (j = n; j != i; j--)
			printf(" ");

		for (j = 0; j < i; j++)
			printf("#");

		printf("\n");
	}
	printf("\n");
}

int
main(int argc, char *argv[])
{
	printstair(4);
	printstair(6);
	if (argc >= 2)
		printstair(atoi(argv[1]));
	return 0;
}
