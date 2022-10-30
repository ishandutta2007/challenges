/*

Your task today will be to take an existing file and append zeros to it until it reaches a certain size.

You must write a program or function which takes the name of a file in the current directory f and a number of bytes b. While maintaining the original content of f, you must write zeroes (null bytes, not ascii 0s) to the end so that its new size is b bytes.

You may assume that f only has alphanumeric ascii in its name, that you have full permissions over it, that it initially is not larger than b, but may be as large as b, and that there is infinite free disk space.

You may not assume f is nonempty, or that it does not already contain null bytes.

Other existing files should not be modified and new files should not exist after execution ends.

Test Cases
Contents of f | b  | Resulting contents of f
12345         | 10 | 1234500000
0             | 3  | 000
[empty]       | 2  | 00
[empty]       | 0  | [empty]
123           | 3  | 123

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void
usage(void)
{
	fprintf(stderr, "usage: file size\n");
	exit(2);
}

int
padzeros(const char *name, long size)
{
	FILE *fp;
	long off;
	int r;

	r = 0;
	fp = fopen(name, "ab");
	if (!fp)
		goto error;

	if (size < 0) {
		errno = EINVAL;
		goto error;
	}

	off = ftell(fp);
	if (off < 0)
		goto error;

	while (off < size) {
		fputc('\0', fp);
		off++;
	}

	if (0) {
	error:
		r = -errno;
	}

	if (fp)
		fclose(fp);

	return r;
}

int
main(int argc, char *argv[])
{
	const char *file;
	long size;

	if (argc != 3)
		usage();

	file = argv[1];
	size = strtol(argv[2], NULL, 0);

	if (padzeros(file, size) < 0)
		fprintf(stderr, "Failed to pad file: %s\n", strerror(errno));

	return 0;
}
