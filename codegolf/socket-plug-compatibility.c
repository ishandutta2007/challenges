/*

Traveling with electronics is always fun, especially when you need an adapter to charge them. Your challenge is to make planning a trip a little easier by checking if a given plug will be compatible with a given socket.

Challenge

Given a plug type and a socket type, return a value that indicates whether they will work together or not.
Compatibility table

Socket  Accepted plugs  |  Plug  Accepting Sockets
A       A               |  A     A, B
B       A, B            |  B     B
C       C               |  C     C, D, E, F, H, J, K, L, N, O
D       C, D, E, F      |  D     D
E       C, E, F         |  E     D, E, F, H, K, O
F       C, E, F         |  F     D, E, F, H, K, O
G       G               |  G     G
H       C, E, F, H      |  H     H
I       I               |  I     I
J       C, J            |  J     J
K       C, E, F, K      |  K     K
L       C, L            |  L     L
M       M               |  M     M
N       C, N            |  N     N
O       C, E, F, O      |  O     O

The tables show the same information, only transposed.

For reference.
Input

    The input will be given as two uppercase or two lowercase letters (you choose).

    Inputs will always be /[A-O]/ (or /[a-o]/), there's no need to handle invalid inputs.

    You may accept the two inputs in any order (please specify which).

    Input can be taken in any reasonable format (string, stdin, array, ...).

    If you take both inputs in a single string, they can be separated by no more than one character and there must be nothing surrounding them

    Good inputs: "G,K", "EF", "a b", ['l', 'o']

    Bad inputs: "K l", "f(O)(I)", [1,5]

Output

    Output can be returned in any reasonable format.

    Output must be either truthy/falsy or one of 2 constant values

    Good outputs: false/any positive number, 1/2, 'T'/'F'

    Bad outputs: an even number/an odd number, 1/more than 1

Examples

Using the format socket, plug => true / false.

A, A => true
I, K => false
O, C => true
C, O => false
E, F => true
F, E => true

Standard loopholes are disallowed.

This is code-golf so the answer with the fewest bytes in each language wins.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

static bool sockplugs[256][256];

void
init(void)
{
	static const char *tab[] = {
	    ['A'] = "A",
	    ['B'] = "AB",
	    ['C'] = "C",
	    ['D'] = "CDEF",
	    ['E'] = "CEF",
	    ['F'] = "CEF",
	    ['G'] = "G",
	    ['H'] = "CEFH",
	    ['I'] = "I",
	    ['J'] = "CJ",
	    ['K'] = "CEFK",
	    ['L'] = "CL",
	    ['M'] = "M",
	    ['N'] = "CN",
	    ['O'] = "CEFO",
	};

	size_t i, j;
	const char *t;

	for (i = 0; i < nelem(tab); i++) {
		t = tab[i];
		if (!t)
			continue;

		for (j = 0; t[j]; j++)
			sockplugs[i][t[j] & 0xff] = true;
	}
}

bool
compatible(unsigned char s, unsigned char p)
{
	return sockplugs[s][p];
}

int
main(void)
{
	init();

	assert(compatible('A', 'A') == true);
	assert(compatible('I', 'K') == false);
	assert(compatible('O', 'C') == true);
	assert(compatible('C', 'O') == false);
	assert(compatible('E', 'F') == true);
	assert(compatible('F', 'E') == true);
	assert(compatible('K', 'K') == true);
	assert(compatible('E', 'O') == false);
	assert(compatible('O', 'E') == true);

	return 0;
}
