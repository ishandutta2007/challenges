/*

Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}

The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seems to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int val;
} Order;

typedef struct {
	Order *ord;
	void (*func)(void);
	int val;
} Closure;

void
millisleep(long ms)
{
	struct timespec tp;

	tp.tv_sec = ms / 1000;
	tp.tv_nsec = (ms % 1000) * 1000000;
	nanosleep(&tp, NULL);
}

void
first(void)
{
	printf("first");
}

void
second(void)
{
	printf("second");
}

void
third(void)
{
	printf("third");
}

void
ordinit(Order *o)
{
	pthread_mutex_init(&o->mutex, NULL);
	pthread_cond_init(&o->cond, NULL);
	o->val = 1;
}

void *
orddo(void *a)
{
	Closure *c;
	Order *o;

	c = a;
	o = c->ord;
	pthread_mutex_lock(&o->mutex);
	while (c->val != o->val)
		pthread_cond_wait(&o->cond, &o->mutex);
	c->func();
	o->val++;
	pthread_cond_broadcast(&o->cond);
	pthread_mutex_unlock(&o->mutex);
	return NULL;
}

void
shuffle(Closure *c, size_t n)
{
	Closure t;
	size_t i, j;

	if (n == 0)
		return;

	for (i = n - 1; i >= 1; i--) {
		j = rand() % (i + 1);
		t = c[i];
		c[i] = c[j];
		c[j] = t;
	}
}

int
main(void)
{
	Order ord;
	Closure ctab[] = {
	    {&ord, first, 1},
	    {&ord, second, 2},
	    {&ord, third, 3},
	};
	pthread_t thread[nelem(ctab)];
	size_t i;

	srand(time(NULL));
	for (;;) {
		ordinit(&ord);
		shuffle(ctab, nelem(ctab));

		for (i = 0; i < nelem(ctab); i++) {
			pthread_create(&thread[i], NULL, orddo, &ctab[i]);
			millisleep(10);
		}
		for (i = 0; i < nelem(ctab); i++)
			pthread_join(thread[i], NULL);
		printf("\n");
	}
	return 0;
}
