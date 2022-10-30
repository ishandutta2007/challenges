/*

A block sequence in three dimensions. We can write a formula for this one:

Sequence Step 1 - 5

Create a function that takes a number (step) as an argument and returns the amount of blocks in that step.
Examples

blocks(1) ➞ 5

blocks(5) ➞ 39

blocks(2) ➞ 12

Notes

    Step 0 obviously has to return 0.
    The input is always a positive integer.
    Check the Resources tab for a video on finding quadratic sequences.

*/

#include <assert.h>
#include <stdio.h>

unsigned
blocks(unsigned n)
{
	double a, b, c;

	if (n == 0)
		return 0;

	a = 0.5;
	b = 5.5;
	c = -1;
	return a * n * n + b * n + c;
}

int
main(void)
{
	assert(blocks(77) == 3387);
	assert(blocks(33) == 725);
	assert(blocks(50) == 1524);
	assert(blocks(21) == 335);
	assert(blocks(12) == 137);
	assert(blocks(30) == 614);
	assert(blocks(93) == 4835);
	assert(blocks(53) == 1695);
	assert(blocks(71) == 2910);
	assert(blocks(36) == 845);
	assert(blocks(8) == 75);
	assert(blocks(100) == 5549);
	assert(blocks(95) == 5034);
	assert(blocks(46) == 1310);
	assert(blocks(63) == 2330);
	assert(blocks(54) == 1754);
	assert(blocks(15) == 194);
	assert(blocks(45) == 1259);
	assert(blocks(64) == 2399);
	assert(blocks(46) == 1310);
	assert(blocks(68) == 2685);
	assert(blocks(46) == 1310);
	assert(blocks(23) == 390);
	assert(blocks(62) == 2262);
	assert(blocks(55) == 1814);
	assert(blocks(95) == 5034);
	assert(blocks(72) == 2987);
	assert(blocks(76) == 3305);
	assert(blocks(24) == 419);
	assert(blocks(98) == 5340);
	assert(blocks(22) == 362);
	assert(blocks(39) == 974);
	assert(blocks(68) == 2685);
	assert(blocks(9) == 89);
	assert(blocks(22) == 362);
	assert(blocks(85) == 4079);
	assert(blocks(37) == 887);
	assert(blocks(98) == 5340);
	assert(blocks(18) == 260);
	assert(blocks(65) == 2469);
	assert(blocks(38) == 930);
	assert(blocks(70) == 2834);
	assert(blocks(84) == 3989);
	assert(blocks(21) == 335);
	assert(blocks(48) == 1415);
	assert(blocks(88) == 4355);
	assert(blocks(28) == 545);
	assert(blocks(8) == 75);
	assert(blocks(93) == 4835);
	assert(blocks(3) == 20);
	assert(blocks(99) == 5444);
	assert(blocks(69) == 2759);
	assert(blocks(1) == 5);
	assert(blocks(19) == 284);
	assert(blocks(83) == 3900);
	assert(blocks(39) == 974);
	assert(blocks(84) == 3989);
	assert(blocks(11) == 120);
	assert(blocks(2) == 12);
	assert(blocks(2) == 12);
	assert(blocks(62) == 2262);
	assert(blocks(93) == 4835);
	assert(blocks(59) == 2064);
	assert(blocks(81) == 3725);
	assert(blocks(50) == 1524);
	assert(blocks(11) == 120);
	assert(blocks(77) == 3387);
	assert(blocks(31) == 650);
	assert(blocks(37) == 887);
	assert(blocks(45) == 1259);
	assert(blocks(31) == 650);
	assert(blocks(15) == 194);
	assert(blocks(5) == 39);
	assert(blocks(33) == 725);
	assert(blocks(18) == 260);
	assert(blocks(92) == 4737);
	assert(blocks(94) == 4934);
	assert(blocks(11) == 120);
	assert(blocks(26) == 480);
	assert(blocks(28) == 545);
	assert(blocks(36) == 845);
	assert(blocks(72) == 2987);
	assert(blocks(20) == 309);
	assert(blocks(82) == 3812);
	assert(blocks(47) == 1362);
	assert(blocks(79) == 3554);
	assert(blocks(1) == 5);
	assert(blocks(20) == 309);
	assert(blocks(83) == 3900);
	assert(blocks(59) == 2064);
	assert(blocks(2) == 12);
	assert(blocks(43) == 1160);
	assert(blocks(23) == 390);
	assert(blocks(78) == 3470);
	assert(blocks(0) == 0);
	assert(blocks(92) == 4737);
	assert(blocks(83) == 3900);
	assert(blocks(96) == 5135);
	assert(blocks(95) == 5034);
	assert(blocks(6) == 50);

	return 0;
}
