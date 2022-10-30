// Rewrite fopen and _fillbuf with fields instead of explicit bit operations.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
	unsigned is_read : 1;
	unsigned is_write : 1;
	unsigned is_unbuf : 1;
	unsigned is_buf : 1;
	unsigned is_eof : 1;
	unsigned is_err : 1;
} file_flag_t;

typedef struct {
	int cnt;
	char *ptr;
	char *base;
	file_flag_t flag;
	int fd;
} file_t;

enum {
	OPEN_MAX = 1024,
};

file_t _iob[OPEN_MAX] = {
    {.flag = {.is_read = 1}, .fd = 0},
    {.flag = {.is_write = 1}, .fd = 1},
    {.flag = {.is_write = 1, .is_unbuf = 1}, .fd = 2},
};

int
_fillbuf(file_t *fp)
{
	int bufsize;

	if (fp->flag.is_read == 0 || fp->flag.is_eof == 1 || fp->flag.is_err == 1)
		return EOF;

	bufsize = (fp->flag.is_unbuf == 1) ? 1 : BUFSIZ;
	if (fp->base == NULL) {
		fp->base = malloc(bufsize);
		if (fp->base == NULL)
			return EOF;
	}

	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag.is_eof = 1;
		else
			fp->flag.is_err = 1;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}

file_t *
xfopen(const char *name, const char *mode)
{
	file_t *fp;
	int fd;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;

	for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
		if (fp->flag.is_read == 0 && fp->flag.is_write == 0)
			break;
	}
	if (fp >= _iob + OPEN_MAX)
		return NULL;

	if (*mode == 'w')
		fd = creat(name, 0666);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) < 0)
			fd = creat(name, 0666);
		lseek(fd, 0, 2);
	} else
		fd = open(name, O_RDONLY, 0);

	if (fd < 0)
		return NULL;

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag.is_unbuf = 0;
	fp->flag.is_buf = 1;
	fp->flag.is_eof = 0;
	fp->flag.is_err = 0;
	if (*mode == 'r') {
		fp->flag.is_read = 1;
		fp->flag.is_write = 0;
	} else {
		fp->flag.is_read = 0;
		fp->flag.is_write = 1;
	}

	return fp;
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
	file_t *fp;

	if (argc < 2)
		usage();
	while (--argc > 0) {
		fp = xfopen(*++argv, "r");
		if (!fp) {
			fprintf(stderr, "failed to open file %s\n", *argv);
			continue;
		}
		_fillbuf(fp);
	}
	return 0;
}
