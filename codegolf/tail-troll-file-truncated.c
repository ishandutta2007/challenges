/*

Background
When you run tail -f file in bash, the file is outputted and then any subsequent appends.

However, when you remove something that has already been displayed, tail outputs:

tail: nameoffile: file truncated

Your Challenge
When given an input f, append tail: [value of f]: file truncated (with trailing & leading newline) to the file f. You can assume that file f exists, the device is not full, f is not empty, and that you have permissions to write to f.

Test Cases
Input: something

File before:

Some
thing
File after:

Some
thing
tail: something: file truncated

Input relative/path/to/file

File before:

tail: relative/path/to/file: file truncated
File after:

tail: relative/path/to/file: file truncated
tail: relative/path/to/file: file truncated

Reference Implementation (Node.js)
x=>require("fs").appendFileSync(x,`
tail: ${x}: file truncated
`)

*/

#include <stdio.h>
#include <stdlib.h>

int
append(const char *name)
{
	FILE *fp;

	fp = fopen(name, "ab");
	if (!fp)
		return -1;

	fprintf(fp, "tail: %s: file truncated\n", name);
	fclose(fp);

	return 0;
}

void
usage(void)
{
	fprintf(stderr, "usage: file ...\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
		usage();

	for (i = 1; i < argc; i++)
		append(argv[i]);

	return 0;
}
