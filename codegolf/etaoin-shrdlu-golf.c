/*

Short and sweet description of the challenge:
Based off ETAOIN SHRDLU, your challenge is to write the shortest program or function in any language that outputs the 26 letters of the English alphabet based on their frequency in the input.

Really long, dry and thorough specification:

    Your program/function will receive as input a string of text, which will contain one or more uppercase and/or lowercase letters and may also contain punctuation, numerals, symbols, and other non-alphabetic characters.
    The program/function must output only the 26 UPPERCASE letters of the English alphabet, including those that do not appear in the input, ordered from most to least frequent based on how many times they appear in the input.
    Edit: The frequency is calculated case-insensitively, but the output must be in uppercase.
    If two or more letters have the same frequency, they may be in any order.
    No other output, such as whitespace, is allowed.
    Edit 7/1/2014: Based on feedback, I am amending this rule. The only other output that is allowed is optional leading and/or trailing whitespace, such as a trailing newline. No other output is allowed.
    Undefined behavior is allowed for input that does not contain any letters.

The winner will be picked 7 days from now, so get those fingers typing!

Example input:

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent vitae erat velit. Mauris gravida euismod libero ut tincidunt. Phasellus elit dui, consectetur et egestas in, aliquam vitae diam. Donec eget varius ante. Vestibulum cursus diam aliquet, egestas orci quis, placerat dolor. Proin vel nisi lectus. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Aliquam erat volutpat. Etiam libero tortor, ornare id dui eget, posuere dignissim libero. Pellentesque commodo consequat volutpat. Integer hendrerit sapien libero, vel viverra augue facilisis sit amet. Quisque consectetur eget nisl quis dignissim. Ut lacinia pretium quam a placerat.
Morbi sed interdum risus, nec pretium lectus. Morbi imperdiet est id accumsan molestie. Duis sed fermentum nisl. Nunc vitae augue mattis, dictum lectus vel, accumsan nisl. Sed ultricies adipiscing rhoncus. Vivamus eu lacus a enim venenatis eleifend. Praesent consectetur tortor non eleifend ultricies. Mauris et odio posuere, auctor erat at, fringilla est. Proin in vestibulum erat. Maecenas congue commodo ante vel varius. Sed tempus mi ut metus gravida, nec dictum libero dapibus. Morbi quis viverra elit. Ut pharetra neque eget lacus tincidunt dictum. Fusce scelerisque viverra tellus et pretium.
Fusce varius adipiscing odio. Nulla imperdiet faucibus sem, at rhoncus ipsum adipiscing vitae. Phasellus imperdiet congue lacus et mollis. Nullam egestas mauris magna, et mollis lectus varius ut. Sed sollicitudin adipiscing dolor, vel elementum elit laoreet molestie. Aliquam nec nulla vel sem ultrices ullamcorper. Nullam nec felis magna. Duis sodales orci non justo aliquam tempus. Integer mi diam, tempor sed vulputate et, varius et nunc. Vestibulum sodales ipsum id mi pharetra, ut convallis mi accumsan. Sed dictum volutpat vestibulum.
Quisque ac dolor sagittis, aliquam libero at, euismod enim. Nulla ullamcorper posuere nulla vitae varius. Nam at dolor non libero elementum pellentesque in in lorem. Fusce porttitor turpis in quam placerat varius. Donec lorem orci, condimentum eu sapien sit amet, aliquet commodo magna. Quisque sed lectus sit amet arcu euismod accumsan et non nunc. Phasellus placerat congue metus, feugiat posuere leo dictum quis. Sed ultricies feugiat eros dignissim bibendum.
Mauris scelerisque consectetur libero eget varius. Aenean neque nunc, ullamcorper vitae orci in, auctor ornare sapien. Nam lacinia molestie imperdiet. Nam vitae mattis nibh. Vestibulum consequat tellus ac nisi sagittis pulvinar. Nullam mollis ornare quam, et venenatis leo porttitor sit amet. Nulla urna neque, dignissim non orci ut, volutpat ultrices erat. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Pellentesque vestibulum tellus nec eros faucibus porta.

Example output:

EITUSALNROMCDPVGQBFHJKWXYZ

Note: there is a 5 way tie between KWXYZ for that input.
Edit:

The competition is over! Thanks to everyone who participated. And now for the winner(s!): Both Dennis' CJam and isaacg's Pyth answers came in at a whopping 19 characters. (Sorry, but I'm not going to accept either of the answers because I think it would be unfair to the other.) Edit: Taking Dennis' advice, I'm going to mark his answer as accepted because his was the first to reach 19 characters. Honorable mentions go to Ilmari Karonen's third-place Golfscript answer at 22 chars as well as undergroundmonorail's 75-char Python answer that got the most upvotes. Once again, thanks to everyone who participated!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char c;
	size_t n;
} ch_t;

int
cmp(const void *a, const void *b)
{
	const ch_t *x, *y;

	x = a;
	y = b;
	if (x->n > y->n)
		return -1;
	if (x->n < y->n)
		return 1;
	if (x->c < y->c)
		return -1;
	if (x->c > y->c)
		return 1;
	return 0;
}

char *
etaoinshrdlu(const char *s, char *b)
{
	ch_t ch[26];
	size_t i;
	int c;

	for (i = 0; i < nelem(ch); i++) {
		ch[i].c = 'A' + i;
		ch[i].n = 0;
	}

	for (i = 0; s[i]; i++) {
		c = toupper(s[i]);
		if ('A' <= c && c <= 'Z')
			ch[c - 'A'].n++;
	}
	qsort(ch, nelem(ch), sizeof(*ch), cmp);

	for (i = 0; i < nelem(ch); i++)
		b[i] = ch[i].c;
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	etaoinshrdlu(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	const char *txt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent vitae erat velit. Mauris gravida euismod libero ut tincidunt. Phasellus elit dui, consectetur et egestas in, aliquam vitae diam. Donec eget varius ante. Vestibulum cursus diam aliquet, egestas orci quis, placerat dolor. Proin vel nisi lectus. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Aliquam erat volutpat. Etiam libero tortor, ornare id dui eget, posuere dignissim libero. Pellentesque commodo consequat volutpat. Integer hendrerit sapien libero, vel viverra augue facilisis sit amet. Quisque consectetur eget nisl quis dignissim. Ut lacinia pretium quam a placerat. Morbi sed interdum risus, nec pretium lectus. Morbi imperdiet est id accumsan molestie. Duis sed fermentum nisl. Nunc vitae augue mattis, dictum lectus vel, accumsan nisl. Sed ultricies adipiscing rhoncus. Vivamus eu lacus a enim venenatis eleifend. Praesent consectetur tortor non eleifend ultricies. Mauris et odio posuere, auctor erat at, fringilla est. Proin in vestibulum erat. Maecenas congue commodo ante vel varius. Sed tempus mi ut metus gravida, nec dictum libero dapibus. Morbi quis viverra elit. Ut pharetra neque eget lacus tincidunt dictum. Fusce scelerisque viverra tellus et pretium. Fusce varius adipiscing odio. Nulla imperdiet faucibus sem, at rhoncus ipsum adipiscing vitae. Phasellus imperdiet congue lacus et mollis. Nullam egestas mauris magna, et mollis lectus varius ut. Sed sollicitudin adipiscing dolor, vel elementum elit laoreet molestie. Aliquam nec nulla vel sem ultrices ullamcorper. Nullam nec felis magna. Duis sodales orci non justo aliquam tempus. Integer mi diam, tempor sed vulputate et, varius et nunc. Vestibulum sodales ipsum id mi pharetra, ut convallis mi accumsan. Sed dictum volutpat vestibulum. Quisque ac dolor sagittis, aliquam libero at, euismod enim. Nulla ullamcorper posuere nulla vitae varius. Nam at dolor non libero elementum pellentesque in in lorem. Fusce porttitor turpis in quam placerat varius. Donec lorem orci, condimentum eu sapien sit amet, aliquet commodo magna. Quisque sed lectus sit amet arcu euismod accumsan et non nunc. Phasellus placerat congue metus, feugiat posuere leo dictum quis. Sed ultricies feugiat eros dignissim bibendum. Mauris scelerisque consectetur libero eget varius. Aenean neque nunc, ullamcorper vitae orci in, auctor ornare sapien. Nam lacinia molestie imperdiet. Nam vitae mattis nibh. Vestibulum consequat tellus ac nisi sagittis pulvinar. Nullam mollis ornare quam, et venenatis leo porttitor sit amet. Nulla urna neque, dignissim non orci ut, volutpat ultrices erat. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Pellentesque vestibulum tellus nec eros faucibus porta.";

	test(txt, "EITUSALNROMCDPVGQBFHJKWXYZ");
	return 0;
}
