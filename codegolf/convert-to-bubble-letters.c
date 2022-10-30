/*

So I was playing around with my compose key, and found some cool things, one of them being that by pressing compose + ( + alphanumeric + ), you get that character inside a bubble, like so: ⓐ.

Your task in this challenge is simple, to convert ordinary text to bubble letter text.

Here are the ascii chars, the bubble characters and their Unicode code points:

0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
⓪①②③④⑤⑥⑦⑧⑨ⓐⓑⓒⓓⓔⓕⓖⓗⓘⓙⓚⓛⓜⓝⓞⓟⓠⓡⓢⓣⓤⓥⓦⓧⓨⓩⒶⒷⒸⒹⒺⒻⒼⒽⒾⒿⓀⓁⓂⓃⓄⓅⓆⓇⓈⓉⓊⓋⓌⓍⓎⓏ
9450 9312 9313 9314 9315 9316 9317 9318 9319 9320 9424 9425 9426 9427 9428 9429 9430 9431 9432 9433 9434 9435 9436 9437 9438 9439 9440 9441 9442 9443 9444 9445 9446 9447 9448 9449 9398 9399 9400 9401 9402 9403 9404 9405 9406 9407 9408 9409 9410 9411 9412 9413 9414 9415 9416 9417 9418 9419 9420 9421 9422 9423
Your input will contain only printable ascii characters, and if a character cannot be bubbleified, leave it as is.

This is code-golf, so shortest code in bytes wins!

Note: This is not isomorphic to my earlier challenge about small-caps conversion since unlike small-caps, bubble letters are in a mostly contiguous segment of code-points, allowing for more interesting approaches.

*/

#include <stdio.h>

char *
bubbles(const char *s, char *b)
{
	static const char tab[][8] = {
	    u8"⓪",
	    u8"①",
	    u8"②",
	    u8"③",
	    u8"④",
	    u8"⑤",
	    u8"⑥",
	    u8"⑦",
	    u8"⑧",
	    u8"⑨",
	    u8"ⓐ",
	    u8"ⓑ",
	    u8"ⓒ",
	    u8"ⓓ",
	    u8"ⓔ",
	    u8"ⓕ",
	    u8"ⓖ",
	    u8"ⓗ",
	    u8"ⓘ",
	    u8"ⓙ",
	    u8"ⓚ",
	    u8"ⓛ",
	    u8"ⓜ",
	    u8"ⓝ",
	    u8"ⓞ",
	    u8"ⓟ",
	    u8"ⓠ",
	    u8"ⓡ",
	    u8"ⓢ",
	    u8"ⓣ",
	    u8"ⓤ",
	    u8"ⓥ",
	    u8"ⓦ",
	    u8"ⓧ",
	    u8"ⓨ",
	    u8"ⓩ",
	    u8"Ⓐ",
	    u8"Ⓑ",
	    u8"Ⓒ",
	    u8"Ⓓ",
	    u8"Ⓔ",
	    u8"Ⓕ",
	    u8"Ⓖ",
	    u8"Ⓗ",
	    u8"Ⓘ",
	    u8"Ⓙ",
	    u8"Ⓚ",
	    u8"Ⓛ",
	    u8"Ⓜ",
	    u8"Ⓝ",
	    u8"Ⓞ",
	    u8"Ⓟ",
	    u8"Ⓠ",
	    u8"Ⓡ",
	    u8"Ⓢ",
	    u8"Ⓣ",
	    u8"Ⓤ",
	    u8"Ⓥ",
	    u8"Ⓦ",
	    u8"Ⓧ",
	    u8"Ⓨ",
	    u8"Ⓩ",
	};

	size_t i, l;
	int c;

	l = 0;
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if ('0' <= c && c <= '9')
			l += sprintf(b + l, "%s", tab[c - '0']);
		else if ('A' <= c && c <= 'Z')
			l += sprintf(b + l, "%s", tab[c - 'A' + 10]);
		else if ('a' <= c && c <= 'z')
			l += sprintf(b + l, "%s", tab[c - 'a' + 10]);
		else
			l += sprintf(b + l, "%c", c);
	}

	return b;
}

void
test(const char *s)
{
	char b[128];

	bubbles(s, b);
	printf("%s\n", b);
}

int
main(void)
{
	test("HeLlO 1234567890 uNxI");

	return 0;
}
