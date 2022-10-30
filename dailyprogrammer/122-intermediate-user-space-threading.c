/*

This challenge is more coding-focused than maths-focused.

Threading, one after another, that it gives users a perception of code running in parallel.
It is essentially a light-weight process that can be launched, managed, or terminated by the owning process.

Your goal is to implement an efficient and dynamic user-level threading library.
You may implement this in any language and on any platform, but you may not use any existing threading code or implementation, such as the Win32 threading code or the UNIX pthreads lib.
You may call system functions (such as interrupts and signals), but again cannot defer any thread-specific work to the operating system.

The term efficient means that when switching the thread of execution, you must do so as quickly as possible (big bonus points for actually measuring this).
The term dynamic means that you provide a way (through either static variables, functions, config file, etc.) to allow end-users to change how fast you switch and what kind of algorithm you use for timing.

To help you get started, try to implement the following functions: (written in C-style for clarity)

ThreadID CreateThread( void (threadFunction)(void) ) // Returns a positive, non-zero, thread ID on success. Returns 0 on failure. Starts a thread of execution of the given thread function (for those confused, this is a C-style function being passed as an argument)

bool DestroyThread( ThreadID givenThreadId ) // Destroys a thread of execution, based on the given thread ID

Please direct questions about this challenge to /u/nint22

Subreddit news: We (the mods) are actively working on new submissions and fixing the bot so that it posts more correctly and consistently.
The next few challenges will be directly related to new subreddit features that we want to the community to try and solve with us :-)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ucontext.h>
#include <err.h>

enum {
	MAX_THREADS = 128,
	STACKSIZE = 4 * 1024 * 1024,
};

typedef struct Thread Thread;

struct Thread {
	ucontext_t ucs;
	ucontext_t uct;
	int status;
	int code;
	char stack[];
};

Thread *threads[MAX_THREADS];
size_t nthreads;

void
threadlaunch(Thread *t, int (*f)(), void *ud)
{
	t->code = f(t, ud);
	t->status = 1;
	swapcontext(&t->uct, &t->ucs);
}

int
threadcreate(int (*f)(), void *ud)
{
	void (*launch)();
	Thread *t;
	ucontext_t *uc;

	if (nthreads >= MAX_THREADS)
		return -1;

	t = calloc(1, sizeof(*t) + STACKSIZE);
	if (!t)
		return -1;

	uc = &t->uct;
	if (getcontext(uc) < 0) {
		free(t);
		return -1;
	}

	uc->uc_stack.ss_sp = t->stack;
	uc->uc_stack.ss_size = STACKSIZE;
	uc->uc_link = NULL;

	launch = threadlaunch;
	makecontext(uc, launch, 3, t, f, ud);

	threads[nthreads++] = t;
	return 0;
}

void
threadyield(Thread *t)
{
	swapcontext(&t->uct, &t->ucs);
}

void
sched(void)
{
	Thread *t;
	size_t i, n, p;

	p = 0;
	for (;;) {
		for (i = 0; i < nthreads; i++)
			getcontext(&threads[i]->ucs);

		n = 0;
		for (i = 0; i < nthreads; i++) {
			if (p >= nthreads)
				p = 0;

			t = threads[p++];
			if (t->status == 0)
				swapcontext(&t->ucs, &t->uct);
			else
				n++;
		}
		if (n >= nthreads)
			break;
	}
}

int
runner(Thread *t, void *ud)
{
	int i, n;

	n = (int)(uintptr_t)ud;
	for (i = 1; i <= 10; i++) {
		printf("thread #%d: %d\n", n, i);
		threadyield(t);
	}
	return 0;
}

int
main(void)
{
	uintptr_t i;

	for (i = 1; i <= 10; i++) {
		if (threadcreate(runner, (void *)i) < 0)
			errx(1, "Failed to create thread");
	}

	sched();

	return 0;
}
