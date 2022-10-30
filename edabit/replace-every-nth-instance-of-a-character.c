/*

Create a function that takes a string and replaces every nth instance of oldChar with newChar. Your function will have four parameters:

    str — The original input text to be processed.
    nth — The nth instance to be replaced.
    oldChar — The character being replaced.
    newChar — The character replacing oldChar.

In other words, if str is "abababa", nth is 3, oldChar is "a" and newChar is "Z", you would replace the 3rd insrtance of "a" with "Z", returning "ababZba".
Examples

replaceNth("A glittering gem is not enough.", 0, "o", "-")
➞ "A glittering gem is not enough."

replaceNth("Vader said: No, I am your father!", 2, "a", "o")
➞ "Vader soid: No, I am your fother!"

replaceNth("Writing a list of random sentences is harder than I initially thought it would be.", 2, "i", "3")
➞ "Writ3ng a list of random sentences 3s harder than I in3tially thought 3t would be."

Notes

    If nth is 0, negative or larger than instances of oldChar, return the original string.
    Tests are case sensitive.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
replacenth(char *s, ssize_t n, char a, char b)
{
	size_t i;
	ssize_t j;

	for (i = j = 0; s[i]; i++) {
		if (s[i] == a && n > 0 && ++j >= n) {
			s[i] = b;
			j = 0;
		}
	}
	return s;
}

int
main(void)
{
	char s1[] = "A glittering gem is not enough.";
	char s2[] = "Vader said: No, I am your father!";
	char s3[] = "Writing a list of random sentences is harder than I initially thought it would be.";
	char s4[] = "Sometimes it is better to just walk away from things and go back to them later when you’re in a better frame of mind.";
	char s5[] = "The clock within this blog and the clock on my laptop are 1 hour different from each other.";
	char s6[] = "Lets all be unique together until we realise we are all the same.";
	char s7[] = "Sometimes, all you NEED to do is completely make an ass of yourself and laugh it off to realise that LIFE isn’t so bad AFTER all.";
	char s8[] = "Is it free?";
	char s9[] = "A glittering gem is not enough.";
	char s10[] = "Please wait outside of the house.";
	char s11[] = "Joe made the sugar cookies; Susan decorated them.";
	char s12[] = "Writing a list of random sentences is harder than I initially thought it would be.";
	char s13[] = "The book is in front of the table.";

	char t1[] = "A glittering gem is not enough.";
	char t2[] = "Vader soid: No, I am your fother!";
	char t3[] = "Writ3ng a list of random sentences 3s harder than I in3tially thought 3t would be.";
	char t4[] = "Sometimes it is b_tter to just walk away from things and go back to them lat_r when you’re in a b_tter frame of mind.";
	char t5[] = "The cl@ck within this bl@g and the cl@ck @n my lapt@p are 1 h@ur different fr@m each @ther.";
	char t6[] = "Lets all be unique together until we rea#ise we are all the same.";
	char t7[] = "Sometimes, all you NExD to do is completely make an ass of yourself and laugh it off to realise that LIFE isn’t so bad AFTxR all.";
	char t8[] = "Is it free?";
	char t9[] = "A glittering gem is not enough.";
	char t10[] = "Please wait outside of the house.";
	char t11[] = "Joe made the sugar cookies; Susan d*corated them.";
	char t12[] = "Writ3ng a list of random sentences 3s harder than I in3tially thought 3t would be.";
	char t13[] = "The book is in front of the table.";

	assert(strcmp(replacenth(s1, 0, 'o', '-'), t1) == 0);
	assert(strcmp(replacenth(s2, 2, 'a', 'o'), t2) == 0);
	assert(strcmp(replacenth(s3, 2, 'i', '3'), t3) == 0);
	assert(strcmp(replacenth(s4, 3, 'e', '_'), t4) == 0);
	assert(strcmp(replacenth(s5, 1, 'o', '@'), t5) == 0);
	assert(strcmp(replacenth(s6, 4, 'l', '#'), t6) == 0);
	assert(strcmp(replacenth(s7, 2, 'E', 'x'), t7) == 0);
	assert(strcmp(replacenth(s8, 100, 'e', 'Y'), t8) == 0);
	assert(strcmp(replacenth(s9, 0, 'o', '-'), t9) == 0);
	assert(strcmp(replacenth(s10, -3, 's', 's'), t10) == 0);
	assert(strcmp(replacenth(s11, 5, 'e', '*'), t11) == 0);
	assert(strcmp(replacenth(s12, 2, 'i', '3'), t12) == 0);
	assert(strcmp(replacenth(s13, 3, 'f', 'K'), t13) == 0);

	return 0;
}
