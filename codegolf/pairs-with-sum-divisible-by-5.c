/*

You will be given two integers M and N. Find the number of pairs (x,y) such that 1≤x≤M, 1≤y≤N and (x+y)mod5=0.

For example, if M=6 and N=12, pairs which satisfies such conditions are, (1,4),(4,1),(1,9),(2,3),(2,8),(3,2),(3,7),(3,12),(4,6),(6,4),(4,11),(5,5),(5,10),(6,9)

Total 14.

Sample

Input : 6 12
Output: 14

Input : 11 14
Output: 31

Input : 553 29
Output: 3208

Input : 2 2
Output: 0

Input : 752486 871672
Output: 131184195318 

This is a code-golf challenge so code with lowest bytes wins!

Update

Jonathan Allan's solution has the smallest code size, 5 bytes. However, it doesn't produce an answer for the last given test.

I have decided to go with the next answer with the shortest size that produces the correct answer for the largest test, there is a tie between two golfers who competed neck-to-neck.

I proudly present the winners of this challenge Lyxal and Kevin Cruijssen with only 7 bytes code! Congratulations! 🎉

As many of you, I found Arnauld's answer most helpful in finding the correct solution. So, I am accepting Arnauld's answer.

Thank you, Golfers!

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
pair(uvlong m, uvlong n)
{
	return m * n / 5 + ((5 - m % 5) * (5 - n % 5) < 5);
}

int
main(void)
{
	assert(pair(6, 12) == 14);
	assert(pair(11, 14) == 31);
	assert(pair(553, 29) == 3208);
	assert(pair(2, 2) == 0);
	assert(pair(752486ull, 871672ull) == 131184195318ull);

	return 0;
}
