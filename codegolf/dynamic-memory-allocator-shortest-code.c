/*

Given an integer n as input, write a function that dynamically allocates n bytes and returns their address.

Rules
The allocator must be able to dynamically allocate memory at runtime.
It doesn't matter where the memory is allocated to or in what form, as long as it's allocated in a valid location which can be read from and written to.
Allocated memory locations must be unique and not override or cross already-allocated locations.
You don't have to write the code in a way such that the memory can be deallocated later.
It might be obvious, but you are not allowed to use a programming language's or standard library's built in allocator. For example, making a function return the result of malloc or new is not a valid solution.
You don't need to worry about out-of-memory errors. Assume big amounts of memory are never allocated.
Efficiency and speed are not a factor. The only requirement for the challenge is the shortest code, in bytes.
Standard loopholes are not allowed.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *
alloc(size_t size)
{
	void *p;

	p = sbrk(size);
	if (p == (void *)-1)
		return NULL;
	return p;
}

void
test(size_t size, size_t iterations)
{
	unsigned char *p;
	size_t i, j;

	for (i = 0; i < iterations; i++) {
		p = alloc(size);
		if (!p)
			abort();

		memset(p, 0x34, size);
		for (j = 0; j < size; j++)
			assert(p[j] == 0x34);
	}
}

int
main(void)
{
	test(1024, 10000);
	test(5123, 2045);

	return 0;
}
