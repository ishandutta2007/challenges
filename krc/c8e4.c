// Write fseek.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
	int cnt;
	char *ptr;
	char *base;
	unsigned flag;
	int fd;
} file_t;

enum {
	OPEN_MAX = 1024,

	_READ = 1 << 0,
	_WRITE = 1 << 1,
	_UNBUF = 1 << 2,
	_ERR = 1 << 3,
	_EOF = 1 << 4,
};

file_t _iob[OPEN_MAX] = {
    {.flag = _READ, .fd = 0},
    {.flag = _WRITE, .fd = 1},
    {.flag = _WRITE | _UNBUF, .fd = 2},
};

int
_fillbuf(file_t *fp)
{
	int bufsize;

	if (!(fp->flag & _READ) || fp->flag & (_EOF | _ERR))
		return EOF;

	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) {
		fp->base = malloc(bufsize);
		if (fp->base == NULL)
			return EOF;
	}

	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}

int
_flushbuf(int x, file_t *fp)
{
	int bufsize, nc;

	if (fp < _iob || fp >= _iob + OPEN_MAX)
		return EOF;

	if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
		return EOF;

	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) {
		fp->base = malloc(bufsize);
		if (fp->base == NULL) {
			fp->flag |= _ERR;
			return EOF;
		}
	} else {
		nc = fp->ptr - fp->base;
		if (write(fp->fd, fp->base, nc) != nc) {
			fp->flag |= _ERR;
			return EOF;
		}
	}

	fp->ptr = fp->base;
	*fp->ptr++ = (char)x;
	fp->cnt = bufsize - 1;
	return x;
}

file_t *
xfopen(const char *name, const char *mode)
{
	file_t *fp;
	int fd;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;

	for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
		if (!(fp->flag & (_READ | _WRITE)))
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
	fp->flag = 0;
	if (*mode == 'r')
		fp->flag = (fp->flag | _READ) & ~_WRITE;
	else
		fp->flag = (fp->flag | _WRITE) & ~_READ;

	return fp;
}

int
xfseek(file_t *fp, long offset, int origin)
{
	unsigned nc;
	long rc;

	rc = 0;
	if (fp->flag & _READ) {
		if (origin == 1)
			offset -= fp->cnt;
		rc = lseek(fp->fd, offset, origin);
		fp->cnt = 0;
	} else if (fp->flag & _WRITE) {
		if ((nc = fp->ptr - fp->base) > 0) {
			if (write(fp->fd, fp->base, nc) != nc)
				rc = -1;
		}
		if (rc != -1)
			rc = lseek(fp->fd, offset, origin);
	}
	return (rc == -1) ? -1 : 0;
}

int
xfflush(file_t *fp)
{
	int rc;

	if (fp < _iob || fp >= _iob + OPEN_MAX)
		return EOF;

	rc = 0;
	if (fp->flag & _WRITE)
		rc = _flushbuf(0, fp);
	fp->ptr = fp->base;
	fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	return rc;
}

int
xfclose(file_t *fp)
{
	int rc;

	if ((rc = xfflush(fp)) != EOF) {
		free(fp->base);
		fp->ptr = NULL;
		fp->cnt = 0;
		fp->base = NULL;
		fp->flag &= ~(_READ | _WRITE);
	}
	return rc;
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
		xfseek(fp, 0, 0);
		xfseek(fp, 0, 1);
		xfseek(fp, 0, 2);
		_fillbuf(fp);
		xfclose(fp);
	}
	return 0;
}
