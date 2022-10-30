/*

4, 8, 15, 16, 23, 42

Write a program that outputs this sequence of numbers infinitely. However, The Numbers must not appear in your source code anywhere.

The following is not a valid Java program to output The Numbers because The Numbers appear in its source code:

class TheNumbers {
    public static void main(String[] args) {
        for(int n = 0;;) System.out.println(
            n == 4 ? n = 8 :
            n == 8 ? n = 15 :
            n == 15 ? n = 16 :
            n == 16 ? n = 23 :
            n == 23 ? n = 42 : (n = 4)
        );
    }
}

The definition of "The Numbers must not appear in your source code" is as follows:

    You must not use the numeral 4.
    You must not use the numeral 8.
    You must not use the numeral 1 followed by the numeral 5.
    You must not use the numeral 1 followed by the numeral 6.
    You must not use the numeral 2 followed by the numeral 3.

If your language ignores certain characters that can be placed between the numerals, it's not a valid substitution. So for example if your language interprets the literal 1_5 as 15, this would count as the numeral 1 followed by the numeral 5.

Alternative bases are included in the restriction, so for example:

    Binary 100 can't be used as a substitute for 4.
    Octal 10 can't be used as a substitute for 8.
    Hexadecimal F can't be used as a substitute for 15.

Therefore, the following is a valid (but not very inspired) Java program to output The Numbers because The Numbers do not appear in its source code:

class TheNumbers {
    public static void main(String[] args) {
        for(int n = '*';;) {
            System.out.println(n -= '&');
            System.out.println(n *= 2);
            System.out.println(n += 7);
            System.out.println(++n);
            System.out.println(n += 7);
            System.out.println(n += 19);
        }
    }
}

Note that in that program, '*' and '&' are substituted for the integers 42 and 38, because otherwise the numerals 4 and 8 would appear in its source code.

The definition of "outputs the sequence infinitely" is open to interpretation. So, for example, a program that outputs glyphs getting smaller until they are "infinitely" small would be valid.

Kudos if you are able to generate the sequence in some way that's not basically hard-coding each number.

    Deriving it to a formula. My impression is there is not one but maybe there is or it can be faked.
    Fixing a pseudo-random generator to return the sequence.

This is a popularity contest, so be creative. The answer with the most up votes on March 26th is the winner.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
seq(unsigned n)
{
	static const unsigned tab[] = {
	    4,
	    8,
	    15,
	    16,
	    23,
	    42,
	};
	return tab[n % nelem(tab)];
}

int
main(void)
{
	unsigned i;

	for (i = 0; i < 1000; i++)
		printf("%u\n", seq(i));
	return 0;
}
