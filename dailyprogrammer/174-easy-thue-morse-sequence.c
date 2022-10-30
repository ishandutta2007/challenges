/*

Description:

The Thue-Morse sequence is a binary sequence (of 0s and 1s) that never repeats.
It is obtained by starting with 0 and successively calculating the Boolean complement of the sequence so far.
It turns out that doing this yields an infinite, non-repeating sequence. This procedure yields 0 then 01, 0110, 01101001, 0110100110010110, and so on.

[Thue-Morse Wikipedia Article] (http://en.wikipedia.org/wiki/Thue%E2%80%93Morse_sequence) for more information.

Input:

Nothing.

Output:

Output the 0 to 6th order Thue-Morse Sequences.

Example:
nth		Sequence
===========================================================================
0 		0
1 		01
2 		0110
3 		01101001
4 		0110100110010110
5 		01101001100101101001011001101001
6 		0110100110010110100101100110100110010110011010010110100110010110
Extra Challenge:
Be able to output any nth order sequence. Display the Thue-Morse Sequences for 100.

Note: Due to the size of the sequence it seems people are crashing beyond 25th order or the time it takes is very long. So how long until you crash. Experiment with it.

Credit:

challenge idea from /u/jnazario from our r/dailyprogrammer_ideas subreddit.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
thuemorse(unsigned n, char *b)
{
	size_t j, l;
	unsigned i;

	l = sprintf(b, "0");
	for (i = 0; i < n; i++) {
		for (j = 0; j < l; j++)
			b[j + l] = (b[j] == '0') ? '1' : '0';
		l += l;
	}
	b[l] = '\0';

	return l;
}

void
test(unsigned n, const char *r)
{
	char b[512];

	thuemorse(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0, "0");
	test(1, "01");
	test(2, "0110");
	test(3, "01101001");
	test(4, "0110100110010110");
	test(5, "01101001100101101001011001101001");
	test(6, "0110100110010110100101100110100110010110011010010110100110010110");

	return 0;
}
