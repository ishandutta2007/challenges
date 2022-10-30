/*

Write a program or function that takes in a single-line string. You can assume it only contains printable ASCII. Print or return a string of an ASCII art rocket such as

  |
 /_\
 |E|
 |a|
 |r|
 |t|
 |h|
 |_|
/___\
 VvV
with the input string written from top to bottom on the fuselage. In this case the input was Earth. The height of the rocket (including flames) is always the length of the string plus five.

Each line in the output may have up to two trailing spaces and there may be a single optional trailing newline. The shortest code in bytes wins.

More Examples:
[empty string]

  |
 /_\
 |_|
/___\
 VvV

a

  |
 /_\
 |a|
 |_|
/___\
 VvV

|0

  |
 /_\
 |||
 |0|
 |_|
/___\
 VvV

\/\

  |
 /_\
 |\|
 |/|
 |\|
 |_|
/___\
 VvV

 _ _ [note trailing space]

  |
 /_\
 | |
 |_|
 | |
 |_|
 | |
 |_|
/___\
 VvV

    [4 spaces]

  |
 /_\
 | |
 | |
 | |
 | |
 |_|
/___\
 VvV

SPACEY

  |
 /_\
 |S|
 |P|
 |A|
 |C|
 |E|
 |Y|
 |_|
/___\
 VvV

*/

#include <stdio.h>

void
rocket(const char *s)
{
	size_t i;

	printf("  |\n");
	printf(" /_\\\n");

	for (i = 0; s[i]; i++)
		printf(" |%c|\n", s[i]);

	printf(" |_|\n");
	printf("/___\\\n");
	printf(" VvV\n");
	printf("\n");
}

int
main(void)
{
	rocket("");
	rocket("a");
	rocket("|0");
	rocket("\\/\\");
	rocket("_ _ ");
	rocket("    ");
	rocket("SPACEY");

	return 0;
}
