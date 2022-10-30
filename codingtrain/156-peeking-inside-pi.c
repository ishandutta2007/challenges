// https://stuff.mit.edu/afs/sipb/contrib/pi/pi-billion.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

typedef long long vlong;

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

char *
readfile(const char *name, size_t *len)
{
	FILE *fp;
	char *p;
	long n;

	p = NULL;
	fp = fopen(name, "rb");
	if (!fp)
		goto error;

	fseek(fp, 0, SEEK_END);
	n = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if (n < 0)
		goto error;

	p = malloc(n + 1);
	if (!p)
		goto error;

	if (fread(p, n, 1, fp) != 1)
		goto error;

	p[n] = '\0';
	if (len)
		*len = n;

	if (0) {
	error:
		free(p);
		p = NULL;
	}

	if (fp)
		fclose(fp);

	return p;
}

void
usage(void)
{
	fprintf(stderr, "usage: pi-billion.txt <digits> ...\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	char *pi, *p;
	vlong l;
	int i;

	if (argc < 3)
		usage();

	pi = readfile(argv[1], NULL);
	if (!pi)
		fatal("Failed to read pi digits file: %s", strerror(errno));

	for (i = 2; i < argc; i++) {
		p = strstr(pi, argv[i]);
		l = (p) ? p - pi : -1;

		printf("%s: %lld\n", argv[i], l);
	}

	free(pi);
	return 0;
}
