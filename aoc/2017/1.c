/*

--- Day 1: Inverse Captcha ---
The night before Christmas, one of Santa's Elves calls you in a panic. "The printer's broken! We can't print the Naughty or Nice List!" By the time you make it to sub-basement 17, there are only a few minutes until midnight. "We have a big problem," she says; "there must be almost fifty bugs in this system, but nothing else can print The List. Stand in this square, quick! There's no time to explain; if you can convince them to pay you in stars, you'll be able to--" She pulls a lever and the world goes blurry.

When your eyes can focus again, everything seems a lot more pixelated than before. She must have sent you inside the computer! You check the system clock: 25 milliseconds until midnight. With that much time, you should be able to collect all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day millisecond in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You're standing in a room with "digitization quarantine" written in LEDs along one wall. The only door is locked, but it includes a small interface. "Restricted Area - Strictly No Digitized Users Allowed."

It goes on to explain that you may only leave by solving a captcha to prove you're not a human. Apparently, you only get one millisecond to solve the captcha: too fast for a normal human, but it feels like hours to you.

The captcha requires you to review a sequence of digits (your puzzle input) and find the sum of all digits that match the next digit in the list. The list is circular, so the digit after the last digit is the first digit in the list.

For example:

1122 produces a sum of 3 (1 + 2) because the first digit (1) matches the second digit and the third digit (2) matches the fourth digit.
1111 produces 4 because each digit (all 1) matches the next.
1234 produces 0 because no digit matches the next.
91212129 produces 9 because the only digit that matches the next one is the last digit, 9.
What is the solution to your captcha?

--- Part Two ---
You notice a progress bar that jumps to 50% completion. Apparently, the door isn't yet satisfied, but it did emit a star as encouragement. The instructions change:

Now, instead of considering the next digit, it wants you to consider the digit halfway around the circular list.
That is, if your list contains 10 items, only include a digit in your sum if the digit 10/2 = 5 steps forward matches it.
Fortunately, your list has an even number of elements.

For example:

1212 produces 6: the list contains 4 items, and all four digits match the digit 2 items ahead.
1221 produces 0, because every comparison is between a 1 and a 2.
123425 produces 4, because both 2s match each other, but no other digit has a match.
123123 produces 12.
12131415 produces 4.
What is the solution to your new captcha?

*/

#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
sum(const char *s, size_t n, size_t k)
{
	size_t i, j;
	uvlong r;

	r = 0;
	for (i = 0; i < n; i++) {
		j = (i + k) % n;
		if (s[i] == s[j])
			r += (s[i] - '0');
	}
	return r;
}

int
main(void)
{
	static const char number[] = "9384274494683632359351641411374573466273164687337536769779487433749179185568461296233353611992672753778126935276769885424719553291616136172298883156626254151278852582397949697874462178536295341822137377563322815527592267791213115418635363174876132196234374887626324931371241841242873783493835919238421879116421481543826222278152238576762132577763214642569545298668935216911493462229629786978273548147171384321525952959196377728493632872618291183256888417779495124837828187298244786175872713299271766246696631257484453347125176233373232245382158656142179687576388951175953419286858673221138553912229576523123114871637487978775855777483921896568333282333137175739746234262744256254149233843517254613981476355147487975859685936527161737644929119345127273149762325158784595946931447738173246311763677997888425452294562823751136515271874725143582623717324394587398371298523368386595426714148717735345237657249712685895921433468949182235146698174393928288313985355769799485511749423552935992391624424575278333625476148888355716967628454862834463357834291788479677576561681171516128495737923155533438413156639155128831349894646317546536886319328573512622325789672115171618195548534941184939233914166432349321992879287349932819135919518955561456615989137221875483561599493342981595678961836562435436285673764213941758954489582656271121429555455368545289416981624961261963953364918377483776322142975937971552271642224933926326665557787586927667898255947116988278131974381388514274833852552695679713424836536348449273149415872522111522749448188993159814183411853994579147867385867619467777654943169814287928966652552129439822741856512265955664872454951159255617513136142717471774698224566543617595742753244142364438589729356939483387466363477224283477843889679221229344974441624448489853764111425798141258155246636844914711222931548722647298953744242682551562166463942694715631497895981643174194294826868561578586851326262619731272665397711381459745281218196515155917877694663186732599688912878149242688741584822831861748845817871681621697944472377688658368145698614861456518138376989688166921187224726942589996534179549171859786241718727295379";
	static const size_t digits = sizeof(number) - 1;

	printf("%llu\n", sum(number, digits, 1));
	printf("%llu\n", sum(number, digits, digits / 2));

	return 0;
}
