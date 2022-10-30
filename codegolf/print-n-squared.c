/*

Write a program or function that takes in a non-negative integer N from stdin or as a function argument. It must print or return a string of a hollow ASCII-art square whose sides are each made with N copies of the number N.

Specifically:

If N is 0, no copies of N are used, so there should be no output (or only a single trailing newline).

If N is 1, the output is:

1

If N is 2:

22
22

If N is 3:

333
3 3
333

If N is 4:

4444
4  4
4  4
4444

If N is 5:

55555
5   5
5   5
5   5
55555

The pattern continues for 6 through 9.

If N is 10, the output is:

10101010101010101010
10                10
10                10
10                10
10                10
10                10
10                10
10                10
10                10
10101010101010101010

Notice that this is not actually square. It is 10 rows tall but 20 columns wide because 10 is two characters long. This is intended. The point is that each side of the "square" contains N copies of N. So all inputs beyond 9 will technically be ASCII rectangles.

For example, if N is 23, the output is:

2323232323232323232323232323232323232323232323
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
23                                          23
2323232323232323232323232323232323232323232323

Here are Pastebins of the required outputs for 99, 100, 111, and 123 (they may look wrong in a browser but in a text editor they'll look correct). The output for 1000 is to large for Pastebin but it would have 1000 rows and 4000 columns. Numbers with 4 or more digits must work just like smaller numbers.
Details:

    N must be written in the usual decimal number representation, with no + sign or other non-digits.
    The hollow area must only be filled with spaces.
    No lines should have leading or trailing spaces.
    A single newline after the squares' last line is optionally allowed.
    Languages written after this challenge was made are welcome, they just aren't eligible to win.
    The shortest code in bytes wins!

*/

#include <stdio.h>

unsigned
count(unsigned n)
{
	unsigned c;

	for (c = 1; n >= 10; c++)
		n /= 10;
	return c;
}

void
square(unsigned n)
{
	unsigned i, j, l;

	l = count(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
				printf("%u", n);
			else
				printf("%*c", l, ' ');
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	square(1);
	square(2);
	square(3);
	square(4);
	square(5);
	square(10);
	square(23);

	return 0;
}
