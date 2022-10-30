/*

This challenge tests your understanding of Sockets and Multi-Threaded programming.

Your task is to write a UNIX Domain Socket(UDS) server which can accept connection from 'N' clients.
Each client will send text data over the socket. Read the data and send it back to the client. The server should be Multi-Threaded and should service all clients in parallel.
To support Multi-Threading you can use the POSIX thread library (C,C++) or the default threading library for other languages.

Communication Protocol

Read data from client and send the response back.
String "END" marks end of communication from a client. Send response "END" and disconnect the client.

Example request 1:

Client 1:
Hello World
END
Example response 1:

Client 1:
Hello World
Example request 2:

Client 2:
This is line 1
This is line 2
END
Example response 2:

Client 2:
This is line 1
This is line 2

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <getopt.h>
#include <err.h>

typedef struct {
	char sockpath[80];
	int backlog;
} Conf;

Conf conf = {
    .sockpath = "unix.sock",
    .backlog = 8192,
};

void
usage(void)
{
	fprintf(stderr, "usage: [options] <socketpath>\n");
	fprintf(stderr, "  -b    set backlog (default: %d)\n", conf.backlog);
	fprintf(stderr, "  -h    show this message\n");
	exit(2);
}

void
parseargs(int *argc, char ***argv)
{
	int c;

	while ((c = getopt(*argc, *argv, "b:h")) != -1) {
		switch (c) {
		case 'b':
			conf.backlog = atoi(optarg);
			break;
		case 'h':
			usage();
			break;
		}
	}

	*argc -= optind;
	*argv += optind;
	if (*argc >= 1)
		snprintf(conf.sockpath, sizeof(conf.sockpath), "%s", *argv[0]);
}

void *
handle(void *arg)
{
	FILE *fp;
	int fd;
	char *line;
	size_t len;
	ssize_t nr;

	line = NULL;
	fd = (uintptr_t)arg;
	fp = fdopen(fd, "w+");
	if (!fp)
		goto out;

	while ((nr = getline(&line, &len, fp)) != -1) {
		if (!strcmp(line, "END\n"))
			break;
		fputs(line, fp);
	}

out:
	free(line);
	if (fp)
		fclose(fp);
	else
		close(fd);

	return NULL;
}

// socat - UNIX-CONNECT:<unix_socket_path>
void
serve(void)
{
	struct sockaddr_un sa, ca;
	socklen_t len;
	pthread_t th;
	int sfd, cfd;
	int r;

	memset(&sa, 0, sizeof(sa));
	sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (sfd < 0)
		err(1, "socket");

	sa.sun_family = AF_UNIX;
	snprintf(sa.sun_path, sizeof(sa.sun_path), "%s", conf.sockpath);
	unlink(conf.sockpath);
	if (bind(sfd, &sa, sizeof(sa)) < 0)
		err(1, "bind");

	if (listen(sfd, conf.backlog) < 0)
		err(1, "listen");

	printf("Serving at %s\n", conf.sockpath);
	for (;;) {
		cfd = accept(sfd, &ca, &len);
		if (cfd < 0) {
			printf("Error accepting connection: %s\n", strerror(errno));
			continue;
		}

		r = pthread_create(&th, NULL, handle, (void *)(uintptr_t)cfd);
		if (r != 0)
			close(cfd);
		else
			pthread_detach(th);
	}

	close(sfd);
}

int
main(int argc, char *argv[])
{
	parseargs(&argc, &argv);
	serve();

	return 0;
}
