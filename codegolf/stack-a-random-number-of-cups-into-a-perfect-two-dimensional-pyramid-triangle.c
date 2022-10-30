/*

You are given a certain number of cups (n). You are tasked with stacking these cups into a pyramid, with each row having one more cup than the row above it.
The number you are given may or may not be able to be perfectly stacked. You must write a function that takes the total number of cups (n), and returns the following values.
t, which is the total number of cups in the pyramid, and b, which is the number of cups on the bottom row. Your answer must be returned in the format of a string, as b,t.

n is a randomly generated, positive, finite, whole number.
b and t must also be positive, finite, and whole.
You may not use any libraries that aren't already built into your language of choice.
The pyramid is two dimensional, so instead of expanding out, it is linear, with each row adding only a single cup more than the last, instead of one with a square or triangular base.
In some potential cases:

If n=4, b=2 and t=3.
If n=13, b=4 and t=10.
If n=5000, b=99 and t=4950.
A verbose example in JavaScript:

var pyramid = function(n){
    var i;
    var t = 0;
    var b;
    for(i=0;i<=(n-t);i++){
        t += i;
        b = i;
    }
    console.log(b + ',' + t);
}
And a tiny example too:

p=function(n){for(t=i=0;i<=(n-t);i++){t+=i;b=i}return b+','+t}

Good luck!

*/

#include <stdio.h>

void
pyramid(int n, int *t, int *b)
{
	int i;

	*b = *t = 0;
	for (i = 0; i <= n - *t; i++) {
		*t += i;
		*b = i;
	}
}

int
main(void)
{
	int i, t, b;

	for (i = 0; i <= 10; i++) {
		pyramid(i, &t, &b);
		printf("%d | %d %d\n", i, b, t);
	}
	return 0;
}
