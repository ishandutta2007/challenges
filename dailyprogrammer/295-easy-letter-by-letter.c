/*

Description

Change the a sentence to another sentence, letter by letter.

The sentences will always have the same length.
Formal Inputs & Outputs
Input description

2 lines with the source and the target
Input 1

floor
brake

Input 2

wood
book

Input 3

a fall to the floor
braking the door in

Output description

All the lines where you change one letter and one letter only
Output 1

floor
bloor
broor
braor
brakr
brake

Output 2

wood
bood
book

Output 3

a fall to the floor
b fall to the floor
brfall to the floor
braall to the floor
brakll to the floor
brakil to the floor
brakin to the floor
brakingto the floor
braking o the floor
braking t the floor
braking ththe floor
braking thehe floor
braking the e floor
braking the d floor
braking the dofloor
braking the dooloor
braking the dooroor
braking the door or
braking the door ir
braking the door in

Bonus

Try to do something fun with it. You could do some codegolfing or use an Esoteric programming language
Finally

Have a good challenge idea?

Consider submitting it to /r/dailyprogrammer_ideas

*/

#include <stdio.h>
#include <string.h>

char *
transform(const char *s, const char *t, char *b)
{
	size_t i, n, m;

	n = strlen(s);
	m = strlen(t);
	if (n != m)
		return NULL;

	strcpy(b, s);
	printf("%s\n", b);
	for (i = 0; i < n; i++) {
		if (b[i] != t[i]) {
			b[i] = t[i];
			printf("%s\n", b);
		}
	}
	printf("\n");

	return b;
}

void
test(const char *s, const char *t)
{
	char b[128];

	transform(s, t, b);
}

int
main(void)
{
	test("floor", "brake");
	test("wood", "book");
	test("a fall to the floor", "braking the door in");

	return 0;
}
