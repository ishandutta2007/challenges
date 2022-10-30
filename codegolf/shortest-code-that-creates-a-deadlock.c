/*

Write the shortest code to create a deadlock. Code execution must halt, so this doesn't work:

public class DeadlockFail extends Thread{ //Java code
    public static void main(String[]a){
        Thread t = new DeadlockFail();
        t.start();
        t.join();
    }
    //this part is an infinite loop; continues running the loop. 
    public void run(){while(true){}}
}

It doesn't need to be certain that the code goes into deadlock, just almost surely (if you run for infinite time, it will deadlock).

*/

#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
	pthread_t thread[3];
	pthread_mutex_t mutex[2];
	atomic_int rid;
	atomic_ullong counter;
} Context;

typedef struct {
	Context *context;
	int il;
	int id;
} Runner;

void
initctx(Context *c)
{
	memset(c, 0, sizeof(*c));
	c->mutex[0] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	c->mutex[1] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
}

void *
watcher(void *ud)
{
	Context *c;

	c = ud;
	c->rid = 0;
	for (;;) {
		printf("%llu\n", c->counter);
		sleep(1);
		if (c->rid != 3) {
			printf("DEADLOCK!\n");
			exit(0);
		}
		c->rid = 0;
	}
	return NULL;
}

void *
runner(void *ud)
{
	Runner *r;
	Context *c;

	r = ud;
	c = r->context;
	for (;;) {
		pthread_mutex_lock(&c->mutex[r->il]);
		pthread_mutex_lock(&c->mutex[(r->il + 1) & 1]);
		c->counter++;
		c->rid |= (1 << r->id);
		pthread_mutex_unlock(&c->mutex[r->il]);
		pthread_mutex_unlock(&c->mutex[(r->il + 1) & 1]);
	}

	return NULL;
}

void
runctx(Context *c, int deadlock)
{
	int i;

	pthread_create(&c->thread[0], NULL, runner, &(Runner){c, 0, 0});
	pthread_create(&c->thread[1], NULL, runner, &(Runner){c, !!deadlock, 1});
	pthread_create(&c->thread[2], NULL, watcher, c);
	for (i = 0; i < 3; i++)
		pthread_join(c->thread[i], NULL);
}

int
main(void)
{
	Context ctx;

	initctx(&ctx);
	runctx(&ctx, 1);

	return 0;
}
