/*

The task of this challenge is as following:

Write a program that reads a file of reasonable size (let's say <16 MB) from stdin or anywhere else (however you like, but must not be hardcoded), and put's the compressed output onto stdout.
The output must be a valid gzip compressed file and if the compressed file runs through gunzip, it should yield exactly the same file as before.

Rules

    The programming language used must be known before this competition started
    The score of your program is the number of characters of the source code or the assembled program (whatever is shorter)
    You're not allowed to use any kind of existing compression libraries.
    Have fun!

*/

#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

int
gzc(FILE *ifp, gzFile ofp, size_t sz)
{
	unsigned char *p;
	size_t n;
	int r;

	r = Z_OK;
	p = calloc(1, sz);
	if (!p)
		goto errno;

	while (!feof(ifp)) {
		n = fread(p, 1, sz, ifp);
		gzwrite(ofp, p, n);
	}

	if (0) {
	errno:
		r = Z_ERRNO;
	}

	free(p);
	gzclose(ofp);
	return r;
}

int
main(void)
{
	int r;

	r = gzc(stdin, gzdopen(1, "wb"), 16 * 1024);
	if (r != Z_OK)
		printf("Failed to compress: %s\n", zError(r));

	return 0;
}
