// Rewrite the program cat from Chapter 7 using read, write, open, close
// instead of their standard library equivalents.
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void
cat(int ifd, int ofd)
{
	char buf[BUFSIZ];
	ssize_t n;

	while ((n = read(ifd, buf, sizeof(buf))) > 0) {
		if (write(ofd, buf, n) != n)
			fprintf(stderr, "cat: write error: %s", strerror(errno));
	}
}

int
main(int argc, char *argv[])
{
	int i, fd;

	if (argc < 2)
		cat(0, 1);
	else {
		for (i = 1; i < argc; i++) {
			fd = open(argv[i], O_RDONLY);
			if (fd < 0) {
				printf("cat: %s: %s\n", argv[i], strerror(errno));
				continue;
			}
			cat(fd, 1);
			close(fd);
		}
	}
	return 0;
}
