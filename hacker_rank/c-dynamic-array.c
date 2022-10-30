/*

Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:

1 x y : Insert a book with  pages at the end of the xth shelf.

2 x y : Print the number of pages in the yth book on the xth shelf.

3 x : Print the number of books on the xth shelf.

Snow Howler has got an assistant, Oshie, provided by the Department of Education. Although inexperienced, Oshie can handle all of the queries of types 2 and 3.

Help Snow Howler deal with all the queries of type 1.

Oshie has used two arrays:


Help Snow Howler deal with all the queries of type 1.

Oshie has used two arrays:

int* total_number_of_books;
int** total_number_of_pages;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
execute(const char **q, size_t s)
{
	size_t i;
	int op, x, y, n, ret;
	int *b, **p, *rp;

	ret = 0;
	b = calloc(s, sizeof(*b));
	p = calloc(s, sizeof(*p));
	if (b == NULL || p == NULL)
		goto error;

	for (i = 0; q[i] != NULL; i++) {
		op = q[i][0];
		if ((n = sscanf(&q[i][1], "%d %d", &x, &y)) < 1)
			continue;

		if (x >= s)
			continue;

		switch (op) {
		case '1':
			rp = realloc(p[x], ++b[x] * sizeof(**p));
			if (rp == NULL)
				goto error;
			p[x] = rp;
			p[x][b[x] - 1] = y;
			break;
		case '2':
			if (n < 2 || y >= b[x])
				break;
			printf("%d\n", p[x][y]);
			break;
		case '3':
			printf("%d\n", b[x]);
			break;
		}
	}
out:
	free(b);
	for (i = 0; i < s; i++)
		free(p[i]);
	free(p);

	return ret;

error:
	ret = -1;
	goto out;
}

int
main(void)
{
	const char *q1[] = {
	    "1 0 15",
	    "1 0 20",
	    "1 2 78",
	    "2 2 0",
	    "3 0",
	    NULL,
	};
	execute(q1, 5);
	return 0;
}
