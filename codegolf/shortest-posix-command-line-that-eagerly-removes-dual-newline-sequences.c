/*

Example:

echo -ne 'a\n\nb\nc\n\n\n\nd\n\n\n' | your-command
should output the same as

echo -ne 'ab\ncd\n'

Watch out, some POSIX tools have implementations that diverge from the standard.
Please consult https://pubs.opengroup.org/onlinepubs/9699919799/idx/utilities.html before submitting your solutions.

*/

#include <stdio.h>

typedef unsigned long long uvlong;

void
ddnl(FILE *in, FILE *out)
{
	uvlong nl;
	int c;

	for (;;) {
		nl = 0;
		while ((c = fgetc(in)) != EOF) {
			if (c == '\n')
				nl++;
			else
				break;
		}

		if (nl == 1 || (nl && c == EOF))
			fputc('\n', out);

		if (c == EOF)
			break;

		fputc(c, out);
	}
}

int
main(void)
{
	ddnl(stdin, stdout);

	return 0;
}
