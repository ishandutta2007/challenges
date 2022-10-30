/*

In your grandparents' day, dialing a phone number was done with a rotary dial like this:

To dial each digit, put your finger in the corresponding hole, pull it over to the finger stop, and release it.
A mechanism will cause the dial to spin back to its resting position, and the phone will disconnect and reconnect a circuit a specified number of times, making audible clicks.

Dialing the digit N requires N such “pulses”, except for N=0 which is ten pulses.

Rotary phones have the property that large digits (8, 9, 0) take longer to dial than small digits (1, 2, 3).
This was an important consideration in drawing up early area code maps, and why New York City with its heavy population (and phone line) density got 212 (only 5 pulses), while while 907 (26 pulses) went to sparsely-inhabited Alaska.
Of course, this all became irrelevant when touch-tone dialing became popular.

The challenge

Write, in as few bytes as possible, a program or function that takes as input a string (or sequence of characters) containing a telephone number, and outputs its number of rotary dial pulses. These are to be counted as follows:
Digits

    Digits 1-9 count as that number of pulses.
    Digit 0 counts as 10 pulses.

Letters

Note that digits 2-9 on the dial have letters of the Latin alphabet associated with them. These were originally intended for named exchanges, but were latter re-appropriated for phonewords, and for text message input systems.

You must support having letters in your phone numbers, using the E.161 assignment of letters to digits:

    A, B, C = 2
    D, E, F = 3
    G, H, I = 4
    J, K, L = 5
    M, N, O = 6
    P, Q, R, S = 7
    T, U, V = 8
    W, X, Y, Z = 9

You may assume that the input has already been case-folded, to either upper or lower case.
Other characters

You must allow arbitrary use of the characters ()+-./ and space as formatting separators. You may chose to allow any non-alphanumeric character for this purpose, if it's easier to implement.

These characters do not contribute to the pulse count.
Example code

A non-golfed lookup table and function in Python:

PULSES = {
    '1': 1,
    '2': 2, 'A': 2, 'B': 2, 'C': 2,
    '3': 3, 'D': 3, 'E': 3, 'F': 3,
    '4': 4, 'G': 4, 'H': 4, 'I': 4,
    '5': 5, 'J': 5, 'K': 5, 'L': 5,
    '6': 6, 'M': 6, 'N': 6, 'O': 6,
    '7': 7, 'P': 7, 'Q': 7, 'R': 7, 'S': 7,
    '8': 8, 'T': 8, 'U': 8, 'V': 8,
    '9': 9, 'W': 9, 'X': 9, 'Y': 9, 'Z': 9,
    '0': 10
}

def pulse_count(phone_num):
    return sum(PULSES.get(digit, 0) for digit in phone_num)

Example input and output

    911 → 11
    867-5309 → 48
    713 555 0123 → 42
    +1 (212) PE6-5000 → 57
    1-800-FLOWERS → 69
    PUZZLES → 48

*/

#include <assert.h>
#include <stdio.h>

int
pulsecount(const char *s)
{
	static int tab[256] = {
	    ['1'] = 1,
	    ['2'] = 2,
	    ['A'] = 2,
	    ['B'] = 2,
	    ['C'] = 2,
	    ['3'] = 3,
	    ['D'] = 3,
	    ['E'] = 3,
	    ['F'] = 3,
	    ['4'] = 4,
	    ['G'] = 4,
	    ['H'] = 4,
	    ['I'] = 4,
	    ['5'] = 5,
	    ['J'] = 5,
	    ['K'] = 5,
	    ['L'] = 5,
	    ['6'] = 6,
	    ['M'] = 6,
	    ['N'] = 6,
	    ['O'] = 6,
	    ['7'] = 7,
	    ['P'] = 7,
	    ['Q'] = 7,
	    ['R'] = 7,
	    ['S'] = 7,
	    ['8'] = 8,
	    ['T'] = 8,
	    ['U'] = 8,
	    ['V'] = 8,
	    ['9'] = 9,
	    ['W'] = 9,
	    ['X'] = 9,
	    ['Y'] = 9,
	    ['Z'] = 9,
	    ['0'] = 10,
	};

	size_t i;
	int r;

	r = 0;
	for (i = 0; s[i]; i++)
		r += tab[s[i] & 0xff];
	return r;
}

int
main(void)
{
	assert(pulsecount("911") == 11);
	assert(pulsecount("867-5309") == 48);
	assert(pulsecount("713 555 0123") == 42);
	assert(pulsecount("+1 (212) PE6-5000") == 57);
	assert(pulsecount("1-800-FLOWERS") == 69);
	assert(pulsecount("PUZZLES") == 48);

	return 0;
}
