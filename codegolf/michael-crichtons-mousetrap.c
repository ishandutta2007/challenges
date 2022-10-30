/*

In 1984, Michael Crichton wrote a security program in BASIC that was published in Creative Computing magazine.
The program would ask the user to type a phrase of their choice, record the intervals between the keystrokes, then ask them to retype the phrase.
If the timings differed by too much, the program would identify the user as an imposter.

Your assignment: create a version of Crichton's program in the language of your choice.

Rules:

Phrases for communicating with the user ("Please type the key phrase," "Please type the key phrase again," etc.) count as one byte each regardless of actual length. This is for user communication only, do not try to hide program code in the strings.

The pass/fail test should be based on the average absolute value of the percentage variances from the original intervals. If the strings don't match, either return fail or allow the user to try again, at your discretion.

The key phrase should not allow a null string. In the event the key phrase is too long for your string datatype, either truncate or disallow and start over, at your discretion.

The sensitivity of the test (the threshold for the pass/fail test) should be adjustable in the source code.

I originally provided a bonus of 20% of total byte count if your source code can be formatted to recognizably resemble a dinosaur.
It has been pointed out that this is highly subjective and perhaps more appropriate for a popularity contest, so I have removed this bonus.
However I still heartily encourage dinosaur formatting, and if you format your code to look like a dinosaur, you can deduct any purely cosmetic comments, linebreak or whitespace characters from your byte total.

Shortest byte count wins, subject to string-length and dinosaur formatting adjustments.

Note that my specification above does not exactly match the operation of Crichton's code, copies of which may be found online. Follow the spec, don't try to clone the original.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <err.h>
#include <getopt.h>
#include <curses.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
	int delay;
} Conf;

typedef struct {
	struct timespec t;
	int ch;
} Key;

Conf conf = {
    .delay = 5,
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

int
clamp(int x, int a, int b)
{
	if (x < a)
		return a;
	if (x > b)
		return b;
	return x;
}

void
bold(const char *text)
{
	size_t i;

	for (i = 0; text[i]; i++)
		addch(text[i] | A_BOLD);
	addch('\n' | A_BOLD);
	refresh();
}

void
record(Key *key, int ch)
{
	struct timespec *t, tn;

	t = &key->t;
	clock_gettime(CLOCK_MONOTONIC, &tn);
	if (t->tv_sec == 0 && t->tv_nsec == 0)
		*t = tn;

	key->ch = ch;
}

int
input(WINDOW *win, int row, int col, const char *prompt, Key *key)
{
	int once;
	int sx, sy;
	int x, y;
	int ch;
	int i;

	if (row <= 1 || col <= 1)
		return 0;

	once = 0;
	for (;;) {
		if (!once || x >= col || y >= row) {
			clear();
			if (once)
				bold("Phrase too long! Type it again!");
			bold(prompt);
			getyx(win, sy, sx);

			memset(key, 0, sizeof(*key) * col);
			x = sx;
			y = sy;
			i = 0;
			once = 1;
			continue;
		}

		ch = getch();
		if (ch == 0 || ch == 4 || ch == '\n')
			break;

		if (ch == '\b' && x >= sx) {
			move(y, x--);
			delch();
			i--;
		} else {
			record(key + i++, ch);
			addch(ch);
			x++;
		}
		x = clamp(x, sx, col);
		i = clamp(i, 0, col);
	}
	return i;
}

time_t
elapsed(Key *k, int i, int j)
{
	struct timespec *a, *b;

	a = &k[i].t;
	b = &k[j].t;
	return max(a->tv_sec, b->tv_sec) - min(a->tv_sec, b->tv_sec);
}

int
cmp(Key *k0, Key *k1, int nk0, int nk1, int delay)
{
	time_t t0, t1;
	int i;

	if (nk0 != nk1)
		return 0;

	for (i = 0; i < nk0; i++) {
		if (k0[i].ch != k1[i].ch)
			return 0;

		if (i > 0) {
			t0 = elapsed(k0, i, i - 1);
			t1 = elapsed(k1, i, i - 1);
			if (max(t1, t0) - min(t1, t0) >= delay)
				return 0;
		}
	}

	return 1;
}

void
usage(void)
{
	fprintf(stderr, "usage: [-d delay]\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	WINDOW *win;
	Key *k0, *k1;
	int nk0, nk1;
	int row, col;
	int c;

	while ((c = getopt(argc, argv, "d:h")) != -1) {
		switch (c) {
		case 'd':
			conf.delay = atoi(optarg);
			break;

		case 'h':
			usage();
			break;
		}
	}
	argc -= optind;
	argv += optind;

	srand(time(NULL));
	win = initscr();
	if (!win)
		errx(1, "Failed to init screen");

	getmaxyx(win, row, col);

	clear();
	cbreak();
	noecho();

	k0 = xcalloc(col, sizeof(*k0));
	k1 = xcalloc(col, sizeof(*k1));
	nk0 = input(win, row, col, "Please type the key phrase", k0);
	nk1 = input(win, row, col, "Please type the key phrase again", k1);

	clear();
	if (cmp(k0, k1, nk0, nk1, conf.delay))
		bold("LEGIT!!!");
	else
		bold("IMPOSTER!!!");
	getch();

	endwin();
	free(k0);
	free(k1);

	return 0;
}
