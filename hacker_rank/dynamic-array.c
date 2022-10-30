/*

Create a list, seqList, of N empty sequences, where each sequence is indexed from 0 to N-1.
The elements within each of the sequences also use 0-indexing.

Create an integer, lastAnswer, and initialize it to 0.

The 2 types of queries that can be performed on your list of sequences (seqList) are described below:

1.
    Query: 1 x y
    	1. Find the sequence, seq, at index ((x ^ lastAnswer) % N) in seqList
	2. Append integer y to sequence seq

2.
    Query: 2 x y
    	1. Find the sequence, seq, at index ((x ^ lastAnswer) % N) in seqList
	2. Find the value of element (y % size) in seq (where size is the size of seq) and assign it to lastAnswer
	3. Print the new value of lastAnswer on the new line


Given N, Q, and Q queries, execute each query.

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	assert(p);
	return p;
}

void *
xrealloc(void *ptr, size_t size)
{
	void *p;

	p = realloc(ptr, size);
	assert(p);
	return p;
}

void
run(size_t N, const char **Q)
{
	unsigned op, x, y, a, **s;
	size_t i, j, *n;

	s = xcalloc(N, sizeof(*s));
	n = xcalloc(N, sizeof(*n));
	a = 0;

	for (i = 0; Q[i]; i++) {
		if (sscanf(Q[i], "%u %u %u", &op, &x, &y) != 3)
			continue;

		j = (x ^ a) % N;
		switch (op) {
		case 1:
			s[j] = xrealloc(s[j], (n[j] + 1) * sizeof(*(s[j])));
			s[j][n[j]++] = y;
			break;
		case 2:
			a = s[j][y % n[j]];
			printf("%u\n", a);
			break;
		}
	}

	for (i = 0; i < N; i++)
		free(s[i]);
	free(s);
	free(n);
}

int
main(void)
{
	const char *Q[] = {
	    "1 0 5",
	    "1 1 7",
	    "1 0 3",
	    "2 1 0",
	    "2 1 1",
	    NULL,
	};
	run(2, Q);
	return 0;
}
