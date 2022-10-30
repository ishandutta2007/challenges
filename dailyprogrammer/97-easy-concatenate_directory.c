/*

Write a program that concatenates all text files (*.txt) in a directory, numbering file names in alphabetical order. Print a header containing some basic information above each file.

For example, if you have a directory like this:

~/example/abc.txt
~/example/def.txt
~/example/fgh.txt

And call your program like this:

nooodl:~$ ./challenge97easy example

The output would look something like this:

=== abc.txt (200 bytes)
(contents of abc.txt)

=== def.txt (300 bytes)
(contents of def.txt)

=== ghi.txt (400 bytes)
(contents of ghi.txt)

For extra credit, add a command line option '-r' to your program that makes it recurse into subdirectories alphabetically, too, printing larger headers for each subdirectory.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <glob.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

int
dumpfile(const char *name)
{
	struct stat st;
	FILE *fp;
	int ch;

	if (stat(name, &st) < 0)
		return -errno;

	fp = fopen(name, "rb");
	if (!fp)
		return -errno;

	printf("=== %s (%zu bytes)\n", name, st.st_size);
	while ((ch = fgetc(fp)) != EOF)
		fputc(ch, stdout);
	printf("\n");

	fclose(fp);
	return 0;
}

int
main(int argc, char *argv[])
{
	char pat[PATH_MAX];
	const char *dir;
	glob_t gl;
	size_t i;

	dir = ".";
	if (argc >= 2)
		dir = argv[1];

	snprintf(pat, sizeof(pat), "%s/*.txt", dir);
	glob(pat, GLOB_TILDE, NULL, &gl);
	for (i = 0; i < gl.gl_pathc; i++) {
		if (dumpfile(gl.gl_pathv[i]) < 0)
			errx(1, "failed to open file %s: %s", gl.gl_pathv[i], strerror(errno));
	}
	globfree(&gl);

	return 0;
}
