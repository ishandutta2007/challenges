/*

As is well known,

Chuck Norris counted to infinity. Twice

Besides,

Chuck Norris can count to infinity backwards.

Also, although perhaps less known, Chuck Norris can speak a little Spanish in addition to English.

The challenge
Write a program (or function) that can be run in two different languages. In one language the program should output the sequence

1, 1, 2, 2, 3, 3, 4, 4, ...
and in the other language it should produce the sequence (including leading zeros)

1, 2, ..., 9, 01, 11, 21, 31, ..., 89, 99, 001, 101, 201, ...
Rules
Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.
Different versions of the same language (such as Python 2/3) don't count as different languages. Related languages (such as C/C++ or Matlab/Octave) do count as different.
No input will be taken.
The program should continue to output terms of the sequence until stopped by the user. Since the program will not stop by itself, output cannot be produced at the end. It must be produced while the program runs, either continuously or in batches.
Output can use STDOUT or equivalent, or can be displayed in a graphic window. Any non-numeric separator between sequence terms is allowed, as long as each term can be clearly distinguished from its neighbouring terms.
It is also acceptable if the screen is cleared between terms.
Either sequence can start at 0 instead of 1. In that case, in the "twice" sequence the 0 should be repeated, just like the other numbers.
Leading zeros are significant in the "backwards" sequence. For example, the tenth term is 01; neither 1 nor 001 are acceptable.
If the two languages use different character encodings, the program is defined by its bytes, not its characters. That is, the bytes should be the same in the two languages.
Shortest code in bytes wins.

*/

#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
count1(uvlong n)
{
	return (n + 2) / 2;
}

uvlong
count2(uvlong n)
{
	uvlong r;

	r = 0;
	do {
		r = (r * 10) + (n % 10);
		n /= 10;
	} while (n);
	return r;
}

void
chucknorris(uvlong n)
{
	uvlong i;

	for (i = 0; i < n; i++) {
#ifndef __cplusplus
		printf("%llu\n", count1(i));
#else
		printf("%llu\n", count2(i));
#endif
	}
}

int
main(void)
{
	chucknorris(100);

	return 0;
}
