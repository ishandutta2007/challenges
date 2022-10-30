/*

This might be a very simple challenge, but I am surprised it hasn't been done on code-golf yet:

Print all Integers from 1 to 10 inclusive in ascending order to standard output.

Your output format can be whatever your language supports. This includes arbitrary separators (commas, semicolons, newlines, combinations of those, etc., but no digits), and prefixes and postfixes (like [...]).
However, you may not output any other numbers than 1 through 10. Your program may not take any input. Standard loopholes are disallowed.

This is code-golf, so shortest answer in bytes wins!

*/

#include <stdio.h>

void
print(void *ud)
{
	int *c;

	c = ud;
	printf("%d\n", ++(*c));
}

// https://en.wikipedia.org/wiki/Duff%27s_device
void
duff(void (*f)(void *), void *ud, int count)
{
	int n;

	n = (count + 7) / 8;
	switch (count % 8) {
	case 0:
		do {
			f(ud);
			// fallthrough
		case 7:
			f(ud);
			// fallthrough
		case 6:
			f(ud);
			// fallthrough
		case 5:
			f(ud);
			// fallthrough
		case 4:
			f(ud);
			// fallthrough
		case 3:
			f(ud);
			// fallthrough
		case 2:
			f(ud);
			// fallthrough
		case 1:
			f(ud);
			// fallthrough
		} while (--n > 0);
	}
}

int
main(void)
{
	int c;

	c = 0;
	duff(print, &c, 10);

	return 0;
}
