/*

Write a program which runs forever and allocates more and more memory on the heap the longer it runs, at least until you reach the limit of the operating system on the amount of memory that can be allocated.

Many kernels won't actually reserve memory you allocate until you use it for something, so if your program is in C or some other low level language you'll have to make sure you write something to each page.
If you're using an interpreted language, you're probably not going to have to worry about this.

Shortest code wins.

*/

#include <stdio.h>
#include <stdlib.h>

void
memstress(size_t size)
{
	char *p;
	size_t i;

	for (;;) {
		p = malloc(size);
		if (!p)
			break;

		for (i = 0; i < size; i++)
			p[i] = i & 0xff;
	}
}

int
main(void)
{
	memstress(4 * 1024 * 1024);

	return 0;
}
