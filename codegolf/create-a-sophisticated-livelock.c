/*

The point of the puzzle is to learn about livelocks:

Create a multi-threaded (or a multi-process) program, whose threads (processes) indefinitely try to wait for each other and never finish.
Unlike a deadlock situation, the state of threads (processes) in a livelock constantly change as they try to resolve the situation, but never succeeding.

The task isn't to create a shortest or a simplest solution. Try to create a solution that resembles a real situation, something that looks like a genuine piece of code, but with some kind of an error that creates the livelock.

This is a popularity contest. The most up-voted answer in ~10 days wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdatomic.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>

typedef struct {
	pthread_mutex_t mutex;
	atomic_int locked;
} Lock;

typedef struct {
	pthread_t tid;
	int id;
	Lock *la;
	Lock *lb;
	unsigned cnt;
} Context;

void
lockinit(Lock *l)
{
	pthread_mutex_init(&l->mutex, NULL);
	l->locked = 0;
}

void
lock(Lock *l)
{
	l->locked = 1;
	pthread_mutex_lock(&l->mutex);
}

void
unlock(Lock *l)
{
	pthread_mutex_unlock(&l->mutex);
	l->locked = 0;
}

void *
run(void *ud)
{
	Context *c;
	Lock *la, *lb;
	struct timespec tp;

	tp.tv_sec = 0;
	tp.tv_nsec = 10000;

	c = ud;
	la = c->la;
	lb = c->lb;
	for (;;) {
		lock(la);
		while (lb->locked) {
			unlock(la);
			nanosleep(&tp, NULL);
			lock(la);
		}
		lock(lb);

		printf("%d: %u\n", c->id, c->cnt++);

		unlock(lb);
		unlock(la);
	}

	return NULL;
}

void
contextinit(Context *c, Lock *la, Lock *lb, int id)
{
	c->la = la;
	c->lb = lb;
	c->id = id;
	c->cnt = 0;
	pthread_create(&c->tid, NULL, run, c);
}

int
main(void)
{
	Lock la, lb;
	Context ca, cb;

	lockinit(&la);
	lockinit(&lb);

	contextinit(&ca, &la, &lb, 0);
	contextinit(&cb, &lb, &la, 1);

	pthread_join(ca.tid, NULL);
	pthread_join(cb.tid, NULL);

	return 0;
}
