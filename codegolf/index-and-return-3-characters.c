/*

The challenge is simple: Read 3 letters from a system input¹ and convert them to numbers (A-1, B-2, C-3...Z-26)². Print each of those numbers in the order the letters were inputted in, each on a new line and then the sum of all 3 numbers, on its own line as well.

NOTE: There will be no extra input characters, only 3 letters. However, the code must be case insensitive.

This follows the standard rules of code golf, and the shortest byte count wins.

¹If your language does not support input, you may use from a file, or predefined variable instead. However, the program should be able to run any and all possibilities.

²The program should be able to take lowercase AND uppercase, and allow for a mix of lowercase and uppercase (e.g wOq or ZNu)

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int
isletter(int c)
{
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void
input(char *a, char *b, char *c)
{
	char buf[80];

	for (;;) {
		printf("Enter 3 letters: ");
		if (!fgets(buf, sizeof(buf), stdin)) {
			printf("\n");
			exit(1);
		}

		if (sscanf(buf, "%c %c %c", a, b, c) != 3)
			continue;

		if (isletter(*a) && isletter(*b) && isletter(*c))
			break;
	}

	*a = toupper(*a) - 'A' + 1;
	*b = toupper(*b) - 'A' + 1;
	*c = toupper(*c) - 'A' + 1;
}

int
main(void)
{
	char a, b, c;

	input(&a, &b, &c);
	printf("%d\n%d\n%d\n%d\n", a, b, c, a + b + c);
	return 0;
}
