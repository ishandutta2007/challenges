/*

Read a string of characters and produce the ROT13 of it. All characters besides [a-zA-Z] should be output verbatim. Each letter in the output may be in any case you wish (you do not have to preserve it).

ROT13 is a simple substitution cipher where each letter of the alphabet is rotated by 13 places (it doesn't matter whether you do it forward or backward, since ROT13 is it's own inverse).

Examples

Input
Output

Hello, world!
Uryyb, jbeyq!

Code Golf and Coding Challenges is awesome.
Pbqr Tbys naq Pbqvat Punyyratrf vf njrfbzr.

Mod abuse!1!!1
Zbq nohfr!1!!1


*/

#include <stdio.h>
#include <ctype.h>

void
rot13(FILE *fp)
{
	int c, p;

	while ((c = fgetc(fp)) != EOF) {
		if (isalpha(c)) {
			p = tolower(c);
			if ('a' <= p && p <= 'm')
				c += 13;
			else if ('n' <= p && p <= 'z')
				c -= 13;
		}
		printf("%c", c);
	}
}

int
main(void)
{
	rot13(stdin);
	return 0;
}
