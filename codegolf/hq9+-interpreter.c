/*

The goal of this code golf is to create an interpreter for the programming language HQ9+

There are 4 commands in this programming language:

    H - prints "Hello, world!"
    Q - prints the source code of the program
    9 - prints the lyrics of the song "99 bottles of beer"
    + - increments the accumulator

The rules:

    Because the accumulator isn't defined, you can ignore the command +
    Your program should prompt for input (this input will be the source code) or the source code is read from a file
    You are not allowed to put the lyrics of "99 bottles of beer" in a file, and read the text from the file
    You are not allowed to use a compression algorithm such as GZip or BZip to compress the song text: you have to create your own compression algorithm. This doesn't have to be a complex algorithm, but try to compress the text as much as possible (remember: this is a code-golf, the code with the fewest bytes wins)
    If the source code contains a char that isn't H, Q, 9 or +, then output "Source code contains invalid characters" before running any commands! This means that, if the source code is H1 for example, then don't output Hello, world! before you output Source code contains invalid characters. No, immediately output Source code contains invalid characters
    If your interpreter accepts both uppercase and lowercase characters, then you get -8 to your character count

Good luck!


*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void
bottles(int n)
{
	const char *s;
	int i;

	for (i = n; i >= 1; i--) {
		s = (i > 1) ? "s" : "";
		printf("%d bottle%s of beer on the wall, %d bottle%s of beer.\n", i, s, i, s);

		if (i - 1 > 0) {
			s = (i - 1 > 1) ? "s" : "";
			printf("Take one down and pass it around, %d bottle%s of beer on the wall.\n\n", i - 1, s);
		}
	}

	printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
	printf("No more bottles of beer on the wall, no more bottles of beer.\n");
	printf("Go to the store and buy some more, %d bottles of beer on the wall.\n", n);
}

int
hq9p(const char *s)
{
	size_t i;
	int ac;

	for (i = 0; s[i]; i++) {
		if (!strchr("hq9+", tolower(s[i]))) {
			printf("Source code contains invalid characters\n");
			return -1;
		}
	}

	ac = 0;
	for (i = 0; s[i]; i++) {
		switch (tolower(s[i])) {
		case 'h':
			printf("Hello, World!\n");
			break;
		case 'q':
			printf("%s\n", s);
			break;
		case '9':
			bottles(99);
			break;
		case '+':
			ac += (ac < INT_MAX);
			break;
		}
	}
	return ac;
}

int
main(void)
{
	hq9p("hq9+");
	return 0;
}
