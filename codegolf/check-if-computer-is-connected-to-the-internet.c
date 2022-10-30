/*

Write a program which, according to whether the script has access to the internet, produces an output which is "Truthy/Falsey".
You may try and connect to any existing site, at your own discretion (don't use a shady site which only has 10% uptime - try to keep to above 80% annual uptime). If the site is down, your program does not have to work.

It must be a standalone program or a function. You may use libraries outside of the standard library to achieve this. Standard loopholes are forbidden. This is code golf, so the code with the shortest byte-count wins.

Example pseudocode:

function a:
    try:
        connect to internet 
        return 1
    catch error:
        return 0

This is my first post on code golf, so if this violates any rules in any way or is a dupe, please alert me.

EDIT: Due to numerous suggestions, I have removed the UTF-8 byte count restriction

*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>

int
internet(const char *host, int port)
{
	struct sockaddr_in sa;
	struct timeval tv;
	fd_set ws;
	int s, r, f;

	r = 0;
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
		goto out;

	f = fcntl(s, F_GETFL, NULL);
	if (f < 0)
		goto out;

	if (fcntl(s, F_SETFL, f | O_NONBLOCK) < 0)
		goto out;

	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr(host);
	sa.sin_port = htons(port);

	if (connect(s, (struct sockaddr *)&sa, sizeof(sa)) == 0) {
		r = 1;
		goto out;
	}

	if (errno == EINPROGRESS) {
		FD_ZERO(&ws);
		FD_SET(s, &ws);

		tv.tv_sec = 1;
		tv.tv_usec = 0;

		r = select(s + 1, NULL, &ws, NULL, &tv);
		r = (r <= 0) ? 0 : 1;
	}

out:
	if (s >= 0)
		close(s);
	return r;
}

int
main(void)
{
	printf("%d\n", internet("8.8.8.8", 443));
	return 0;
}
