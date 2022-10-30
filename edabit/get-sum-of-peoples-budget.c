/*

Create the function that takes an array with objects and returns the sum of people's budgets.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	unsigned age;
	unsigned long budget;
} Person;

unsigned long
budget(Person *p, size_t n)
{
	unsigned long b;
	size_t i;

	b = 0;
	for (i = 0; i < n; i++)
		b += p[i].budget;
	return b;
}

int
main(void)
{
	Person p1[] = { { "John", 21u, 23000ul }, { "Steve", 32u, 40000ul }, { "Martin", 16u, 2700ul } };
	Person p2[] = { { "John", 21u, 29000ul }, { "Steve", 32u, 32000ul }, { "Martin", 16u, 1600ul } };
	Person p3[] = { { "John", 21u, 19401ul }, { "Steve", 32u, 12321ul }, { "Martin", 16u, 1204ul } };
	Person p4[] = { { "John", 21u, 10234ul }, { "Steve", 32u, 21754ul }, { "Martin", 16u, 4935ul } };

	assert(budget(p1, nelem(p1)) == 65700ul);
	assert(budget(p2, nelem(p2)) == 62600ul);
	assert(budget(p3, nelem(p3)) == 32926ul);
	assert(budget(p4, nelem(p4)) == 36923ul);

	return 0;
}
