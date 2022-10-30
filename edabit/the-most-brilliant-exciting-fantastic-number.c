/*

Given a number n, return a sentence which describes the number in the following ways.

    Always start the string with "The most ".
    If n is evenly divisible by 1, add "brilliant " to the sentence.
    If n is evenly divisble by 2, add "exciting " to the sentence.
    ... 3, add "fantastic " to the sentence.
    ... 4, add "virtuous " to the sentence.
    ... 5, add "heart-warming " ...
    ... 6, add "tear-jerking " ...
    ... 7, add "beautiful " ...
    ... 8, add "exhilarating " ...
    ... 9, add "emotional " ...
    If n is evenly divisible by 10, add "inspiring " to the sentence.
    Always end the string with "number is n!".

Examples

describeNum(13) ➞ "The most brilliant number is 13!"
// 13 is evenly divisble by 1 only

describeNum(4) ➞ "The most brilliant exciting virtuous number is 4!"
// 4 is evenly divisible by 1, 2 and 4

describeNum(21) ➞ "The most brilliant fantastic beautiful number is 21!"
// 21 is evenly divisible by 1, 3 and 7

describeNum(60) ➞ "The most brilliant exciting fantastic virtuous heart-warming tear-jerking inspiring number is 60!"
// 60 is evenly divisible by 1, 2, 3, 4, 5, 6 and 10

Notes

    Add words to the sentence in the order going down the list.
    Remember to add a space between each word.
    BONUS: Try to find the lowest number which uses all possible words in the sentence!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
describe(unsigned n, char *b)
{
	static const char *tab[] = {
	    "brilliant",
	    "exciting",
	    "fantastic",
	    "virtuous",
	    "heart-warming",
	    "tear-jerking",
	    "beautiful",
	    "exhilarating",
	    "emotional",
	    "inspiring",
	};

	size_t i, l;

	l = 0;
	l += sprintf(b + l, "The most ");
	for (i = 0; i < nelem(tab); i++) {
		if ((n % (i + 1)) == 0)
			l += sprintf(b + l, "%s ", tab[i]);
	}
	l += sprintf(b + l, "number is %u!", n);

	return b;
}

void
test(unsigned n, const char *r)
{
	char b[128];

	describe(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(13, "The most brilliant number is 13!");
	test(4, "The most brilliant exciting virtuous number is 4!");
	test(21, "The most brilliant fantastic beautiful number is 21!");
	test(60, "The most brilliant exciting fantastic virtuous heart-warming tear-jerking inspiring number is 60!");
	test(56, "The most brilliant exciting virtuous beautiful exhilarating number is 56!");
	test(47, "The most brilliant number is 47!");
	test(115, "The most brilliant heart-warming number is 115!");
	test(300, "The most brilliant exciting fantastic virtuous heart-warming tear-jerking inspiring number is 300!");
	test(201, "The most brilliant fantastic number is 201!");
	test(224, "The most brilliant exciting virtuous beautiful exhilarating number is 224!");
	test(42, "The most brilliant exciting fantastic tear-jerking beautiful number is 42!");
	test(22, "The most brilliant exciting number is 22!");
	test(23, "The most brilliant number is 23!");
	test(108, "The most brilliant exciting fantastic virtuous tear-jerking emotional number is 108!");
	test(58, "The most brilliant exciting number is 58!");
	test(184, "The most brilliant exciting virtuous exhilarating number is 184!");
	test(46, "The most brilliant exciting number is 46!");
	test(43, "The most brilliant number is 43!");
	test(178, "The most brilliant exciting number is 178!");
	test(191, "The most brilliant number is 191!");
	test(175, "The most brilliant heart-warming beautiful number is 175!");
	test(264, "The most brilliant exciting fantastic virtuous tear-jerking exhilarating number is 264!");
	test(130, "The most brilliant exciting heart-warming inspiring number is 130!");
	test(213, "The most brilliant fantastic number is 213!");
	test(25, "The most brilliant heart-warming number is 25!");
	test(219, "The most brilliant fantastic number is 219!");
	test(173, "The most brilliant number is 173!");
	test(212, "The most brilliant exciting virtuous number is 212!");
	test(116, "The most brilliant exciting virtuous number is 116!");
	test(103, "The most brilliant number is 103!");
	test(34, "The most brilliant exciting number is 34!");
	test(89, "The most brilliant number is 89!");
	test(40, "The most brilliant exciting virtuous heart-warming exhilarating inspiring number is 40!");
	test(138, "The most brilliant exciting fantastic tear-jerking number is 138!");
	test(153, "The most brilliant fantastic emotional number is 153!");
	test(201, "The most brilliant fantastic number is 201!");
	test(262, "The most brilliant exciting number is 262!");
	test(232, "The most brilliant exciting virtuous exhilarating number is 232!");
	test(128, "The most brilliant exciting virtuous exhilarating number is 128!");
	test(129, "The most brilliant fantastic number is 129!");
	test(264, "The most brilliant exciting fantastic virtuous tear-jerking exhilarating number is 264!");
	test(24, "The most brilliant exciting fantastic virtuous tear-jerking exhilarating number is 24!");
	test(124, "The most brilliant exciting virtuous number is 124!");
	test(163, "The most brilliant number is 163!");
	test(80, "The most brilliant exciting virtuous heart-warming exhilarating inspiring number is 80!");
	test(130, "The most brilliant exciting heart-warming inspiring number is 130!");
	test(46, "The most brilliant exciting number is 46!");
	test(247, "The most brilliant number is 247!");
	test(89, "The most brilliant number is 89!");
	test(127, "The most brilliant number is 127!");
	test(169, "The most brilliant number is 169!");
	test(195, "The most brilliant fantastic heart-warming number is 195!");
	test(192, "The most brilliant exciting fantastic virtuous tear-jerking exhilarating number is 192!");
	test(146, "The most brilliant exciting number is 146!");

	return 0;
}
