/*

You've seen the amazing alphabet triangle, the revenge of the alphabet triangle and now it's time for the revenge of the revenge of the alphabet triangle!

Introducing...

THE ALPHABET DIAMOND!

Your task is to output this exact text, lowercase/uppercase does not matter, though newlines do:

bcdefghijklmnopqrstuvwxyzazyxwvutsrqponmlkjihgfedcb
cdefghijklmnopqrstuvwxyzabazyxwvutsrqponmlkjihgfedc
defghijklmnopqrstuvwxyzabcbazyxwvutsrqponmlkjihgfed
efghijklmnopqrstuvwxyzabcdcbazyxwvutsrqponmlkjihgfe
fghijklmnopqrstuvwxyzabcdedcbazyxwvutsrqponmlkjihgf
ghijklmnopqrstuvwxyzabcdefedcbazyxwvutsrqponmlkjihg
hijklmnopqrstuvwxyzabcdefgfedcbazyxwvutsrqponmlkjih
ijklmnopqrstuvwxyzabcdefghgfedcbazyxwvutsrqponmlkji
jklmnopqrstuvwxyzabcdefghihgfedcbazyxwvutsrqponmlkj
klmnopqrstuvwxyzabcdefghijihgfedcbazyxwvutsrqponmlk
lmnopqrstuvwxyzabcdefghijkjihgfedcbazyxwvutsrqponml
mnopqrstuvwxyzabcdefghijklkjihgfedcbazyxwvutsrqponm
nopqrstuvwxyzabcdefghijklmlkjihgfedcbazyxwvutsrqpon
opqrstuvwxyzabcdefghijklmnmlkjihgfedcbazyxwvutsrqpo
pqrstuvwxyzabcdefghijklmnonmlkjihgfedcbazyxwvutsrqp
qrstuvwxyzabcdefghijklmnoponmlkjihgfedcbazyxwvutsrq
rstuvwxyzabcdefghijklmnopqponmlkjihgfedcbazyxwvutsr
stuvwxyzabcdefghijklmnopqrqponmlkjihgfedcbazyxwvuts
tuvwxyzabcdefghijklmnopqrsrqponmlkjihgfedcbazyxwvut
uvwxyzabcdefghijklmnopqrstsrqponmlkjihgfedcbazyxwvu
vwxyzabcdefghijklmnopqrstutsrqponmlkjihgfedcbazyxwv
wxyzabcdefghijklmnopqrstuvutsrqponmlkjihgfedcbazyxw
xyzabcdefghijklmnopqrstuvwvutsrqponmlkjihgfedcbazyx
yzabcdefghijklmnopqrstuvwxwvutsrqponmlkjihgfedcbazy
zabcdefghijklmnopqrstuvwxyxwvutsrqponmlkjihgfedcbaz
abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba
bcdefghijklmnopqrstuvwxyzazyxwvutsrqponmlkjihgfedcb
abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba
zabcdefghijklmnopqrstuvwxyxwvutsrqponmlkjihgfedcbaz
yzabcdefghijklmnopqrstuvwxwvutsrqponmlkjihgfedcbazy
xyzabcdefghijklmnopqrstuvwvutsrqponmlkjihgfedcbazyx
wxyzabcdefghijklmnopqrstuvutsrqponmlkjihgfedcbazyxw
vwxyzabcdefghijklmnopqrstutsrqponmlkjihgfedcbazyxwv
uvwxyzabcdefghijklmnopqrstsrqponmlkjihgfedcbazyxwvu
tuvwxyzabcdefghijklmnopqrsrqponmlkjihgfedcbazyxwvut
stuvwxyzabcdefghijklmnopqrqponmlkjihgfedcbazyxwvuts
rstuvwxyzabcdefghijklmnopqponmlkjihgfedcbazyxwvutsr
qrstuvwxyzabcdefghijklmnoponmlkjihgfedcbazyxwvutsrq
pqrstuvwxyzabcdefghijklmnonmlkjihgfedcbazyxwvutsrqp
opqrstuvwxyzabcdefghijklmnmlkjihgfedcbazyxwvutsrqpo
nopqrstuvwxyzabcdefghijklmlkjihgfedcbazyxwvutsrqpon
mnopqrstuvwxyzabcdefghijklkjihgfedcbazyxwvutsrqponm
lmnopqrstuvwxyzabcdefghijkjihgfedcbazyxwvutsrqponml
klmnopqrstuvwxyzabcdefghijihgfedcbazyxwvutsrqponmlk
jklmnopqrstuvwxyzabcdefghihgfedcbazyxwvutsrqponmlkj
ijklmnopqrstuvwxyzabcdefghgfedcbazyxwvutsrqponmlkji
hijklmnopqrstuvwxyzabcdefgfedcbazyxwvutsrqponmlkjih
ghijklmnopqrstuvwxyzabcdefedcbazyxwvutsrqponmlkjihg
fghijklmnopqrstuvwxyzabcdedcbazyxwvutsrqponmlkjihgf
efghijklmnopqrstuvwxyzabcdcbazyxwvutsrqponmlkjihgfe
defghijklmnopqrstuvwxyzabcbazyxwvutsrqponmlkjihgfed
cdefghijklmnopqrstuvwxyzabazyxwvutsrqponmlkjihgfedc
bcdefghijklmnopqrstuvwxyzazyxwvutsrqponmlkjihgfedcb

This is code-golf, lowest bytecount wins.

Rules:

    Standard loopholes are disallowed.
    a must be the center of the alphabet diamond.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void
diamond(void)
{
	int c, i, x, y;

	for (i = 2756; --i;) {
		x = i % 52;
		y = i / 52;
		c = 10;
		if (i % 52)
			c = 90 - (abs(x - 26) + abs(y - 26) + 25) % 26;
		putchar(tolower(c));
	}
	putchar('\n');
}

int
main(void)
{
	diamond();
	return 0;
}