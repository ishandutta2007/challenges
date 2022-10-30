/*

I've already made this in Python, but it seems that it could be shortened a lot:

txt = input("Type something.. ")
c = "#"
b = " "
print(c * (len(txt) + 4))
print(c, b * len(txt), c)
print(c, txt, c)
print(c, b * len(txt), c)
print(c * (len(txt) + 4))

So if the user types:

Hello World

The program prints:

###############
#             #
# Hello World #
#             #
###############

Fewest bytes wins—and of course, the answer can be written in any language.

*/

#include <stdio.h>
#include <string.h>

void
lines(int c, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%c", c);
	printf("\n");
}

void
blinders(int c, size_t n)
{
	size_t i;

	printf("%c", c);
	for (i = 0; i < n; i++)
		printf(" ");
	printf("%c\n", c);
}

void
munchies(const char *s)
{
	size_t n;

	n = strlen(s);
	lines('#', n + 4);
	blinders('#', n + 2);
	printf("# %s #\n", s);
	blinders('#', n + 2);
	lines('#', n + 4);
}

int
main(void)
{
	munchies("Hello World");
	munchies("0123456789");

	return 0;
}
