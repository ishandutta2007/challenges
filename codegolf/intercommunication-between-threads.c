/*

So glad I found this cool site. Wanted to try sharing a coding challenge a friend gave me, an interview question. Usually it is written in java, but you can use whatever language you want, just have fun!

Challenge: write efficiently and securely a program that creates an array of n threads that communicate with each other, where each thread, for simplicity, represents a number between 1,...,100. Oh, and it has to be randomly initialized.

Here comes the fun part: each thread looks at its neighbours(i-1,i+1) and:

If its number is smaller than the number of both of his neighbours(i-1,i+1), it increments itself.

If its number is larger than the numbers of both of his neighbours, it decrements itself.

If its number is equal or between the numbers of its neighbours, it keeps the number the same.

So far not fun, right? So let's also make it a circular array! (the first element in the array and the last element in the array are neighbours) the tricky parts are: each thread should not change its number before its neighbors finished checking it.

The program performs m rounds of checks.

Input: For program logic, you can take the input from the user, or define it, doesn't matter.

Output:
first line should print the starting state of the array.
Second line should print all of the numbers in the array after each thread did one check.
Third line should print the numbers in all of the array after each thread did a second test(second round) and so on.

Might be quite tricky in the beginning, but have fun with it! The winner will be the one who can write the shortest code, and in case of a tie, cool algorithmic tricks or functional utilization of the java language will be awarded extra points!

First post here, will try to post more cool stuff for you to enjoy! Really like this site.
I posted it a while ago, but forgot my credentials while being abroad so I couldn't log in to the site and fix the previous post.
Hoping that this one is according to the standards of the site and more than that, I really hope you'll enjoy this cool coding gamexercise.

Good luck to all and most importantly - enjoy!

As kevin well-said: Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdatomic.h>
#include <math.h>
#include <time.h>
#include <getopt.h>
#include <pthread.h>
#include <err.h>

typedef struct Flags Flags;
typedef struct Pocket Pocket;

struct Flags {
	int pockets;
	int rounds;
};

struct Pocket {
	pthread_t thread;
	pthread_mutex_t *lock[3];
	int id;
	int value;
	int runs;

	Pocket *links;
	int nlinks;
	int rounds;
	atomic_int *count;
};

unsigned
randn(unsigned n)
{
	unsigned r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
}

void
swap(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

void
shuffle(int *a, size_t n)
{
	size_t i, j;

	if (n < 2)
		return;

	if (n < 3) {
		swap(&a[0], &a[1]);
		return;
	}

	for (i = 0; i < n - 2; i++) {
		j = i + (randn(n - i - 1));
		swap(&a[i], &a[j]);
	}
}

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!nmemb)
		nmemb = 1;

	if (!size)
		size = 1;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

void
usage(Flags *f)
{
	fprintf(stderr, "usage: [options]\n");
	fprintf(stderr, "  -h\tshow this message\n");
	fprintf(stderr, "  -m\tnumber of iterations (default: %d)\n", f->rounds);
	fprintf(stderr, "  -n\tnumber of pockets (default: %d)\n", f->pockets);
	exit(2);
}

void
parseflags(Flags *f, int *argc, char ***argv)
{
	int c;

	f->pockets = 100;
	f->rounds = 10000;

	while ((c = getopt(*argc, *argv, "hm:n:")) != -1) {
		switch (c) {
		case 'n':
			f->pockets = atoi(optarg);
			break;
		case 'm':
			f->rounds = atoi(optarg);
			break;
		case 'h':
			usage(f);
			break;
		}
	}

	if (f->pockets <= 0)
		errx(1, "Invalid number of pockets");
	if (f->rounds <= 0)
		errx(1, "Invalid number of rounds");

	*argc -= optind;
	*argv += optind;
}

void
dump(Pocket *p, size_t n, unsigned id)
{
	Pocket *t;
	char b[64];
	size_t i;
	int l;

	l = log10(n) + 1;
	printf("ID: %u\n", id);
	for (i = 0; i < n; i++) {
		t = p + i;
		if (id == i)
			snprintf(b, sizeof(b), "->%*d", l, t->value);
		else
			snprintf(b, sizeof(b), "%*d", l, t->value);

		printf("%*s", l + 4, b);
		if ((i & 15) == 15)
			printf("\n");
	}
	printf("\n\n");
}

void *
run(void *ud)
{
	Pocket *l, *r, *t;
	int c;

	t = ud;
	l = t->links + mod(t->id - 1, t->nlinks);
	r = t->links + mod(t->id + 1, t->nlinks);

	for (;;) {
		c = *t->count;
		if (c >= t->rounds)
			break;

		pthread_mutex_lock(t->lock[0]);
		pthread_mutex_lock(t->lock[1]);

		pthread_mutex_lock(t->lock[2]);
		if (t->value < l->value && t->value < r->value)
			t->value++;
		else if (t->value > l->value && t->value > r->value)
			t->value--;
		*t->count += 1;
		t->runs += 1;

		dump(t->links, t->nlinks, t->id);
		pthread_mutex_unlock(t->lock[2]);

		pthread_mutex_unlock(t->lock[1]);
		pthread_mutex_unlock(t->lock[0]);
	}

	return NULL;
}

void
sim(int n, int m)
{
	pthread_attr_t a;
	pthread_mutex_t *l;
	Pocket *p, *t;
	atomic_int c;
	int i, r, *v;

	if (n <= 0 || m <= 0)
		return;

	p = xcalloc(n, sizeof(*p));
	l = xcalloc(n + 2, sizeof(*l));
	v = xcalloc(n, sizeof(*v));
	c = 0;

	for (i = 0; i < n + 2; i++)
		pthread_mutex_init(l + i, NULL);

	for (i = 0; i < n; i++)
		v[i] = i;
	shuffle(v, n);

	for (i = 0; i < n; i++) {
		t = p + i;
		t->id = i;
		t->value = v[i];
		t->lock[0] = l + i;
		t->lock[1] = l + i + 1;
		t->lock[2] = l + n + 1;

		t->links = p;
		t->nlinks = n;
		t->rounds = m;
		t->count = &c;
	}
	if (n > 1) {
		t = p + n - 1;
		t->lock[1] = t->lock[0];
		t->lock[0] = p->lock[0];
	}

	for (i = 0; i < n; i++) {
		t = p + i;

		r = pthread_attr_init(&a);
		if (r != 0)
			errx(1, "Failed to init attribute: %s", strerror(r));

		r = pthread_attr_setschedpolicy(&a, SCHED_RR);
		if (r != 0)
			errx(1, "Failed to set scheduler policy: %s", strerror(r));

		r = pthread_create(&t->thread, &a, run, t);
		if (r != 0)
			errx(1, "Failed to create thread: %s", strerror(r));
	}
	for (i = 0; i < n; i++) {
		t = p + i;
		pthread_join(t->thread, NULL);
	}
	for (i = 0; i < n; i++) {
		t = p + i;
		printf("Thread #%d: %d runs\n", t->id, t->runs);
	}

	free(p);
	free(l);
	free(v);
}

int
main(int argc, char *argv[])
{
	Flags f;

	srand(time(NULL));
	parseflags(&f, &argc, &argv);
	sim(f.pockets, f.rounds);

	return 0;
}
