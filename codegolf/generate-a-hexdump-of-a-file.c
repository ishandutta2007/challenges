/*

In this task, your goal is to write a program for generating hexdumps of files of arbitrary types.

Input

The input consists of a (relative or absolute) path to the file to be processed. It may be taken from STDIN, a function argument, or a command line argument.
Output

The output (which may be written to a separate plaintext file or to STDOUT) should contain a hexdump of the file, formatted as follows:

    A-F may be uppercase or lowercase, but should be consistent throughout the output
    Spaces between bytes on the same line
    16 bytes per line (the last line may be shorter, depending on the input file)
    A trailing newline at the end of the output is permissible
    A single trailing space at the beginning or end of each line is permissible, but should be consistent throughout the output.

Some test cases:

Input text file:

Hello, World!

Output (STDOUT or separate text file):

48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21

Input text file:

"Look behind you! It's a three-headed monkey!"

Output (STDOUT or separate text file):

22 4C 6F 6F 6B 20 62 65 68 69 6E 64 20 79 6F 75
21 20 49 74 27 73 20 61 20 74 68 72 65 65 2D 68
65 61 64 65 64 20 6D 6F 6E 6B 65 79 21 22

Input JVM class file:

https://googledrive.com/host/0B66Q2_YrkhNnQkYzY0hyck04NWc/HelloWorld.class

Output (STDOUT or separate text file):

CA FE BA BE 00 00 00 34 00 1D 0A 00 06 00 0F 09
00 10 00 11 08 00 12 0A 00 13 00 14 07 00 15 07
00 16 01 00 06 3C 69 6E 69 74 3E 01 00 03 28 29
56 01 00 04 43 6F 64 65 01 00 0F 4C 69 6E 65 4E
75 6D 62 65 72 54 61 62 6C 65 01 00 04 6D 61 69
6E 01 00 16 28 5B 4C 6A 61 76 61 2F 6C 61 6E 67
2F 53 74 72 69 6E 67 3B 29 56 01 00 0A 53 6F 75
72 63 65 46 69 6C 65 01 00 0F 48 65 6C 6C 6F 57
6F 72 6C 64 2E 6A 61 76 61 0C 00 07 00 08 07 00
17 0C 00 18 00 19 01 00 0D 48 65 6C 6C 6F 2C 20
57 6F 72 6C 64 21 07 00 1A 0C 00 1B 00 1C 01 00
0A 48 65 6C 6C 6F 57 6F 72 6C 64 01 00 10 6A 61
76 61 2F 6C 61 6E 67 2F 4F 62 6A 65 63 74 01 00
10 6A 61 76 61 2F 6C 61 6E 67 2F 53 79 73 74 65
6D 01 00 03 6F 75 74 01 00 15 4C 6A 61 76 61 2F
69 6F 2F 50 72 69 6E 74 53 74 72 65 61 6D 3B 01
00 13 6A 61 76 61 2F 69 6F 2F 50 72 69 6E 74 53
74 72 65 61 6D 01 00 07 70 72 69 6E 74 6C 6E 01
00 15 28 4C 6A 61 76 61 2F 6C 61 6E 67 2F 53 74
72 69 6E 67 3B 29 56 00 21 00 05 00 06 00 00 00
00 00 02 00 01 00 07 00 08 00 01 00 09 00 00 00
1D 00 01 00 01 00 00 00 05 2A B7 00 01 B1 00 00
00 01 00 0A 00 00 00 06 00 01 00 00 00 01 00 09
00 0B 00 0C 00 01 00 09 00 00 00 25 00 02 00 01
00 00 00 09 B2 00 02 12 03 B6 00 04 B1 00 00 00
01 00 0A 00 00 00 0A 00 02 00 00 00 03 00 08 00
04 00 01 00 0D 00 00 00 02 00 0E

Input ICO image file:

http://cdn.sstatic.net/codegolf/img/favicon.ico

Output (STDOUT or separate text file):

340 lines starting with 00 00 01 00 02 00 10 10 00 00 01 00 20 00 68 04

Input PNG image file:

http://i.stack.imgur.com/xPAwA.png

Output (STDOUT or separate text file):

7982 lines starting with 89 50 4E 47 0D 0A 1A 0A 00 00 00 0D 49 48 44 52

Input MP3 Audio file:

http://www.newgrounds.com/audio/download/142057

(CC BY-NC-SA NemesisTheory 2008)

Output (STDOUT or separate text file):

300769 lines starting with 49 44 33 03 00 00 00 00 1F 76 54 49 54 32 00 00

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void
hexdump(FILE *in, FILE *out)
{
	unsigned i;
	int ch;

	i = 0;
	while ((ch = fgetc(in)) != EOF) {
		if (i)
			fprintf(out, " ");
		fprintf(out, "%02X", ch);
		if (++i >= 16) {
			fprintf(out, "\n");
			i = 0;
		}
	}
	if (i < 16)
		fprintf(out, "\n");
}

int
main(int argc, char *argv[])
{
	FILE *fp;
	int i;

	if (argc < 2)
		hexdump(stdin, stdout);
	else {
		for (i = 1; i < argc; i++) {
			fp = fopen(argv[i], "rb");
			if (!fp) {
				fprintf(stderr, "%s: %s\n", argv[i], strerror(errno));
				continue;
			}
			hexdump(fp, stdout);
			fclose(fp);
		}
	}
	return 0;
}
