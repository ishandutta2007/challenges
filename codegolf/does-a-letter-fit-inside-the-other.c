/*

Do you remember my mat properly grouped by colors?

My mat properly grouped by colors

Yesterday I was looking at it and realized that some letters fit inside others.
Example: a letter P fits in the place where the letter R goes. So here's a simple challenge: given two letters, return a truthy value if any one of the letters fits inside the other (directly or rotated, but not flipped), or a falsey value if they don't.
That is, if the input is [P,R] or [R,P], you must return truthy because in both cases one letter fits inside the other. If you get [L,U] you must return falsey as neither fit inside the other.

Rules

    The input must be two alphanumeric characters in the range [0-9A-Z], as there are also numbers in the mat, in any form you need (two separate chars as two inputs, a list with two chars, a string with the 2 chars, whatever).
    The output must be consistent (the truthy and falsey values must be always the same).

    Following is the table of fittings (note that a letter always fits in its proper place, just in case you get something like [Y,Y] as input):

    char fits inside chars
    --------------------------------------------------------
       C             G,O
       F             B,E,P,R
       G             O
       I             0,1,7,B,D,E,F,H,K,L,M,N,O,P,R,T,V,W,X,Z
       L             E
       M             W
       P             R
       S             O
       V             A
       W             M
       0             O
       1             B,E,L
       3             O
       6             9,O
       8             O
       9             6,O

I solemnly swear that I have tested every fitting in my kid's mat. (Dries his sweat from his forehead.)

This is code-golf, so may the shortest code for each language win!

Some test cases

input  output
-------------
[C,G]  truthy (C fits inside G)
[G,C]  truthy (C fits inside G)
[F,R]  truthy (F fits inside R)
[M,W]  truthy (both fit inside the other)
[O,S]  truthy (S fits inside O)
[T,T]  truthy (T fits in its place)
[E,V]  falsey (no fit found)
[P,L]  falsey

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>

bool
charfit(char a, char b)
{
	static const char *tab[256] = {
	    ['C'] = "GO",
	    ['F'] = "BEPR",
	    ['G'] = "O",
	    ['I'] = "017BDEFHKLMNOPRTVWXZ",
	    ['L'] = "E",
	    ['M'] = "W",
	    ['P'] = "R",
	    ['S'] = "O",
	    ['V'] = "A",
	    ['W'] = "M",
	    ['0'] = "O",
	    ['1'] = "BEL",
	    ['3'] = "O",
	    ['6'] = "9O",
	    ['8'] = "O",
	    ['9'] = "6O",
	};
	const char *p, *q;

	p = tab[a & 0xff];
	q = tab[b & 0xff];
	return (a == b || (p && strchr(p, b)) || (q && strchr(q, a)));
}

int
main(void)
{
	assert(charfit('C', 'G') == true);
	assert(charfit('G', 'C') == true);
	assert(charfit('F', 'R') == true);
	assert(charfit('M', 'W') == true);
	assert(charfit('O', 'S') == true);
	assert(charfit('T', 'T') == true);
	assert(charfit('E', 'V') == false);
	assert(charfit('P', 'L') == false);

	return 0;
}
