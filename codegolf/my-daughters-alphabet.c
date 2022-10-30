/*

The other day we were writing sentences with my daughter with a fridge magnet letter.
While we were able to make some(I love cat), we didn't have enough letters to make the others (I love you too) due to an insufficient amount of letters o (4)

I then found out that while one set included 3 e letters it had only 2 o letters.
Probably inspired by http://en.wikipedia.org/wiki/Letter_frequency this would still not reflect the actual situation "on the fridge".

Problem

Given the text file where each line contains a "sample sentence" one would want to write on the fridge, propose an alphabet set with minimum amount of letters but still sufficient to write each sentence individually.

Note: ignore cases, all magnet letters are capitals anyway.
Input

The file contain newline separated sentences:

hello
i love cat
i love dog
i love mommy
mommy loves daddy

Output

Provide back sorted list of letters, where each letter appears only as many times to be sufficient to write any sentence:

acdddeghillmmmoostvyy

(thanks, isaacg!)
Winner

Shortest implementation (code)
UPDATED: Testing

I have created an extra test and tried with various answers here:

https://gist.github.com/romaninsh/11159751

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
alphabet(const char **s, size_t n, char *b)
{
	size_t h[256], m[256];
	size_t i, j, l;
	int c;

	memset(m, 0, sizeof(m));
	for (i = 0; i < n; i++) {
		memset(h, 0, sizeof(h));
		for (j = 0; s[i][j]; j++) {
			c = tolower(s[i][j]);
			if (++h[c] > m[c])
				m[c] = h[c];
		}
	}

	l = 0;
	for (i = 'a'; i <= 'z'; i++) {
		for (j = 0; j < m[i]; j++)
			b[l++] = i;
	}
	b[l] = '\0';

	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[256];

	alphabet(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	static const char *s1[] = {
	    "hello",
	    "i love cat",
	    "i love dog",
	    "i love mommy",
	    "mommy loves daddy",
	};

	static const char *s2[] = {
	    "I SAW THE MAN WITH THE BINOCULARS",
	    "THEY ARE HUNTING DOGS",
	    "FREE WHALES",
	    "POLICE HELP DOG BITE VICTIM",
	    "HE SAW THAT GAS CAN EXPLODE",
	    "TURN RIGHT HERE",
	    "WE SAW HER DUCK",
	    "IN ANIMAL CRACKERS GROUCHO MARX AS CAPTAIN RUFUS T SPAULDING QUIPPED ONE MORNING I SHOT AN ELEPHANT IN MY PAJAMAS HOW HE GOT IN MY PAJAMAS I DONT KNOW",
	    "SHIP SAILS TOMORROW",
	    "BOOK STAYS IN LONDON",
	    "WANTED A NURSE FOR A BABY ABOUT TWENTY YEARS OLD",
	    "THE GIRL IN THE CAR THAT NEEDED WATER IS WAITING",
	    "DID YOU EVER HEAR THE STORY ABOUT THE BLIND CARPENTER WHO PICKED UP HIS HAMMER AND SAW",
	    "THOSE PROSECUTORS HAVE BEEN TRYING TO LOCK HIM UP FOR TEN YEARS",
	    "FLYING PLANES CAN BE DANGEROUS",
	    "I ONCE SAW A DEER RIDING MY BICYCLE",
	    "TOILET OUT OF ORDER PLEASE USE FLOOR BELOW",
	    "LOOK AT THE DOG WITH ONE EYE",
	};

	test(s1, nelem(s1), "acdddeghillmmmoostvyy");
	test(s2, nelem(s2), "aaaaaaaaaaaaaaaabbbccccdddddeeeeeeeeeffgggghhhhhhiiiiiiiiiijjkkllllmmmmmmmnnnnnnnnnnnnnooooooooopppppppqrrrrrrsssssssttttttuuuuuvwwxyyy");

	return 0;
}
