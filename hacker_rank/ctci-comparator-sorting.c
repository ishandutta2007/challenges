/*

Comparators are used to compare two objects. In this challenge, you'll create a comparator and use it to sort an array.
The Player class is provided in the editor below. It has two fields:

name:  a string.

score: an integer.

Given an array of n Player objects, write a comparator that sorts them in order of decreasing score. If or more players have the same score,
sort those players alphabetically ascending by name. To do this, you must create a Checker class that implements the Comparator interface,
then write an int compare(Player a, Player b) method implementing the
Comparator.compare(T o1, T o2) method. In short, when sorting in ascending order, a comparator function returns if -1 a < b, 0 if a = b, and 1 if a < b. 

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[256];
	int score;
} Player;

int
cmp(const void *a, const void *b)
{
	const Player *p = a;
	const Player *q = b;
	if (p->score == q->score)
		return strcmp(p->name, q->name);
	if (p->score > q->score)
		return -1;
	return 1;
}

void
order(Player *p, size_t n)
{
	size_t i;
	qsort(p, n, sizeof(*p), cmp);
	for (i = 0; i < n; i++)
		printf("%s %d\n", p[i].name, p[i].score);
}

int
main(void)
{
	Player a[] = {
	    {"amy", 100},
	    {"david", 100},
	    {"heraldo", 50},
	    {"aakansha", 75},
	    {"aleksa", 150},
	};
	order(a, nelem(a));
	return 0;
}
