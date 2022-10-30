/*

Given a lottery ticket (ticket), represented by a list of 2-value lists, create a function to find out if you've won the jackpot.

To do this, you must first count the 'mini-wins' on your ticket. Each sublist has both a string and a number within it. If the character code of any of the characters in the string matches the number, you get a mini-win. Note you can only have one mini-win per sublist.

Once you have counted all of your mini-wins, compare that number to the other input provided (win). If your number of mini-wins is more than or equal to win, return Winner!. Else, return Loser!.
Examples

lottery([["YYW", 70], ["WXK", 65], ["RPDI", 88]], 2)
➞ "Loser!"

lottery([["KG", 80], ["NTBBVZ", 79], ["CI", 73], ["AGXMEE", 74], ["IU", 68], ["VOSP" , 84]], 1)
➞ "Winner!"

lottery([["ZSAMZB", 81], ["XWWCXP", 72], ["SYBRQOHP", 88], ["HJSVV", 75]], 1)
➞ "Loser!"

Notes

    All inputs will be in the correct format.
    Strings on ticket are not always the same length.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char code[128];
	unsigned value;
} Ticket;

const char *
lottery(Ticket *t, size_t n, unsigned w)
{
	size_t i, j;
	unsigned c;

	c = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; t[i].code[j]; j++) {
			if ((t[i].code[j] & 0xff) == t[i].value) {
				c++;
				break;
			}
		}
	}
	return (c >= w) ? "Winner!" : "Loser!";
}

void
test(Ticket *t, size_t n, unsigned w, const char *r)
{
	const char *s;

	s = lottery(t, n, w);
	assert(!strcmp(s, r));
}

int
main(void)
{
	Ticket t1[] = {{"YYW", 70}, {"WXK", 65}, {"RPDI", 88}};
	Ticket t2[] = {{"KG", 80}, {"NTBBVZ", 79}, {"CI", 73}, {"AGXMEE", 74}, {"IU", 68}, {"VOSP", 84}};
	Ticket t3[] = {{"ZSAMZB", 81}, {"XWWCXP", 72}, {"SYBRQOHP", 88}, {"HJSVV", 75}};
	Ticket t4[] = {{"GM", 84}, {"KLJ", 86}, {"UOF", 77}, {"JKC", 84}, {"RUI", 72}};
	Ticket t5[] = {{"CXFAFUOW", 90}, {"VKKC", 74}, {"OPYVAUR", 84}, {"WTMRW", 79}, {"ZIL", 84}, {"TDQMZD", 74}, {"MR", 66}, {"IQ", 86}, {"JTBX", 88}, {"ZJKX", 77}};
	Ticket t6[] = {{"SHUT", 85}, {"DOWPKSLD", 80}, {"QOOGBTDG", 85}, {"EID", 68}, {"EZKKAEYW", 81}, {"OYQBJCJE", 86}, {"WYTDAMFI", 87}, {"CW", 89}, {"BICKVN", 76}, {"BQH", 79}};
	Ticket t7[] = {{"GITVQFQ", 65}, {"VCQ", 71}, {"DLK", 70}, {"HUVMWH", 80}, {"PLUYERTX", 68}, {"JVJSHC", 81}, {"OUSXBLP", 77}, {"IGNCP", 82}, {"LV", 65}};
	Ticket t8[] = {{"CKLD", 80}, {"VDGDL", 78}, {"LKAJBSPM", 74}, {"CCPNIE", 67}, {"GS", 77}, {"QYWGWS", 83}, {"XLJUE", 73}, {"CMUCLWE", 70}, {"MHM", 90}};
	Ticket t9[] = {{"TRJZKKCQ", 81}, {"KYC", 80}, {"WU", 66}, {"MFTWCFZ", 83}, {"TNIRSP", 72}, {"VC", 86}, {"AINOS", 87}, {"RGROXMF", 86}, {"URKVFY", 70}};
	Ticket t10[] = {{"XONLHEB", 71}, {"FXMR", 65}, {"WMGY", 89}};

	test(t1, nelem(t1), 2, "Loser!");
	test(t2, nelem(t2), 1, "Winner!");
	test(t3, nelem(t3), 1, "Loser!");
	test(t4, nelem(t4), 1, "Loser!");
	test(t5, nelem(t5), 4, "Loser!");
	test(t6, nelem(t6), 3, "Winner!");
	test(t7, nelem(t7), 9, "Loser!");
	test(t8, nelem(t8), 8, "Loser!");
	test(t9, nelem(t9), 3, "Winner!");
	test(t10, nelem(t10), 1, "Winner!");

	return 0;
}
