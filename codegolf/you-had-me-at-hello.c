/*

Task

Read in a possibly infinite text stream or file, outputting its contents until the word hello has been output, abiding to the following rules.

Once hello has been output, your code should quit immediately. It should not wait for a newline for example.

Your code should output as it goes. That is it shouldn't read in a huge amount of input and then start outputting.

If the stream/file doesn't contain hello, your code should just carry on outputting the input forever or until the end of the stream/file is reached.

This is a case sensitive challenge, so hello is not equal to Hello.

You may assume that the input consists solely of printable ASCII characters and newlines.

Your code can't expect that the text will be terminated by a newline or that there will be any newlines at all in the input. Also, you code cannot assume that it will run on a machine with an infinite amount of memory.

You may assume that your code will be called from an empty directory.

Example input stream

I once had a horse called hellopina.
Output

I once had a horse called hello

Tip

Run yes | tr -d \\n | <your program> to check if it works with infinite streams. If it doesn't print anything and/or leaks memory, the program doesn't comply with the spec. It should print yyyyyyyyyyyyyyyyyyyyyy... forever with no newlines.

*/

#include <stdio.h>

void
process(FILE *in, FILE *out, const char *str)
{
	int c;
	size_t n;

	n = 0;
	while ((c = fgetc(in)) != EOF) {
		if (str[n] == '\0')
			break;

		if (c == str[n])
			n = n + 1;
		else
			n = 0;

		fputc(c, out);
	}
}

int
main(void)
{
	process(stdin, stdout, "hello");

	return 0;
}
