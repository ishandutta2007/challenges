/*

A Proth number, named after François Proth, is a number that can be expressed as

N=k×2^n+1

Where k is an odd positive integer and n is a positive integer such that 2^n>k. Let's use a more concrete example. Take 3. 3 is a Proth number because it can be written as

3=(1×2^1)+1

and 2^1>1 is satisfied. 5 Is also a Proth number because it can be written as

5=(1×2^2)+1

and 2^2>1 is satisfied. However, 7 is not a Proth number because the only way to write it in the form N=k×2n+1 is

7=(3×2^1)+1

and 2^1>3 is not satisfied.

Your challenge is fairly simple: you must write a program or function that, given a positive integer, determines if it is a Proth number or not.
You may take input in any reasonable format, and should output a truthy value if it is a Proth number and a falsy value if it is not. If your language has any "Proth-number detecting" functions, you may use them.

Test IO
Here are the first 46 Proth numbers up to 1000. (A080075)

3, 5, 9, 13, 17, 25, 33, 41, 49, 57, 65, 81, 97, 113, 129, 145, 161, 177, 193, 209, 225, 241, 257, 289, 321, 353, 385, 417, 449, 481, 513, 545, 577, 609, 641, 673, 705, 737, 769, 801, 833, 865, 897, 929, 961, 993
Every other valid input should give a falsy value.

As usual, this is code-golf, so standard loopholes apply, and the shortest answer in bytes wins!

Number theory fun-fact side-note:

The largest known prime that is not a Mersenne Prime is 19249×2^13018586+1, which just so happens to also be a Proth number!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A080075
bool
proth(int n)
{
	int k, m, t;

	if (n < 2)
		return false;

	t = n - 1;
	m = 0;
	while (t > 1 && !(t % 2)) {
		m += 1;
		t /= 2;
	}
	k = t;
	m = 1 << m;

	if (m <= k)
		return false;
	return (k * m) + 1 == n;
}

int
main(void)
{
	static const int tab[] = {
	    3,
	    5,
	    9,
	    13,
	    17,
	    25,
	    33,
	    41,
	    49,
	    57,
	    65,
	    81,
	    97,
	    113,
	    129,
	    145,
	    161,
	    177,
	    193,
	    209,
	    225,
	    241,
	    257,
	    289,
	    321,
	    353,
	    385,
	    417,
	    449,
	    481,
	    513,
	    545,
	    577,
	    609,
	    641,
	    673,
	    705,
	    737,
	    769,
	    801,
	    833,
	    865,
	    897,
	    929,
	    961,
	    993,
	};

	char lut[1024];
	unsigned i, n;

	memset(lut, 0, sizeof(lut));
	for (i = 0; i < nelem(tab); i++)
		lut[tab[i]] = 1;

	n = tab[nelem(tab) - 1];
	for (i = 0; i <= n; i++) {
		if (lut[i])
			assert(proth(i) == true);
		else
			assert(proth(i) == false);
	}

	return 0;
}
