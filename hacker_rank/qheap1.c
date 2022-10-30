/*

This question is designed to help you get a better understanding of basic heap operations. 
You will be given queries of  types:

"1 v" - Add an element  to the heap.
"2 v" - Delete the element  from the heap.
"3" - Print the minimum of all the elements in the heap.
NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any instant, only distinct elements will be in the heap.

*/

/*

https://www.cs.cmu.edu/~tcortina/15-121sp10/Unit06B.pdf
http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/heap-delete.html

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Heap Heap;

struct Heap {
	size_t i;
	size_t n;
	int a[];
};

void
swap(int *x, int *y)
{
	int z;

	z = *y;
	*y = *x;
	*x = z;
}

int
ispow2(int v)
{
	return (v & (v - 1)) == 0;
}

Heap *
hnew(void)
{
	static const size_t N = 32;
	Heap *h;

	h = calloc(1, sizeof(*h) + sizeof(*h->a) * N);
	h->n = N;
	if (!h)
		abort();
	return h;
}

int
hmin(Heap *h)
{
	return h->a[1];
}

int
hmax(Heap *h)
{
	return h->a[h->i];
}

void
hup(Heap *h, size_t i)
{
	size_t j;

	for (;;) {
		j = i / 2;
		if (j == 0)
			break;

		if (h->a[i] < h->a[j])
			swap(&h->a[i], &h->a[j]);
		else
			break;
	}
}

void
hdown(Heap *h, size_t i)
{
	size_t j, l, r;

	for (;;) {
		l = 2 * i;
		r = 2 * i + 1;
		j = l;
		if (r <= h->i && h->a[r] < h->a[l])
			j = r;
		if (j <= h->i)
			swap(&h->a[j], &h->a[i]);
		else
			break;
		i = j;
	}
}

void
heapify(Heap *h, size_t i)
{
	size_t j;

	j = i / 2;
	if (j == 0 || h->a[i] > h->a[j])
		hdown(h, i);
	else
		hup(h, i);
}

Heap *
hinsert(Heap *h, int v)
{
	if (++h->i >= h->n) {
		h = realloc(h, sizeof(*h) + sizeof(*h->a) * h->n * 2);
		if (h == NULL)
			abort();
		h->n *= 2;
	}

	h->a[h->i] = v;
	heapify(h, h->i);

	return h;
}

size_t
hfind(Heap *h, int v)
{
	size_t i;

	for (i = 1; i <= h->i; i++) {
		if (v == h->a[i])
			return i;
	}

	return SIZE_MAX;
}

Heap *
hdelete(Heap *h, int v)
{
	size_t i;

	i = hfind(h, v);
	if (i == SIZE_MAX)
		return h;

	h->a[i] = h->a[h->i--];
	heapify(h, i);

	return h;
}

int
hpop(Heap *h)
{
	if (h->i < 1)
		return INT_MIN;
	h->a[1] = h->a[h->i--];
	heapify(h, 1);
}

int
hpopl(Heap *h)
{
	if (h->i < 1)
		return INT_MIN;
	return h->a[h->i--];
}

void
hfree(Heap *h)
{
	free(h);
}

void
hdump(Heap *h)
{
	size_t i;

	for (i = 1; i <= h->i; i++) {
		printf("%d ", h->a[i]);
		if (ispow2(i + 1))
			printf("\n");
	}
	printf("\n\n");
}

void
run(const char **ins)
{
	Heap *h;
	size_t i;
	int op;

	printf("running\n");
	h = hnew();
	for (i = 0; ins[i]; i++) {
		op = ins[i][0];
		switch (op) {
		case '1':
			h = hinsert(h, atoi(&ins[i][1]));
			break;
		case '2':
			h = hdelete(h, atoi(&ins[i][1]));
			break;
		case '3':
			printf("%d\n", hmin(h));
			break;
		case '4':
			hdump(h);
			break;
		}
	}
	hfree(h);
	printf("\n\n");
}

int
main(void)
{
	const char *i1[] = {
	    "1 4",
	    "1 9",
	    "3",
	    "2 4",
	    "3",
	    NULL,
	};
	run(i1);

	const char *i2[] = {
	    "1 1",
	    "1 5",
	    "1 6",
	    "1 9",
	    "1 11",
	    "1 8",
	    "1 15",
	    "1 17",
	    "1 21",
	    "4",
	    "2 5",
	    "4",
	    NULL,
	};
	run(i2);

	return 0;
}
