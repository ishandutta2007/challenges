/*

An anonymous user on world4ch's programming text board posted a thread in early 2011 in which he describes an ingenious O(n) sorting algorithm.
This means it's, supposedly, more efficient than any sorting algorithm ever invented. Some bloggers picked up on it, and dubbed the algorithm sleep sort:

#!/bin/bash
function f() {
    sleep "$1"
    echo "$1"
}
while [ -n "$1" ]
do
    f "$1" &
    shift
done
wait

This program takes some command line arguments, like ./sleepsort.sh 3 1 4 1 5 9, and starts a new [thread](http://en.wikipedia.org/wiki/Thread_(computing)) for each number in the list, which first sleeps for n seconds, then prints n.
After 1 second, both 1s are printed, then after 2 more seconds the 3 follows, etc. Because it only loops through the list of numbers once, the algorithm appears to run in linear time.

Your task is to re-implement sleep sort in a language of your choice (which might look trivial, but this challenge is all about learning how your language handles multithreading.)

BONUS: at first glance, this algorithm appears to be O(n). Can you prove this isn't true? (This bonus requires some knowledge of both algorithms and concurrency.)

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>

void
usage(void)
{
	fprintf(stderr, "usage: number ...\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	int i, n;

	if (argc < 2)
		usage();

	for (i = 1; i < argc; i++) {
		switch (fork()) {
		case -1:
			err(1, "fork");
			break;

		case 0:
			n = atoi(argv[i]);
			sleep(n);
			printf("%d\n", n);
			exit(0);
			break;
		}
	}

	while (wait(NULL) >= 0)
		;

	return 0;
}
