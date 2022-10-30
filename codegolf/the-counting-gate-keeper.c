/*

Related as it requires you to measure the time between the first and last input. But here you're required to count how many inputs in a period of time.

I was assigned a task to stand by a gate and count how many students enter it. The problem is that my memory is not as good as it was when I first started this job. I need some kind of program to help me count how many students enter the gate until my shift is over.

Task
Given an integer t that represents the number of seconds until my shift is over. Tell me how many times I pressed the button during that time.

Rules
The button press can be any convenient user input, such as pressing the Return key;
You can assume that t will allways be in range [1; 60];
You can assume that the number of students will be less than 231;
When the time is up, you must output within 1 second;
Your program does not need to end, as long as the only output to stdout is at the end of the shift;
If your input method (such as Enter-key) repeats if held, you can choose to count it just once, or several times. Either way, you must still be able to handle separate inputs.

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef unsigned long long uvlong;

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
	fprintf(stderr, "usage: <seconds>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	uvlong n;
	int c, s;

	if (argc < 2)
		usage();

	signal(SIGALRM, sighandle);
	signal(SIGINT, sighandle);

	s = atoi(argv[1]);
	if (s < 0)
		usage();

	alarm(s);

	n = 0;
	while (!quit) {
		c = fgetc(stdin);
		if (c == EOF)
			break;
		if (c == '\n')
			n++;
	}
	printf("%llu\n", n);

	return 0;
}
