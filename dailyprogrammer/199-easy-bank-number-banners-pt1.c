/*

Description

You work for a bank, which has recently purchased an ingenious machine to assist in reading letters and faxes sent in by branch offices. The machine scans the paper documents, and produces a file with a number of entries which each look like this:

    _  _     _  _  _  _  _
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|

Each entry is 4 lines long, and each line has 27 characters. The first 3 lines of each entry contain an account number written using pipes and underscores, and the fourth line is blank.
Each account number should have 9 digits, all of which should be in the range 0-9.

Right now you're working in the print shop and you have to take account numbers and produce those paper documents.

Input

You'll be given a series of numbers and you have to parse them into the previously mentioned banner format. This input...

000000000
111111111
490067715

Output

...would reveal an output that looks like this

 _  _  _  _  _  _  _  _  _
| || || || || || || || || |
|_||_||_||_||_||_||_||_||_|


 |  |  |  |  |  |  |  |  |
 |  |  |  |  |  |  |  |  |

    _  _  _  _  _  _     _
|_||_|| || ||_   |  |  ||_
  | _||_||_||_|  |  |  | _|

Notes

Thanks to /u/jnazario for yet another challenge!

*/

#include <stdio.h>

void
banner(const char *s)
{
	static const char *tab[] = {
	    " _ "
	    "| |"
	    "|_|"
	    "   ",

	    "   "
	    " | "
	    " | "
	    "   ",

	    " _ "
	    " _|"
	    "|_ "
	    "   ",

	    " _ "
	    " _|"
	    " _|"
	    "   ",

	    "   "
	    "|_|"
	    "  |"
	    "   ",

	    " _ "
	    "|_ "
	    " _|"
	    "   ",

	    " _ "
	    "|_ "
	    "|_|"
	    "   ",

	    " _ "
	    "  |"
	    "  |"
	    "   ",

	    " _ "
	    "|_|"
	    "|_|"
	    "   ",

	    " _ "
	    "|_|"
	    " _|"
	    "   ",
	};

	int c, x, y, w, h;
	size_t i;

	w = 3;
	h = 4;
	for (y = 0; y < h; y++) {
		for (i = 0; s[i]; i++) {
			if (!('0' <= s[i] && s[i] <= '9'))
				continue;

			c = s[i] - '0';
			for (x = 0; x < w; x++)
				printf("%c", tab[c][(y * w) + x]);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	banner("000000000");
	banner("111111111");
	banner("490067715");
	banner("0123456789");

	return 0;
}
