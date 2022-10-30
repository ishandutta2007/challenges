/*

You just returned home to find your mansion has been robbed! Given an object of the stolen items, return the total amount of the burglary (number). If nothing was robbed, return the string "Lucky you!".
Examples

const stolenItems = {
  tv: 30,
  skate: 20,
  stereo: 50,
} ➞ 100

const stolenItems = {
  painting: 20000,
} ➞ 20000

const stolenItems = {} ➞ "Lucky you!"

Notes

The item value is always positive.
This is my first experience in creating a challenge. I started to learn testing so I decided to give it a go here at Edabit as well. Hope I did it right... Suggestions are very welcome!
This series is part of a collection that focuses on objects. If you are interested in following the breath-taking narrative skills
of yours truly or just do some object focused challenges (the challenges are ordered in ascending difficulty order), you can more easily do that there.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	unsigned long value;
} Item;

unsigned long
losses(Item *it, size_t n)
{
	unsigned long v;
	size_t i;

	v = 0;
	for (i = 0; i < n; i++)
		v += it[i].value;
	return v;
}

int
main(void)
{
	Item i1[] = {
	    {"tv", 30},
	    {"skate", 20},
	    {"stereo", 50},
	};
	Item i2[] = {
	    {"ring", 30000UL},
	    {"painting", 20000UL},
	    {"bust", 1},
	};
	Item i3[] = {
	    {"chair", 3500},
	};

	assert(losses(i1, nelem(i1)) == 100UL);
	assert(losses(i2, nelem(i2)) == 50001UL);
	assert(losses(i3, nelem(i3)) == 3500UL);
	assert(losses(NULL, 0) == 0);

	return 0;
}
