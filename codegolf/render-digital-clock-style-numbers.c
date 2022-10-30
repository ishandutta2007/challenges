/*

Write the shortest program which will take a string of numbers (of up to at least 20 length) as input, and display the output using the standard digital clock style numbers. For instance for input 81, a solution with ascii output would give:

 _
|_|  |
|_|  |

Graphical output is also acceptable, if it helps.

*/

#include <stdio.h>

void
display(const char *s)
{
	static const char *digits[] = {
	    u8"🯰",
	    u8"🯱",
	    u8"🯲",
	    u8"🯳",
	    u8"🯴",
	    u8"🯵",
	    u8"🯶",
	    u8"🯷",
	    u8"🯸",
	    u8"🯹",
	};

	size_t i;
	int c;

	for (i = 0; (c = s[i]); i++) {
		if ('0' <= c && c <= '9')
			printf("%s ", digits[c - '0']);
	}
	printf("\n");
}

int
main(void)
{
	display("81");
	display("0123456789");
	display("7777777777");
	display("11011001010101011011");

	return 0;
}
