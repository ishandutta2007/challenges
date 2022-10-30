/*

Like many people who program, I got started doing this because I wanted to learn how to make video games.

As a result, my first ever 'project' was also my first video game. It involved a simple text adventure I called "The adventure of the barren moor"

In "The adventure of the barren moor" the player is in the middle of an infinite grey swamp.
This grey swamp has few distinguishing characteristics, other than the fact that it is large and infinite and dreary.
However, the player DOES have a magic compass that tells the player how far away the next feature of interest is.

The player can go north,south,east,or west. In my original version of the game, there was only one feature of interest, a treasure chest at a random point in the world.

Here is an example playthrough of my old program:

You awaken to find yourself in a barren moor.  Try "look"
> look
Grey foggy clouds float oppressively close to you,
reflected in the murky grey water which reaches up your shins.
Some black plants barely poke out of the shallow water.
Try "north","south","east",or "west"
You notice a small watch-like device in your left hand.
It has hands like a watch, but the hands don't seem to tell time.

The dial reads '5m'

>north
The dial reads '4.472m'
>north
The dial reads '4.123m'
>n
The dial reads '4m'
>n
The dial reads '4.123m'
>south
The dial reads '4m'
>e
The dial reads '3m'
>e
The dial reads '2m'
>e
The dial reads '1m'
>e

You see a box sitting on the plain.   Its filled with treasure!  You win!  The end.

The dial reads '0m'
Obviously, you do not have to use my flavor text, or my feature points. As a matter of fact, its probably more interesting if you don't!

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

Point
place(int r)
{
	Point p;

	do {
		p.x = rand();
		p.y = rand();
	} while (p.x == 0 && p.y == 0);

	p.x %= r;
	p.y %= r;
	return p;
}

int
decode(char *b)
{
	static const struct {
		int op;
		char cmd[16];
	} xec[] = {
	    {'l', "look"},
	    {'n', "north"},
	    {'s', "south"},
	    {'e', "east"},
	    {'w', "west"},
	    {'q', "quit"},
	};

	size_t i, n;
	char *p;

	p = strchr(b, '\n');
	if (p)
		*p = '\0';

	n = strlen(b);
	if (n == 0)
		return 0;

	for (i = 0; i < nelem(xec); i++) {
		if (!strncmp(b, xec[i].cmd, n))
			return xec[i].op;
	}
	return -1;
}

double
distance(Point *p, Point *q)
{
	return hypot(p->x - q->x, p->y - q->y);
}

void
dial(Point *p, Point *t)
{
	printf("The dial reads '%.3fm'\n", distance(p, t));
}

void
look(Point *p, Point *t)
{
	printf("Grey foggy clouds float oppressively close to you,\n");
	printf("reflected in the murky grey water which reaches up your shins.\n");
	printf("Some black plants barely poke out of the shallow water.\n");
	printf("Try \"north\", \"south\", \"east\", or \"west\"\n");
	printf("You notice a small watch-like device in your left hand.\n");
	printf("It has hands like a watch, but the hands don't seem to tell time.\n");
	printf("\n");
	dial(p, t);
}

void
move(Point *p, Point *t, int dx, int dy)
{
	p->x += dx;
	p->y += dy;
	dial(p, t);
}

void
play(void)
{
	Point p, t;
	char b[32];
	int c;

	p.x = 0;
	p.y = 0;
	t = place(100);

	printf("You awaken to find yourself in a barren moor.  Try \"look\".\n");
	for (;;) {
		if (p.x == t.x && p.y == t.y) {
			printf("You see a box sitting on the plain.   Its filled with treasure!  You win!  The end.\n");
			return;
		}

		printf("> ");

		if (!fgets(b, sizeof(b), stdin)) {
			printf("\n");
			break;
		}

		c = decode(b);
		if (c == 'q')
			break;

		switch (c) {
		case 'l':
			look(&p, &t);
			break;
		case 'n':
			move(&p, &t, 0, 1);
			break;
		case 's':
			move(&p, &t, 0, -1);
			break;
		case 'e':
			move(&p, &t, 1, 0);
			break;
		case 'w':
			move(&p, &t, -1, 0);
			break;
		case 0:
			break;
		default:
			printf("Unknown command '%s'.\n", b);
			break;
		}
	}

	printf("The treasure was at (%d, %d).\n", t.x, t.y);
}

int
main(void)
{
	srand(time(NULL));
	play();
	return 0;
}
