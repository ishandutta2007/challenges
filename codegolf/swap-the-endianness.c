/*

As most of you probably know, (byte-addressable) hardware memories can be divided into two categories - little-endian and big-endian.
In little-endian memories the bytes are numbered starting with 0 at the little (least significant) end and in big-endian ones the other way round.

Fun fact: These terms are based on Jonathan Swift's book Gulliver's Travels where the Lilliputian king ordered his citizens to break their eggs on the little end (thus the little-endians) and the rebels would break theirs on the big end.
How swapping works

Suppose we have an unsigned integer (32bit) 12648430 in memory, in a big-endian machine that might look as follows:

  addr: 0  1  2  3
memory: 00 C0 FF EE

By inverting the byte-order we get the hexadecimal integer 0xEEFFC000 which is 4009738240 in decimal.
Your task

Write a program/function that receives an unsigned 32bit integer in decimal and outputs the resulting integer when swapping the endianness as described above.
Rules

    Input will always be in the range 0 to 4294967295
    Output can be printed to STDOUT (trailing newlines/spaces are fine) or returned
    Input and output are in decimal
    Behavior on invalid input is left undefined

Test cases

0 -> 0
1 -> 16777216
42 -> 704643072
128 -> 2147483648
12648430 -> 4009738240
16885952 -> 3232235777
704643072 -> 42
3735928559 -> 4022250974
4009738240 -> 12648430
4026531839 -> 4294967279
4294967295 -> 4294967295

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uint32_t
enswap32(uint32_t x)
{
	return ((x & 0xfful) << 24) |
	       ((x & 0xff00ul) << 8) |
	       ((x & 0xff0000ul) >> 8) |
	       ((x & 0xff000000ul) >> 24);
}

int
main(void)
{
	static const uint32_t tab[][2] = {
	    {0ul, 0ul},
	    {1ul, 16777216ul},
	    {42ul, 704643072ul},
	    {128ul, 2147483648ul},
	    {12648430ul, 4009738240ul},
	    {16885952ul, 3232235777ul},
	    {704643072ul, 42ul},
	    {3735928559ul, 4022250974ul},
	    {4009738240ul, 12648430ul},
	    {4026531839ul, 4294967279ul},
	    {4294967295ul, 4294967295ul},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(enswap32(tab[i][0]) == tab[i][1]);

	return 0;
}
