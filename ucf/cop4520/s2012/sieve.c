#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <pthread.h>

// max primes
#define MAXPRIMES 100000

// max thread we are using
#define MAXTHREADS 5

// the work structure
// that each worker thread gets
typedef struct
{
	long prime;
} work_t;

// write output to this file
const char *outfile = "sieve.out";

// worker data for each threads
work_t workdata[MAXTHREADS];

// thread ids
pthread_t threads[MAXTHREADS];

// the main prime
char marked[MAXPRIMES + 1];

// the index in marked, keep this
// to know when to quit
long primepos = 2;

// we store generated primes in here
// to speed up finding next prime
long genprime[MAXTHREADS];
long genprimecnt;

// a lock for the prime generate
pthread_mutex_t primemutex;

// this is (sqrt(MAXPRIMES)+1)
long limit;

// generate the next prime for a worker
// thread so it can start working
void
genprimes(int id)
{
	long i, j;
	work_t *w;
	int prime;

	pthread_mutex_lock(&primemutex);

	// go from the current position to the sqrt(MAXPRIMES)+1
	w = &workdata[id];
	w->prime = 0;
	for (i = primepos; i <= limit; i++) {
		// if marked, then composite so continue
		if (marked[i])
			continue;

		// this is a test to see if the previous
		// generated primes divide with this one,
		// if it does, then we know its not a prime
		prime = 1;
		for (j = 0; j < genprimecnt; j++) {
			if ((i % genprime[j]) == 0) {
				marked[i] = 1;
				prime = 0;
				break;
			}
		}

		// found a prime
		if (prime) {
			genprime[genprimecnt] = w->prime = i;
			break;
		}
	}

	// save the current prime pos
	primepos = i + 1;
	genprimecnt = (genprimecnt + 1) % MAXTHREADS;

	pthread_mutex_unlock(&primemutex);
}

// the sieve to find the primes
void
sieve(long p)
{
	long i, step;

	if (p == 0)
		return;

	// mark off all the multiples of this number
	// until maxprimes
	step = p;
	for (i = p * p; i <= MAXPRIMES; i += step)
		marked[i] = 1;
}

// the worker thread
void *
workthread(void *u)
{
	int id;
	work_t *w;

	id = *(int *)u;
	w = &workdata[id];

	// while generate prime still give some prime
	while (w->prime) {
		// sieve, add it to marked
		sieve(w->prime);

		// generate more primes
		genprimes(id);
	}

	// done, kill the thread
	pthread_exit(NULL);
}

// main
int
main(int argc, char *argv[])
{
	FILE *fp;
	pthread_attr_t attr;
	long i;
	int failed;
	int id[MAXTHREADS];

	for (i = 0; i < MAXTHREADS; i++)
		id[i] = i;

	// if specified a file
	// use that instead of the default out file
	if (argc >= 2)
		outfile = argv[1];

	printf("Writing output to %s\n", outfile);

	// limit of the primes
	limit = sqrt(MAXPRIMES) + 1;

	// generate a few primes to get
	// ready to start the thread
	for (i = 0; i < MAXTHREADS; i++)
		genprimes(i);

	// init pthread attributes to default
	failed = pthread_attr_init(&attr);
	if (failed) {
		printf("pthread_attr_init: %s\n", strerror(errno));
		exit(1);
	}
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	failed = pthread_mutex_init(&primemutex, NULL);
	if (failed) {
		printf("pthread_mutex_init: %s\n", strerror(errno));
		exit(1);
	}
	// start the threads
	for (i = 0; i < MAXTHREADS; i++) {
		failed = pthread_create(&threads[i], NULL, workthread, &id[i]);
		if (failed) {
			printf("pthread_create: %s\n", strerror(errno));
			exit(1);
		}
	}

	// main thread then waits for all other threads
	// to finish
	// join with all the threads to finish
	for (i = 0; i < MAXTHREADS; i++)
		pthread_join(threads[i], NULL);

	// cleanup
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&primemutex);

	// write to file, if we can't
	// print why
	fp = fopen(outfile, "wt");
	if (!fp) {
		printf("%s\n", strerror(errno));
		exit(1);
	}

	// write it
	for (i = 2; i <= MAXPRIMES; i++) {
		if (!marked[i])
			fprintf(fp, "%ld\n", i);
	}
	fprintf(fp, "\n");

	if (fp)
		fclose(fp);

	return 0;
}
