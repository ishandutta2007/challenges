/*

Using FTP's ASCII mode to transfer binary files is a bad idea. It is likely to corrupt your data. Badly. Let's simulate this corruption!

Your task is to write a program which takes a file as input and outputs the corrupted version of the file.
Because how exactly your file gets corrupted is dependent on both the FTP client and server and their systems/implementations, for this challenge, we will use the following rules for corruption, in this order:

Clear the high bit in each byte of the file. (Masking with 0x7F is an option here)
When encountering escape (0x1b) followed by [, delete from the escape character through the next letter character (A-Z and a-z), inclusive.
Escape followed by any other character should remove both the escape and the character following it.
All control codes (characters in the range 0x00-0x1F, inclusive, and 0x7F) other than tab (0x09) and linefeed (0x0a) should be removed.

Other rules
Input and output can be in any convenient format. You do not need to use actual files.
Shortest code wins, of course.
Standard rules and loopholes apply.

*/

#include <stdio.h>
#include <ctype.h>

int
getch(FILE *fp)
{
	int c;

	c = fgetc(fp);
	if (c == EOF)
		return c;
	return c & 0x7f;
}

int
isctrl(int c)
{
	if (c == '\t' || c == '\n' || c == 0x1b)
		return 0;
	return 0x00 <= c && c <= 0x1f;
}

void
corrupt(FILE *in, FILE *out)
{
	int c, nc;

	while ((c = getch(in)) != EOF) {
		if (c == 0x1b) {
			nc = getch(in);
			if (nc != '[')
				continue;

			do {
				c = getch(in);
			} while (!isalpha(c) && c != EOF);

			if (c != EOF)
				fputc(c, out);

		} else if (!isctrl(c))
			fputc(c, stdout);
	}
}

int
main(void)
{
	corrupt(stdin, stdout);

	return 0;
}
