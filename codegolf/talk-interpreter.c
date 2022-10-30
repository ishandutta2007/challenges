/*

"Talk" is a baroquified accumulator-based language that is created in response to Dennis's quote on talk.tryitonline.net.

Waiting for someone to create an esolang called talk.
The "Talk" language has 4 commands:

00 If the accumulator is 0, set the accumulator to 0.
01 If the accumulator is 0, set the accumulator to 1.
10 If the accumulator is 1, set the accumulator to 0.
11 If the accumulator is 1, set the accumulator to 1.

Input:

The input can be taken via any acceptable input method by our standard I/O rules.

There are two inputs, the initial accumulator value and the program. You can merge these two inputs into one input or split your input into valid commands (e.g. taking them as a list; e.g. [00, 01, 00]) if you like.

Output:

On the end of a command execution, the accumulator is outputted implicitly.

Rules:

The input can be a single string or character list.
As this is code-golf, the shortest answer, in bytes, wins.
We take digits or strings/characters.

Test cases:
0 0001111101 -> 1
0 000100 -> 1
0 11001000 -> 0

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
decode(const char *s)
{
	static const char *tab[] = {
	    "00",
	    "01",
	    "10",
	    "11",
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strncmp(s, tab[i], 2))
			return i;
	}
	return -1;
}

int
interpret(int ac, const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i += 2) {
		switch (decode(s + i)) {
		case 1:
			ac = (ac == 0) ? 1 : ac;
			break;
		case 2:
			ac = (ac == 1) ? 0 : ac;
			break;
		}
	}
	return ac;
}

int
main(void)
{
	assert(interpret(0, "0001111101") == 1);
	assert(interpret(0, "000100") == 1);
	assert(interpret(0, "11001000") == 0);

	return 0;
}
