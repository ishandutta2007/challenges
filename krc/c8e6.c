// The standard library function calloc(n, size) returns a pointer to
// n objects of size size, with storage initialized to zero.
// Write calloc, by calling malloc or modifying it.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>

#define MUL_NO_OVERFLOW (1ull << (sizeof(size_t) * 4))

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (nmemb == 0)
		nmemb = 1;
	if (size == 0)
		size = 1;

	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && SIZE_MAX / nmemb < size) {
		errno = ENOMEM;
		return NULL;
	}

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return NULL;
	memset(ptr, 0, nmemb * size);

	return ptr;
}

int
main(void)
{
	int *p;
	size_t i;

	srand(time(NULL));
	for (i = 0; i < 256; i++) {
		p = xcalloc(rand() & 0xffff, sizeof(int));
		free(p);
	}
	return 0;
}
