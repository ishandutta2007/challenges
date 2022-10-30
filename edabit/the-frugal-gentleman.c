/*

Atticus has been invited to a dinner party, and he decides to purchase a bottle of wine.
However, he has little knowledge of how to choose a good bottle. Being a very frugal gentleman (yet disliking looking like a cheapskate),
he decides to use a very simple rule. In any selection of two or more wines, he will always buy the second-cheapest.

Given an array of wine objects, write a function that returns the name of the wine he will buy for the party.
If given an empty array, return null. If given an array of only one, Atticus will buy that wine.

Examples

chosenWine([
  { name: "Wine A", price: 8.99 },
  { name: "Wine 32", price: 13.99 },
  { name: "Wine 9", price: 10.99 }
]) ➞ "Wine 9"

chosenWine([{ name: "Wine A", price: 8.99 }]) ➞ "Wine A"

chosenWine([]) ➞ null

Notes

All wines will be different prices, so there is no confusion in the ordering.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *name;
	double price;
} Wine;

const char *
choosewine(Wine *w, size_t n)
{
	size_t i, x, y;

	if (n == 0)
		return NULL;
	if (n == 1)
		return w[0].name;

	x = y = 0;
	for (i = 1; i < n; i++) {
		if (w[y].price > w[i].price) {
			x = y;
			y = i;
		} else if (x == y || (w[y].price < w[i].price && w[i].price < w[x].price))
			x = i;
	}
	return w[x].name;
}

void
test(Wine *w, size_t n, const char *t)
{
	const char *s;

	s = choosewine(w, n);
	if (t == NULL)
		assert(s == t);
	else
		assert(!strcmp(s, t));
}

int
main(void)
{
	Wine w1[] = {
	    {"Wine A", 8.99},
	    {"Wine 32", 13.99},
	    {"Wine 9", 10.99},
	};
	Wine w2[] = {
	    {"Wine A", 8.99},
	    {"Wine B", 9.99},
	};
	Wine w3[] = {
	    {"Wine A", 8.99},
	    {"Wine 389", 109.99},
	    {"Wine 44", 38.44},
	    {"Wine 72", 22.77},
	};

	test(w1, nelem(w1), "Wine 9");
	test(w2, nelem(w2), "Wine B");
	test(w2, 1, "Wine A");
	test(w2, 0, NULL);
	test(w3, nelem(w3), "Wine 72");

	return 0;
}
