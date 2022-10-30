/*

Standard competition ranking (also known as "1224" ranking) assigns the same rank to matching values. Rank numbers are increased each time, so ranks are sometimes skipped. If we have 5 scores (the highest score having a rank of 1):

No matching values:

Scores = [99, 98, 97, 96, 95]
Rank = 1,  2,  3,  4,  5

With matching values:

Scores = [99, 98, 98, 96, 95]
Rank = 1,  2,  2,  4,  5

// Second and third scores are equal, so rank "3" is skipped.

Given an object containing the names and scores of 5 competitors, and a competitor name, return the rank of that competitor after applying competition ranking.
Examples

competition_rank({
  George: 96,
  Emily: 95,
  Susan: 93,
  Jane: 89,
  Brett: 82
  }, "Jane") ➞ 4

competition_rank({
  Kate: 92,
  Carol: 92,
  Jess: 87,
  Bruce: 87,
  Scott: 84
  }, "Bruce") ➞ 3

Notes

The highest score has a rank value of 1.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	unsigned score;
} Competitor;

int
cmp(const void *a, const void *b)
{
	const Competitor *p, *q;

	p = a;
	q = b;
	if (p->score > q->score)
		return -1;
	if (p->score == q->score)
		return 0;
	return 1;
}

size_t
rank(Competitor *c, size_t n, const char *s)
{
	size_t i, j;

	qsort(c, n, sizeof(*c), cmp);
	for (i = j = 0; i < n; i++) {
		if (!strcmp(s, c[i].name))
			break;
		if (i + 1 < n && c[i].score != c[i + 1].score)
			j = i + 1;
	}

	return (i < n) ? j + 1 : SIZE_MAX;
}

int
main(void)
{
	Competitor c1[] = {
		{ "Aria", 90 },
		{ "Brooke", 90 },
		{ "Olivia", 90 },
		{ "Eve", 74 },
		{ "Ellie", 87 },
	};
	Competitor c2[] = {
		{ "Ryan", 97 },
		{ "Thomas", 85 },
		{ "Kai", 95 },
		{ "Aiden", 87 },
		{ "Logan", 90 },
	};
	Competitor c3[] = {
		{ "Lilly", 91 },
		{ "Harris", 87 },
		{ "Archie", 93 },
		{ "Lexi", 100 },
		{ "Ava", 88 },
	};
	Competitor c4[] = {
		{ "Jayden", 90 },
		{ "Josh", 90 },
		{ "Rebecca", 96 },
		{ "Jack", 89 },
		{ "Max", 96 },
	};
	Competitor c5[] = {
		{ "Ben", 78 },
		{ "Quinn", 84 },
		{ "Lena", 84 },
		{ "Isla", 92 },
		{ "Kayla", 72 },
	};
	Competitor c6[] = {
		{ "Lucy", 81 },
		{ "Ella", 90 },
		{ "Summer", 91 },
		{ "Harper", 81 },
		{ "Sadie", 85 },
	};
	Competitor c7[] = {
		{ "Cole", 96 },
		{ "Carson", 92 },
		{ "Gabriel", 91 },
		{ "Hollie", 97 },
		{ "Penelope", 85 },
	};
	Competitor c8[] = {
		{ "Michael", 89 },
		{ "Noah", 98 },
		{ "Reuben", 88 },
		{ "Sam", 91 },
		{ "Mia", 91 },
	};
	Competitor c9[] = {
		{ "James", 93 },
		{ "Maria", 91 },
		{ "Lewis", 95 },
		{ "Joseph", 96 },
		{ "Imogen", 90 },
	};
	Competitor c10[] = {
		{ "Jessica", 90 },
		{ "Emily", 99 },
		{ "Hope", 91 },
		{ "Charlie", 96 },
		{ "Lucas", 87 },
	};
	Competitor c11[] = {
		{ "Sophie", 86 },
		{ "Piper", 98 },
		{ "Elliot", 100 },
		{ "Erica", 90 },
		{ "Freya", 100 },
	};
	Competitor c12[] = {
		{ "Grace", 93 },
		{ "Henry", 90 },
		{ "Florence", 98 },
		{ "Millie", 89 },
		{ "David", 99 },
	};
	Competitor c13[] = {
		{ "Alfie", 90 },
		{ "Elijah", 90 },
		{ "Cara", 85 },
		{ "Isaac", 96 },
		{ "Bella", 92 },
	};
	Competitor c14[] = {
		{ "Clara", 85 },
		{ "Matilda", 86 },
		{ "Amelia", 98 },
		{ "Oliver", 95 },
		{ "Adam", 94 },
	};
	Competitor c15[] = {
		{ "Nina", 81 },
		{ "Tommy", 79 },
		{ "Tyler", 84 },
		{ "Leo", 79 },
		{ "Hallie", 79 },
	};
	Competitor c16[] = {
		{ "Violet", 99 },
		{ "Finn", 100 },
		{ "Eden", 99 },
		{ "Frankie", 98 },
		{ "Rory", 98 },
	};
	Competitor c17[] = {
		{ "Robbie", 70 },
		{ "Julia", 76 },
		{ "Owen", 70 },
		{ "Phoebe", 92 },
		{ "Jacob", 79 },
	};
	Competitor c18[] = {
		{ "Andrew", 95 },
		{ "Louis", 95 },
		{ "Riley", 95 },
		{ "Amy", 95 },
		{ "Charlotte", 95 },
	};
	Competitor c19[] = {
		{ "Harry", 81 },
		{ "Elsie", 81 },
		{ "Grayson", 84 },
		{ "John", 84 },
		{ "Alex", 81 },
	};
	Competitor c20[] = {
		{ "Innes", 76 },
		{ "Lola", 85 },
		{ "Anna", 92 },
		{ "Cooper", 93 },
		{ "Daniel", 93 },
	};

	assert(rank(c1, nelem(c1), "Ellie") == 4);
	assert(rank(c2, nelem(c2), "Logan") == 3);
	assert(rank(c3, nelem(c3), "Lilly") == 3);
	assert(rank(c4, nelem(c4), "Rebecca") == 1);
	assert(rank(c5, nelem(c5), "Ben") == 4);
	assert(rank(c6, nelem(c6), "Ella") == 2);
	assert(rank(c7, nelem(c7), "Hollie") == 1);
	assert(rank(c8, nelem(c8), "Mia") == 2);
	assert(rank(c9, nelem(c9), "Lewis") == 2);
	assert(rank(c10, nelem(c10), "Hope") == 3);
	assert(rank(c11, nelem(c11), "Freya") == 1);
	assert(rank(c12, nelem(c12), "Henry") == 4);
	assert(rank(c13, nelem(c13), "Elijah") == 3);
	assert(rank(c14, nelem(c14), "Clara") == 5);
	assert(rank(c15, nelem(c15), "Nina") == 2);
	assert(rank(c16, nelem(c16), "Frankie") == 4);
	assert(rank(c17, nelem(c17), "Owen") == 4);
	assert(rank(c18, nelem(c18), "Charlotte") == 1);
	assert(rank(c19, nelem(c19), "Elsie") == 3);
	assert(rank(c20, nelem(c20), "Cooper") == 1);

	return 0;
}
