/*

Alpha Decay is a kind of radiation decay where every time the atom "decays", it loses a helium nucleus (an alpha particle).
This means that an atom loses 2 protons and 2 neutrons each time.
Your task is to simulate this, including the problems that occur during alpha decay.

Given two integers as input, m
and p, where 1<p<m, count down in steps of 4 and 2 respectively until either m or p is equal to or less than 1. At this point, you should output the number which has not yet reached 1.

In order to mimic radioactive decay, however, your program should work when up to any 2 characters are removed from your program.
These characters are chosen with uniform probability, and (obviously) chosen without replacement.
"Up to" means that the number of characters removed can either be 0, 1 or 2, and your program should work when any number of characters between 0, 1 and 2 are removed.

By "work" it means that, your program, modified or not, should perform the task as specified. Programs may error, so long as the correct output is produced.

Input and output formats are liberal, so long as it's covered by the defaults, it's allowed.

The shortest code in bytes (without characters removed) wins!
Test Cases

m, p     => output
100, 20  => 60
101, 100 => 50
45, 2    => 41
2000, 80 => 1840
57, 23   => 13
80, 40   => 0
81, 40   => 1
81, 41   => 1
43, 42   => 20

*/

#include <assert.h>

int
decay(int m, int p)
{
	while (m > 1 && p > 1) {
		m -= 4;
		p -= 2;
	}
	if (m > 1)
		return m;
	if (p > 1)
		return p;
	return m;
}

int
main(void)
{
	assert(decay(100, 20) == 60);
	assert(decay(101, 100) == 50);
	assert(decay(45, 2) == 41);
	assert(decay(2000, 80) == 1840);
	assert(decay(57, 23) == 13);
	assert(decay(80, 40) == 0);
	assert(decay(81, 40) == 1);
	assert(decay(81, 41) == 1);
	assert(decay(43, 42) == 20);

	return 0;
}
