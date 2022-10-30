/*

So what effect does a marriage ceremony has on an arbitrary bachelor (boy)? Well it depends on his thought process and context: he can be happy or sad.
But in general what a marriage ceremony does is that it decreases the number of both bachelor and spinster (Female Bachelor) by one in the community.
And so marriage ceremony has an effect on the probability of marriage of a bachelor.
Let’s simplify things a bit as life is more complicated than what we want to admit.
Suppose in a community there are B bachelors and S spinsters
(Both B and S are strictly positive) and all of them are equally likely to be married with one another (ahem! a bachelor and a spinster of course) and marriage does not happen outside the community.
And so in this model the probability of getting married for any bachelor is S/B or 1 (The value that is smaller).
So when a marriage ceremony occurs the probability becomes (S−1)(B−1) or 1 (The value that is smaller).
But of course if the denominator becomes zero the probability cannot be determined.
Whether this new probability (S−1)(B−1) is greater than the previous one (S/B) depends on the relative values of B and S (B > S, B = S or B < S).
Given the number of bachelors and spinsters in a community your job is to find out whether or not the probability of marriage for any bachelor will increase or decrease in the community after a marriage ceremony has occurred.

Input

The input file contains at most 1000 lines of inputs. Each line contains two integers B and S (0 < B, S < 2000000001).
Input is terminated by a line containing two zeroes. This line should not be processed.

Output

For each line of input produce one line of output. This line should contain the serial of output followed
by a ‘:-)’, ‘:-(’ or ‘:-|’ respectively (without the quotes) depending on whether or not the probability
of marriage for a bachelor increases, decreases or remains same. If the desired probability after the
marriage cannot be determined then produce the output ‘:-\’ (Without the quotes) instead.

Sample Input
10 10
2 3
3 2
0 0

Sample Output
Case 1: :-|
Case 2: :-|
Case 3: :-(

*/

#include <assert.h>
#include <string.h>

const char *
state(int b, int s)
{
	if (b == 0 || b == 1)
		return ":-\\";
	if (s >= b)
		return ":-|";
	return ":-(";
}

int
main(void)
{
	assert(!strcmp(state(10, 10), ":-|"));
	assert(!strcmp(state(2, 3), ":-|"));
	assert(!strcmp(state(3, 2), ":-("));
	assert(!strcmp(state(1, 0), ":-\\"));

	return 0;
}
