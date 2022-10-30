/*

The image below shows a sequence of larger and larger houses of cards, with the total number of cards included for each:

House of Cards

Given the tower height n, return the number of cards needed to construct a full house of cards.
Examples

cardsNeeded(3) ➞ 15

cardsNeeded(4) ➞ 26

cardsNeeded(0) ➞ 0

Notes

The height should always be equal or greater than 0. Return "invalid" if the value given doesn't abide by this rule.

*/

#include <assert.h>
#include <stdio.h>

// https://oeis.org/A005449
long
cards(long n)
{
	if (n < 0)
		return -1;
	return n * (3 * n + 1) / 2;
}

int
main(void)
{
	assert(cards(-3) == -1);
	assert(cards(-2) == -1);
	assert(cards(-1) == -1);
	assert(cards(0) == 0);
	assert(cards(1) == 2);
	assert(cards(2) == 7);
	assert(cards(3) == 15);
	assert(cards(4) == 26);
	assert(cards(5) == 40);
	assert(cards(6) == 57);
	assert(cards(7) == 77);
	assert(cards(8) == 100);
	assert(cards(9) == 126);
	assert(cards(10) == 155);
	assert(cards(11) == 187);
	assert(cards(12) == 222);
	assert(cards(13) == 260);
	assert(cards(14) == 301);
	assert(cards(15) == 345);
	assert(cards(16) == 392);
	assert(cards(17) == 442);
	assert(cards(18) == 495);
	assert(cards(19) == 551);
	assert(cards(20) == 610);
	assert(cards(21) == 672);
	assert(cards(22) == 737);
	assert(cards(23) == 805);
	assert(cards(24) == 876);
	assert(cards(25) == 950);
	assert(cards(26) == 1027);
	assert(cards(27) == 1107);
	assert(cards(28) == 1190);
	assert(cards(29) == 1276);
	assert(cards(30) == 1365);
	assert(cards(31) == 1457);
	assert(cards(32) == 1552);
	assert(cards(33) == 1650);
	assert(cards(34) == 1751);
	assert(cards(35) == 1855);
	assert(cards(36) == 1962);
	assert(cards(37) == 2072);
	assert(cards(38) == 2185);
	assert(cards(39) == 2301);
	assert(cards(40) == 2420);
	assert(cards(41) == 2542);
	assert(cards(42) == 2667);
	assert(cards(43) == 2795);
	assert(cards(44) == 2926);
	assert(cards(45) == 3060);
	assert(cards(46) == 3197);
	assert(cards(47) == 3337);
	assert(cards(48) == 3480);
	assert(cards(49) == 3626);
	assert(cards(50) == 3775);

	return 0;
}
