/*

Write a program, which outputs I'm Blue,  and then Da, Ba, Dee, Da, Ba, Die,  forever, the words must be space-seperated in one line, and it must pause 0.4 to 0.6 seconds after printing each word.
Also, the text should be outputted in the color blue 0x0000FF or in ANSI escape code blues.

So the output must be something like this: enter image description here

You can use any programming language you want. The output can be in either text or image form (escape codes allowed!).

*/

#define _DEFAULT_SOURCE
#include <stdio.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
bluez(void)
{
	static const char *lyrics[] = {"I'm", "Blue", "Da,", "Ba,", "Dee,", "Da,", "Ba,", "Die,"};
	struct timespec tp;
	size_t c, i;

	tp.tv_sec = 0;
	tp.tv_nsec = 400000000L;
	c = i = 0;
	for (;;) {
		printf("\033[107;34m%s%s", lyrics[i++], (c >= 3) ? "\n" : " ");
		fflush(stdout);

		c = (c + 1) & 3;
		if (i >= nelem(lyrics))
			i = 2;

		nanosleep(&tp, NULL);
	}
}

int
main(void)
{
	bluez();
	return 0;
}
