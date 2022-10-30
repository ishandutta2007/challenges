/*

Back in the day, telephone autodialers used punched cards with one column for each digit of the number to be dialed.
Columns had seven rows. The first three rows represented the numbers (1,2,3), (4,5,6), and (7,8,9) respectively.
The last three rows rotated this arrangement by 90°: (1,4,7), (2,5,8), and (3,6,9).
The middle row was used for 0. Any digit 1-9 would have two holes punched - one in the first three rows, and one in the bottom three rows.
Zero would only have the middle row punched. Let's visualize the punched column for the number 6 (. is unpunched, x is punched, guide on left is just to illustrate the encoding):

123 .
456 x
789 .
 0  .
147 .
258 .
369 x
We look for which row(s) contain the number we're trying to dial. For 6, this is the second row, and the ninth row. These two rows are punched, the remaining five rows are unpunched. Here are the punched patterns for all digits 0-9:

    0 1 2 3 4 5 6 7 8 9
123 . x x x . . . . . .
456 . . . . x x x . . .
789 . . . . . . . x x x
 0  x . . . . . . . . .
147 . x . . x . . x . .
258 . . x . . x . . x .
369 . . . x . . x . . x
Your goal is to (write a program or function to) punch these cards for me.

Input: A number, taken in any reasonable format (string, integer, list of integers, &c.), not to exceed 9999999999999.

Output: The grid of punched columns corresponding to the number input. You don't need the headers or extra spacing shown above, just the punched columns themselves.
Leading/trailing newlines are ok, as is whitespace between rows/columns as long as it is consistent.
Speaking of, as long as they are consistent, you may use any (non-whitespace) character for punched, and any other character for unpunched (while it should be obvious, please specify what characters you are using).

This is code-golf, so shortest code wins. Standard loopholes are disallowed.

Test cases (all use . for unpunched, x for punched):

In: 911
Out: .xx
     ...
     x..
     ...
     .xx
     ...
     x..

In: 8675309
Out: ....x..
     .x.x...
     x.x...x
     .....x.
     ..x....
     x..x...
     .x..x.x

In: 5553226
Out: ...xxx.
     xxx...x
     .......
     .......
     .......
     xxx.xx.
     ...x..x

*/

#include <stdio.h>

void
punchcard(const char *s)
{
	static const int mask[] = {0x8, 0x11, 0x21, 0x41, 0x12, 0x22, 0x42, 0x14, 0x24, 0x44};

	int c, i;
	size_t n;

	printf("%s\n", s);
	for (i = 0; i < 7; i++) {
		for (n = 0; s[n]; n++) {
			c = (s[n] & 0xff) - '0';
			if (0 <= c && c <= 9 && (mask[c] & (1 << i)))
				printf("x");
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	punchcard("911");
	punchcard("8675309");
	punchcard("5553226");

	return 0;
}
