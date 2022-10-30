/*

A rewrite of this question with a simpler input format and guidelines.
Challenge

Deadfish uses a single accumulator, on which all commands are to be performed.

It has the following commands:
Command 	Description
i 	increment the accumulator
d 	decrement the accumulator
s 	square the value of the accumulator
o 	output the value of the accumulator as a number

If, after executing a command, the accumulator is equal to -1 or equal to 256, the accumulator must be reset to zero.
I/O

Input can be taken as a single string, list of codepoints, or any other reasonable format. It is guaranteed that the input will only consist of deadfish commands.

Output can be given as an array of numbers, or just the numbers printed with separators between them.
Testcases

(some are borrowed from the Esolangs wiki)

iissso -> 0
diissisdo -> 288
iissisdddddddddddddddddddddddddddddddddo -> 0
isssoisoisoisoiso -> 1,4,25,676,458329
ooooosioiiisooo -> 0,0,0,0,0,1,16,16,16
iiii -> nothing
iiiiiiiissdiiiiiiiiiiiiiiiiio -> 4112
o -> 0

*/

#include <stdio.h>
#include <string.h>

typedef struct {
	long ac;
} Deadfish;

void
interpret(Deadfish *d, const char *s)
{
	size_t i;
	int f;

	f = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'i':
			d->ac++;
			break;

		case 'd':
			d->ac--;
			break;

		case 's':
			d->ac *= d->ac;
			break;

		case 'o':
			printf("%s%ld", (f) ? "," : "", d->ac);
			f = 1;
			break;
		}

		if (d->ac == -1 || d->ac == 256)
			d->ac = 0;
	}

	printf("\n");
}

void
test(const char *s)
{
	Deadfish d;

	memset(&d, 0, sizeof(d));
	interpret(&d, s);
}

int
main(void)
{
	test("iissso");
	test("diissisdo");
	test("iissisdddddddddddddddddddddddddddddddddo");
	test("isssoisoisoisoiso");
	test("ooooosioiiisooo");
	test("iiii");
	test("iiiiiiiissdiiiiiiiiiiiiiiiiio");
	test("o");
	return 0;
}
