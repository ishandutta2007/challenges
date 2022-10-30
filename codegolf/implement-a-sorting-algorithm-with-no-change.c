/*

In this task, you have to write a program, that reads a string with a length of up to 1024 characters and prints it out sorted. In order to make an interesting task from a boring one, I set a few restrictions:

You must not change the contents of any variable. A variable can be assigned only once and must not be changed afterwards. For instance, all of the following constructs are forbidden:

int a = 0;
a = 1;

a = 10;
for (a-->0);

string[12] = a

and many more. What is changing a variable and what not is judged by me.

Additionally, you must not use any sorting function or any library function, that must be "imported" somehow.
The only library functions, that are allowed to import are those to print out the result and read in the string, if they are not available whithout importing them.

*/

#include <stdio.h>

void
print(int c, size_t n)
{
	if (n == 0)
		return;
	printf("%c", c);
	print(c, n - 1);
}

size_t
count(const char *s, int c)
{
	if (*s == '\0')
		return 0;
	return (*s == c) + count(s + 1, c);
}

void
chars(const char *s, int c)
{
	size_t n;

	if (c >= 128)
		return;

	n = count(s, c);
	print(c, n);
	chars(s, c + 1);
}

void
psort(const char *s)
{
	chars(s, 0);
	printf("\n");
}

int
main(void)
{
	psort("abcdef");
	psort("ixtos");
	psort("kekeke");
	psort("hfeuhgeuirhy35hy34jgowhg928yt831y02g348y34");

	return 0;
}
