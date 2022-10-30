#include <stdio.h>
#include <string.h>

void
bottles(int n)
{
	const char *s;
	int i;

	for (i = n; i >= 1; i--) {
		s = (i > 1) ? "s" : "";
		printf("%d bottle%s of beer on the wall, %d bottle%s of beer.\n", i, s, i, s);

		if (i - 1 > 0) {
			s = (i - 1 > 1) ? "s" : "";
			printf("Take one down and pass it around, %d bottle%s of beer on the wall.\n\n", i - 1, s);
		}
	}

	printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
	printf("No more bottles of beer on the wall, no more bottles of beer.\n");
	printf("Go to the store and buy some more, %d bottles of beer on the wall.\n", n);
}

int
main(void)
{
	bottles(99);
	return 0;
}
