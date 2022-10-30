/*

Given any unsigned 16 bit integer, convert its decimal form (i.e., base-10) number into a 4x4 ASCII grid of its bits, with the most-significant bit (MSB) at the top left, least-significant bit (LSB) at bottom right, read across and then down (like English text).

Examples

Input: 4242
+---+---+---+---+
|   |   |   | # |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
| # |   |   | # |
+---+---+---+---+
|   |   | # |   |
+---+---+---+---+

Input: 33825
+---+---+---+---+
| # |   |   |   |
+---+---+---+---+
|   | # |   |   |
+---+---+---+---+
|   |   | # |   |
+---+---+---+---+
|   |   |   | # |
+---+---+---+---+

Specific Requirements

Input must be in decimal (base-10), however you may convert to binary any way you wish (including using language built-ins, if available).

Output table format must match exactly. This means you must use the specific ASCII characters (-, +, and |) for the table grid lines as shown, each cell's interior is 3 characters, and true bits are represented by # while false is represented by a space ().

Leading or trailing whitespace is not permitted. Final newline is required.

Bit order must match the examples as described.

Allowances
Input must be a base-10 number on the command line, standard input, or user input, but must not be hard-coded into your source code.
May the clearest shortest code win! :-)

*/

#include <stdint.h>
#include <stdio.h>

void
display(uint16_t v)
{
	char sq[][18] = {
	    "+---+---+---+---+",
	    "|   |   |   |   |",
	    "+---+---+---+---+",
	    "|   |   |   |   |",
	    "+---+---+---+---+",
	    "|   |   |   |   |",
	    "+---+---+---+---+",
	    "|   |   |   |   |",
	    "+---+---+---+---+",
	};

	int i, x, y;

	for (i = 0; i < 16; i++) {
		if (v & (1u << i)) {
			x = 4 * ((15 - i) % 4) + 2;
			y = 2 * ((15 - i) / 4) + 1;
			sq[y][x] = '#';
		}
	}

	for (i = 0; i < 9; i++)
		printf("%s\n", sq[i]);
	printf("\n");
}

int
main(void)
{
	display(4242u);
	display(33825u);
	display(0xffffu);

	return 0;
}
