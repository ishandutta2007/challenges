#include "lib.h"

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	if (nmemb == 0)
		nmemb = 1;
	if (size == 0)
		size = 1;
	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

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

void *
read_file(const char *name, size_t *len)
{
	FILE *fp;
	void *p;
	long n;

	fp = fopen(name, "rb");
	if (!fp)
		goto error;

	fseek(fp, 0, SEEK_END);
	n = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if (n < 0)
		goto error;

	p = xcalloc(1, n + 1);
	fread(p, n, 1, fp);

	if (0) {
	error:
		p = NULL;
		n = 0;
	}

	if (fp)
		fclose(fp);

	if (len)
		*len = n;
	return p;
}
