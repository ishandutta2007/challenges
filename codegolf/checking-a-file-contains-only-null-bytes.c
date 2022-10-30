/*

Your goal is to write a program or function that takes in as input a string representing the path to a file, and outputs a truthy value if that file is not empty and contains no non-null bytes -- i.e., all bits are 0 -- and a falsey value otherwise.

I realize it is a very simple problem and I guess I could hack something, but I suspect there must be some short and elegant way of doing it, and that gave me the idea to make a challenge out of it.

This is code-golf, so shortest code in bytes wins. (My own preference would go to the fastest solution, but that is too implementation dependent...)

Related questions: Pad a file with zeros

Motivation : This is only to tell where the problem comes from, in case you are interested. You do not need to read it.

ISO images of CDs and DVDs, copied with "dd" or other means, often terminate with a sequence of useless blocks containing only null bytes.
Standard techniques to remove these blocks are known and simple (see https://unix.stackexchange.com/questions/74827/ ) but they may sometimes remove non null useful data because the medium can lie about its own size.
So I want to check that the removed blocks contain only null bytes. Removing these blocks is important for defining a normalised version of ISO-images.

*/

#include <stdio.h>
#include <stdlib.h>

int
check(const char *name)
{
	FILE *fp;
	int lch, ch;

	fp = fopen(name, "rb");
	if (!fp)
		return 0;

	lch = 0;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == 0)
			break;
		lch = ch;
	}

	fclose(fp);
	return lch && ch;
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
		printf("%s: %d\n", argv[i], check(argv[i]));

	return 0;
}
