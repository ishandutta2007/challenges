#include "lib.h"

[[noreturn]] void fatal(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

char *file2str(const char *name, size_t *size)
{
	char *str = NULL;
	long len = 0;
	auto fp = fopen(name, "rb");
	if (!fp)
		goto error;

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if (len <= 0)
		goto error;

	str = (char *)malloc(len + 1);
	if (!str)
		goto error;

	fread(str, len, 1, fp);
	str[len] = '\0';
	if (size)
		*size = len;

	if (0)
	{
	error:
		free(str);
		str = NULL;
	}

	if (fp)
		fclose(fp);

	return str;
}

void hexdump(void *buf, size_t len)
{
	auto ptr = (unsigned char *)buf;
	for (size_t i = 0; i < len; i++)
	{
		printf("%02X ", ptr[i]);
		if ((i & 15) == 15)
			printf("\n");
	}
	printf("\n");
}

char *stprint(const char *fmt, ...)
{
	static thread_local char buf[8192];
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	return buf;
}
