/*

Input/Output:

Input: A uniformly random, infinitely long, string of '0's and '1's, taken from stdin. The string is assumed to be truly random, not pseudo-random.
It is uniform in that each character is equally likely to be a '0' or '1'.

Careful! The input is infinitely long, so you can't store it all in memory using a function like raw_input() in python. If I'm not mistaken, golfscript will fail with infinite input, since it pushes the entire input onto the stack prior to running.

Output: A uniformly random shuffled standard deck, without jokers. It is uniform in that all orderings are equally likely.

Each card in the output is it's rank, A, 2-9, T, J, Q or K concatenated with it's suit, c, d, h or s. For example, the 10 of spades is Ts

The cards of the deck should be separated by spaces.

You may not use built-in random libraries or functions because they are not truly random, only pseudo-random.

Example input
You may use the following python script to pipe input into your program:

import sys, random
try:
    while True:
        sys.stdout.write(str(random.randint(0,1)))
except IOError:
    pass
If you save the script as rand.py, test your program with python rand.py | your_program

In python 3 it runs as expected, but in python 2.7 I get an error message after my program's output, but only after everything's done, so just ignore the error message.

Example output:
Here's how the deck should be printed if it happened to be shuffled into a sorted order:

Ac 2c 3c 4c 5c 6c 7c 8c 9c Tc Jc Qc Kc Ad 2d 3d 4d 5d 6d 7d 8d 9d Td Jd Qd Kd Ah 2h 3h 4h 5h 6h 7h 8h 9h Th Jh Qh Kh As 2s 3s 4s 5s 6s 7s 8s 9s Ts Js Qs Ks
Scoring:
This is a code golf. Shortest code wins.

Example program:
Here is a python 2.7 solution, not golfed.

import sys
def next():
    return int(sys.stdin.read(1))==1
def roll(n):
    if n==1:
        return 0
    if n%2==0:
        r=roll(n/2)
        if next():
            r+=n/2
        return r
    else:
        r=n
        while(r==n):
            r=roll(n+1)
        return r
deck = [rank+suit for suit in 'cdhs' for rank in 'A23456789TJQK']
while len(deck)>0:
    print deck.pop(roll(len(deck))),

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int rank;
	int suit;
} Card;

int
deck(Card *c)
{
	static const char rank[] = "A23456789TJQK";
	static const char suit[] = "cdhs";

	const char *r, *s;
	Card *p;

	p = c;
	for (s = suit; *s; s++) {
		for (r = rank; *r; r++) {
			p->rank = *r;
			p->suit = *s;
			p++;
		}
	}
	return p - c;
}

int
rand2()
{
	return rand() % 2;
}

int
roll(int n, int (*next)(void))
{
	int r;

	if (n < 0)
		return 0;
	if (n == 1)
		return 0;
	if (n % 2 == 0) {
		r = roll(n / 2, next);
		if (next())
			r += n / 2;
		return r;
	}
	r = n;
	while (r == n)
		r = roll(n + 1, next);
	return r;
}

int
pop(Card *c, int i, int n)
{
	c[i] = c[n - 1];
	return n - 1;
}

void
sim(int (*next)(void))
{
	Card c[52];
	int i, n;

	n = deck(c);
	while (n > 0) {
		i = roll(n, next);
		printf("%c%c ", c[i].rank, c[i].suit);
		n = pop(c, i, n);
	}
	printf("\n");
}

int
main(void)
{
	srand(time(NULL));
	sim(rand2);

	return 0;
}
