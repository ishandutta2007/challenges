/*

Introduction
hackertyper.net is a website that simulates "hacking" (as the media portrays it) by outputting complicated code from the crypto section of the Linux kernel onto the screen as you type at a rate of 3 characters per one inputted.

Challenge
Your program/function should either accept a file as a command-line argument, have the file path hard-coded,
or accept the text [that would be in the file] as a command-line or function argument,
and mimic hackertyper.net by outputting 3 characters onto the screen (STDOUT or equivalent) from the file for each one received through STDIN or equivalent.

Once EOF is reached, the program should start outputting characters from the beginning of the file again (wrap).

Specs
For the purposes of simplicity, you can assume that STDIN has already been set to no buffer and no echo mode, that is not waiting until the user presses enter before passing input to your program and not displaying the characters you type.

The file can contain newlines, while the input will not contain newlines.

For a small example written in C (not golfed) that demonstrates how this works, see this.

Green text and a black background are not required.

Example input and output
The file:

#include <stdio.h>
int main() { }

Input:

hello world
Output:

#include <stdio.h>
int main() { }
The file:

hello
Input:

hello world
Output:

hellohellohellohellohellohellohel

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include <err.h>

volatile sig_atomic_t quit;

void
sighandle(int sig)
{
	quit = 1;

	(void)sig;
}

void
usage(void)
{
	fprintf(stderr, "usage: <file>\n");
	exit(2);
}

int
setecho(int enb)
{
	struct termios tc;
	int fd;

	fd = fileno(stdin);
	if (tcgetattr(fd, &tc) != 0)
		return -1;

	if (enb)
		tc.c_lflag |= ECHO | ICANON;
	else
		tc.c_lflag &= ~(ECHO | ICANON);
	return tcsetattr(fd, TCSANOW, &tc);
}

int
hackertype(const char *name)
{
	FILE *fp;
	int c, i;

	fp = fopen(name, "rb");
	if (!fp)
		return -errno;

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setecho(0);

	while (!quit) {
		fgetc(stdin);
		for (i = 0; i < 3; i++) {
			c = fgetc(fp);
			if (c == EOF) {
				fseek(fp, 0, SEEK_SET);
				fflush(fp);
				c = fgetc(fp);
			}
			if (c != EOF)
				putc(c, stdout);
		}
	}

	setecho(1);
	fclose(fp);
	return 0;
}

int
main(int argc, char *argv[])
{
	if (argc < 2)
		usage();

	signal(SIGTERM, sighandle);
	signal(SIGINT, sighandle);

	if (hackertype(argv[1]) < 0)
		err(1, "open: %s", argv[1]);

	return 0;
}
