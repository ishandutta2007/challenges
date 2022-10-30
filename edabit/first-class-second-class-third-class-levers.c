/*

Levers are simple machines with a rigid beam and a fulcrum. From the picture below, you can see that there are 3-types of levers: first class, second class and third class.

    In a first class lever, the fulcrum is situated in the middle with the effort and the load being positioned opposite of each other.
    In a second class lever, the fulcrum is situated in the right with the effort on the left and the load in the middle.
    In a third class lever, the fulcrum is situated in the left with the effort being in the middle and the load being on the right.

Given an array that contains the fulcrum "f", the effort "e", and the load "l", write a function that determines whether or not the array shows a first class lever, second class lever, or a third class lever.
Examples

determineLever(["e", "f", "l"]) ➞ "first class lever"

determineLever(["e", "l", "f"]) ➞ "second class lever"

determineLever(["f", "e", "l"]) ➞ "third class lever"

Notes

A pair of scissors is a first class lever, a nutcracker is a second class lever and a broom is a third class lever.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
lever(char t[3])
{
	long v;

	v = t[0] | t[1] << 8 | t[2] << 16;
	switch (v) {
	case 0x6c6665:
		return "first class lever";
	case 0x666c65:
		return "second class lever";
	case 0x6c6566:
		return "third class lever";
	}
	return NULL;
}

int
main(void)
{
	char t1[] = {'e', 'f', 'l'};
	char t2[] = {'e', 'l', 'f'};
	char t3[] = {'f', 'e', 'l'};

	assert(!strcmp(lever(t1), "first class lever"));
	assert(!strcmp(lever(t2), "second class lever"));
	assert(!strcmp(lever(t3), "third class lever"));

	return 0;
}
